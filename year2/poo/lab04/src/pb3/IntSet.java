/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pb3;

import java.util.BitSet;

/**
 *
 * @author master
 */
public class IntSet {
    BitSet b;
    public IntSet() {
        b = new BitSet();
    }
    
    public IntSet(int n) {
        b = new BitSet(n);
    }
    
    public void add(int x) {
//        if (contains(x)) {
//            System.out.println("Elemntul exista");
//            return;
//        }
        b.set(x, true);
    }
    
    public void remove(int x) {
        b.set(x, false);
    }
    
    public boolean contains(int x) {
        return b.get(x);
    }
    
    @Override
    public String toString() {
        return b.toString();
    }
    
    public static void main(String args[]) {
        IntSet v = new IntSet(10);
        v.add(5);
        System.out.println(v);
        v.add(2);
        System.out.println(v);
        v.add(4);
        System.out.println(v);
        v.add(6);
        System.out.println(v);
        v.remove(4);
        System.out.println(v);
    }
}
