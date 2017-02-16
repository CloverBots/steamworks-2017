#include "LiftOff.h"

LiftOff::LiftOff() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(CommandBase::liftSubsystem);
	liftSubsystem->setMotor(false);
}
