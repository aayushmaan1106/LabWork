// Set 2 - Problem 6: Unique Student Registration Using HashSet
import java.util.HashSet;

public class c6 {
    public static void main(String[] args) {
        HashSet<Student> registered = new HashSet<>();

        Student s1 = new Student(101, "Aamir");
        Student s2 = new Student(101, "Aamir Khan");   // same reg. number as s1
        Student s3 = new Student(102, "Sara");

        System.out.println("Add s1: " + registered.add(s1));
        System.out.println("Add s2: " + registered.add(s2) + "  (duplicate registration number)");
        System.out.println("Add s3: " + registered.add(s3));

        System.out.println("\nRegistered students (" + registered.size() + "):");
        for (Student s : registered) System.out.println(s);

        Student check = new Student(101, "Anyone");
        System.out.println("\nIs registration number 101 already registered? " + registered.contains(check));
        System.out.println("Is registration number 999 already registered? "
                + registered.contains(new Student(999, "Unknown")));
    }
}

class Student {
    private final int regNo;
    private final String name;

    public Student(int regNo, String name) {
        this.regNo = regNo;
        this.name = name;
    }

    // Equality depends only on the registration number
    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Student other)) return false;
        return regNo == other.regNo;
    }

    @Override
    public int hashCode() {
        return Integer.hashCode(regNo);
    }

    @Override
    public String toString() {
        return "RegNo: " + regNo + " | Name: " + name;
    }
}
