#include "DriveFromInput.h"
#include "../Subsystems/DriveSystem.h"

DriveFromInput::DriveFromInput()
{
	Requires(CommandBase::pDriveSystem.get());
}

// Called just before this Command runs the first time
void DriveFromInput::Initialize()
{
	CommandBase::pDriveSystem->Drive(0.0f, 0.0f, 0.0f);
}

// Called repeatedly when this Command is scheduled to run
void DriveFromInput::Execute()
{
	Joystick* pDriveStick = CommandBase::oi->GetDriveStick();

	if (pDriveStick->GetRawButton(6))
	{
		CommandBase::pDriveSystem->Drive(
				pDriveStick->GetRawAxis(1) * 0.5f,
				(pDriveStick->GetRawAxis(3) - pDriveStick->GetRawAxis(2)) * 0.5f,
				pDriveStick->GetRawAxis(4) * 0.5f);
	}
	else
	{
		CommandBase::pDriveSystem->Drive(
				pDriveStick->GetRawAxis(1),
				pDriveStick->GetRawAxis(3) - pDriveStick->GetRawAxis(2),
				pDriveStick->GetRawAxis(4));
	}
}

// Make this return true when this Command no longer needs to run execute()
bool DriveFromInput::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void DriveFromInput::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveFromInput::Interrupted()
{

}
