#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ofstream outfile("students.txt");
    outfile << "101 Ali 87\n";
    outfile << "102 Sara 92\n";
    outfile.close();
    cout << "Success message: Records written to students.txt successfully." << endl;
    return 0;
}