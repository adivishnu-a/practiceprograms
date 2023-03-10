public class TryCatchDemo1 {
    public static void main(String args[]){
        try{
            int i=50, j=0;
            int k=i/j;
        }
        catch(Exception e){
            System.out.println(e);
        }
    }
}
