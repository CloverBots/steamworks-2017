#ifndef SetStageingWheelSpeed_H
#define SetStageingWheelSpeed_H

#include "../CommandBase.h"
#include "WPILib.h"

class SetStageingWheelSpeed: public CommandBase
{
private:
	float speed;
public:
	SetStageingWheelSpeed(float speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
