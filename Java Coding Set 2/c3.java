// Set 2 - Problem 3: Employee Salary Management
public class c3 {
    public static void main(String[] args) {
        Employee e1 = new Employee(101, "Aamir", 40000);
        Employee e2 = new Employee(102, "Sara", 60000);
        Employee e3 = new Employee(103, "Rahul", 55000);

        e1.displaySalaryDetails();
        e2.displaySalaryDetails();
        e3.displaySalaryDetails();

        Employee higher = Employee.higherGross(e1, e2);
        System.out.println("Higher gross salary (Aamir vs Sara): " + higher.getName());
        higher = Employee.higherGross(e2, e3);
        System.out.println("Higher gross salary (Sara vs Rahul): " + higher.getName());
    }
}

class Employee {
    private final int id;
    private final String name;
    private final double basicSalary;

    public Employee(int id, String name, double basicSalary) {
        this.id = id;
        this.name = name;
        this.basicSalary = basicSalary;
    }

    public String getName() { return name; }

    private double hra()   { return basicSalary * 0.20; }
    private double da()    { return basicSalary * 0.10; }
    private double bonus() { return basicSalary > 50000 ? basicSalary * 0.05 : 0; }

    public double getGrossSalary() {
        return basicSalary + hra() + da() + bonus();
    }

    // Returns the employee with the higher gross salary
    public static Employee higherGross(Employee a, Employee b) {
        return a.getGrossSalary() >= b.getGrossSalary() ? a : b;
    }

    public void displaySalaryDetails() {
        System.out.println("ID: " + id + ", Name: " + name);
        System.out.printf("  Basic: %.2f  HRA: %.2f  DA: %.2f  Bonus: %.2f%n",
                basicSalary, hra(), da(), bonus());
        System.out.printf("  Gross Salary: %.2f%n%n", getGrossSalary());
    }
}
