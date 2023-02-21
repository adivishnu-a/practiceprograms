import java.util.Scanner;
public class ScannerDemo {
    public static void main(String args[]){
        Scanner myObj = new Scanner(System.in);
        System.out.print("Enter Username : ");
        String userName = myObj.nextLine();
        System.out.println("Username is : "+userName);
        myObj.close();
    }
}
