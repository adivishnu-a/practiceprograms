class ZeroException {
    public static void main(String[] args) {
      try {
        // code that may generate an exception
        int divideByZero = 5 / 0;
        System.out.println("This statement will not be executed");
      } catch (ArithmeticException e) {
        // handle the exception
        System.out.println("Division by zero not possible");
      }
    }
  }  