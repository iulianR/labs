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
class Comparator2 implements Comparator {

    @Override
    public int compare(Object o1, Object o2) {
        Pair p1 = (Pair) o1;
        Pair p2 = (Pair) o2;
        return ((int) p1.o2 - (int) p2.o2);
    }   
}
