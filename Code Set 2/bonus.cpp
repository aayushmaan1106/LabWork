#include <iostream>
#include <string>

class Book {
private:
    std::string title;
    std::string author;
    int year;

public:
    Book() {
        title = "";
        author = "";
        year = 0;
    }

    Book(std::string t, std::string a, int y) {
        title = t;
        author = a;
        year = y;
    }

    std::string getTitle() const {
        return title;
    }

    void display() const {
        std::cout << "Title: " << title << "\n";
        std::cout << "Author: " << author << "\n";
        std::cout << "Year: " << year << "\n\n";
    }
};

class Library {
private:
    Book books[10];
    int count;

public:
    Library() {
        count = 0;
    }

    void addBook(const Book& b) {
        if (count < 10) {
            books[count] = b;
            count++;
        }
    }

    void searchByTitle(const std::string& searchTitle) const {
        bool found = false;
        for (int i = 0; i < count; ++i) {
            if (books[i].getTitle() == searchTitle) {
                books[i].display();
                found = true;
            }
        }
        if (!found) {
            std::cout << "No matching books found for: " << searchTitle << "\n";
        }
    }
};

int main() {
    Library myLibrary;

    myLibrary.addBook(Book("The Hobbit", "J.R.R. Tolkien", 1937));
    myLibrary.addBook(Book("1984", "George Orwell", 1949));
    myLibrary.addBook(Book("To Kill a Mockingbird", "Harper Lee", 1960));
    myLibrary.addBook(Book("The Great Gatsby", "F. Scott Fitzgerald", 1925));
    myLibrary.addBook(Book("Moby Dick", "Herman Melville", 151));
    myLibrary.addBook(Book("Hamlet", "William Shakespeare", 1603));
    myLibrary.addBook(Book("The Odyssey", "Homer", -700));
    myLibrary.addBook(Book("1984", "George Orwell (Alternate)", 1950));
    myLibrary.addBook(Book("War and Peace", "Leo Tolstoy", 1869));
    myLibrary.addBook(Book("The Catcher in the Rye", "J.D. Salinger", 1951));

    std::string searchQuery = "1984";
    std::cout << "Searching for '" << searchQuery << "':\n\n";
    myLibrary.searchByTitle(searchQuery);

    return 0;
}
