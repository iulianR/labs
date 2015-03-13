package pb6;

import java.util.Arrays;

/**
 *
 * @author master
 */
public class Problem6 {
    
    static long startCustom, startBuiltin, endCustom, endBuiltin;
    static void print(String[] stringsArray) {
        for (String s : stringsArray) {
            System.out.println(s);
        }
    }
    
    public static String[] build(int n) {
        String[] stringsArray = new String[n];
        
        for (int i = 0; i < n; i++) {
            StringBuilder sb = new StringBuilder();
            for (int j = 0; j < 5; j++) {
                char c = (char) ('a' + Math.random() * 26);
                sb.append(c);
            }
            stringsArray[i] = sb.toString();
        }
        return stringsArray;
    }
    
    static String[] customSort(String[] stringsArray) {
        String temp;
        for (int i = 0; i < stringsArray.length; i++) {
            for (int j = i + 1; j < stringsArray.length; j++) {
                if (stringsArray[j].compareTo(stringsArray[i]) < 0) {
                    temp = stringsArray[i];
                    stringsArray[i] = stringsArray[j];
                    stringsArray[j] = temp;
                }
            }
        }
        return stringsArray;
    }


    public static void main(String args[]) {
        String[] stringsArray = build(1000);
        String[] stringsArray2;
        stringsArray2 = stringsArray.clone();
        String[] customSortedArray;
        System.out.println("Unsorted:");
        print(stringsArray);
        
        System.out.println("\n\nCustom sort");
        startCustom = System.currentTimeMillis();
        customSortedArray = customSort(stringsArray);
  
        endCustom = System.currentTimeMillis();
        print(customSortedArray);
        
        System.out.println("\n\nBuiltin sort");
        startBuiltin = System.currentTimeMillis();
        
        Arrays.sort(stringsArray2);
        endBuiltin = System.currentTimeMillis();
        print(stringsArray2);
        
        System.out.println("Custom sort time: " + (endCustom - startCustom) + "milliseconds");
        System.out.println("Builtin sort time: " + (endBuiltin - startBuiltin) + "milliseconds");
    }
}
