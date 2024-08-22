//wap to calculate area of triangle with heron's formula
import java.util.*;
import java.util.Scanner;
import java.lang.Math;
public class area
{
    public static void main(String args[])
    {
        double a,b,c,s,area;
        Scanner input = new Scanner(System.in);

        System.out.println("side a length");
        a = input.nextInt();
        System.out.println("side b length");
        b = input.nextInt();
        System.out.println("side c length");
        c = input.nextInt();
        s=(a+b+c)/2.0d;
        area=Math.sqrt(s * (s-a)* (s-b) * (s-c));
        System.out.println("area:"+area);
    }
}