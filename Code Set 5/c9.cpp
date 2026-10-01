#include <iostream>
using namespace std;

template <class T>
class Result
{
private:
    T marks[5];

public:
    void input()
    {
        cout << "Enter marks of 5 subjects: ";

        for(int i = 0; i < 5; i++)
        {
            cin >> marks[i];
        }
    }

    T total()
    {
        T sum = 0;

        for(int i = 0; i < 5; i++)
        {
            sum = sum + marks[i];
        }

        return sum;
    }

    double average()
    {
        return (double)total() / 5;
    }

    T highest()
    {
        T high = marks[0];

        for(int i = 1; i < 5; i++)
        {
            if(marks[i] > high)
            {
                high = marks[i];
            }
        }

        return high;
    }

    T lowest()
    {
        T low = marks[0];

        for(int i = 1; i < 5; i++)
        {
            if(marks[i] < low)
            {
                low = marks[i];
            }
        }

        return low;
    }

    void display()
    {
        cout << "Total Marks: " << total() << endl;
        cout << "Average Marks: " << average() << endl;
        cout << "Highest Marks: " << highest() << endl;
        cout << "Lowest Marks: " << lowest() << endl;
    }
};

int main()
{
    Result<int> r1;

    cout << "Integer Marks" << endl;
    r1.input();
    r1.display();

    cout << endl;

    Result<float> r2;

    cout << "Floating Point Marks" << endl;
    r2.input();
    r2.display();

    return 0;
}