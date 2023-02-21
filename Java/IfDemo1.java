public class IfDemo1 
{
    public static void main(String args[]) {
        int a=10,b=151,c=5,d=100; 
        if(a==10) 
        {
            if(b<20) a=b; 
            if(c>100) c=d; 
            else a=c; 
        } 
        else a=d; 
        System.out.println(a); 
    }
}
