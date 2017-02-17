#ifndef GearDropper_H
#define GearDropper_H

#include <Commands/Subsystem.h>

class GearDropper : public Subsystem {
private:

public:
	GearDropper();
	void InitDefaultCommand();
	void DropGear();
	void CloseDoor();
};

#endif  // GearDropper_H
