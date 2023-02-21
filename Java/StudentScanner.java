import java.util.Scanner;
public class StudentScanner {
    public static void main(String args[]){
        Scanner myObj = new Scanner(System.in);
        System.out.print("Enter Username : ");
        String stuname = myObj.nextLine();
        System.out.print("Enter Roll No. : ");
        long rno = myObj.nextLong();
        System.out.print("Enter College Fee : ");
        float clgfee = myObj.nextFloat();
        System.out.println("Student name : "+stuname);
        System.out.println("Roll Number  : "+rno);
        System.out.println("College Fee  : "+clgfee);
        myObj.close();
    }
}
