/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pb2;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.RandomAccessFile;
import java.util.ArrayList;
import java.util.Set;

/**
 *
 * @author master
 */
public class ArraySet extends ArrayList implements Set {
    
    @Override
    public boolean add(Object o) {
        if (this.contains(o))
            return false;
        
        return super.add(o);
    }
    
    @Override
    public void add(int i, Object o) {
        if (!this.contains(o))
            super.add(i, o);
    }
    
    public static void main(String[] args) throws FileNotFoundException, IOException {
        ArraySet a = new ArraySet();
        
        RandomAccessFile raf = new RandomAccessFile("test.txt", "r");
        
        String s = raf.readLine();
        String[] words = s.split(" ");
        
        for (String w : words)
            a.add(w);
        
        System.out.println(a);
    }
}
