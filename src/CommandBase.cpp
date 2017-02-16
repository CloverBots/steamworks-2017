#include "CommandBase.h"

#include <Commands/Scheduler.h>

#include "Subsystems/LiftSubsystem.h"

LiftSubsystem* CommandBase::liftSubsystem;
std::unique_ptr<OI> CommandBase::oi;

// Initialize a single static instance of all of your subsystems. The following
// line should be repeated for each subsystem in the project.

CommandBase::CommandBase(const std::string &name) :
		frc::Command(name) {

}

void CommandBase::init()
{
	liftSubsystem = new LiftSubsystem();

	oi.reset(new OI());
}
