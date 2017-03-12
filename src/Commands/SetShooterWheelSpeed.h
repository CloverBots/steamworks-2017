#ifndef SetShooterWheelSpeed_H
#define SetShooterWheelSpeed_H

#include "../CommandBase.h"
#include "WPILib.h"

class SetShooterWheelSpeed: public CommandBase
{
private:

	const int m_MIN_SPEED = 34000;

	float speed;
public:
	SetShooterWheelSpeed(float speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
