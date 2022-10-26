#include "person.h"
#include <iostream>

using namespace std;

class Mechanic :public Person
{
	int counter = 0;
	appointment appArr[24];
public:
	Mechanic() :Person() {}

	Mechanic(int id, string n, int a) :Person(id, n, a) {}

	bool isAvailable(appointment available);

	void setAppointment(appointment);
	appointment getAppointment();

	int getCounter();
	

};