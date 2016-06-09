//
// ********************************************************************
// * DISCLAIMER                                                       *
// *                                                                  *
// * The following disclaimer summarizes all the specific disclaimers *
// * of contributors to this software. The specific disclaimers,which *
// * govern, are listed with their locations in:                      *
// *   http://cern.ch/geant4/license                                  *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.                                                             *
// *                                                                  *
// * This  code  implementation is the  intellectual property  of the *
// * GEANT4 collaboration.                                            *
// * By copying,  distributing  or modifying the Program (or any work *
// * based  on  the Program)  you indicate  your  acceptance of  this *
// * statement, and all its terms.                                    *
// ********************************************************************
//
///////////////////////////////////////////////////////////////////////////////
// File: CCalG4Hall.hh
// Description: Equipped to construct G4 geometry of the experimental hall
///////////////////////////////////////////////////////////////////////////////
#ifndef CCalG4Hall_h
#define CCalG4Hall_h 1

#include "CCalHall.hh"
#include "CCalG4Able.hh"

class CCalG4Hall: public CCalHall, public CCalG4Able {
public:
  //Constructor and Destructor
  CCalG4Hall(const G4String &name);
  virtual ~CCalG4Hall();
  
protected:
  //This methods actually constructs the volume.
  virtual G4VPhysicalVolume* constructIn(G4VPhysicalVolume*);
  virtual void constructDaughters();
};

#endif