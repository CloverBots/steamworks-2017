#include "OI.h"
#include "Commands/AlignWithTape.h"

OI::OI()
{
	m_pDriveStick = new Joystick(0);

	m_pXButton = new JoystickButton(m_pDriveStick, 3);
	m_pXButton->WhileHeld(new AlignWithTape());

	m_pNetworkTable = NetworkTable::GetTable("GRIP/tape");
}

Joystick* OI::GetDriveStick()
{
	return m_pDriveStick;
}

std::vector<double> OI::GetContourValues(std::string value)
{
	return m_pNetworkTable->GetNumberArray(value, llvm::ArrayRef<double>());
}
