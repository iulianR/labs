/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pb2;

import java.util.Collections;
import java.util.Vector;

/**
 *
 * @author master
 */
public class SortedVector extends Vector {
    public void addElement(Object o) {
        super.add(o);
        Collections.sort(this);
    }
    
    public void insertElementAt(Object o, int position) {
        super.insertElementAt(o, position);
        Collections.sort(this);
    }
    
    public static void main(String args[]) {
        // set, setElementAt
        SortedVector v = new SortedVector();
        v.addElement(5); 
        System.out.println(v);
        v.addElement(7);
        System.out.println(v);
        v.addElement(3);
        System.out.println(v);
        v.insertElementAt(7, 2);
        System.out.println(v);
        v.insertElementAt(1, 3);
        System.out.println(v);
        v.insertElementAt(2, 5);
        System.out.println(v);
    }
}
