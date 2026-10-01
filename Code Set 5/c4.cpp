#include <iostream>
#include <string>
using namespace std;

class Vehicle
{
protected:
    string registrationNumber;
    string companyName;

public:
    Vehicle(string r, string c)
    {
        registrationNumber = r;
        companyName = c;
    }
};

class Car : public Vehicle
{
private:
    string fuelType;
    int engineCapacity;

public:
    Car(string r, string c, string f, int e)
        : Vehicle(r, c)
    {
        fuelType = f;
        engineCapacity = e;
    }

    void display()
    {
        cout << "Car Details" << endl;
        cout << "Registration Number: " << registrationNumber << endl;
        cout << "Company: " << companyName << endl;
        cout << "Fuel Type: " << fuelType << endl;
        cout << "Engine Capacity: " << engineCapacity << " cc" << endl;
        cout << endl;
    }
};

class Bike : public Vehicle
{
private:
    string fuelType;
    int engineCapacity;

public:
    Bike(string r, string c, string f, int e)
        : Vehicle(r, c)
    {
        fuelType = f;
        engineCapacity = e;
    }

    void display()
    {
        cout << "Bike Details" << endl;
        cout << "Registration Number: " << registrationNumber << endl;
        cout << "Company: " << companyName << endl;
        cout << "Fuel Type: " << fuelType << endl;
        cout << "Engine Capacity: " << engineCapacity << " cc" << endl;
        cout << endl;
    }
};

int main()
{
    Car car1("JK01AB1234", "Toyota", "Petrol", 1500);
    Car car2("JK01CD5678", "Honda", "Petrol", 1200);

    Bike bike1("JK02EF1111", "Yamaha", "Petrol", 150);
    Bike bike2("JK02GH2222", "Honda", "Petrol", 125);

    car1.display();
    car2.display();
    bike1.display();
    bike2.display();

    return 0;
}