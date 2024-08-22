import java.util.Scanner;
public class First
{
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter your marks: ");
        int marks = sc.nextInt();
        if(marks<0 || marks>100){
            throw new InvalidMarksExceptions("Marks are Invalid");
        }
        else 
        System.out.println("Valid Marks");
    }
}
class InvalidMarksExceptions extends RuntimeException
{
    InvalidMarksExceptions(String str)
    {
        super(str);
    }
}
