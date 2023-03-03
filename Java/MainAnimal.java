class Animal { // Superclass (parent)
  public void animalSound() {
    System.out.println("The animal makes a sound");
  }
}

class Dog extends Animal { // Subclass (child)
  public void animalSound() {
    super.animalSound(); // Call the superclass method
    System.out.println("The dog says: bow wow");
  }
}

public class MainAnimal {
   public static void main(String[] args) {
      Animal myDog = new Dog(); // Create a Dog object
      myDog.animalSound(); // Call the method on the Dog object
   }
}
