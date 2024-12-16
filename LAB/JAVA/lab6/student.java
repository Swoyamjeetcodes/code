import java.util.Scanner;
// Driver class Main
public class Main {
    public static void main(String[] args) {
        Kiitian kiitian = new Kiitian();

        System.out.println("Enter details for a KIITian:");
        kiitian.getInput(); // Calls the getInput() method of the superclass
        kiitian.course();   // Calls the course() method of the subclass

        // Printing details
        System.out.println("\nDetails of the KIITian:");
        System.out.println("Roll Number: " + kiitian.rollNo);
        System.out.println("Registration Number: " + kiitian.regNo);
    }
}

// Abstract class Student
abstract class Student {
    int rollNo;
    int regNo;

    // Abstract method
    abstract void course();

    // Concrete method
    void getInput() {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter Roll Number: ");
        rollNo = scanner.nextInt();
        System.out.print("Enter Registration Number: ");
        regNo = scanner.nextInt();
    }
}

// Subclass Kiitian extending Student
class Kiitian extends Student {
    // Implementation of the abstract method
    @Override
    void course() {
        System.out.println("Student is a KIITian.");
    }
}