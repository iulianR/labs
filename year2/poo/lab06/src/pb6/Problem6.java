/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pb6;

import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.Comparator;

/**
 *
 * @author master
 */
public class Problem6 {
    
    public static void tabsort(final Object[][] a, final int c) {
        Arrays.sort(a, new Comparator(){
                    @Override
                    public int compare(Object o1, Object o2){
                        String[] v1 = (String[])o1;
                        String[] v2 = (String[])o2;
                        return v1[c].compareTo(v2[c]);
                    }   
        });
    }
    
    public static void print(Object a[][]) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                System.out.print(a[i][j] + " ");
            }
            System.out.println();
        }
    }
    
    public static void main(String[] args) {
        String[][] a = {
            {"ana", "are", "mere"},
            {"irina", "cumpara", "pere"},
            {"mihai", "vinde", "mure"}
        };
        
        for (int i = 0; i < 3; i++) {
            System.out.println("\nSortare după coloana " + i);
            tabsort(a, i);
            print(a);
        }
    }
}
