#include <Subsystems/Shooter.h>
#include "../RobotMap.h"
Shooter::Shooter() :
		Subsystem("ShooterSubsystem")
{
	Stageing_wheel = new Talon(RobotMap::STAGING_MOTOR);
	Bin = new Talon(RobotMap::BIN_MOTOR);
	Shooting_wheel = new CANTalon(RobotMap::SHOOTER_MOTOR);
	ShooterSource = new CANPIDSource(Shooting_wheel, m_ENCODER_RATE);
	ShooterController = new PIDController(m_P, m_I, m_D, ShooterSource, Shooting_wheel);
}

void Shooter::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void Shooter::ShooterWheel(float speed)
{
	Shooting_wheel->Set(speed);
}

int Shooter::GetShooterEncVel(){
return Shooting_wheel->GetEncVel();
}

void Shooter::StagingWheel(float speed)
{
	Stageing_wheel->Set(speed);
}

void Shooter::BinSpeed(float speed)
{
	Bin->Set(speed);
}
void Shooter::SetPIDEnabled(bool enabled)
{
	ShooterController->SetSetpoint(0.0f);
	Shooting_wheel->Set(0.0f);
	ShooterController->Reset();
	if (enabled)
		ShooterController->Enable();
}

void Shooter::SetPID(float p, float i, float d)
{
	ShooterController->SetPID(p, i, d);
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
