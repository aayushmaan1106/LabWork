#include <iostream>
#include <string>
using namespace std;

class Book
{
protected:
    string title;
    string author;

public:
    Book(string t, string a)
    {
        title = t;
        author = a;
    }
};

class EBook : public Book
{
private:
    float fileSize;
    string fileFormat;

public:
    EBook(string t, string a, float fs, string ff)
        : Book(t, a)
    {
        fileSize = fs;
        fileFormat = ff;
    }

    void display()
    {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "File Size: " << fileSize << " MB" << endl;
        cout << "File Format: " << fileFormat << endl;
        cout << endl;
    }
};

int main()
{
    EBook books[3] =
    {
        EBook("C++ Programming", "Bjarne Stroustrup", 10.5, "PDF"),
        EBook("Data Structures", "Mark Allen", 8.2, "EPUB"),
        EBook("OOP Concepts", "Robert Lafore", 12.4, "PDF")
    };

    for(int i = 0; i < 3; i++)
    {
        books[i].display();
    }

    return 0;
}