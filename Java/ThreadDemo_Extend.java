class T1 extends Thread
{
    public void run()
    {
        System.out.println("This code is running in a thread");
    }
}

public class ThreadDemo_Extend
{
    public static void main(String args[])
    {
        T1 obj=new T1();
        obj.start();
        System.out.println("This code is running outside a thread");
    }
}