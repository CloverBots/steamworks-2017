#include "ControlCollector.h"

ControlCollector::ControlCollector() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(CommandBase::pCollector.get());
}

// Called just before this Command runs the first time
void ControlCollector::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void ControlCollector::Execute()
{
	if(CommandBase::oi->GetOperatorStick()->GetRawButton(3))
		CommandBase::pCollector->SetCollectorSpeed(1.0f);
	else
		CommandBase::pCollector->SetCollectorSpeed(0.0f);
}

// Make this return true when this Command no longer needs to run execute()
bool ControlCollector::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ControlCollector::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ControlCollector::Interrupted() {

}
