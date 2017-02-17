#ifndef shooter_H
#define shooter_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../CANPIDSource.h"
class shooter: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	float m_P = 1.5f;
	float m_I = 0.75f;;
	float m_D = 0.0f;
	const double m_ENCODER_RATE = 1400;
	Talon* Stageing_wheel;
	Talon* Bin;
	CANTalon* Shooting_wheel;
	CANPIDSource* ShooterSource;
	PIDController* ShooterController;

public:
	shooter();
	void StageingWheel(float speed);
	void ShooterWheel(float speed);
	int GetShooterEncVel();
	void BinSpeed(float speed);
	void SetPIDEnabled(bool enabled);
	void SetPID(float p, float i, float d);
	void InitDefaultCommand();
};

#endif
