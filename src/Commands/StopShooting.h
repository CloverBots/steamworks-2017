#ifndef StopShooting_H
#define StopShooting_H

#include "../CommandBase.h"
#include "WPILib.h"

class StopShooting: public CommandBase
{
public:
	StopShooting();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
