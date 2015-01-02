/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pb1;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.RandomAccessFile;
import java.util.Arrays;
import java.util.Comparator;
import java.util.TreeSet;

/**
 *
 * @author master
 */
public class Problem1 {
    
    public static void main(String[] args) throws FileNotFoundException, IOException {
        RandomAccessFile raf = new RandomAccessFile("test.txt", "r");
        
        String s = raf.readLine();
        String[] words = s.split(" ");
        
        // No comparator
        TreeSet<String> ts = new TreeSet<>();
        ts.addAll(Arrays.asList(words));
        
        System.out.println("No comparator:");
        System.out.println(ts);
        
        // Comparator
        TreeSet<String> tc = new TreeSet<>(new Comparator<String> () {
            @Override
            public int compare(String s1, String s2) {
                return s2.compareTo(s1);
            } 
        });
        tc.addAll(Arrays.asList(words));
        System.out.println("Comparator:");
        System.out.println(tc);
    }
}
