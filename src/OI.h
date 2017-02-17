#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
private:

	Joystick* m_pDriveStick;
	Joystick* m_pOperatorStick;
	JoystickButton* m_pXButton;

	std::shared_ptr<NetworkTable> m_pNetworkTable;

public:
	OI();

	const int CAMERA_X_RES = 320;
	const int CAMERA_Y_RES = 240;

	Joystick* GetDriveStick();
	Joystick* GetOperatorStick();

	std::vector<double> GetContourValues(std::string value);
};

#endif
