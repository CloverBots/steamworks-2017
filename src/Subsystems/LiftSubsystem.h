#ifndef LiftSubsystem_H
#define LiftSubsystem_H

#include <Commands/Subsystem.h>
#include <WPILib.h>
#include <DigitalOutput.h>

class LiftSubsystem : public Subsystem {
private:
	Relay* m_pLiftMotor;
public:
	LiftSubsystem();
	void setMotor(bool b);
};
#endif
