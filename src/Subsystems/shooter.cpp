#include "shooter.h"
#include "../RobotMap.h"
shooter::shooter() :
		Subsystem("ShooterSubsystem")
{
	Stageing_wheel = new Talon(RobotMap::STAGEING_WHEEL);
	Bin = new Talon(RobotMap::BIN_MOTOR);
	Shooting_wheel = new CANTalon(RobotMap::SHOOTING_WHEEL);
	ShooterSource = new CANPIDSource(Shooting_wheel, m_ENCODER_RATE);
	ShooterController = new PIDController(m_P, m_I, m_D, ShooterSource, Shooting_wheel);

}

void shooter::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void shooter::ShooterWheel(float speed)
{
	Shooting_wheel->Set(speed);
}

int shooter::GetShooterEncVel(){
return Shooting_wheel->GetEncVel();
}

void shooter::StageingWheel(float speed)
{
	Stageing_wheel->Set(speed);
}

void shooter::BinSpeed(float speed)
{
	Bin->Set(speed);
}
void shooter::SetPIDEnabled(bool enabled)
{
	ShooterController->SetSetpoint(0.0f);
	Shooting_wheel->Set(0.0f);
	ShooterController->Reset();
	if (enabled)
		ShooterController->Enable();
}

void shooter::SetPID(float p, float i, float d)
{
	ShooterController->SetPID(p, i, d);
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
