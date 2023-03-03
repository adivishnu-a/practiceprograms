public class ConstructorsDemo {

    // default constructor
    public ConstructorsDemo() {
        System.out.println("Inside default constructor");
    }

    // parameterized constructor
    public ConstructorsDemo(int num) {
        System.out.println("Inside parameterized constructor with num = " + num);
    }

    // copy constructor
    public ConstructorsDemo(ConstructorsDemo obj) {
        System.out.println("Inside copy constructor");
    }

    public static void main(String[] args) {

        // create object using no-arg constructor
        ConstructorsDemo obj1 = new ConstructorsDemo();

        // create object using parameterized constructor
        ConstructorsDemo obj2 = new ConstructorsDemo(10);

        // create object using copy constructor
        ConstructorsDemo obj3 = new ConstructorsDemo(obj1);

    }
}