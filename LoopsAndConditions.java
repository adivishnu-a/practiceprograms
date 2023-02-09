class LoopsAndConditions {
    public static void main(String[] args) {
      // For loop
      for (int i = 1; i <=5; i++) {
        System.out.println("For loop iteration: " + i);
      }
  
      // While loop
      int n = 10;
      while (n > 5) {
        System.out.println("While loop iteration: " + n);
        n--;
      }

      // Conditional statement (if-else)
      int num = 186;
      if (num > 0) {
        System.out.println(num + " is positive");
      } 
	else if (num < 0) {
        System.out.println(num + " is negative");
      } 
	else {
        System.out.println(num + " is zero");
      }
    }
  }
  