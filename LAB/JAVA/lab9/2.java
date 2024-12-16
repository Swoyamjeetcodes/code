import java.util.Scanner;

public class ArithmeticExceptionHandling {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter numerator:");
        int numerator = scanner.nextInt();

        System.out.println("Enter denominator:");
        int denominator = scanner.nextInt();

        try {
            int result = numerator / denominator; // This line will throw ArithmeticException if denominator is 0
            System.out.println("Result: " + result); // This line will not execute if an exception occurs
        } catch (ArithmeticException e) {
            System.out.println("ArithmeticException caught by try-catch-finally block" + e.getMessage());
        } finally {
            System.out.println("Finally block is always executed.");
        }
    }
}