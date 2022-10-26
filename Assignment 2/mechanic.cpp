#include "mechanic.h"
#include <iostream>
#include <fstream>
using namespace std;


bool Mechanic::isAvailable(appointment available)
{
	for (int i = 0; i > 24; i++)
	{
		if (available.hour == this->appArr[24].hour && available.min == this->appArr[24].min)
			return false;
	}
}

void Mechanic::setAppointment(appointment a1) {
	appArr[++counter].hour = a1.hour;
	appArr[counter].min = a1.min;
}

int Mechanic::getCounter() {
	return counter;
}

appointment Mechanic::getAppointment()
{
	return appArr[counter];
}
