public class FinalExample {

    // final variable
    public static final int MAX_VALUE = 100;

    // final method
    public final void display() {
        System.out.println("Displaying...");
    }

    public static void main(String[] args) {
        FinalExample obj = new FinalExample();
        obj.display();
        System.out.println("MAX_VALUE = " + MAX_VALUE);
    }
}