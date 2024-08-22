import java.util.Scanner;

public class Product {
    private String name;
    private double price;
    private int quantity;

    // Constructor with two arguments
    public Product(String name, double price) {
        this.name = name;
        this.price = price;
        //this.quantity = 1 // Default quantity
    }

    // Constructor with three arguments
    public Product(String name, double price, int quantity) {
        this.name = name;
        this.price = price;
        this.quantity = quantity;
    }

    // Method to display product details
    public void displayProduct() {
        System.out.println("Product Name: " + name);
        System.out.println("Price: $" + price);
        System.out.println("Quantity: " + quantity);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Taking input for name and price from command line arguments
        String nameFromCommandLine = args[0];

        // Taking input for quantity using Scanner
        System.out.print("Enter price: ");
        double priceFromScanner = scanner.nextDouble();

        System.out.print("Enter quantity: ");
        int quantityFromScanner = scanner.nextInt();

        // Creating objects using constructors based on input
        Product product1 = new Product(nameFromCommandLine, priceFromScanner);
        Product product2 = new Product(nameFromCommandLine, priceFromScanner, quantityFromScanner);

        // Displaying product details
        System.out.println("Product 1 details:");
        product1.displayProduct();

        System.out.println("\nProduct 2 details:");
        product2.displayProduct();

        // Close scanner
        scanner.close();
    }
}