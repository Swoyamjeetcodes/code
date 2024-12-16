import java.util.Scanner;

public class Demo {
    public static void main(String[] args) 
    {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the length of the box: ");
        double length = scanner.nextDouble();

        System.out.print("Enter the width of the box: ");
        double width = scanner.nextDouble();

        System.out.print("Enter the height of the box: ");
        double height = scanner.nextDouble();

        Box myBox = new Box(length, width, height);

        System.out.println("Volume of the box: " + myBox.volume());
        scanner.close();
    } 
}

class Box 
{
    static double length;
    static double width;
    static double height;

    public Box(double length, double width, double height) {
        this.length = length;
        this.width = width;
        this.height = height;
    }

    public double volume() {
        return length * width * height;
    }
}
