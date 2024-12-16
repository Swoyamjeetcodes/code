import java.util.*;

class Sample
{ 
	public static void main(String args[])
	{
	subtract obj = new subtract(); 
	obj.subtract('a');
	obj.subtract(5);
	}
} 

class subtract
{
	public void subtract(char c)
	{
	System.out.println(c);
	}
	
	public void subtract(int c)
	{
		System.out.println(c);
	}
}