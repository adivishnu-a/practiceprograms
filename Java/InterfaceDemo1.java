interface Print
{
    void print();
}
interface Showable extends Print
{
    void show();
}
class InterfaceDemo1 implements Showable 
{
    public void print()
    {
        System.out.println("Hello");
    }     
    public void show()
    {
        System.out.println("Po ra HOWLE");
    }
    public static void main(String[] args)
    {
        InterfaceDemo1 obj1 = new InterfaceDemo1();
        obj1.print();
        obj1.show();
    }
}