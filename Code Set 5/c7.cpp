#include <iostream>
using namespace std;

template <class T>
class Pair
{
private:
    T first;
    T second;

public:
    Pair(T a, T b)
    {
        first = a;
        second = b;
    }

    T maximum()
    {
        if(first > second)
            return first;
        else
            return second;
    }

    T minimum()
    {
        if(first < second)
            return first;
        else
            return second;
    }

    void display()
    {
        cout << "First value: " << first << endl;
        cout << "Second value: " << second << endl;
        cout << "Maximum: " << maximum() << endl;
        cout << "Minimum: " << minimum() << endl;
        cout << endl;
    }
};

int main()
{
    Pair<int> p1(10, 25);
    p1.display();

    Pair<float> p2(12.5, 8.7);
    p2.display();

    return 0;
}