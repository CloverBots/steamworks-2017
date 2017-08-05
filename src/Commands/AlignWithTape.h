#ifndef AlignWithTape_H
#define AlignWithTape_H

#include "../CommandBase.h"
#include "WPILib.h"

class AlignWithTape : public CommandBase
{
private:

	enum AlignMode
	{
		ROTATE,
		APPROACH
	} m_alignMode;

	const float m_SENSITIVITY_X = 1.0f;
	const float m_SENSITIVITY_Y = 0.5f;
	const float m_SENSITIVITY_ALIGN = 4.0f;
	const float m_MAX_THROTTLE = 0.3f;//0.25f;//0.4f;
	const float m_MIN_THROTTLE = 0.175f;//0.15f;//0.2f;
	const float m_MAX_ROTATION = 0.175f;
	const float m_TARGET_LOST_TIMEOUT = 6;
	const int m_UPDATE_RATE = 50;

	int m_alignFrames;
	int m_approachFrames;

	float m_throttle;
	float m_rotation;

	int m_frameCount;
	int m_framesLost;

	int m_defaultAlignDirection;

public:

	enum AlignDirection
	{
		NONE = 0,
		CW = 1,
		CCW = 2
	};

	AlignWithTape(float alignTime, float timeoutInSeconds, AlignDirection defaultAlignDirection = AlignDirection::NONE);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
