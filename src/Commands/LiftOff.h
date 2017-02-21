#ifndef LiftOff_H
#define LiftOff_H

#include "../CommandBase.h"
#include <WPILib.h>

class LiftOff : public CommandBase {
public:
	LiftOff();

	void Initialize();
	bool IsFinished() { return true; }
};

#endif  // LiftOff_H
