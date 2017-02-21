#include "Rotate.h"

Rotate::Rotate(double angle) : m_targetAngle(angle), m_initAngle(0) {
	Requires(CommandBase::pDriveSystem.get());
}

// Called just before this Command runs the first time
void Rotate::Initialize() {
	m_initAngle = CommandBase::pDriveSystem->GetGyroAngle();
}

// Called repeatedly when this Command is scheduled to run
void Rotate::Execute() {

//	double remainingAngle = m_targetAngle - (CommandBase::pDriveSystem->GetGyroAngle() - m_initAngle);
//	double speed = std::fmax(std::fmin(remainingAngle / m_targetAngle, m_MAX_RATE), -m_MAX_RATE);
//
//	std::cout << speed << std::endl;
	double speed = 0.0;
	double currentAngle = CommandBase::pDriveSystem->GetGyroAngle() - m_initAngle;

	if (currentAngle < m_targetAngle)
		speed = m_RATE;
	else if (currentAngle > m_targetAngle)
		speed = -m_RATE;

	std::cout << speed << std::endl;

	CommandBase::pDriveSystem->Drive(0.0f, 0.0f, speed);
}

// Make this return true when this Command no longer needs to run execute()
bool Rotate::IsFinished() {
	return std::abs(CommandBase::pDriveSystem->GetGyroAngle() - m_initAngle - m_targetAngle) <= m_ELIPSON;
}

// Called once after isFinished returns true
void Rotate::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Rotate::Interrupted() {

}
