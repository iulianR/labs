/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pb3;

import java.util.Iterator;
import java.util.LinkedList;
import java.util.Set;

/**
 *
 * @author master
 */
public class LinkedSet extends LinkedList implements Set {
    
    @Override
    public boolean add(Object o) {
        if (this.contains(o)) {
            return false;
        }
        
        return super.add(o);
    }
    
    public static void main(String[] args) {
        LinkedSet ls = new LinkedSet();
        
        ls.add(5); ls.add(6); ls.add(12);
        ls.add(3); ls.add(1); ls.add(10);
        ls.add(1); ls.add(12); ls.add(0);
        
        System.out.println("No iterator:");
        ls.stream().forEach((o) -> {
            System.out.print(o + " ");
        });
        
        System.out.println("\nWith Iterator:");
        for (Iterator it = ls.iterator(); it.hasNext();) {
            System.out.print(it.next() + " ");
        }
        
        System.out.println();
    }
}
