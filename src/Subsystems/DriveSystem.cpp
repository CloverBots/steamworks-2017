#include "DriveSystem.h"
#include "../RobotMap.h"

#include "../Commands/DriveFromInput.h"

DriveSystem::DriveSystem() :
		Subsystem("DriveSystem")
{
	m_pRobotDrive = new RobotDrive(
			RobotMap::LEFT_FRONT_TALON,
			RobotMap::LEFT_REAR_TALON,
			RobotMap::RIGHT_FRONT_TALON,
			RobotMap::RIGHT_REAR_TALON);
	m_pRobotDrive->SetInvertedMotor(RobotDrive::MotorType::kFrontLeftMotor, true);
	m_pRobotDrive->SetInvertedMotor(RobotDrive::MotorType::kRearLeftMotor, true);
	m_pRobotDrive->SetSafetyEnabled(false);

	m_gyro = new AnalogGyro(0);
}

void DriveSystem::InitDefaultCommand()
{
	SetDefaultCommand(new DriveFromInput());
}

void DriveSystem::Drive(float speed, float strafe, float rotation)
{
	m_pRobotDrive->MecanumDrive_Cartesian(strafe, speed, rotation);
}

void DriveSystem::ResetGyro()
{
	m_gyro->Reset();
}

double DriveSystem::GetGyroAngle()
{
	return m_gyro->GetAngle();
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
