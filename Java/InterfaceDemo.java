interface one
{
    public void show();
}
class demo extends InterfaceDemo implements one
{
    public void show()
    {
        System.out.println("This is a DEMO");
    }
}
class InterfaceDemo 
{
    public static void main(String[] args)
    {
        demo obj1 = new demo();
        obj1.show();
    }
}