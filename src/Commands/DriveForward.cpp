#include "DriveForward.h"
#include "FuncCommand.h"
#include "Subsystems/DriveSystem.h"

DriveForward::DriveForward() {
	Requires(CommandBase::pDriveSystem.get());

	AddSequential(new FuncCommand(std::bind(&DriveSystem::Drive, CommandBase::pDriveSystem.get(), -1.0f, 0.0f, 0.0f)));
	AddSequential(new FuncCommand(std::bind(&Wait, 1.0)));
	AddSequential(new FuncCommand(std::bind(&DriveSystem::Drive, CommandBase::pDriveSystem.get(), 0.0f, 0.0f, 0.0f)));
}
