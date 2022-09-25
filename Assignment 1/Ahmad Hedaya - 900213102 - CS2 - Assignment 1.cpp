#include <iostream>
#include <string>
#include <queue>
using namespace std;

class Car
{
private:

	string Car_brand;
	string Car_type;
	string Car_plate;
	int Speed;
	int Year_model;


public:
	Car()
	{
		Car_brand = "";
		Car_type = "";
		Car_plate = "";
		Speed = 0;
		Year_model = 0;
	}

	Car(string brand, int Max_speed, int Year)
	{
		Car_brand = brand;
		Speed = Max_speed;
		Year_model = Year;
	}

	void setCarBrand(string brand)
	{
		Car_brand = brand;
	}

	string getCarBrand()
	{
		return Car_brand;
	}

	void setCarType(string Type)
	{
		Car_type = Type;
	}

	string getCarType()
	{
		return Car_type;
	}

	void setCarPlate(string plate)
	{
		Car_plate = plate;
	}

	string getCarPlate()
	{
		return Car_plate;
	}

	void setSpeed(int speed)
	{
		Speed = speed;
	}

	int getSpeed()
	{
		return Speed;
	}

	void setYearModel(int year)
	{
		Year_model = year;
	}

	int getYearModel()
	{
		return Year_model;
	}

};

class Road
{

private:
	char Road_type;
	int Speed_limit;
	int countA, countB, countC;

public:
	Road()
	{
		Road_type;
		Speed_limit = 0;
		countA = 0;
		countB = 0;
		countC = 0;

	}
	Road(char Road, int speedlimit)
	{
		Road_type = Road;
		Speed_limit = speedlimit;
	}

	void setRoadType(char Road)
	{
		while (Road != 'A' && Road != 'B' && Road != 'C');

		Road_type = Road;
	}

	char getRoadType()
	{
		return Road_type;
	}

	void setSpeedLimit(int speed)
	{
		Speed_limit = speed;
	}

	int getSpeedLimit()
	{
		return Speed_limit;
	}

	void setCountA(int cA)
	{
		countA = cA;
	}

	int getCountA()
	{
		return countA;
	}

	void setCountB(int cB)
	{
		countA = cB;
	}

	int getCountB()
	{
		return countB;
	}

	void setCountC(int cC)
	{
		countC = cC;
	}

	int getCountC()
	{
		return countC;
	}

	bool Radar(int Car_Speed, char Road_type)
	{
		if (Car_Speed > Speed_limit)
		{
			return 1;
		}
		else
		{
			return 0;
		}

	}

	void allow(string Car_type)
	{

		if (Road_type == 'A')
		{
			if (Car_type == "Private" || Car_type == "motorcycle")
			{
				cout << "allowed to pass road A" << endl;

				countA = countA + 1;


			}
			else
			{
				cout << "Not allowed to pass road A" << endl;

			}
		}
		if (Road_type == 'B')
		{
			if (Car_type != "")
			{
				cout << "allowed to pass road B" << endl;
				countB = countB + 1;

			}
			else
			{
				cout << "Not allowed to pass road B" << endl;

			}
		}
		if (Road_type == 'C')
		{
			if (Car_type == "truck")
			{
				cout << "allowed to pass road C" << endl;
				countC = countC + 1;

			}
			else
			{
				cout << "Not allowed to pass road C" << endl;

			}
		}

	}

	int age(int Year_model)
	{
		int age = 2022 - Year_model;
		cout << "The Age of the Vehicle is : " << age << endl;
		return 0;
	}
};




int main()
{
	queue<Car> Queue;

	//car 1
	Queue.push(Car("Hyundai", 100, 2008));
	Queue.back().setCarPlate("HDY139");
	Queue.back().setCarType("Private");

	//car2
	Queue.push(Car("Ford", 60, 2008));
	Queue.back().setCarPlate("YES123");
	Queue.back().setCarType("truck");

	//car3
	Queue.push(Car("Harley-Davidson", 120, 2008));
	Queue.back().setCarPlate("WOO321");
	Queue.back().setCarType("motorcycle");
	
	//car4
	Queue.push(Car("Hunda", 190, 2006));
	Queue.back().setCarPlate("HUD130");
	Queue.back().setCarType("Private");

	//car5
	Queue.push(Car("Mercades", 60, 2003));
	Queue.back().setCarPlate("SKL221");
	Queue.back().setCarType("Bus");

	//push is used to add into the queue, and the back is used to edit the variables of each object


	Road road1('A', 110);
	Road road2('B', 90);
	Road road3('C', 60);



	do
	{
		road1.age(Queue.front().getYearModel());
		cout << endl;

		road1.allow(Queue.front().getCarType());

		if (road1.Radar(Queue.front().getSpeed(), road1.getRoadType()) == 1)
		{

			cout << " On Road A : " << Queue.front().getCarPlate() << " - " << Queue.front().getCarType() << " - " << Queue.front().getYearModel() << " - Speed : " << Queue.front().getSpeed() << endl;
			cout << "This car will be fined!" << endl;
		}
		cout << endl;

		road2.allow(Queue.front().getCarType());

		if (road2.Radar(Queue.front().getSpeed(), road2.getRoadType()) == 1)
		{

			cout << "On Road B : " << Queue.front().getCarPlate() << " - " << Queue.front().getCarType() << " - " << Queue.front().getYearModel() << " - Speed : " << Queue.front().getSpeed() << endl;
			cout << "This car will be fined!" << endl;
		}
		cout << endl;
		road3.allow(Queue.front().getCarType());

		if (road3.Radar(Queue.front().getSpeed(), road3.getRoadType()) == 1)
		{

			cout << "On Road C" << Queue.front().getCarPlate() << " - " << Queue.front().getCarType() << " - " << Queue.front().getYearModel() << " - Speed : " << Queue.front().getSpeed() << endl;
			cout << "This car will be fined!" << endl;
		}

		Queue.pop(); //pop to view next object

		cout << endl << endl;

	} while (Queue.size() != 0);

	cout << endl;

	int largest;

	if (road1.getCountA() >= road2.getCountB() && road1.getCountA() >= road3.getCountC())
	{
		largest = road1.getCountA();
	}
	else
	{
		if (road2.getCountB() >= road1.getCountA() && road2.getCountB() >= road3.getCountC())
		{
			largest = road2.getCountB();
		}
		else
		{
			if (road3.getCountC() >= road1.getCountA() && road3.getCountC() >= road2.getCountB())
			{
				largest = road3.getCountC();
			}
		}
	}

	double efficiencya, efficiencyb, efficiencyc;

	efficiencya = (road1.getCountA() / largest) * 100;
	efficiencyb = (road2.getCountB() / largest) * 100;
	efficiencyc = (road3.getCountC() / largest) * 100;


	cout << " The efficiency of Road A = " << efficiencya << "%" << endl;
	cout << " The efficiency of Road B = " << efficiencyb << "%" << endl;
	cout << " The efficiency of Road C = " << efficiencyc << "%" << endl;
}
