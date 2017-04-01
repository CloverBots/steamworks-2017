#include "LiftOff.h"

LiftOff::LiftOff() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(CommandBase::liftSubsystem.get());
}

void LiftOff::Initialize()
{
	liftSubsystem->Set(0.0);
}
