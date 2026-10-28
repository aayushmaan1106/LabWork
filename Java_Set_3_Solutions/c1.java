// Set 3 - Problem 1: Multilevel Inheritance with Constructor Chaining
public class c1 {
    public static void main(String[] args) {
        System.out.println("Creating a Developer object...\n");
        Developer dev = new Developer("Aamir", 28, 501, 75000, "Java", "Order Portal");

        System.out.println("\nDetails:");
        dev.displayDetails();
    }
}

class Person {
    protected String name;
    protected int age;

    Person(String name, int age) {
        System.out.println("1. Person constructor executed");
        this.name = name;
        this.age = age;
    }

    void displayDetails() {
        System.out.println("Name: " + name + ", Age: " + age);
    }
}

class Employee extends Person {
    protected int empId;
    protected double salary;

    Employee(String name, int age, int empId, double salary) {
        super(name, age);                       // calls Person constructor first
        System.out.println("2. Employee constructor executed");
        this.empId = empId;
        this.salary = salary;
    }

    @Override
    void displayDetails() {
        super.displayDetails();
        System.out.println("Employee ID: " + empId + ", Salary: " + salary);
    }
}

class Developer extends Employee {
    private String language;
    private String project;

    Developer(String name, int age, int empId, double salary, String language, String project) {
        super(name, age, empId, salary);        // calls Employee constructor first
        System.out.println("3. Developer constructor executed");
        this.language = language;
        this.project = project;
    }

    @Override
    void displayDetails() {
        super.displayDetails();
        System.out.println("Language: " + language + ", Project: " + project);
    }
}

/*
 * Constructor order: Person -> Employee -> Developer (top of the hierarchy first).
 *
 * Challenge: what if super() is not the first statement?
 *  - Before JDK 25 it is a compile error: "call to super must be first statement in constructor".
 *  - From JDK 25 (flexible constructor bodies) statements may appear BEFORE super(...),
 *    but only code that does not use the object being built: you may validate or compute
 *    arguments, but you cannot read this.field or call instance methods yet.
 *    super(...) must still run before the object is used.
 *  - If you write no super() at all, the compiler inserts super() (no-arg) automatically.
 *    That fails to compile if the parent has no no-arg constructor.
 */
