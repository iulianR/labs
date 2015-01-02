/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pb2;

/**
 *
 * @author master
 */
public class Pair {
    Object o1, o2;

    Pair(Object o1, Object o2) {
        this.o1 = o1;
        this.o2 = o2;
    }
    
    @Override
    public boolean equals(Object o){
        Pair p = (Pair) o;
        return p.o1.equals(o1) && p.o2.equals(o2);
    }
    
    public String toString() {
        return o1 + " " + o2;
    }
}
