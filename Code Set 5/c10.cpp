#include <iostream>
#include <string>
using namespace std;

class Person
{
protected:
    string name;
    int age;

public:
    Person(string n, int a)
    {
        name = n;
        age = a;
    }
};

class Teacher : public Person
{
private:
    string subject;

public:
    Teacher(string n, int a, string s)
        : Person(n, a)
    {
        subject = s;
    }

    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Subject: " << subject << endl;
    }
};

class ResearchScholar : public Person
{
private:
    string researchArea;

public:
    ResearchScholar(string n, int a, string r)
        : Person(n, a)
    {
        researchArea = r;
    }

    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Research Area: " << researchArea << endl;
    }
};

template <class T>
class RecordManager
{
private:
    T records[5];
    int count;

public:
    RecordManager()
    {
        count = 0;
    }

    void addRecord(T record)
    {
        records[count] = record;
        count++;
    }

    void displayRecords()
    {
        for(int i = 0; i < count; i++)
        {
            records[i].display();
            cout << endl;
        }
    }
};

int main()
{
    Teacher t1("Rahul", 40, "C++");
    Teacher t2("Aman", 45, "Data Structures");

    RecordManager<Teacher> teacherRecords;

    teacherRecords.addRecord(t1);
    teacherRecords.addRecord(t2);

    cout << "Teacher Records" << endl;
    teacherRecords.displayRecords();

    ResearchScholar r1("Rohit", 25, "Artificial Intelligence");
    ResearchScholar r2("Karan", 27, "Machine Learning");

    RecordManager<ResearchScholar> scholarRecords;

    scholarRecords.addRecord(r1);
    scholarRecords.addRecord(r2);

    cout << "Research Scholar Records" << endl;
    scholarRecords.displayRecords();

    return 0;
}