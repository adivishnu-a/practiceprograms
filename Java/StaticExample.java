public class StaticExample {

    // static variable
    public static int count = 0;

    // static method
    public static void increment() {
        count++;
        System.out.println("count = " + count);
    }

    public static void main(String[] args) {
        //StaticExample obj = new StaticExample();
        //obj.increment();
        increment();
    }
}
