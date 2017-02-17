#ifndef ControlCollector_H
#define ControlCollector_H

#include "../CommandBase.h"

class ControlCollector : public CommandBase {
public:
	ControlCollector();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ControlCollector_H
