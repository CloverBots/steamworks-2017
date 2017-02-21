#include "OperateGearFromInput.h"

OperateGearFromInput::OperateGearFromInput() {
	Requires(CommandBase::gearDropper.get());
}

// Called just before this Command runs the first time
void OperateGearFromInput::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void OperateGearFromInput::Execute() {
	Joystick* joy = CommandBase::oi->GetOperatorStick();

	if (joy->GetRawButton(5))
		CommandBase::gearDropper->SetDoorDirection(Relay::kForward);
	else if (joy->GetRawButton(6))
		CommandBase::gearDropper->SetDoorDirection(Relay::kReverse);
	else
		CommandBase::gearDropper->SetDoorDirection(Relay::kOff);

	std::cout << "Open: " << CommandBase::gearDropper->IsOpenTriggered() <<
			", Closed: " << CommandBase::gearDropper->IsClosedTriggered() << std::endl;
}

// Make this return true when this Command no longer needs to run execute()
bool OperateGearFromInput::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void OperateGearFromInput::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void OperateGearFromInput::Interrupted() {

}
