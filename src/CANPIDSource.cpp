/*
 * CANPIDSource.cpp
 *
 *  Created on: Dec 19, 2016
 *      Author: Mackinnon Buck
 */

#include <CANPIDSource.h>

CANPIDSource::CANPIDSource(CANTalon* pTalon, double range) : m_pTalon(pTalon), m_range(range)
{

}

CANPIDSource::~CANPIDSource()
{
	// TODO Auto-generated destructor stub
}

double CANPIDSource::PIDGet()
{
	//std::cout << (double)-m_pTalon->GetEncVel() / m_range << std::endl;
	return (double)-m_pTalon->GetEncVel() / m_range;
}
