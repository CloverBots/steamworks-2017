#ifndef GearDropper_H
#define GearDropper_H

#include <WPILib.h>
#include <Commands/Subsystem.h>

class GearDropper : public Subsystem {
private:
	Relay* pSpike;
	DigitalInput* pOpenLimSwitch;
	DigitalInput* pClosedLimSwitch;

	bool m_open;

	void PrintSwitchStatus();
public:
	GearDropper();
	void InitDefaultCommand();
	void DropGear();
	void CloseDoor();
	void SetDoorDirection(Relay::Value direction);

	Relay* GetSpike();
	bool IsOpenTriggered();
	bool IsClosedTriggered();

	void SetOpen(bool open);
	bool IsOpen();
};

#endif  // GearDropper_H
