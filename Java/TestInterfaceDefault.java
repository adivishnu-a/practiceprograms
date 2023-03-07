interface Draw
{
    void draw();
    default void msg()
    {
        System.out.println("Default");
    }
    static int cube(int x){return x*x*x;}
} 
class Shape implements Draw
{
    public void draw()
    {
        System.out.println("Drawing a shape");
    }
}
class TestInterfaceDefault 
{
    public static void main(String[] args)
    {
        Draw d = new Shape();
        d.draw();
        d.msg();
        System.out.println(Draw.cube(3));
    }  
}