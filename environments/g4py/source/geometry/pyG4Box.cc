//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
// $Id: pyG4Box.cc,v 1.4 2006/06/29 15:31:50 gunter Exp $
// $Name: geant4-08-01 $
// ====================================================================
//   pyG4Box.cc
//
//                                         2005 Q
// ====================================================================
#include <boost/python.hpp>
#include "G4Box.hh"

using namespace boost::python;

// ====================================================================
// module definition
// ====================================================================
void export_G4Box()
{
  class_<G4Box, G4Box*, bases<G4VSolid> >
    ("G4Box", "box solid class", no_init)
    // constructors
    .def(init<const G4String&, G4double, G4double, G4double>())
    // ---
    .def("GetXHalfLength",   &G4Box::GetXHalfLength)
    .def("GetYHalfLength",   &G4Box::GetYHalfLength)
    .def("GetZHalfLength",   &G4Box::GetZHalfLength)
    .def("SetXHalfLength",   &G4Box::SetXHalfLength)
    .def("SetYHalfLength",   &G4Box::SetYHalfLength)
    .def("SetZHalfLength",   &G4Box::SetZHalfLength)
    .def("GetCubicVolume",   &G4Box::GetCubicVolume)
    // operators
    .def(self_ns::str(self))
    ;
}
