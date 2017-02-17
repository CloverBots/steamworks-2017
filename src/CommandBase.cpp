#include "CommandBase.h"
#include "Subsystems/DriveSystem.h"
#include "Commands/Scheduler.h"

// Initialize a single static instance of all of your subsystems to NULL
std::unique_ptr<DriveSystem> CommandBase::pDriveSystem;
std::unique_ptr<Collector> CommandBase::pCollector;
std::unique_ptr<LiftSubsystem> CommandBase::liftSubsystem;
std::unique_ptr<Shooter> CommandBase::shooterSubsystem;
std::unique_ptr<GearDropper> CommandBase::gearDropper;
std::unique_ptr<OI> CommandBase::oi;

CommandBase::CommandBase(const std::string &name) :
		Command(name)
{
}

CommandBase::CommandBase() :
		Command()
{

}

void CommandBase::init()
{
	// Create a single static instance of all of your subsystems. The following
	// line should be repeated for each subsystem in the project.
	pDriveSystem.reset(new DriveSystem());
	pCollector.reset(new Collector());

	oi.reset(new OI());
}
