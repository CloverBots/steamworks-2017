#include <Commands/EnableShooter.h>
#include "ShootSequence.h"
#include "SetStageingWheelSpeed.h"
#include "SetBinSpeed.h"

ShootSequence::ShootSequence()
{
	AddSequential(new EnableShooter());
	AddSequential(new SetStageingWheelSpeed(-1.0f));
	AddSequential(new SetBinSpeed(-0.5f/*-0.6f*//*-0.75f*/));
}
