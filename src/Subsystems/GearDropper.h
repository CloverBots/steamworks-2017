#ifndef GearDropper_H
#define GearDropper_H

#include <WPILib.h>
#include <Commands/Subsystem.h>

class GearDropper : public Subsystem {
private:
	Relay* pSpike;
	DigitalInput* pOpenLimSwitch;
	DigitalInput* pClosedLimSwitch;
public:
	GearDropper();
	void InitDefaultCommand();
	void DropGear();
	void CloseDoor();
	void SetDoorDirection(Relay::Value direction);

	Relay* GetSpike();
	bool IsOpenTriggered();
	bool IsClosedTriggered();
};

#endif  // GearDropper_H
