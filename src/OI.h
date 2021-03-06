#ifndef OI_H
#define OI_H

#include <TapeAlignment.h>
#include "WPILib.h"
#include <vector>

class OI
{
public:
	const static int CAMERA_X_RES = 160;
	const static int CAMERA_Y_RES = 120;

	struct Contour
	{
		int left;
		int right;
		int top;
		int bottom;
		int centerX;
		int centerY;

		Contour()
		{
			left = OI::CAMERA_X_RES;
			right = 0;
			top = OI::CAMERA_Y_RES;
			bottom = 0;
			centerX = top / 2;
			centerY = bottom / 2;
		}
	};

	OI();

	Joystick* GetDriveStick();
	Joystick* GetOperatorStick();

	grip::TapeAlignment* GetGearAlignment();

	std::vector<double> GetContourValues(std::string value);
	std::vector<Contour> GetGearContours();
	cv::Point GetGearCenter();
	cv::Point GetBoilerCenter();

private:

	Joystick* m_pDriveStick;
	Joystick* m_pOperatorStick;

	JoystickButton* m_pXButton;
	JoystickButton* m_pAButton;
	JoystickButton* m_pYButton;
	JoystickButton* m_pRightBumper;
	JoystickButton* m_pLeftBumper;

	JoystickButton* m_pDriveAButton;

	cs::UsbCamera m_gearCamera;
	cs::UsbCamera m_boilerCamera;

	grip::TapeAlignment* m_pGearAlignment;
	grip::TapeAlignment* m_pBoilerAlignment;

	VisionRunner<grip::TapeAlignment>* m_pGearVisionRunner;
	VisionRunner<grip::TapeAlignment>* m_pBoilerVisionRunner;

	std::thread m_gearThread;
	std::thread m_boilerThread;

	std::shared_ptr<NetworkTable> m_pNetworkTable;

	std::vector<Contour> m_gearContours;
	std::vector<Contour> m_boilerContours;

	std::mutex m_gearLock;
	std::mutex m_boilerLock;

	void GearAlignmentThread();
	void BoilerAlignmentThread();

	void ProcessGearAlignment();
	void ProcessBoilerAlignment();

	std::vector<Contour> GenerateContours(std::vector<std::vector<cv::Point>>* points);
	cv::Point GetCenterContours(std::vector<Contour> contours);
};

#endif
