#ifndef LiftOn_H
#define LiftOn_H

#include "../CommandBase.h"
#include <WPILib.h>

class LiftOn : public CommandBase {
public:
	LiftOn();

	void Initialize();
	bool IsFinished() { return true; }
};

#endif  // LiftOn_H
