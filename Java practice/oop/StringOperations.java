import java.util.Scanner;

public class StringOperations 
{
    public static boolean isPalindrome(String str) {
        str = str.replaceAll("\\s", "").toLowerCase();
        int length = str.length();
        for (int i = 0; i < length / 2; i++) {
            if (str.charAt(i) != str.charAt(length - i - 1)) 
            {
                return false;
            }
        }
        return true;
    }

    public static int countWords(String str) {
        if (str == null || str.isEmpty()) {
            return 0;
        }
        String[] words = str.split("\\s+");
        return words.length;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a string: ");
        String inputString = scanner.nextLine();

        if (isPalindrome(inputString)) {
            System.out.println("The string is a palindrome.");
        } else {
            System.out.println("The string is not a palindrome.");
        }
        int wordCount = countWords(inputString);
        System.out.println("Number of words in the string: " + wordCount);

        scanner.close();
    }
}