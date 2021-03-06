#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include <memory>
#include <string>

#include <Commands/Command.h>

#include <string>
#include "Commands/Command.h"
#include "Subsystems/DriveSystem.h"
#include "Subsystems/Collector.h"
#include "Subsystems/LiftSubsystem.h"
#include "Subsystems/Shooter.h"
#include "Subsystems/GearDropper.h"
#include "OI.h"
#include "WPILib.h"

/**
 * The base for all commands. All atomic commands should subclass CommandBase.
 * CommandBase stores creates and stores each control system. To access a
 * subsystem elsewhere in your code in your code use
 * CommandBase::exampleSubsystem
 */
class CommandBase: public frc::Command {
public:
	CommandBase(const std::string& name);
	CommandBase() = default;

	static void Init();

	// Create a single static instance of all of your subsystems
	static std::unique_ptr<DriveSystem> pDriveSystem;
	static std::unique_ptr<Collector> pCollector;
	static std::unique_ptr<LiftSubsystem> liftSubsystem;
	static std::unique_ptr<Shooter> shooterSubsystem;
	static std::unique_ptr<GearDropper> gearDropper;
	static std::unique_ptr<OI> oi;
};

#endif  // COMMAND_BASE_H
