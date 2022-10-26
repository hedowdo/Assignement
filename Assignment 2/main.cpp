#include "person.h"
#include "customer.h"
#include "mechanic.h"
#include <iostream>
#include <fstream>
#include "queue.h"
using namespace std;

Queue <Customer> cqueue;

int main()
{
	int const n = 100;
	string mName[n];
	int mID[n];
	int mAge[n];

	string cName[n];
	int cID[n];
	int cAge[n];

	int nomech;
	int nocust;

	cout << "indicate number of mechanics" << endl;
	cin >> nomech;
	cout << "indicate number of customers" << endl;
	cin >> nocust;

	ifstream in;
	in.open("Mechaniclist.txt");

	for (int i = 0; i < nomech; i++)
	{
		cout << "Input NAME of Mechanic number " << i;
		in >> mName[i];
		cout << "Input ID of Mechanic number " << i;
		in >> mID[i];
		cout << "Input AGE of Mechanic number " << i;
		in >> mAge[i];

		nomech++;
	}
	in.close();


	Mechanic* mechanics = new Mechanic[nomech];
	for (int i = 0; i < nomech; i++)
	{
		mechanics[i] = { Mechanic(mID[i],mName[i],mAge[i]) };
	}

	ifstream in;
	in.open("CustomerList");

	for (int i = 0; i < nocust; i++)
	{
		cout << "Input NAME of Customer number " << i;
		in >> cName[i];
		cout << "Input ID of Customer number " << i;
		in >> cID[i];
		cout << "Input AGE of Customer number " << i;
		in >> cAge[i];

		nocust++;
	}
	in.close();


	Customer* customers = new Customer[nocust];
	for (int i = 0; i < nocust; i++)
	{
		customers[i] = { Customer(cID[i],cName[i],cAge[i]) };
	}


	for (int i = 0; i < nocust; i++)
	{
		if (mechanics[i].isAvailable(mechanics[i].getAppointment()))
		{
			customers[i].setMechanicID(mechanics[i].getId());
			customers[i].setAppointment(mechanics[i].getAppointment());
			mechanics[i].setAppointment(mechanics[i].getAppointment());
			
			cqueue.push(customers[i]);
		}
		else
		{
			customers[i].setMechanicID(mechanics[i + 1].getId());
			customers[i].setAppointment(mechanics[i + 1].getAppointment());
			mechanics[i].setAppointment(mechanics[i].getAppointment());

			cqueue.push(customers[i]);

		}
	}

	while (cqueue.Front().getName() != "");
	{
		Customer temp = cqueue.Front();
		temp.print();
		cout << endl;
		cout << "this customer is with mechanic with ID : ";
		cout << temp.getMechanicId();
		cqueue.pop();
		cout << endl;
	}


	





	return 0;
}