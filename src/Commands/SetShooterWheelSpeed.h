#ifndef SetShooterWheelSpeed_H
#define SetShooterWheelSpeed_H

#include "../CommandBase.h"
#include "WPILib.h"

class SetShooterWheelSpeed: public CommandBase
{
private:
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
