#ifndef AlignWithTape_H
#define AlignWithTape_H

#include "../CommandBase.h"
#include "WPILib.h"

class AlignWithTape : public CommandBase
{
private:

	const float m_SENSITIVITY_X = 1.0f;
	const float m_SENSITIVITY_Y = 0.5f;
	const float m_MAX_THROTTLE = 0.25f;
	const float m_MIN_THROTTLE = 0.15f;
	const float m_MAX_ROTATION = 0.175f;
	const float m_TARGET_LOST_TIMEOUT = 6;
	const int m_UPDATE_RATE = 50;

	int m_maxFrames; // 1.5 seconds * 50 frames/s

	float m_throttle;
	float m_rotation;

	int m_totalFrames;
	int m_framesLost;

public:
	AlignWithTape(float timeoutInSeconds);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
