#include "AlignWithTape.h"

AlignWithTape::AlignWithTape()
{
	Requires(CommandBase::pDriveSystem.get());
}

// Called just before this Command runs the first time
void AlignWithTape::Initialize()
{
	CommandBase::pDriveSystem->Drive(0.0f, 0.0f, 0.0f);
}

// Called repeatedly when this Command is scheduled to run
void AlignWithTape::Execute()
{
	int targetX = 0;
	int targetY = 0;

	std::vector<double> centerXValues = CommandBase::oi->GetContourValues("centerX");

	if (centerXValues.size() > 0)
		targetX = centerXValues[0] - CommandBase::oi->CAMERA_X_RES / 2;

	std::vector<double> centerYValues = CommandBase::oi->GetContourValues("centerY");

	if (centerYValues.size() > 0)
		targetY = fmax(0, centerYValues[0] - m_VERTICAL_TARGET);

	CommandBase::pDriveSystem->Drive(
			-fmax(
					fmin(
							(m_SENSITIVITY *
							((float)targetY / (float)CommandBase::oi->CAMERA_Y_RES)),
					m_MAXPOWER),
			-m_MAXPOWER),
			0.0f,
			fmax(
					fmin(
							(m_SENSITIVITY *
							((float)targetX / (float)CommandBase::oi->CAMERA_X_RES)),
					m_MAXPOWER),
			-m_MAXPOWER));
}

// Make this return true when this Command no longer needs to run execute()
bool AlignWithTape::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void AlignWithTape::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AlignWithTape::Interrupted()
{

}
