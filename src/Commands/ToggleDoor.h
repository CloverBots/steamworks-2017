#ifndef ToggleDoor_H
#define ToggleDoor_H

#include "../CommandBase.h"

class ToggleDoor : public CommandBase {
public:
	ToggleDoor();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ToggleDoor_H
