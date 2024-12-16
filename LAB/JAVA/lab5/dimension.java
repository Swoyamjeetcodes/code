import java.util.Scanner;

public class dimension {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter dimensions for Plate (length and width):");
        double lengthPlate = scanner.nextDouble();
        double widthPlate = scanner.nextDouble();

        System.out.println("Enter dimensions for Box (length, width, and height):");
        double lengthBox = scanner.nextDouble();
        double widthBox = scanner.nextDouble();
        double heightBox = scanner.nextDouble();

        System.out.println("Enter dimensions for WoodBox (length, width, height, and thickness):");
        double lengthWoodBox = scanner.nextDouble();
        double widthWoodBox = scanner.nextDouble();
        double heightWoodBox = scanner.nextDouble();
        double thicknessWoodBox = scanner.nextDouble();

        WoodBox woodBox = new WoodBox(lengthWoodBox, widthWoodBox, heightWoodBox, thicknessWoodBox);
    }
}

class Plate {
    protected double length;
    protected double width;

    public Plate(double length, double width) {
        this.length = length;
        this.width = width;
        System.out.println("Plate constructor called with length = " + length + " and width = " + width);
    }
}

class Box extends Plate {
    protected double height;

    public Box(double length, double width, double height) {
        super(length, width);
        this.height = height;
        System.out.println("Box constructor called with height = " + height);
    }
}

class WoodBox extends Box {
    protected double thickness;

    public WoodBox(double length, double width, double height, double thickness) {
        super(length, width, height);
        this.thickness = thickness;
        System.out.println("WoodBox constructor called with thickness = " + thickness);
    }
}