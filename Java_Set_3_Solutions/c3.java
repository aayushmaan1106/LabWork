// Set 3 - Problem 3: Overriding with super and Runtime Polymorphism
public class c3 {
    public static void main(String[] args) {
        int days = 3;

        Vehicle[] vehicles = {
            new Vehicle("Generic Van"),
            new Car("Swift"),
            new LuxuryCar("BMW 5 Series")
        };

        for (Vehicle v : vehicles) {
            // Runtime polymorphism: the overridden method of the real object runs
            System.out.println(v.getName() + " (" + v.getClass().getSimpleName() + ") rent for "
                    + days + " days = Rs." + v.calculateRent(days));
        }
    }
}

class Vehicle {
    protected String name;

    Vehicle(String name) { this.name = name; }
    String getName() { return name; }

    double calculateRent(int days) {
        return days * 1000;                       // base rate: Rs.1000 per day
    }
}

class Car extends Vehicle {
    Car(String name) { super(name); }

    @Override
    double calculateRent(int days) {
        return super.calculateRent(days) + 500;   // base rent + flat insurance
    }
}

class LuxuryCar extends Car {
    LuxuryCar(String name) { super(name); }

    @Override
    double calculateRent(int days) {
        return super.calculateRent(days) * 2 + 1500 * days;   // double the car rent + chauffeur per day
    }
}
