/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pb4;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.LineNumberReader;
import java.util.Arrays;
import java.util.Comparator;

/**
 *
 * @author master
 */
public class Problem4 {
    public static void main(String[] args) throws FileNotFoundException, IOException {
        FileReader fr = new FileReader(args[0]);
        LineNumberReader lnr = new LineNumberReader(fr);
        
        String[] lines = new String[3];
        String line;
        
        int i = 0;
        while ((line = lnr.readLine()) != null) {
            System.out.println(line);
            lines[i++] = line;
        }
        System.out.println();
        final int word_count = Integer.parseInt(args[1]);
        
        Arrays.sort(lines, new Comparator() {
            @Override
            public int compare(Object o1, Object o2){
                String[] s1 = ((String) o1).split(" ");
                String[] s2 = ((String) o2).split(" ");
                
                return s1[word_count].compareTo(s2[word_count]);
            }
        });
        
        for (String l : lines) {
            System.out.println(l);
        }
        fr.close();
        lnr.close();
    }
}
