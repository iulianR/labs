/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pb5;

import java.util.Arrays;
import java.util.Comparator;

/**
 *
 * @author master
 */
public class Problem5 {
    
    public static Object[] descending(Object[] o) {
        Arrays.sort(o, new Comparator(){
            @Override
            public int compare(Object o1, Object o2){
                String s1 = (String) o1;
                String s2 = (String) o2;
                if(s1.compareTo(s2) > 0)
                    return -1;
                else
                    if(s1.compareTo(s2) < 0)
                        return 1;
                return 0;
            }
        });   
        return o;
    }
    
    public static void main(String[] args) {
        Object[] objects = {
            "ana", "alina", "banana", 
        };
        objects = descending(objects);
        for (Object o : objects) {
            System.out.println(o);
        }
    }      
}
