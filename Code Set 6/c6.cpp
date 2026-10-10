#include <iostream>

using namespace std;

class VotingException {
public:
    string what() const {
        return "Exception: Not eligible for voting.";
    }
};

int main() {
    int age;
    cin >> age;
    try {
        if (age < 18) {
            throw VotingException();
        }
        cout << "Eligible to vote." << endl;
    } catch (VotingException& e) {
        cout << e.what() << endl;
    }
    return 0;
}