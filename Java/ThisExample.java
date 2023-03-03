public class ThisExample {

    private String name;

    public ThisExample(String name) {
        this.name = name;
    }

    public void display() {
        System.out.println("Name: " + this.name);
    }

    public static void main(String[] args) {
        ThisExample obj = new ThisExample("Adi");
        obj.display();
    }
}