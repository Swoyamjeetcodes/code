//wap to input a 3 digit number and print sum of digits without using loop.
import java.util.Scanner;

public class sum3 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter a 3-digit number: ");
        int number = scanner.nextInt();

        int digit1 = number / 100;        
        int digit2 = (number / 10) % 10;   
        int digit3 = number % 10;           

        int sum = digit1 + digit2 + digit3;

        // Display the result
        System.out.println("Sum of digits: " + sum);

        scanner.close();
    }
}
