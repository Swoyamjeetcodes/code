import java.io.*;
public class EvenOdd {
    
	public static void main(String[] args) {
		
		int n, i;
		int evenCount = 0, oddCount = 0;
		
		for (i = 0; i < args.length; i++)
		{
			n=Integer.parseInt(args[i]);
		
			if(n % 2 == 0)
			{
				evenCount++;
			}
			else
			{
				oddCount++;
			}
		}		
		System.out.println("\n Total Number of Even Numbers in this Array = " + evenCount);
		System.out.println("\n Total Number of Odd  Numbers in this Array = " + oddCount);
	}
}