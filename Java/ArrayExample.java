public class ArrayExample {
    public static void main(String[] args) {
        // Single-Dimensional Array
        int[] myArray = new int[5];
        myArray[0] = 10;
        myArray[1] = 20;
        myArray[2] = 30;
        myArray[3] = 40;
        myArray[4] = 50;
        System.out.println("Single-Dimensional Array:");
        for (int i = 0; i < myArray.length; i++) {
            System.out.print(myArray[i] + " ");
        }
        System.out.println();

        // Multi-Dimensional Array
        int[][] myMultiArray = new int[3][4];
        myMultiArray[0][0] = 1;
        myMultiArray[0][1] = 2;
        myMultiArray[0][2] = 3;
        myMultiArray[0][3] = 4;
        myMultiArray[1][0] = 5;
        myMultiArray[1][1] = 6;
        myMultiArray[1][2] = 7;
        myMultiArray[1][3] = 8;
        myMultiArray[2][0] = 9;
        myMultiArray[2][1] = 10;
        myMultiArray[2][2] = 11;
        myMultiArray[2][3] = 12;
        System.out.println("Multi-Dimensional Array:");
        for (int i = 0; i < myMultiArray.length; i++) {
            for (int j = 0; j < myMultiArray[i].length; j++) {
                System.out.print(myMultiArray[i][j] + " ");
            }
            System.out.println();
        }

        // Jagged Array
        int[][] myJaggedArray = new int[3][];
        myJaggedArray[0] = new int[]{1, 2};
        myJaggedArray[1] = new int[]{3, 4, 5};
        myJaggedArray[2] = new int[]{6, 7, 8, 9};
        System.out.println("Jagged Array:");
        for (int i = 0; i < myJaggedArray.length; i++) {
            for (int j = 0; j < myJaggedArray[i].length; j++) {
                System.out.print(myJaggedArray[i][j] + " ");
            }
            System.out.println();
        }
    }
}

