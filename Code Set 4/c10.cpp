#include <iostream>
#include <string>
using namespace std;

class Book {
    int bookID;
    string bookName;
    double price;

public:
    static int totalBooks;

    Book(int id, string name, double p) {
        bookID = id;
        bookName = name;
        price = p;
        totalBooks++;
    }

    inline double getDiscountedPrice() {
        return price * 0.90;
    }

    bool operator>(Book const &b) {
        return price > b.price;
    }

    friend void displayCostlier(Book b1, Book b2);
};

int Book::totalBooks = 0;

void displayCostlier(Book b1, Book b2) {
    if (b1 > b2) {
        cout << "Costlier Book:" << endl;
        cout << "ID: " << b1.bookID << endl;
        cout << "Name: " << b1.bookName << endl;
        cout << "Price: " << b1.price << endl;
        cout << "Discounted Price = " << b1.getDiscountedPrice() << endl;
    } else {
        cout << "Costlier Book:" << endl;
        cout << "ID: " << b2.bookID << endl;
        cout << "Name: " << b2.bookName << endl;
        cout << "Price: " << b2.price << endl;
        cout << "Discounted Price = " << b2.getDiscountedPrice() << endl;
    }
}

int main() {
    Book b1(101, "Java Programming", 500);
    Book b2(102, "C++ Programming", 700);

    displayCostlier(b1, b2);
    cout << "Total Books = " << Book::totalBooks << endl;

    return 0;
}