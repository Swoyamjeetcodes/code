import java.util.Scanner;

public class StudentDetails {
    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter your name: ");
        String name = scanner.nextLine();

        System.out.print("Enter your roll number: ");
        int rollNumber = scanner.nextInt();
        scanner.nextLine();

        System.out.print("Enter your section: ");
        char section = scanner.next().charAt(0);

        System.out.print("Enter your branch: ");
        String branch = scanner.next();

        scanner.close();


        System.out.println("Name: " + name);
        System.out.println("Roll Number: " + rollNumber);
        System.out.println("Section: " + section);
        System.out.println("Branch: " + branch);
    }
}
