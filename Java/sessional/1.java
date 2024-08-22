import java.util.Scanner;
public class Postpaid_Bill {
     String Mobile_number;
     String customer_Id;
     String bill_date;
     int[] monthly_transactions = new int[5];

    public void getPostPaidbill() throws InputValidationException {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter Mobile Number:");
        Mobile_number = scanner.nextLine();
        System.out.println("Enter Customer ID:");
        customer_Id = scanner.nextLine();
        System.out.println("Enter Bill Date (dd-mm-yyyy):");
        bill_date = scanner.nextLine();

        validateData();

        for (int i = 0; i < 5; i++) {
            System.out.println("Enter Monthly Transaction " + (i + 1) + ":");
            monthly_transactions[i] = scanner.nextInt();
        }
    }

    public void validateData() throws InputValidationException {
        if (Mobile_number.length() != 10) {
            throw new InputValidationException("Mobile number should be of 10 digits");
        }
        if (customer_Id.length() != 6) {
            throw new InputValidationException("Customer ID should be a 6 digit numeric value");
        }
        if (!bill_date.matches("\\d{2}-\\d{2}-\\d{4}")) {
            throw new InputValidationException("Bill date should be in dd-mm-yyyy format");
        }
    }

    public int getTotalAmount() {
        int total = 0;
        for (int transaction : monthly_transactions) {
            total += transaction;
        }
        return total;
    }
    class InputValidationException extends Exception 
    {
        public InputValidationException(String message) 
        {
            super(message);
        }
    }
    public static void main(String[] args) {
        Postpaid_Bill bill = new Postpaid_Bill();
        try {
            bill.getPostPaidbill();
            System.out.println("Total amount: " + bill.getTotalAmount());
        } catch (InputValidationException e) {
            System.out.println("Input Validation Error: " + e.getMessage());
        }
    }
}