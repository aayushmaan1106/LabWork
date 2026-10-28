// Set 3 - Problem 8: Shape Hierarchy with Overloaded Constructors and Methods
import java.util.Arrays;

public class c8 {
    public static void main(String[] args) {
        Shape[] shapes = {
            new Circle(5),
            new Circle(),                    // default: unit circle
            new Rectangle(4, 6),
            new Rectangle(5),                // square
            new Triangle(3, 4, 5),
            new Triangle(6)                  // equilateral
        };

        System.out.println("Shapes in original order:");
        for (Shape s : shapes) System.out.println(s);

        // Sort in descending order of area using compareArea(Shape)
        Arrays.sort(shapes, (s1, s2) -> s2.compareArea(s1));

        System.out.println("\nShapes by area (descending):");
        for (Shape s : shapes) System.out.println(s);

        System.out.println();
        Shape circle = new Circle(5);
        Shape rect = new Rectangle(4, 6);
        System.out.println("circle.compareArea(rect)  = " + circle.compareArea(rect) + "   (circle is bigger)");
        System.out.println("rect.compareArea(50.0)    = " + rect.compareArea(50.0) + "   (24 < 50)");
    }
}

abstract class Shape {
    abstract double area();
    abstract double perimeter();

    // Overloaded: compare with another shape ...
    int compareArea(Shape other) {
        return Double.compare(this.area(), other.area());
    }

    // ... or with a numeric area
    int compareArea(double otherArea) {
        return Double.compare(this.area(), otherArea);
    }

    @Override
    public String toString() {
        return String.format("%-10s area = %8.2f, perimeter = %8.2f",
                getClass().getSimpleName(), area(), perimeter());
    }
}

class Circle extends Shape {
    private final double radius;

    Circle() { this(1.0); }
    Circle(double radius) { this.radius = radius; }

    @Override double area() { return Math.PI * radius * radius; }
    @Override double perimeter() { return 2 * Math.PI * radius; }
}

class Rectangle extends Shape {
    private final double length, width;

    Rectangle(double side) { this(side, side); }     // square
    Rectangle(double length, double width) {
        this.length = length;
        this.width = width;
    }

    @Override double area() { return length * width; }
    @Override double perimeter() { return 2 * (length + width); }
}

class Triangle extends Shape {
    private final double a, b, c;

    Triangle(double side) { this(side, side, side); }   // equilateral
    Triangle(double a, double b, double c) {
        if (a + b <= c || a + c <= b || b + c <= a) {
            throw new IllegalArgumentException("Invalid triangle sides");
        }
        this.a = a;
        this.b = b;
        this.c = c;
    }

    @Override
    double area() {                                       // Heron's formula
        double s = (a + b + c) / 2;
        return Math.sqrt(s * (s - a) * (s - b) * (s - c));
    }

    @Override double perimeter() { return a + b + c; }
}

/*
 * Challenge: comparison across different shape types.
 * Every shape, whatever its type, can report its area() through the abstract Shape class.
 * compareArea(Shape) therefore only needs area() and never needs to know which subclass it has.
 */
