/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pb1;

import java.util.Vector;

/**
 *
 * @author master
 */
public class SetAsVector extends Vector {
    
    @Override
    public boolean add(Object o) {
        if (contains(o)) {
            System.out.println("Elementul există în mulțime");
            return false;
        }
        return super.add(o);
    }
    
    public static void main(String args[]) {
        SetAsVector v = new SetAsVector();
        v.add("Ana"); v.add("Are"); v.add("Mere"); v.add("Ana");
        System.out.println(v);
        v.remove("Are");
        System.out.println(v);
    }
}
