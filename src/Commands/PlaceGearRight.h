#ifndef PlaceGearRight_H
#define PlaceGearRight_H

#include <Commands/CommandGroup.h>

class PlaceGearRight : public CommandGroup {
public:
	PlaceGearRight(bool strafeToBoiler);
};

#endif  // PlaceGearRight_H
