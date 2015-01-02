/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pb1;

import java.io.File;
import java.io.IOException;
import java.util.Collection;
import java.util.HashMap;
import java.util.TreeMap;

/**
 *
 * @author master
 */
public class Problem1 {
    
    public static void main(String[] args) throws IOException {
        File file = new File(".");
        File[] files = file.listFiles();
        
        HashMap hm = new HashMap();
        TreeMap tm = new TreeMap();
        
        for (File f : files) {
            if (!f.isDirectory()) {
                hm.put(f.getName(), f.length());
                tm.put(f.getName(), f.length());
            }
        }
        
        System.out.println("HashMap:");
        System.out.println(hm);
//        Collection.toArray(hm);
        
        System.out.println("TreeMap:");
        System.out.println(tm);
    }
}
