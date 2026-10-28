// Set 2 - Problem 5: Product Catalogue Using HashMap
import java.util.HashMap;

public class c5 {
    public static void main(String[] args) {
        HashMap<Integer, Product> catalogue = new HashMap<>();
        Catalogue store = new Catalogue(catalogue);

        store.addProduct(new Product(1, "Keyboard", 800, 10));
        store.addProduct(new Product(2, "Mouse", 700, 25));
        store.addProduct(new Product(3, "Monitor", 9500, 5));
        store.addProduct(new Product(2, "Duplicate Mouse", 1, 1));   // rejected

        System.out.println("\nSearch ID 3: " + store.searchProduct(3));
        System.out.println("Search ID 9: " + store.searchProduct(9));

        System.out.println();
        store.updatePrice(1, 850);
        store.updatePrice(9, 100);   // not found

        System.out.println();
        store.removeProduct(2);
        store.removeProduct(9);      // not found

        System.out.println("\nAll products:");
        store.displayAll();

        System.out.println("""

                Why HashMap instead of ArrayList for search by ID?
                - HashMap finds a key in O(1) average time using its hash code,
                  no matter how many products there are.
                - ArrayList must check elements one by one: O(n) in the worst case.
                - HashMap also rejects duplicate IDs naturally (one key = one product).""");
    }
}

class Product {
    private final int id;
    private final String name;
    private double price;
    private int quantity;

    public Product(int id, String name, double price, int quantity) {
        this.id = id;
        this.name = name;
        this.price = price;
        this.quantity = quantity;
    }

    public int getId() { return id; }
    public void setPrice(double price) { this.price = price; }

    @Override
    public String toString() {
        return "ID: " + id + " | " + name + " | Rs." + price + " | Qty: " + quantity;
    }
}

class Catalogue {
    private final HashMap<Integer, Product> products;

    public Catalogue(HashMap<Integer, Product> products) {
        this.products = products;
    }

    public void addProduct(Product p) {
        if (products.containsKey(p.getId())) {
            System.out.println("Product ID " + p.getId() + " already exists. Not added.");
        } else {
            products.put(p.getId(), p);
            System.out.println("Added: " + p);
        }
    }

    public Product searchProduct(int id) {
        return products.get(id);
    }

    public void updatePrice(int id, double newPrice) {
        Product p = products.get(id);
        if (p == null) {
            System.out.println("Cannot update: product ID " + id + " not found.");
        } else {
            p.setPrice(newPrice);
            System.out.println("Updated: " + p);
        }
    }

    public void removeProduct(int id) {
        Product removed = products.remove(id);
        if (removed == null) System.out.println("Cannot remove: product ID " + id + " not found.");
        else System.out.println("Removed: " + removed);
    }

    public void displayAll() {
        for (Product p : products.values()) System.out.println(p);
    }
}
