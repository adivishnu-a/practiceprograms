public class DatatypesDemo {
    public static void main(String[] args) {
      // Declaring and initializing primitive data types
      byte b = 127;
      short s = 32767;
      int i = 2147483647;
      long l = 9223372036854775807L;
      float f = 3.14159f;
      double d = 3.141592653589793238;
      char c = 'A';
      boolean bool = true;
  
      // Printing primitive data types
      System.out.println("byte: " + b);
      System.out.println("short: " + s);
      System.out.println("int: " + i);
      System.out.println("long: " + l);
      System.out.println("float: " + f);
      System.out.println("double: " + d);
      System.out.println("char: " + c);
      System.out.println("boolean: " + bool);
  
      // Declaring and initializing reference data types
      String str = "Hello, world!";
      int[] arr = {1, 2, 3, 4, 5};
      DatatypesDemo obj = new DatatypesDemo();
  
      // Printing reference data types
      System.out.println("String: " + str);
      System.out.println("Array: " + arr[2]);
      System.out.println("Class: " + obj);
    }
  }
  