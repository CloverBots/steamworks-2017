#include "OI.h"
#include "Commands/AlignWithTape.h"
#include "Commands/ShootSequence.h"
#include "Commands/StopShooting.h"
#include "Commands/ToggleDoor.h"
#include "Commands/LiftOn.h"
#include "Commands/LiftOff.h"
#include "Commands/Rotate.h"

OI::OI()
{
	m_pDriveStick = new Joystick(0);
	m_pOperatorStick = new Joystick(1);

	m_pXButton = new JoystickButton(m_pDriveStick, 3);
	m_pXButton->WhenPressed(new AlignWithTape());

	m_pAButton = new JoystickButton(m_pOperatorStick, 1);
//	m_pAButton->WhenPressed(new ShootSequence());
//	m_pAButton->WhenReleased(new StopShooting());

	m_pYButton = new JoystickButton(m_pOperatorStick, 4);
	m_pYButton->WhenPressed(new ToggleDoor());

	m_pRightBumper = new JoystickButton(m_pOperatorStick, 6);
	m_pRightBumper->WhenPressed(new LiftOn());
	m_pRightBumper->WhenReleased(new LiftOff());

	m_pDriveAButton = new JoystickButton(m_pDriveStick, 1);
	m_pDriveAButton->WhenPressed(new Rotate(-90));

	m_pNetworkTable = NetworkTable::GetTable("GRIP/tape");

	m_contours = std::vector<Contour>();

	m_pGearAlignment = new grip::GearAlignment();

	m_usbCamera = CameraServer::GetInstance()->StartAutomaticCapture(0);
	m_usbCamera.SetResolution(CAMERA_X_RES, CAMERA_Y_RES);
	m_usbCamera.SetExposureManual(16);
	m_usbCamera.SetExposureHoldCurrent();
	m_usbCamera.SetFPS(30);

	m_pVisionRunner = new VisionRunner<grip::GearAlignment>(m_usbCamera, m_pGearAlignment,
			std::bind(&OI::ProcessGearAlignment, this));

	std::thread t(std::bind(&OI::GearAlignmentThread, this));
	t.detach();
}

void OI::ProcessGearAlignment()
{
	std::vector<std::vector<cv::Point>>* output = m_pGearAlignment->getfilterContoursOutput();

	m_contours.clear();

	for (unsigned int i = 0; i < output->size(); i++)
	{
		Contour c;

		for (unsigned int j = 0; j < output->at(i).size(); j++)
		{
			cv::Point p = (cv::Point)output->at(i).at(j);

			c.left = std::min(c.left, p.x);
			c.right = std::max(c.right, p.x);
			c.top = std::min(c.top, p.y);
			c.bottom = std::max(c.bottom, p.y);
		}

		c.centerX = (c.left + c.right) / 2;
		c.centerY = (c.top + c.bottom / 2);

		m_contours.push_back(c);
	}
}

cv::Point OI::GetGearCenter()
{
	cv::Point avg;
	int numPoints = m_contours.size();

	if (numPoints == 0)
		return avg;

	for (int i = 0; i < numPoints; i++)
	{
		avg.x += m_contours[i].centerX;
		avg.y += m_contours[i].centerY;
	}

	avg.x /= numPoints;
	avg.y /= numPoints;
	avg.x -= CAMERA_X_RES / 2;
	avg.y -= CAMERA_Y_RES / 2;

	return avg;
}

std::vector<OI::Contour> OI::GetGearContours()
{
	return m_contours;
}

void OI::GearAlignmentThread()
{
	m_pVisionRunner->RunForever();
}

Joystick* OI::GetDriveStick()
{
	return m_pDriveStick;
}

Joystick* OI::GetOperatorStick()
{
	return m_pOperatorStick;
}

grip::GearAlignment* OI::GetGearAlignment()
{
	return m_pGearAlignment;
}

std::vector<double> OI::GetContourValues(std::string value)
{
	return m_pNetworkTable->GetNumberArray(value, llvm::ArrayRef<double>());
}
