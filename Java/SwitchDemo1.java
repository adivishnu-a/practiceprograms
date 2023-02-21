public class SwitchDemo1
{ 
    public static void main(String args[]) 
    { 
        int a=5; 
        a+=6; 
        switch(a-1){
            case 5:
            System.out.println("10"); 
            case 10:
            System.out.println("15"); 
            System.out.println(((a%2==0)?"even":"odd")); 
            default: 
            System.out.println(a%2); 
        } 
    }
}
