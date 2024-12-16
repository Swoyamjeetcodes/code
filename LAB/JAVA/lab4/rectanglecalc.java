import java.util.*;

public class Rectanglecalc 
{
    public static void main(String[] args) {
    
        Rectangle rl = new Rectangle();

        rl.read();

        rl.calculate();
    }
}

class Rectangle 
{

    static double length;
    static double breadth;

    public void read() {

        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter length of the rectangle: ");
        length = scanner.nextDouble();
        System.out.print("Enter breadth of the rectangle: ");
        breadth = scanner.nextDouble();
        scanner.close();
    }

    public void calculate() 
    {

        double area = length * breadth;
        double perimeter = 2 * (length + breadth);

        display(area, perimeter);
    }

    private void display(double area, double perimeter) 
    {
        System.out.println("Area of the rectangle: " + area);
        System.out.println("Perimeter of the rectangle: " + perimeter);
    }
}