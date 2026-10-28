// Set 3 - Problem 6: Employee Payroll with Different Compensation Models
import java.util.ArrayList;

public class c6 {
    public static void main(String[] args) {
        // Employee e = new Employee(1, "X");   // COMPILE ERROR: abstract class cannot be instantiated

        PermanentEmployee perm = new PermanentEmployee(1, "Aamir", 50000);

        ArrayList<Employee> staff = new ArrayList<>();
        staff.add(perm);
        staff.add(new ContractEmployee(2, "Sara", 160, 300));
        staff.add(new CommissionEmployee(3, "Rahul", 20000, 400000, 0.05));

        System.out.println("PAYROLL REPORT");
        System.out.println("--------------------------------------------");
        double total = 0;
        for (Employee e : staff) {
            double salary = e.calculateSalary();       // polymorphic call
            total += salary;
            System.out.printf("%-3d %-8s %-20s %10.2f%n", e.getId(), e.getName(),
                    e.getClass().getSimpleName(), salary);
        }
        System.out.println("--------------------------------------------");
        System.out.printf("Total payroll: %.2f%n", total);

        // Overloaded method (only available on the PermanentEmployee reference)
        System.out.printf("%nAamir with Rs.5000 festival bonus: %.2f%n", perm.calculateSalary(5000));
    }
}

abstract class Employee {
    private final int id;
    private final String name;

    Employee(int id, String name) {
        this.id = id;
        this.name = name;
    }

    int getId() { return id; }
    String getName() { return name; }

    abstract double calculateSalary();
}

class PermanentEmployee extends Employee {
    private final double basic;

    PermanentEmployee(int id, String name, double basic) {
        super(id, name);
        this.basic = basic;
    }

    @Override
    double calculateSalary() {
        return basic + basic * 0.20 + basic * 0.10;      // basic + HRA + DA
    }

    // Overloaded version with an extra bonus
    double calculateSalary(double bonus) {
        return calculateSalary() + bonus;
    }
}

class ContractEmployee extends Employee {
    private final int hoursWorked;
    private final double hourlyRate;

    ContractEmployee(int id, String name, int hoursWorked, double hourlyRate) {
        super(id, name);
        this.hoursWorked = hoursWorked;
        this.hourlyRate = hourlyRate;
    }

    @Override
    double calculateSalary() {
        return hoursWorked * hourlyRate;
    }
}

class CommissionEmployee extends Employee {
    private final double baseSalary;
    private final double salesAmount;
    private final double commissionRate;

    CommissionEmployee(int id, String name, double baseSalary, double salesAmount, double commissionRate) {
        super(id, name);
        this.baseSalary = baseSalary;
        this.salesAmount = salesAmount;
        this.commissionRate = commissionRate;
    }

    @Override
    double calculateSalary() {
        return baseSalary + salesAmount * commissionRate;
    }
}

/*
 * Challenge: why can't an abstract method be invoked on an abstract class instance, but can be
 * invoked through an Employee reference?
 *  - You can never create an instance of an abstract class (new Employee(...) does not compile),
 *    so there is no object whose abstract method has no body.
 *  - An Employee reference can only point to an object of a concrete subclass
 *    (PermanentEmployee, ContractEmployee, ...), and every concrete subclass must implement
 *    calculateSalary(). The call is resolved at runtime to that subclass's implementation.
 */
