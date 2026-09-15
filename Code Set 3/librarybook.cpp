#include <iostream>
#include <string>

class Book {
public:
    int bookID;
    std::string title;
    int copies;

    Book(int id, std::string t, int c) : bookID(id), title(t), copies(c) {}

    void exchange(Book &other) {
        int tempID = this->bookID;
        this->bookID = other.bookID;
        other.bookID = tempID;

        std::string tempTitle = this->title;
        this->title = other.title;
        other.title = tempTitle;

        int tempCopies = this->copies;
        this->copies = other.copies;
        other.copies = tempCopies;
    }
};

Book getMoreCopies(Book b1, Book b2) {
    if (b1.copies > b2.copies) {
        return b1;
    }
    return b2;
}

int main() {
    Book book1(101, "The C++ Programming Language", 5);
    Book book2(202, "Introduction to Algorithms", 12);

    Book popular = getMoreCopies(book1, book2);
    std::cout << "Book with more copies: " << popular.title << " (" << popular.copies << " copies)" << std::endl;

    std::cout << "\n--- Exchanging Book Data ---" << std::endl;
    book1.exchange(book2);

    std::cout << "Book 1 Title: " << book1.title << ", Copies: " << book1.copies << std::endl;
    std::cout << "Book 2 Title: " << book2.title << ", Copies: " << book2.copies << std::endl;

    return 0;
}
