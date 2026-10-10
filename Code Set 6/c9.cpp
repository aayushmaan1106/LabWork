#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream file("article.txt");
    int chars = 0, words = 0, lines = 0;
    string line;
    while (getline(file, line)) {
        lines++;
        chars += line.length();
        bool inWord = false;
        for (char c : line) {
            if (isspace(c)) {
                inWord = false;
            } else if (!inWord) {
                inWord = true;
                words++;
            }
        }
    }
    file.close();
    cout << "Characters: " << chars << endl;
    cout << "Words: " << words << endl;
    cout << "Lines: " << lines << endl;
    return 0;
}