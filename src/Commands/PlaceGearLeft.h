#ifndef PlaceGearLeft_H
#define PlaceGearLeft_H

#include <Commands/CommandGroup.h>
#include "Commands/AlignWithTape.h"

class PlaceGearLeft : public CommandGroup {
public:
	PlaceGearLeft(bool strafeToBoiler);
};

#endif  // PlaceGearLeft_H
