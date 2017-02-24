#include "FuncCommand.h"

FuncCommand::FuncCommand(std::function<void()> func, std::initializer_list<Subsystem*> requiredSubsystems) : m_func(func)
{
	for (auto subsystem : requiredSubsystems)
		Requires(subsystem);
}

// Called just before this Command runs the first time
void FuncCommand::Initialize()
{
	m_func();
}

// Called repeatedly when this Command is scheduled to run
void FuncCommand::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool FuncCommand::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void FuncCommand::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void FuncCommand::Interrupted()
{

}
