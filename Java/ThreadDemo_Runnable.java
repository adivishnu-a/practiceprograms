class T1 implements Runnable
{
    public void run()
    {
        System.out.println("This code is running in a thread");
    }
}

public class ThreadDemo_Runnable
{
    public static void main(String args[])
    {
        T1 obj=new T1();
        Thread thread=new Thread(obj);
        thread.start();
        System.out.println("This code is running outside a thread");
    }
}