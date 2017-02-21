#include "ToggleDoor.h"

ToggleDoor::ToggleDoor() {
	Requires(CommandBase::gearDropper.get());
}

// Called just before this Command runs the first time
void ToggleDoor::Initialize() {
	CommandBase::gearDropper->SetDoorDirection(
			CommandBase::gearDropper->IsOpenTriggered() ?
					Relay::kForward : Relay::kReverse);

	std::cout << (CommandBase::gearDropper->IsOpenTriggered() ?
			"Opening...\n" : "Closing...\n");
}

// Called repeatedly when this Command is scheduled to run
void ToggleDoor::Execute() {
}

// Make this return true when this Command no longer needs to run execute()
bool ToggleDoor::IsFinished() {
	return (CommandBase::gearDropper->GetSpike()->Get() == Relay::kReverse ?
			CommandBase::gearDropper->IsOpenTriggered() :
			CommandBase::gearDropper->IsClosedTriggered()) ||
			CommandBase::oi->GetOperatorStick()->GetRawButton(2);
}

// Called once after isFinished returns true
void ToggleDoor::End() {
	std::cout << "Finished.\n";
	CommandBase::gearDropper->SetDoorDirection(Relay::kOff);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ToggleDoor::Interrupted() {

}
