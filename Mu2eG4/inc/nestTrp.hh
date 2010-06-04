#ifndef NESTTRP_HH
#define NESTTRP_HH
//
// Free function to create a new G4 Trp, placed inside a logical volume.
// 
// $Id: nestTrp.hh,v 1.1 2010/06/04 22:07:22 genser Exp $
// $Author: genser $ 
// $Date: 2010/06/04 22:07:22 $
//
// Original author Rob Kutschke
//

#include <string>
#include <vector>

#include "Mu2eG4/inc/VolumeInfo.hh"

class G4Material;
class G4LogicalVolume;
class G4VPhysicalVolume;
class G4CSGSolid;

#include "G4ThreeVector.hh"
#include "G4RotationMatrix.hh"
#include "G4Colour.hh"

namespace mu2e {

  VolumeInfo nestTrp ( std::string const& name,
                       double const halfDim[5],
                       G4Material* material,
                       G4RotationMatrix* rot,
                       G4ThreeVector const& offset,
                       G4LogicalVolume* parent,
                       int copyNo,
                       G4Colour color = G4Colour::Yellow(),
                       bool forceSolid = false
                       );
  


  // Alternate argument list, using a vector for the half dimensions.
  inline VolumeInfo nestTrp ( std::string const& name,
                              std::vector<double> const&  halfDim,
                              G4Material* material,
                              G4RotationMatrix* rot,
                              G4ThreeVector const& offset,
                              G4LogicalVolume* parent,
                              int copyNo,
                              G4Colour color = G4Colour::Yellow(),
                              bool forceSolid = false
                              ){
    return nestTrp( name, 
                    &halfDim[0],
                    material,
                    rot,
                    offset,
                    parent,
                    copyNo,
                    color,
                    forceSolid
                    );
  }
}

#endif
