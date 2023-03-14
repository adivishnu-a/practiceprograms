public class ExcHanDemo {
    public static void main(String args[]){
        try{
            System.out.println("Hi");
            System.out.println(12/0);
            System.out.println("Welcome");
        }
        catch(Exception e){
            System.out.println(e);
        }
        System.out.println("Java Program");
    }
}
