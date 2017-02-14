#ifndef AlignWithTape_H
#define AlignWithTape_H

#include "../CommandBase.h"
#include "WPILib.h"

class AlignWithTape: public CommandBase
{
private:

	const float m_SENSITIVITY = 2.0f;
	const float m_MAXPOWER = 0.175f;
	const int m_VERTICAL_TARGET = 100;

public:
	AlignWithTape();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
