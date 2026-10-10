#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream src("source.txt");
    ofstream dest("destination.txt");
    dest << src.rdbuf();
    src.close();
    dest.close();
    cout << "File copied successfully." << endl;
    return 0;
}