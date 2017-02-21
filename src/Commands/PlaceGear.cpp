#include "PlaceGear.h"
#include "Commands/AlignWithTape.h"
#include "Commands/ToggleDoor.h"
#include "Subsystems/DriveSystem.h"
#include "FuncCommand.h"

PlaceGear::PlaceGear() {
	Requires(CommandBase::pDriveSystem.get());
	Requires(CommandBase::gearDropper.get());

	AddSequential(new AlignWithTape());
	AddSequential(new FuncCommand(std::bind(&DriveSystem::Drive, CommandBase::pDriveSystem.get(), 0.125f, 0.0f, 0.0f)));
	AddSequential(new FuncCommand(std::bind(&Wait, 1.0)));
	AddSequential(new FuncCommand(std::bind(&DriveSystem::Drive, CommandBase::pDriveSystem.get(), 0.0f, 0.0f, 0.0f)));
	AddSequential(new ToggleDoor());
	AddSequential(new FuncCommand(std::bind(&Wait, 1.0)));
	AddSequential(new FuncCommand(std::bind(&DriveSystem::Drive, CommandBase::pDriveSystem.get(), -0.25f, 0.0f, 0.0f)));
	AddSequential(new FuncCommand(std::bind(&Wait, 1.0)));
	AddSequential(new FuncCommand(std::bind(&DriveSystem::Drive, CommandBase::pDriveSystem.get(), 0.0f, 0.0f, 0.0f)));
	AddSequential(new ToggleDoor());
}
