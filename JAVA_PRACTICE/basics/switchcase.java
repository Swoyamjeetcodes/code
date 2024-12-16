import java.util.*;
class switchcase
{
    public static void main(String[] args)
    {
        int n;
        String marks ;
        Scanner xyz=new Scanner(System.in);
        System.out.println("----MENU-----");
        System.out.println("A");
        System.out.println("B");
        System.out.println("C");
        System.out.println("\nEnter option:-");
        n=xyz.nextInt();

        switch(n)
        {
            case 1:
            marks = "good";
            break;

            case 2:
            marks = "ok";
            break;

            case 3:
            marks = "bad";
            break;

        }
        System.out.println("marks" + marks);

    }
}