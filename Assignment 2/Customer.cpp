#include "person.h"
#include "customer.h"

void Customer::setMechanicID(int id)
{
	mechanicID = id;
}

void Customer::setAppointment(appointment a)
{
	app.hour = a.hour;
	app.min = a.min;
}

int Customer::getMechanicId()
{
	return mechanicID;
}

bool Customer::operator>(const appointment& checkbigger)
{
	if (this->app.hour > checkbigger.hour)
		return true;
	else if (this->app.hour == checkbigger.hour && this->app.min > checkbigger.min)
		return true;
	return false;
}

bool Customer::operator<(const appointment& checksmaller)
{
	if (this->app.hour < checksmaller.hour)
		return true;
	else if (this->app.hour == checksmaller.hour && this->app.min < checksmaller.min)
		return true;
	return false;
}

bool Customer::operator==(const appointment& checkequal)
{
	if (this->app.hour == checkequal.hour && this->app.min == checkequal.min)
		return true;
	else
	return false;
}