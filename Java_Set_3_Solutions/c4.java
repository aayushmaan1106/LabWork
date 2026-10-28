// Set 3 - Problem 4: Overloading vs Overriding - Predict the Output
public class c4 {
    public static void main(String[] args) {
        A a = new B();           // reference type A, object type B
        String s = "Hello";
        Object o = "Hello";      // Object variable referring to a String

        System.out.println("Through A reference (A a = new B()):");
        a.show(s);               // B-Object
        a.show(o);               // B-Object
        a.show(null);            // B-Object

        System.out.println("\nThrough B reference (B b = new B()):");
        B b = new B();
        b.show(s);               // B-String
        b.show(o);               // B-Object
        b.show(null);            // B-String
    }
}

class A {
    void show(Object x) {
        System.out.println("A-Object");
    }
}

class B extends A {
    @Override
    void show(Object x) {
        System.out.println("B-Object");
    }

    void show(String x) {        // overload (new method), NOT an override
        System.out.println("B-String");
    }
}

/*
 * How it works:
 *  1. COMPILE TIME - overload resolution uses the reference type.
 *     With reference type A, only show(Object) is visible, so every call becomes show(Object),
 *     even show(s) and show(null). The compiler never sees show(String) through an A reference.
 *     With reference type B, both show(Object) and show(String) are visible. The compiler picks
 *     the most specific applicable one: show(s) -> String; show(o) -> Object (the static type of
 *     o is Object); show(null) -> String (String is more specific than Object).
 *  2. RUNTIME - overriding uses the actual object. The chosen signature show(Object) is
 *     overridden in B, so the JVM runs B's version: "B-Object" instead of "A-Object".
 *     show(String) is only an overload, so it is never dispatched dynamically.
 */
