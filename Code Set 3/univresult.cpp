#include <iostream>
using namespace std;

class Result {
private:
    int rollNumber;
    int marks[5];

public:
    Result(int roll, int m1, int m2, int m3, int m4, int m5) {
        rollNumber = roll;
        marks[0] = m1;
        marks[1] = m2;
        marks[2] = m3;
        marks[3] = m4;
        marks[4] = m5;
    }

    int total() const {
        int sum = 0;
        for (int i = 0; i < 5; i++)
            sum += marks[i];
        return sum;
    }

    void compare(Result other) {
        if (total() > other.total())
            cout << "Roll " << rollNumber << " has higher marks." << endl;
        else if (total() < other.total())
            cout << "Roll " << other.rollNumber << " has higher marks." << endl;
        else
            cout << "Both students have equal marks." << endl;
    }

    friend Result topper(Result r1, Result r2, Result r3);
    friend Result applyGrace(Result r);
    
    void display() const {
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Marks: ";
        for (int i = 0; i < 5; i++)
            cout << marks[i] << " ";
        cout << endl;
        cout << "Total: " << total() << endl;
    }
};

Result topper(Result r1, Result r2, Result r3) {
    Result top = r1;

    if (r2.total() > top.total())
        top = r2;

    if (r3.total() > top.total())
        top = r3;

    return top;
}

Result applyGrace(Result r) {
    int grace = 0;
    
    for (int i = 0; i < 5; i++) {
        if (r.marks[i] < 40) {
            int needed = 40 - r.marks[i];
            int add = (needed <= 5) ? needed : 5;

            if (grace + add <= 20) {
                r.marks[i] += add;
                grace += add;
            }
        }
    }

    return r;
}

int main() {
    Result r1(101, 35, 67, 78, 82, 70);
    Result r2(102, 88, 75, 69, 91, 84);
    Result r3(103, 45, 79, 81, 73, 76);

    cout << "Comparison:" << endl;
    r1.compare(r2);

    cout << "\nTopper:" << endl;
    Result top = topper(r1, r2, r3);
    top.display();

    cout << "\nAfter Grace Marks:" << endl;
    Result graceResult = applyGrace(r1);
    graceResult.display();

    return 0;
}
