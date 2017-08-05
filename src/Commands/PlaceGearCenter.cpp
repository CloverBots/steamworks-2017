#include "PlaceGearCenter.h"
#include "Commands/AlignWithTape.h"
#include "Commands/ToggleDoor.h"
#include "../FuncCommand.h"

PlaceGearCenter::PlaceGearCenter() {
	Requires(CommandBase::pDriveSystem.get());
	Requires(CommandBase::gearDropper.get());

	AddSequential(new AlignWithTape(0.0, 2.5, AlignWithTape::AlignDirection::NONE)); // TODO: Check for if first param is 0.
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
