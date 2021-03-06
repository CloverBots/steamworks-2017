#include <memory>

#include <Commands/Command.h>
#include <Commands/PlaceGearCenter.h>
#include <Commands/PlaceGearLeft.h>
#include <Commands/PlaceGearRight.h>
#include <Commands/ShootSequence.h>
#include <Commands/Scheduler.h>
#include <IterativeRobot.h>
#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>

#include "CommandBase.h"
#include "Commands/DriveForward.h"

class Robot : public frc::IterativeRobot {
public:
	void RobotInit() override {
		CommandBase::Init();
		chooser.AddDefault("Do Nothing", 0);
		chooser.AddObject("Shoot Immediately", new ShootSequence());
		chooser.AddObject("Drive Forward", new DriveForward());
		chooser.AddObject("Place Gear (Center)", new PlaceGearCenter());
		chooser.AddObject("Place Gear (Left)", new PlaceGearLeft(false));
		chooser.AddObject("Place Gear (Left, Boiler)", new PlaceGearLeft(true));
		chooser.AddObject("Place Gear (Right)", new PlaceGearRight(false));
		chooser.AddObject("Place Gear (Right, Boiler)", new PlaceGearRight(true));

		frc::SmartDashboard::PutData("Auto Modes", &chooser);
//		frc::SmartDashboard::PutNumber("Shooter Speed", 0.0);
//		frc::SmartDashboard::PutNumber("Shooter P", 0.0);
//		frc::SmartDashboard::PutNumber("Shooter I", 0.0);
//		frc::SmartDashboard::PutNumber("Shooter D", 0.0);
	}

	/**
	 * This function is called once each time the robot enters Disabled mode.
	 * You can use it to reset any subsystem information you want to clear when
	 * the robot is disabled.
	 */
	void DisabledInit() override {
		CommandBase::shooterSubsystem->SetPIDEnabled(false);

		//SmartDashboard::PutString("Enabled:", "False");
	}

	void DisabledPeriodic() override {
		frc::Scheduler::GetInstance()->Run();
	}

	/**
	 * This autonomous (along with the chooser code above) shows how to select
	 * between different autonomous modes using the dashboard. The sendable
	 * chooser code works with the Java SmartDashboard. If you prefer the
	 * LabVIEW Dashboard, remove all of the chooser code and uncomment the
	 * GetString code to get the auto name from the text box below the Gyro.
	 *
	 * You can add additional auto modes by adding additional commands to the
	 * chooser code above (like the commented example) or additional comparisons
	 * to the if-else structure below with additional strings & commands.
	 */
	void AutonomousInit() override {
		//CommandBase::shooterSubsystem->SetPIDEnabled(true);
		CommandBase::pDriveSystem->ResetGyro();
		/* std::string autoSelected = frc::SmartDashboard::GetString("Auto Selector", "Default");
		if (autoSelected == "My Auto") {
			autonomousCommand.reset(new MyAutoCommand());
		}
		else {
			autonomousCommand.reset(new ExampleCommand());
		} */

		autonomousCommand.reset(chooser.GetSelected());

		if (autonomousCommand.get() != nullptr) {
			autonomousCommand->Start();
		}
	}

	void AutonomousPeriodic() override {
		frc::Scheduler::GetInstance()->Run();
	}

	void TeleopInit() override {
		CommandBase::shooterSubsystem->SetPIDEnabled(false);
		CommandBase::pDriveSystem->ResetGyro();

		//SmartDashboard::PutString("Enabled:", "True");

		// This makes sure that the autonomous stops running when
		// teleop starts running. If you want the autonomous to
		// continue until interrupted by another command, remove
		// this line or comment it out.
		if (autonomousCommand != nullptr) {
			autonomousCommand->Cancel();
		}
	}

	void TeleopPeriodic() override {
//		if (CommandBase::oi->GetOperatorStick()->GetRawButton(7) || CommandBase::oi->GetDriveStick()->GetRawButton(7))
//		{
//			frc::Scheduler::GetInstance()->SetEnabled(false);
//			frc::Scheduler::GetInstance()->
//			SmartDashboard::PutString("Enabled:", "False");
//		}
//		else if (CommandBase::oi->GetOperatorStick()->GetRawButton(8) || CommandBase::oi->GetDriveStick()->GetRawButton(8))
//		{
//			frc::Scheduler::GetInstance()->SetEnabled(true);
//			SmartDashboard::PutString("Enabled:", "True");
//		}

		frc::Scheduler::GetInstance()->Run();
	}

	void TestPeriodic() override {
		frc::LiveWindow::GetInstance()->Run();
	}

private:
	std::unique_ptr<frc::Command> autonomousCommand;
	frc::SendableChooser<frc::Command*> chooser;
};

START_ROBOT_CLASS(Robot)
