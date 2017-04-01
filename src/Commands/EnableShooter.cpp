#include <Commands/EnableShooter.h>

EnableShooter::EnableShooter()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(CommandBase::shooterSubsystem.get());
}

// Called just before this Command runs the first time
void EnableShooter::Initialize()
{
	CommandBase::shooterSubsystem->SetShooterMotor(true);
}

// Called repeatedly when this Command is scheduled to run
void EnableShooter::Execute()
{
	std::cout << CommandBase::shooterSubsystem->GetShooterSpeed() << std::endl;;
//	int encVel = CommandBase::shooterSubsystem->GetShooterEncVel();
//	CommandBase::shooterSubsystem->ShooterWheel((1.0f - ((float)encVel / (float)m_MAX_RATE)) * m_PGAIN);
}

// Make this return true when this Command no longer needs to run execute()
bool EnableShooter::IsFinished()
{
	return abs(CommandBase::shooterSubsystem->GetShooterSpeed()) >= abs(CommandBase::shooterSubsystem->GetShooterTargetSpeed()) - m_SPEED_THRESHOLD;
}

// Called once after isFinished returns true
void EnableShooter::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void EnableShooter::Interrupted()
{

}
