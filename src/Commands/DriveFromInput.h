#ifndef DriveFromInput_H
#define DriveFromInput_H

#include "../CommandBase.h"
#include "WPILib.h"

class DriveFromInput: public CommandBase
{
public:
	DriveFromInput();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
