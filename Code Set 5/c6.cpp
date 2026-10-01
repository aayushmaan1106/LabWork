#include <iostream>
using namespace std;

template <class T>
T larger(T a, T b)
{
    if(a > b)
        return a;
    else
        return b;
}

template <class T>
void swapValues(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

int main()
{
    int a = 10, b = 20;
    cout << "Larger integer: " << larger(a, b) << endl;
    swapValues(a, b);
    cout << "After swap: " << a << " " << b << endl;

    float c = 5.5, d = 3.2;
    cout << "Larger float: " << larger(c, d) << endl;
    swapValues(c, d);
    cout << "After swap: " << c << " " << d << endl;

    double e = 15.7, f = 25.4;
    cout << "Larger double: " << larger(e, f) << endl;
    swapValues(e, f);
    cout << "After swap: " << e << " " << f << endl;

    char x = 'A', y = 'Z';
    cout << "Larger character: " << larger(x, y) << endl;
    swapValues(x, y);
    cout << "After swap: " << x << " " << y << endl;

    return 0;
}