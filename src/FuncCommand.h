#ifndef FuncCommand_H
#define FuncCommand_H

#include "CommandBase.h"
#include "WPILib.h"

class FuncCommand : public CommandBase
{
private:

	std::function<void()> m_func;

public:
	FuncCommand(std::function<void()> func);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
