#include <Commands/PlaceGearRight.h>
#include "Commands/AlignWithTape.h"
#include "Commands/ToggleDoor.h"
#include "Commands/Rotate.h"
#include "Subsystems/DriveSystem.h"
#include "FuncCommand.h"

PlaceGearRight::PlaceGearRight(bool strafeToBoiler) {
	Requires(CommandBase::pDriveSystem.get());
	Requires(CommandBase::gearDropper.get());

	AddSequential(new FuncCommand(std::bind(&DriveSystem::Drive, CommandBase::pDriveSystem.get(), 0.5f, 0.0f, 0.0f)));
	AddSequential(new FuncCommand(std::bind(&Wait, 0.9/*1.2*//*1.25*/)));
	AddSequential(new Rotate(-50, false));
	AddSequential(new AlignWithTape(2.0));
	AddSequential(new FuncCommand(std::bind(&DriveSystem::Drive, CommandBase::pDriveSystem.get(), 0.125f, 0.0f, 0.0f)));
	AddSequential(new FuncCommand(std::bind(&Wait, 1.0)));
	AddSequential(new FuncCommand(std::bind(&DriveSystem::Drive, CommandBase::pDriveSystem.get(), 0.0f, 0.0f, 0.0f)));
	AddSequential(new ToggleDoor());
	AddSequential(new FuncCommand(std::bind(&Wait, 1.0)));
	AddSequential(new FuncCommand(std::bind(&DriveSystem::Drive, CommandBase::pDriveSystem.get(), -0.25f, 0.0f, 0.0f)));
	AddSequential(new FuncCommand(std::bind(&Wait, 0.75)));
	AddSequential(new FuncCommand(std::bind(&DriveSystem::Drive, CommandBase::pDriveSystem.get(), 0.0f, 0.0f, 0.0f)));
	AddSequential(new ToggleDoor());

	if (strafeToBoiler)
	{
		AddSequential(new Rotate(-180, false));
		AddSequential(new FuncCommand(std::bind(&DriveSystem::Drive, CommandBase::pDriveSystem.get(), 0.0, 1.0f, 0.0f)));
		AddSequential(new FuncCommand(std::bind(&Wait, 1.4)));
		AddSequential(new FuncCommand(std::bind(&DriveSystem::Drive, CommandBase::pDriveSystem.get(), 0.0f, 0.0f, 0.0f)));
	}
}
