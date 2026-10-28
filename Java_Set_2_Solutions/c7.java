// Set 2 - Problem 7: Hospital Patient Queue Using PriorityQueue
import java.util.Comparator;
import java.util.PriorityQueue;

public class c7 {
    public static void main(String[] args) {
        PriorityQueue<Patient> queue = new PriorityQueue<>(
                Comparator.comparingInt(Patient::getPriority)       // smaller number = more urgent
                          .thenComparingInt(Patient::getArrivalSeq) // tie: who arrived first
        );

        // Arrival order: A, B, C, D
        queue.add(new Patient(1, "Patient A", 1));
        queue.add(new Patient(2, "Patient B", 2));
        queue.add(new Patient(3, "Patient C", 1));
        queue.add(new Patient(4, "Patient D", 3));

        System.out.println("Processing order:");
        while (!queue.isEmpty()) {
            System.out.println(queue.poll());
        }
    }
}

class Patient {
    private static int arrivalCounter = 0;     // gives every patient an arrival number

    private final int id;
    private final String name;
    private final int priority;
    private final int arrivalSeq;

    public Patient(int id, String name, int priority) {
        this.id = id;
        this.name = name;
        this.priority = priority;
        this.arrivalSeq = ++arrivalCounter;
    }

    public int getPriority() { return priority; }
    public int getArrivalSeq() { return arrivalSeq; }

    private String priorityLabel() {
        return switch (priority) {
            case 1 -> "Critical";
            case 2 -> "Urgent";
            default -> "Normal";
        };
    }

    @Override
    public String toString() {
        return name + " - Priority " + priority + " (" + priorityLabel() + ")";
    }
}
