#ifndef shooter_H
#define shooter_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../CANPIDSource.h"
#include "CANTalon.h"

class Shooter: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	const float m_P = 0.75f;
	const float m_I = 0.175f;
	const float m_D = 0.0f;

	float m_shooterTargetSpeed;

	Talon* Stageing_wheel;
	Talon* Bin;
	CANTalon* Shooting_wheel;
	CANPIDSource* ShooterSource;
	PIDController* ShooterController;

public:
	const double m_ENCODER_RATE = 34000;

	Shooter();

	float GetShooterSpeed();
	void StagingWheel(float speed);
	void SetShooterMotor(bool enabled);
	int GetShooterEncVel();
	float GetShooterTargetSpeed();
	void BinSpeed(float speed);
	void SetPIDEnabled(bool enabled);
	void SetPID(float p, float i, float d);
	void UpdateFromSmartDashboard();

	void InitDefaultCommand();
};

#endif
