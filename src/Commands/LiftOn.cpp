#include "LiftOn.h"

LiftOn::LiftOn() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(CommandBase::liftSubsystem.get());
}

void LiftOn::Initialize()
{
	liftSubsystem->setMotor(true);
}
