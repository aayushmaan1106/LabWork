#include <iostream>
using namespace std;

template <class T>
class Array
{
private:
    T arr[5];

public:
    void input()
    {
        cout << "Enter 5 elements: ";

        for(int i = 0; i < 5; i++)
        {
            cin >> arr[i];
        }
    }

    void display()
    {
        cout << "Elements: ";

        for(int i = 0; i < 5; i++)
        {
            cout << arr[i] << " ";
        }

        cout << endl;
    }

    T largest()
    {
        T large = arr[0];

        for(int i = 1; i < 5; i++)
        {
            if(arr[i] > large)
            {
                large = arr[i];
            }
        }

        return large;
    }

    T smallest()
    {
        T small = arr[0];

        for(int i = 1; i < 5; i++)
        {
            if(arr[i] < small)
            {
                small = arr[i];
            }
        }

        return small;
    }
};

int main()
{
    Array<int> a1;

    cout << "Integer Array" << endl;
    a1.input();
    a1.display();

    cout << "Largest: " << a1.largest() << endl;
    cout << "Smallest: " << a1.smallest() << endl;

    cout << endl;

    Array<float> a2;

    cout << "Float Array" << endl;
    a2.input();
    a2.display();

    cout << "Largest: " << a2.largest() << endl;
    cout << "Smallest: " << a2.smallest() << endl;

    return 0;
}