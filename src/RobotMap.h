#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"

struct RobotMap
{
	static const uint32_t
		LEFT_FRONT_TALON = 3,
		LEFT_REAR_TALON = 2,
		RIGHT_FRONT_TALON = 8,
		RIGHT_REAR_TALON = 6,
		BIN_MOTOR = 7,
		LIFT_SPIKE = 0,
		GEAR_SPIKE = 1,
		SHOOTER_MOTOR = 0,
		COLLECTOR_MOTOR = 9,
		STAGING_MOTOR = 1,
		GEAR_OPEN_SWITCH = 2,
		GEAR_CLOSED_SWITCH = 1;
};

#endif
