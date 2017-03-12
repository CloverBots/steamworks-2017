#include "ShootSequence.h"
#include "SetShooterWheelSpeed.h"
#include "SetStageingWheelSpeed.h"
#include "SetBinSpeed.h"
ShootSequence::ShootSequence()
{
	AddSequential(new SetShooterWheelSpeed(1.0f));
	AddSequential(new SetStageingWheelSpeed(-1.0f));
	AddSequential(new SetBinSpeed(-1.0f));
}
