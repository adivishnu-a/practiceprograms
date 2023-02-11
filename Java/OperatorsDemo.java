public class OperatorsDemo {
    public static void main(String[] args) {
      int a = 10;
      int b = 20;
      int c = 30;
      System.out.println("a = "+a+"\tb = "+b+"\tc = "+c+"\n");
  
      // Arithmetic Operators
      System.out.println("Arithmetic Operators:");
      System.out.println("a + b = " + (a + b));
      System.out.println("a - b = " + (a - b));
      System.out.println("a * b = " + (a * b));
      System.out.println("b / a = " + (b / a));
      System.out.println("b % a = " + (b % a));
      System.out.println();
  
      // Bitwise Operators
      System.out.println("Bitwise Operators:");
      System.out.println("a & b = " + (a & b));
      System.out.println("a | b = " + (a | b));
      System.out.println("a ^ b = " + (a ^ b));
      System.out.println("c >> 2 = " + (c >> 2));
      System.out.println("c << 2 = " + (c << 2));
      System.out.println("~c = " + (~c));
      System.out.println();
  
      // Relational Operators
      System.out.println("Relational Operators:");
      System.out.println("a < b is " + (a < b));
      System.out.println("a > b is " + (a > b));
      System.out.println("a <= b is " + (a <= b));
      System.out.println("a >= b is " + (a >= b));
      System.out.println("a == b is " + (a == b));
      System.out.println("a != b is " + (a != b));
      System.out.println();
  
      // Logical Operators
      System.out.println("Logical Operators:");
      System.out.println("(a < b) AND (c > b) is " + ((a < b) && (c > b)));
      System.out.println("(a < b) OR (c > b) is " + ((a < b) || (c > b)));
      System.out.println("NOT(a < b) is " + (!(a < b)));
      System.out.println();
  
      // Conditional Operators
      System.out.println("Conditional Operator:");
      System.out.println("Greatest of a and b = " + (a > b ? a : b));
      int max = ((a > b) ? (a > c ? a : c):(b > c ? b : c));
      System.out.println("Greatest of three numbers = " + max);
    }
  }
  