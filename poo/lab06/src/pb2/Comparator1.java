/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pb2;

import java.util.Comparator;

/**
 *
 * @author master
 */
class Comparator1 implements Comparator {

    @Override
    public int compare(Object o1, Object o2) {
        Pair p1 = (Pair) o1;
        Pair p2 = (Pair) o2;
        return p1.o1.toString().compareTo(p2.o1.toString());
    }   
}