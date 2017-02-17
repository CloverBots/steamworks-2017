#ifndef Collector_H
#define Collector_H

#include "wpilib.h"
#include <Commands/Subsystem.h>

class Collector : public Subsystem {
private:
	Talon* collectorTalon;
public:
	Collector();
	void InitDefaultCommand();

	void SetCollectorSpeed(float speed);
};

#endif  // Collector_H
