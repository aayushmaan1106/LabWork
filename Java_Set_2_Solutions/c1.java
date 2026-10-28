// Set 2 - Problem 1: Student Result Management System
public class c1 {
    public static void main(String[] args) {
        Student s = new Student(101, "Aamir", 80, 90, 85);
        s.display();
    }
}

class Student {
    private final int rollNumber;
    private final String name;
    private final int marks1, marks2, marks3;

    public Student(int rollNumber, String name, int marks1, int marks2, int marks3) {
        this.rollNumber = rollNumber;
        this.name = name;
        this.marks1 = marks1;
        this.marks2 = marks2;
        this.marks3 = marks3;
    }

    public int getRollNumber() { return rollNumber; }
    public String getName() { return name; }
    public int getMarks1() { return marks1; }
    public int getMarks2() { return marks2; }
    public int getMarks3() { return marks3; }

    public int calculateTotal() {
        return marks1 + marks2 + marks3;
    }

    public double calculatePercentage() {
        return calculateTotal() / 3.0;
    }

    public char calculateGrade() {
        double p = calculatePercentage();
        if (p >= 90) return 'A';
        else if (p >= 75) return 'B';
        else if (p >= 60) return 'C';
        else return 'D';
    }

    public void display() {
        System.out.println("Roll Number: " + rollNumber);
        System.out.println("Name: " + name);
        System.out.println("Total Marks: " + calculateTotal() + " / 300");
        System.out.printf("Percentage: %.1f%%%n", calculatePercentage());
        System.out.println("Grade: " + calculateGrade());
    }
}
