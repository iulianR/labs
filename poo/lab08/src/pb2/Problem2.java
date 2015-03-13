/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pb2;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.RandomAccessFile;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Map;
import java.util.TreeMap;

/**
 *
 * @author master
 */
public class Problem2 {
    
    public static void main(String[] args) throws FileNotFoundException, IOException {
        TreeMap tm = new TreeMap();
    
        // Open file
        RandomAccessFile raf = new RandomAccessFile("./test.txt", "r");
        
        String line;
        int lineNumber = 1;
        
        // Read lines, split and add words to treemap
        while ((line = raf.readLine()) != null) {
            for (String word : line.split(" ")) {
                LinkedList temp;
                temp = tm.containsKey(word) ? (LinkedList) tm.get(word) :new LinkedList();
                temp.add(lineNumber);
                tm.put(word, temp);
            }
            lineNumber++;
        }
        
        // Iterate over and print
        Iterator it = tm.entrySet().iterator();
        while (it.hasNext()) {
            Map.Entry pairs = (Map.Entry) it.next();
            System.out.println(pairs.getKey());
            System.out.println(pairs.getValue());
        }
    }
}
