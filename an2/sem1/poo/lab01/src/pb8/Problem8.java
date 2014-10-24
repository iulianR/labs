package pb8;

import static java.util.Arrays.binarySearch;
import static java.util.Arrays.sort;


public class Problem8 {
    
    static int[] arrayOne;
    static double[] arrayTwo;
    
    
    public static void main(String args[]) {
        arrayOne = new int[]{3, 4, 5, 1};
        sort(arrayOne);
        for (int i = 0; i < arrayOne.length; i++) {
            System.out.print(arrayOne[i] + " ");
        }
        System.out.println("");
        int number = 3;
        System.out.println(number + " se găsește pe poziția " +
                binarySearch(arrayOne, number));
        
        
        arrayTwo = new double[30];
        for (int i = 0; i < 30; i++) {
            arrayTwo[i] = Math.random();
        }
        sort(arrayTwo);
        for (int i = 0; i < arrayTwo.length; i++) {
            System.out.print(arrayTwo[i] + " ");
        }
        System.out.println("");
    }
}
