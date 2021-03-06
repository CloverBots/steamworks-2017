#ifndef Rotate_H
#define Rotate_H

#include "../CommandBase.h"

class Rotate : public CommandBase {
private:

	const float m_MAX_RATE = 0.35f;
	const float m_MIN_RATE = 0.1f;
	const float m_RATE = 0.35f;
	const double m_ELIPSON = 1.0;

	double m_targetAngle;
	double m_initAngle;

	bool m_relative;

public:
	Rotate(double angle, bool relative);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // Rotate_H
