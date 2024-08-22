import java.util.Scanner;

public class StringOperations {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Prompt user for string input
        System.out.println("Enter a string:");
        String str1 = scanner.nextLine();

        // Prompt user for another string input
        System.out.println("Enter another string:");
        String str2 = scanner.nextLine();

        // Prompt user for a character input
        System.out.println("Enter a character:");
        char ch = scanner.next().charAt(0);

        // Operations
        // i) Change the case of the string
        System.out.println("String 1 in uppercase: " + str1.toUpperCase());
        System.out.println("String 2 in lowercase: " + str2.toLowerCase());

        // ii) Reverse the string
        System.out.println("Reverse of String 1: " + reverseString(str1));

        // iii) Compare two strings
        System.out.println("Comparison of String 1 and String 2: " + str1.equals(str2));

        // iv) Insert one string into another string
        System.out.println("Insert String 2 into String 1: " + insertString(str1, str2));

        // v) Convert the string to upper case and lower case
        // Already performed above

        // vi) Check whether the character is present in the string and at which position
        int position = str1.indexOf(ch);
        if (position != -1) {
            System.out.println("Character " + ch + " is present in String 1 at position: " + (position + 1));
        } else {
            System.out.println("Character " + ch + " is not present in String 1.");
        }

        // vii) Check whether the string is palindrome or not.
        System.out.println("Is String 1 a palindrome? " + isPalindrome(str1));

        // viii) Check the number of words, vowels, and consonants in the string
        int[] counts = countWordsVowelsConsonants(str1);
        System.out.println("Number of words in String 1: " + counts[0]);
        System.out.println("Number of vowels in String 1: " + counts[1]);
        System.out.println("Number of consonants in String 1: " + counts[2]);

        scanner.close();
    }

    // Method to reverse a string
    public static String reverseString(String str) {
        StringBuilder reversed = new StringBuilder();
        for (int i = str.length() - 1; i >= 0; i--) {
            reversed.append(str.charAt(i));
        }
        return reversed.toString();
    }

    // Method to insert one string into another string
    public static String insertString(String original, String toInsert) {
        int index = original.length() / 2; // Insert at the middle for demonstration
        return original.substring(0, index) + toInsert + original.substring(index);
    }

    // Method to check if a string is palindrome
    public static boolean isPalindrome(String str) {
        StringBuilder reversed = new StringBuilder(str).reverse();
        return str.equals(reversed.toString());
    }

    // Method to count words, vowels, and consonants in a string
    public static int[] countWordsVowelsConsonants(String str) {
        int words = str.split("\\s+").length;
        int vowels = 0;
        int consonants = 0;
        str = str.toLowerCase();
        for (int i = 0; i < str.length(); i++) {
            char ch = str.charAt(i);
            if (ch >= 'a' && ch <= 'z') {
                if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                    vowels++;
                } else {
                    consonants++;
                }
            }
        }
        return new int[]{words, vowels, consonants};
    }
}
