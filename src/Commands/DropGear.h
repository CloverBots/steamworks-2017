#ifndef DropGear_H
#define DropGear_H

#include "../CommandBase.h"

class DropGear : public CommandBase
{
private:
	Relay* pSpike;
	DigitalInput* pLimSwitchOpen;

public:
	DropGear();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // DropGear_H
