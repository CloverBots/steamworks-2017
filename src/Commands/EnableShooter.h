#ifndef SetShooterWheelSpeed_H
#define SetShooterWheelSpeed_H

#include "../CommandBase.h"
#include "WPILib.h"

class EnableShooter: public CommandBase
{
private:

	const float m_SPEED_THRESHOLD = 0.1f;

public:
	EnableShooter();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
