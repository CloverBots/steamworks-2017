#ifndef CloseDoor_H
#define CloseDoor_H

#include "../CommandBase.h"

class CloseDoor : public CommandBase
{
private:
	Relay* pSpike;
	DigitalInput* pLimSwitchClosed;
public:
	CloseDoor();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // CloseDoor_H
