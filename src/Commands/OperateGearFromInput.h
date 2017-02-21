#ifndef OperateGearFromInput_H
#define OperateGearFromInput_H

#include "../CommandBase.h"

class OperateGearFromInput : public CommandBase {
public:
	OperateGearFromInput();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // OperateGearFromInput_H
