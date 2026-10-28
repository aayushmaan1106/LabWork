// Set 2 - Problem 4: Library Book Inventory Using ArrayList
import java.util.ArrayList;

public class c4 {
    public static void main(String[] args) {
        Library library = new Library();

        library.addBook(new Book("B101", "Java Basics", "James Gosling", 450.0));
        library.addBook(new Book("B102", "Data Structures", "Mark Weiss", 620.5));
        library.addBook(new Book("B103", "Clean Code", "Robert Martin", 800.0));
        library.addBook(new Book("B101", "Duplicate Book", "Someone", 100.0)); // rejected

        System.out.println("\nAll books:");
        library.displayAll();

        System.out.println("\nSearch ISBN B102:");
        Book found = library.searchByIsbn("B102");
        System.out.println(found != null ? found : "Book not found");

        System.out.println("\nRemove ISBN B101:");
        library.removeByIsbn("B101");
        library.removeByIsbn("B999"); // not present

        System.out.println("\nRemaining books:");
        library.displayAll();
    }
}

class Book {
    private final String isbn;
    private final String title;
    private final String author;
    private final double price;

    public Book(String isbn, String title, String author, double price) {
        this.isbn = isbn;
        this.title = title;
        this.author = author;
        this.price = price;
    }

    public String getIsbn() { return isbn; }

    // Two books are the same if they share an ISBN
    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Book other)) return false;
        return isbn.equals(other.isbn);
    }

    @Override
    public int hashCode() { return isbn.hashCode(); }

    @Override
    public String toString() {
        return "ISBN: " + isbn + " | " + title + " | " + author + " | Rs." + price;
    }
}

class Library {
    private final ArrayList<Book> books = new ArrayList<>();

    public boolean addBook(Book book) {
        if (books.contains(book)) {                 // uses equals() -> same ISBN
            System.out.println("Cannot add: ISBN " + book.getIsbn() + " already exists.");
            return false;
        }
        books.add(book);
        System.out.println("Added: " + book);
        return true;
    }

    public Book searchByIsbn(String isbn) {
        for (Book b : books) {
            if (b.getIsbn().equals(isbn)) return b;
        }
        return null;
    }

    public boolean removeByIsbn(String isbn) {
        Book b = searchByIsbn(isbn);
        if (b == null) {
            System.out.println("Cannot remove: ISBN " + isbn + " not found.");
            return false;
        }
        books.remove(b);
        System.out.println("Removed: " + b);
        return true;
    }

    public void displayAll() {
        if (books.isEmpty()) {
            System.out.println("No books in the library.");
            return;
        }
        for (Book b : books) System.out.println(b);
    }
}
