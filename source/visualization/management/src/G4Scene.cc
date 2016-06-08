// This code implementation is the intellectual property of
// the RD44 GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G4Scene.cc,v 1.3 1999/05/25 09:14:15 johna Exp $
// GEANT4 tag $Name: geant4-00-01 $
//
// 
// Scene data  John Allison  19th July 1996.

#include "G4Scene.hh"

#include "G4Vector3D.hh"
#include "G4BoundingSphereScene.hh"
#include "G4VisAttributes.hh"
#include "G4PhysicalVolumeModel.hh"
#include "G4TransportationManager.hh"

G4Scene::G4Scene (const G4String& name):
  fName (name)
{} // Note all data members have default initial values.

G4Scene::~G4Scene () {}

void G4Scene::AddRunDurationModel (G4VModel* pModel) {
  fRunDurationModelList.append (pModel);
  G4int nModels = fRunDurationModelList.entries ();
  G4BoundingSphereScene boundingSphereScene;
  for (int i = 0; i < nModels; i++) {
    const G4VisExtent& thisExtent =
      fRunDurationModelList[i] -> GetExtent ();
    G4Point3D thisCentre = thisExtent.GetExtentCentre ();
    G4double thisRadius = thisExtent.GetExtentRadius ();

    //thisCentre.transform (fRunDurationModelList[i] -> GetTransformation ());
    // To by-pass temporary CLHEP non-const problem...
    G4Transform3D modelTransformation =
      fRunDurationModelList[i] -> GetTransformation ();
    thisCentre.transform (modelTransformation);

    boundingSphereScene.AccrueBoundingSphere (thisCentre, thisRadius);
  }
  fExtent = boundingSphereScene.GetBoundingSphereExtent ();
  fStandardTargetPoint = fExtent.GetExtentCentre ();
}
  
void G4Scene::AddWorldIfEmpty () {
  if (IsEmpty ()) {
    G4VPhysicalVolume* pWorld =
      G4TransportationManager::GetTransportationManager ()
      -> GetNavigatorForTracking () -> GetWorldVolume ();
    if (pWorld) {
      const G4VisAttributes* pVisAttribs =
	pWorld -> GetLogicalVolume () -> GetVisAttributes ();
      if (!pVisAttribs || pVisAttribs -> IsVisible ()) {
	G4cout << 
	  "Your \"world\" has no vis attributes or is marked as visible."
	  "\n  For a better view of the contents, mark the world as"
	  " invisible, e.g.,"
	  "\n  myWorldLogicalVol ->"
	  " SetVisAttributes (G4VisAttributes::Invisible);"
	       << endl;
      }
      AddRunDurationModel (new G4PhysicalVolumeModel (pWorld));
      // Note: default depth and no modeling parameters.
      G4cout <<
	"G4Scene::AddWorldIfEmpty: The scene was empty,"
	"\n   \"world\" has been added.";
      G4cout << endl;
    }
  }
}

void G4Scene::Clear () {
  fRunDurationModelList.clearAndDestroy ();
  fEndOfEventModelList.clearAndDestroy ();
}

ostream& operator << (ostream& os, const G4Scene& d) {

  os << "Scene data:";

  os << "\n  Run-duration model list:";
  for (int i = 0; i < d.fRunDurationModelList.entries (); i++) {
    os << "\n  " << *(d.fRunDurationModelList[i]);
  }

  os << "\n  End-of-event model list:";
  for (int ii = 0; ii < d.fEndOfEventModelList.entries (); ii++) {
    os << "\n  " << *(d.fEndOfEventModelList[ii]);
  }

  os << "\n  Extent or bounding box: " << d.fExtent;

  os << "\n  Standard target point:  " << d.fStandardTargetPoint;

  return os;
}

G4bool G4Scene::operator != (const G4Scene& s) const {
  if (
      (fRunDurationModelList.entries () !=
       s.fRunDurationModelList.entries ())              ||
      (fExtent               != s.fExtent)              ||
      !(fStandardTargetPoint == s.fStandardTargetPoint)
      ) return true;

  for (int i = 0; i < fRunDurationModelList.entries (); i++) {
    if (fRunDurationModelList[i] != s.fRunDurationModelList[i])
      return true;
  }

  return false;
}