#include "person.h"
#include <iostream>
#include <string>
using namespace std;
class Customer :public Person
{
	appointment app; 
	int mechanicID; 
public:
	Customer() :Person() {}
	Customer(int id, string Name, int Age) :Person(id, Name, Age) {} 


	void setMechanicID(int);
	int getMechanicId();

	void setAppointment(appointment);
	


	bool operator >(const appointment& checkbigger);
	bool operator <(const appointment& checksmaller);
	bool operator ==(const appointment& checkequal);

};
