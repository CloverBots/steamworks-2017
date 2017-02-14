#ifndef DriveSystem_H
#define DriveSystem_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class DriveSystem: public Subsystem
{
private:

	RobotDrive* m_pRobotDrive;

public:
	DriveSystem();

	void InitDefaultCommand();
	void Drive(float speed, float strafe, float rotation);
};

#endif
