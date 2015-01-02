/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pb2;

import java.util.Collections;
import java.util.Comparator;
import java.util.Vector;

/**
 *
 * @author master
 */
public class SortedVector extends Vector {
    
    Comparator comp;
    
    SortedVector(Comparator comp) {
        this.comp = comp;
    }
    
    @Override
    public boolean add(Object o){
        super.add(o);
        
        Collections.sort(this, comp);
        return true;
    }
        
    public static void main(String[] args) {
       SortedVector v1 = new SortedVector(new Comparator1());
       v1.add(new Pair("Ana", 1));
       v1.add(new Pair("Are", 3));
       v1.add(new Pair("Mere", 2));
       System.out.println(v1);
       
       SortedVector v2 = new SortedVector(new Comparator2());
       v2.add(new Pair("Elena", 5));
       v2.add(new Pair("Are", 7));
       v2.add(new Pair("Pere", 6));
       System.out.println(v2);
    }
}
