    // Main method to test the functionality
public class Main
{
public static void main(String[] args) 
{
        NumberProcessor processor = new NumberProcessor();
        int inputNumber = 5; // Change this to test different numbers

        try {
            processor.ProcessInput(inputNumber);
        } catch (NegativeNumberException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }
}
// Main class with ProcessInput method
public class NumberProcessor 
{

    // Method to process the input
    public void ProcessInput(int number) throws NegativeNumberException {
        if (number < 0) {
            throw new NegativeNumberException("Negative numbers are not allowed");
        } else {
            System.out.println("Double value of the entered number: " + number * number);
        }
    }
}
// Define a custom exception for negative numbers
class NegativeNumberException extends Exception 
{
    NegativeNumberException(String message) {
        super(message);
    }
}
