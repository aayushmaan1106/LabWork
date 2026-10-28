// Set 2 - Problem 8: Course Registration Using ArrayList and HashMap
import java.util.ArrayList;
import java.util.HashMap;

public class c8 {
    public static void main(String[] args) {
        RegistrationSystem system = new RegistrationSystem();

        system.addCourse(new Course("CS101", "Java Programming", 2));
        system.addCourse(new Course("CS102", "Data Structures", 3));
        system.addCourse(new Course("CS101", "Duplicate Course", 5));   // rejected

        Student s1 = new Student(1, "Aamir");
        Student s2 = new Student(2, "Sara");
        Student s3 = new Student(3, "Rahul");

        System.out.println();
        system.registerStudent("CS101", s1);
        system.registerStudent("CS101", s1);   // duplicate in same course
        system.registerStudent("CS101", s2);
        system.registerStudent("CS101", s3);   // course full (capacity 2)
        system.registerStudent("CS102", s1);   // same student, different course: allowed
        system.registerStudent("CS999", s2);   // course does not exist

        System.out.println();
        system.displayEnrolled("CS101");
        system.displayEnrolled("CS102");
    }
}

class Course {
    private final String code;
    private final String name;
    private final int maxCapacity;

    public Course(String code, String name, int maxCapacity) {
        this.code = code;
        this.name = name;
        this.maxCapacity = maxCapacity;
    }

    public String getCode() { return code; }
    public String getName() { return name; }
    public int getMaxCapacity() { return maxCapacity; }
}

class Student {
    private final int id;
    private final String name;

    public Student(int id, String name) {
        this.id = id;
        this.name = name;
    }

    public String getName() { return name; }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Student other)) return false;
        return id == other.id;
    }

    @Override
    public int hashCode() { return Integer.hashCode(id); }

    @Override
    public String toString() { return "ID " + id + " - " + name; }
}

class RegistrationSystem {
    private final HashMap<String, Course> courses = new HashMap<>();
    private final HashMap<String, ArrayList<Student>> enrolled = new HashMap<>();

    public void addCourse(Course course) {
        if (courses.containsKey(course.getCode())) {
            System.out.println("Course " + course.getCode() + " already exists.");
            return;
        }
        courses.put(course.getCode(), course);
        enrolled.put(course.getCode(), new ArrayList<>());
        System.out.println("Added course: " + course.getCode() + " - " + course.getName()
                + " (capacity " + course.getMaxCapacity() + ")");
    }

    public void registerStudent(String courseCode, Student student) {
        Course course = courses.get(courseCode);
        if (course == null) {
            System.out.println("Registration failed: course " + courseCode + " not found.");
            return;
        }
        ArrayList<Student> list = enrolled.get(courseCode);
        if (list.contains(student)) {
            System.out.println(student.getName() + " is already registered in " + courseCode + ".");
        } else if (list.size() >= course.getMaxCapacity()) {
            System.out.println("Registration failed: " + courseCode + " is full. (" + student.getName() + ")");
        } else {
            list.add(student);
            System.out.println(student.getName() + " registered in " + courseCode + ".");
        }
    }

    public void displayEnrolled(String courseCode) {
        ArrayList<Student> list = enrolled.get(courseCode);
        if (list == null) {
            System.out.println("Course " + courseCode + " not found.");
            return;
        }
        System.out.println("Students in " + courseCode + " (" + list.size() + "/"
                + courses.get(courseCode).getMaxCapacity() + "):");
        for (Student s : list) System.out.println("  " + s);
    }
}
