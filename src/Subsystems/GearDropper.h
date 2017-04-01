#ifndef GearDropper_H
#define GearDropper_H

#include <WPILib.h>
#include <Commands/Subsystem.h>

class GearDropper : public Subsystem {
private:
	//Relay* pSpike;
	Talon* pTalon;
	DigitalInput* pOpenLimSwitch;
	DigitalInput* pClosedLimSwitch;

	bool m_open;
	const float m_speed = 0.8f;//0.75f;

	void PrintSwitchStatus();
public:
	GearDropper();
	void InitDefaultCommand();
	void DropGear();
	void CloseDoor();
	void SetDoorDirection(Relay::Value direction);

	bool IsOpenTriggered();
	bool IsClosedTriggered();

	void SetOpen(bool open);
	bool IsOpen();
};

#endif  // GearDropper_H
