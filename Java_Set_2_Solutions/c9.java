// Set 2 - Problem 9: Employee Directory with Sorting
import java.util.ArrayList;
import java.util.Comparator;

public class c9 {
    public static void main(String[] args) {
        ArrayList<Employee> employees = new ArrayList<>();
        employees.add(new Employee(1, "Aamir", "IT", 60000));
        employees.add(new Employee(2, "Sara", "HR", 45000));
        employees.add(new Employee(3, "Rahul", "IT", 80000));
        employees.add(new Employee(4, "Neha", "Finance", 70000));
        employees.add(new Employee(5, "Bilal", "HR", 52000));
        employees.add(new Employee(6, "Zoya", "Finance", 95000));

        System.out.println("Sorted by salary (ascending):");
        employees.sort(Comparator.comparingDouble(Employee::getSalary));
        employees.forEach(System.out::println);

        System.out.println("\nSorted by name (alphabetical):");
        employees.sort(Comparator.comparing(Employee::getName, String.CASE_INSENSITIVE_ORDER));
        employees.forEach(System.out::println);

        String dept = "IT";
        System.out.println("\nEmployees in department " + dept + ":");
        for (Employee e : employees) {
            if (e.getDepartment().equalsIgnoreCase(dept)) System.out.println(e);
        }

        System.out.println("\nTop three highest-paid employees:");
        ArrayList<Employee> bySalary = new ArrayList<>(employees);
        bySalary.sort(Comparator.comparingDouble(Employee::getSalary).reversed());
        for (int i = 0; i < Math.min(3, bySalary.size()); i++) {
            System.out.println((i + 1) + ". " + bySalary.get(i));
        }
    }
}

class Employee {
    private final int id;
    private final String name;
    private final String department;
    private final double salary;

    public Employee(int id, String name, String department, double salary) {
        this.id = id;
        this.name = name;
        this.department = department;
        this.salary = salary;
    }

    public String getName() { return name; }
    public String getDepartment() { return department; }
    public double getSalary() { return salary; }

    @Override
    public String toString() {
        return "ID: " + id + " | " + name + " | " + department + " | Rs." + salary;
    }
}
