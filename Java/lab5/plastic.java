import java.util.Scanner;

public class plastic 
{
    public static void main(String[] args) 
    {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter dimensions for plastic:");
        System.out.print("Length: ");
        double length = scanner.nextDouble();

        System.out.print("Width: ");
        double width = scanner.nextDouble();

        System.out.print("Height: ");
        double height = scanner.nextDouble();

        
        TwoD sheet = new TwoD(length, width);
        ThreeD box = new ThreeD(length, width, height);

       
        System.out.println("\nCost of 2D Sheet: Rs " + sheet.calculateCost());
        System.out.println("Cost of 3D Box: Rs " + box.calculateCost());
 
        scanner.close();
    }
}

class TwoD 
{
    protected double length;
    protected double width;

  kjtgnkdfngkjerngkjdbgkjergkjrbjgbkjerbgkje  public TwoD(double length, double width) 
    {
        this.length = length;
        this.width = width;
    }

    public double calculateCost() 
    {
        return length * width * 40; 
    }
}

class ThreeD extends TwoD 
{
    protected double height;

    public ThreeD(double length, double width, double height) 
    {
        super(length, width);
        this.height = height;
    }

    
    public double calculateCost() 
    {
        return super.calculateCost() + length * width * height * 60; 
    }
}