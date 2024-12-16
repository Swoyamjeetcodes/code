import java.util.Scanner;

public class main 
{
    public static void main(String args[])
    {
    Time ob = new Time(); 
    try
    {
        ob.userinput(6,1,-20);
    }
    catch(HrsException e)
    {
        System.out.println(e.getMessage());
    }
    catch(MinException e1)
    {
        System.out.println(e1.getMessage());
    }
    catch(SecException e2)
    {
        System.out.println(e2.getMessage());
    }

    }
}
class Time
{
    int hours,minutes,seconds;
    void userinput(int hr,int min,int sec) throws HrsException,MinException,SecException
    {
        if (hr>24 || hr <0)
        {
            throw new HrsException("na1");
        }
        if (min>60 || min<0)
        {
            throw new MinException("na2");
        }
        if (sec>60 || sec<0)
        {
            throw new SecException("na3");
        }
    }
}

class HrsException extends Exception
{
    HrsException(String message)
{
super(message);
}
}
class MinException extends Exception
{
    MinException(String message)
{
super(message);
}
}
class SecException extends Exception
{
    SecException(String message)
{
super(message);
}
}