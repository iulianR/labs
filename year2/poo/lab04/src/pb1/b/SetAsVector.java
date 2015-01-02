/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pb1.b;

import java.util.Vector;

/**
 *
 * @author master
 */
public class SetAsVector {
    Vector v;
    
    public SetAsVector() {
        v = new Vector();
    }
    
    public boolean add(Object o) {
        if (v.contains(o)) {
            System.out.println("Elementul există în mulțime");
            return false;
        }
        return v.add(o);
    }
    
    public boolean remove(Object o) {
        return v.remove(o);
    }
    
    public boolean contains(Object o) {
        return v.contains(o);
    }
    
    public String toString() {
        return v.toString();
    }
    
    public static void main(String args[]) {
        SetAsVector v = new SetAsVector();
        v.add("Miruna"); v.add("are"); v.add("pere"); v.add("pere");
        System.out.println(v);
        v.remove("pere");
        System.out.println(v);
    }
}
