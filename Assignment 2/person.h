#include <iostream>
#include <string>
using namespace std;

struct appointment
{
    int hour;
    int min;
};

class Person
{
   
    string Name;
    int ID;
    int age;
public:
    Person();
    Person(int, string, int);

   
    void setName(string);
    string getName();

    void setId(int);
    int getId();

    void setAge(int);    
    int getAge();

 
    virtual void print() = 0;
};
