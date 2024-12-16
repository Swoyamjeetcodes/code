import java.util.Scanner;

public class UserInputArrayIndexOutOfBoundsException {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        try {
            System.out.print("Enter the size of the array: ");
            int size = scanner.nextInt();

            int[] numbers = new int[size-1];

            System.out.println("Enter " + size + " numbers:");
              for (int i = 0; i < size; i++) {
                numbers[i] = scanner.nextInt();
            }

            int value = numbers[size];
        } catch (ArrayIndexOutOfBoundsException e) {

            System.out.println("Exception in thread \"main\"");
            System.out.println("java.lang.ArrayIndexOutOfBoundsException: " + e.getMessage());
        } finally {
            scanner.close();
        }
    }
}