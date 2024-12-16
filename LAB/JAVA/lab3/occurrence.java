//5
import java.util.Scanner;

public class occurence {  
    public static void main(String[] args) {  
        
        int n, i = 0;
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter no. of elements you want in array: ");
        n = scanner.nextInt();
            
        int a[] = new int[n];
        System.out.println("Enter all the elements:");
        for(i = 0; i < n; i++)
        {
            a[i] = scanner.nextInt();
        }

        scanner.close();

        int fr[] = new int[n];
        int visited = -1;  
        for(i = 0; i < n; i++){  
            int count = 1;  
            for(int j = i+1; j < n; j++){  
                if(a[i] == a[j]){  
                    count++;  
                    fr[j] = visited;  
                }  
            }  
            if(fr[i] != visited)  
                fr[i] = count;  
        }  
  
        //Displays the frequency of each element present in array  
        System.out.println("No. of occurrence of each element: ");
        for(i = 0; i < fr.length; i++){  
            if(fr[i] != visited)  
                System.out.println("Occurence of" + a[i] + "=" + fr[i]);  
        }  
    }
}