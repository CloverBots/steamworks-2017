#include <Subsystems/Shooter.h>
#include "../RobotMap.h"
#include "../FuncCommand.h"

Shooter::Shooter() :
		Subsystem("ShooterSubsystem"), m_shooterTargetSpeed(0.75f) // 0.65?
{
	Stageing_wheel = new Talon(RobotMap::STAGING_MOTOR);
	Bin = new Talon(RobotMap::BIN_MOTOR);
	Shooting_wheel = new CANTalon(RobotMap::SHOOTER_MOTOR);
	ShooterSource = new CANPIDSource(Shooting_wheel, m_ENCODER_RATE);
	ShooterController = new PIDController(m_P, m_I, m_D, ShooterSource, Shooting_wheel);
}

void Shooter::InitDefaultCommand()
{
	//SetDefaultCommand(new FuncCommand(std::bind(&Shooter::UpdateFromSmartDashboard, this), { CommandBase::shooterSubsystem.get() }));
}

void Shooter::SetShooterMotor(bool enabled)
{
	SetPIDEnabled(enabled);
	ShooterController->SetSetpoint(enabled ? m_shooterTargetSpeed : 0.0f);
	//Shooting_wheel->Set(speed);
}

int Shooter::GetShooterEncVel(){
	std::cout << Shooting_wheel->GetEncVel();
	return Shooting_wheel->GetEncVel();
}

float Shooter::GetShooterSpeed()
{
	return ShooterController->Get();
}

void Shooter::StagingWheel(float speed)
{
	Stageing_wheel->Set(speed);
}

void Shooter::BinSpeed(float speed)
{
	Bin->Set(speed);
}

float Shooter::GetShooterTargetSpeed()
{
	return m_shooterTargetSpeed;
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

void Shooter::UpdateFromSmartDashboard()
{
	SetPID(
			(float)SmartDashboard::GetNumber("Shooter P", 0.0),
			(float)SmartDashboard::GetNumber("Shooter I", 0.0),
			(float)SmartDashboard::GetNumber("Shooter D", 0.0));

	m_shooterTargetSpeed = (float)SmartDashboard::GetNumber("Shooter Speed", 0.0);
}
