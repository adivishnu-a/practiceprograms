public class CommandLine1 {
    public static void main(String args[]){
        String name=args[0];
        String rno=args[1];
        float fee1=Float.parseFloat(args[2]);
        float fee2=Float.parseFloat(args[3]);
        float total=fee1+fee2;
        System.out.println("Student Name : "+name);
        System.out.println("Student Roll No : "+rno);
        System.out.println("First Year Fee : "+fee1);
        System.out.println("Second Year Fee : "+fee2);
        System.out.println("Total Fee : "+total);
    }
}