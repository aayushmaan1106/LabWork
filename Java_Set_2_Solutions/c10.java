// Set 2 - Problem 10: E-Commerce Shopping Cart
import java.util.HashMap;
import java.util.LinkedHashMap;

public class c10 {
    public static void main(String[] args) {
        Product keyboard = new Product(1, "Keyboard", 800);
        Product mouse = new Product(2, "Mouse", 700);

        ShoppingCart cart = new ShoppingCart();
        cart.addProduct(keyboard, 1);
        cart.addProduct(keyboard, 1);   // already present -> quantity increases to 2
        cart.addProduct(mouse, 1);

        cart.display();

        System.out.println("\n--- Invalid operations ---");
        cart.addProduct(mouse, 0);          // invalid quantity
        cart.updateQuantity(2, -3);         // invalid quantity
        cart.updateQuantity(99, 2);         // not in cart
        cart.removeProduct(99);             // not in cart

        System.out.println("\n--- Update mouse quantity to 8 ---");
        cart.updateQuantity(2, 8);
        cart.display();

        System.out.println("\n--- Remove keyboard ---");
        cart.removeProduct(1);
        cart.display();
    }
}

class Product {
    private final int id;
    private final String name;
    private final double price;

    public Product(int id, String name, double price) {
        this.id = id;
        this.name = name;
        this.price = price;
    }

    public int getId() { return id; }
    public String getName() { return name; }
    public double getPrice() { return price; }
}

// Immutable: once created it cannot be changed from outside
class CartItem {
    private final Product product;
    private final int quantity;

    public CartItem(Product product, int quantity) {
        this.product = product;
        this.quantity = quantity;
    }

    public Product getProduct() { return product; }
    public int getQuantity() { return quantity; }
    public double getAmount() { return product.getPrice() * quantity; }
}

class ShoppingCart {
    // private; LinkedHashMap keeps insertion order so the bill prints in the order items were added
    private final HashMap<Integer, CartItem> items = new LinkedHashMap<>();

    public boolean addProduct(Product product, int quantity) {
        if (product == null || quantity <= 0) {
            System.out.println("Invalid quantity: " + quantity);
            return false;
        }
        CartItem existing = items.get(product.getId());
        int newQty = (existing == null) ? quantity : existing.getQuantity() + quantity;
        items.put(product.getId(), new CartItem(product, newQty));
        return true;
    }

    public boolean updateQuantity(int productId, int quantity) {
        CartItem existing = items.get(productId);
        if (existing == null) {
            System.out.println("Product ID " + productId + " is not in the cart.");
            return false;
        }
        if (quantity <= 0) {
            System.out.println("Invalid quantity: " + quantity);
            return false;
        }
        items.put(productId, new CartItem(existing.getProduct(), quantity));
        return true;
    }

    public boolean removeProduct(int productId) {
        if (items.remove(productId) == null) {
            System.out.println("Product ID " + productId + " is not in the cart.");
            return false;
        }
        return true;
    }

    public double getSubtotal() {
        double total = 0;
        for (CartItem item : items.values()) total += item.getAmount();
        return total;
    }

    public int getDiscountPercent() {
        double subtotal = getSubtotal();
        if (subtotal >= 5000) return 10;
        if (subtotal >= 1000) return 5;
        return 0;
    }

    public double getTotalBill() {
        double subtotal = getSubtotal();
        return subtotal - subtotal * getDiscountPercent() / 100.0;
    }

    public void display() {
        if (items.isEmpty()) {
            System.out.println("Cart is empty.");
            return;
        }
        System.out.printf("%-12s %-10s %10s%n", "Product", "Quantity", "Amount");
        for (CartItem item : items.values()) {
            System.out.printf("%-12s %-10d %10.2f%n",
                    item.getProduct().getName(), item.getQuantity(), item.getAmount());
        }
        System.out.println("----------------------------------");
        double subtotal = getSubtotal();
        int percent = getDiscountPercent();
        System.out.printf("Subtotal: %.2f%n", subtotal);
        System.out.printf("Discount (%d%%): %.2f%n", percent, subtotal * percent / 100.0);
        System.out.printf("Final Amount: %.2f%n", getTotalBill());
    }
}
