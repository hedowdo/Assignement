#include "person.h"
#include <iostream>
using namespace std;

Person::Person()
{
    Name = " ";
    ID = 0;
    age = 0;
}

Person::Person(int id, string n, int a)
{
    Name = n;
    age = a;
    ID = id;
}

void Person::setName(string n)
{
    Name = n;
}
void Person::setId(int i)
{
    ID = i;
}
void Person::setAge(int a)
{
    age = a;
}
string Person::getName()
{
    return Name;
}
int Person::getId()
{
    return ID;
}
int Person::getAge()
{
    return age;
}
void Person::print()
{
    cout << "Name: " << Name << endl;
    cout << "ID: " << ID << endl;
    cout << "Age: " << age << endl;
}