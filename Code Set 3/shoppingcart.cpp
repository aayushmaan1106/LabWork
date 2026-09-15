#include <iostream>
#include <string>
using namespace std;

class Product {
private:
    string productName;
    double price;
    int quantity;

public:
    Product(string name = "", double p = 0, int q = 0) {
        productName = name;
        price = p;
        quantity = q;
    }

    double totalValue() const {
        return price * quantity;
    }

    friend Product higherValueProduct(const Product& p1, const Product& p2);

    Product combineInventory(const Product& other) const {
        return Product(productName, price, quantity + other.quantity);
    }

    void display() const {
        cout << "Product Name: " << productName << endl;
        cout << "Price: " << price << endl;
        cout << "Quantity: " << quantity << endl;
        cout << "Total Value: " << totalValue() << endl;
    }
};

Product higherValueProduct(const Product& p1, const Product& p2) {
    if (p1.totalValue() > p2.totalValue())
        return p1;
    return p2;
}

int main() {
    Product p1("Laptop", 50000, 2);
    Product p2("Mobile", 30000, 4);

    cout << "Product 1:\n";
    p1.display();

    cout << "\nProduct 2:\n";
    p2.display();

    Product higher = higherValueProduct(p1, p2);

    cout << "\nProduct with Higher Total Value:\n";
    higher.display();

    Product p3("Laptop", 50000, 3);
    Product combined = p1.combineInventory(p3);

    cout << "\nCombined Inventory:\n";
    combined.display();

    return 0;
}
