#ifndef SetBinSpeed_H
#define SetBinSpeed_H

#include "../CommandBase.h"
#include "WPILib.h"

class SetBinSpeed: public CommandBase
{
float speed;
public:
	SetBinSpeed(float speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
