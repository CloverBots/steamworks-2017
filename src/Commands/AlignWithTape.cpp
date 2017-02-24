#include "AlignWithTape.h"

AlignWithTape::AlignWithTape() : m_throttle(0), m_rotation(0), m_framesLost(0)
{
	Requires(CommandBase::pDriveSystem.get());
}

// Called just before this Command runs the first time
void AlignWithTape::Initialize()
{
	CommandBase::pDriveSystem->Drive(0.0f, 0.0f, 0.0f);

	m_throttle = 0.0f;
	m_rotation = 0.0f;

	//CommandBase::oi->SetCameraMode(OI::CameraMode::GEAR);
}

// Called repeatedly when this Command is scheduled to run
void AlignWithTape::Execute()
{
	cv::Point center = CommandBase::oi->GetGearCenter();

	if (CommandBase::oi->GetGearContours().size() >= 2)
	{
		m_throttle = fmax(fmax(OI::CAMERA_Y_RES - center.y, 0) / (float)OI::CAMERA_Y_RES * m_MAX_THROTTLE, m_MIN_THROTTLE);
		m_rotation = fmax(fmin((m_SENSITIVITY_X * ((float)center.x / (float)OI::CAMERA_X_RES)), m_MAX_ROTATION), -m_MAX_ROTATION);

		m_framesLost = 0;
	}
	else
	{
		m_framesLost++;
	}

	CommandBase::pDriveSystem->Drive(
			m_throttle,
			0.0f,
			m_rotation);
}

// Make this return true when this Command no longer needs to run execute()
bool AlignWithTape::IsFinished()
{
	return m_framesLost > m_TARGET_LOST_TIMEOUT;
}

// Called once after isFinished returns true
void AlignWithTape::End()
{
	//CommandBase::oi->SetCameraMode(OI::CameraMode::NONE);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AlignWithTape::Interrupted()
{

}
