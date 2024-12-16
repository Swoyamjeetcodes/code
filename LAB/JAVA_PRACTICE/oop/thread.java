class Multi extends Thread
{  
public void run()
{  

for(int i=0;i<10;i++)
{
    try
    {
        Thread.sleep(1000);
    }
    catch(Exception e)
    {
        e.getMessage();
    }
    Thread.currentThread().setPriority(10);  
    System.out.println("Name of the main thread is : " + Thread.currentThread().getName()); 
System.out.println("Priority of the main thread is : " + Thread.currentThread().getPriority()); 

    System.out.println("HelloJava"); 
}

} 
public static void main(String args[])
{  
Multi t1=new Multi();  
t1.start();
} 
}