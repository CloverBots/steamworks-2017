#ifndef OI_H
#define OI_H

#include "WPILib.h"
#include "GearAlignment.h"
#include <vector>

class OI
{
public:
	const static int CAMERA_X_RES = 640;
	const static int CAMERA_Y_RES = 480;

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

	grip::GearAlignment* GetGearAlignment();

	void ProcessGearAlignment();
	void GearAlignmentThread();

	std::vector<double> GetContourValues(std::string value);
	std::vector<Contour> GetGearContours();
	cv::Point GetGearCenter();

private:

	Joystick* m_pDriveStick;
	Joystick* m_pOperatorStick;
	JoystickButton* m_pXButton;
	JoystickButton* m_pAButton;
	JoystickButton* m_pYButton;
	JoystickButton* m_pRightBumper;

	JoystickButton* m_pDriveAButton;

	grip::GearAlignment* m_pGearAlignment;
	cs::UsbCamera m_usbCamera;
	VisionRunner<grip::GearAlignment>* m_pVisionRunner;

	std::shared_ptr<NetworkTable> m_pNetworkTable;

	std::vector<Contour> m_contours;
};

#endif
