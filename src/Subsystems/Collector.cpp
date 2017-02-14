#include "Collector.h"
#include "../RobotMap.h"

Collector::Collector() : Subsystem("ExampleSubsystem")
{
	collectorTalon = new Talon(RobotMap::COLLECTOR_TALON);

}

void Collector::InitDefaultCommand()
{
	SetDefaultCommand(new ControlCollector());
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

void Collector::SetCollectorSpeed(float speed)
{
	collectorTalon->Set(speed);
}

