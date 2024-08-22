public class main 
{   
    public static void main (String args[])
    {   
        int l = args.length;
        checkarg ob = new checkarg();
        try
        {
            ob.check(l);
        }

        catch(CheckArgumentException e)
        {
        System.out.println(e.getMessage());
        }
    }
}
public class checkarg
{   
    void check(int length)
    {
        if (length<4)
    {
        throw new CheckArgumentException("na");
    }
    }
}
class CheckArgumentException extends Exception
{
    CheckArgumentException(String message)
    {
        super(message);
    }
}