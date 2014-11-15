/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pb5b;

import java.util.Enumeration;
import java.util.Hashtable;

/**
 *
 * @author master
 */
public class HSet {
    private Hashtable h;

    public HSet()
    {
        this.h = new Hashtable();
    }

    public boolean contains(int x)
    {
        return this.h.containsValue(x);
    }

    public void add(int x)
    {
        if (!this.contains(x))
            h.put(x, x);
    }

    public int size()
    {
        return h.size();
    }

    public void remove(int x)
    {
        h.remove(x, x);
    }
//
//    @Override
//    public String toString()
//    {
//        String s = "";
//        Enumeration keys = h.keys();
//        while (keys.hasMoreElements())
//                s += keys.nextElement() + " ";
//        return s;
//    }

    public static void main (String args[])
    {
        HSet h = new HSet();

        h.add(3);
        h.add(4);
        System.out.println(h);
        h.add(5);
        h.add(2);
        System.out.println(h);
        System.out.println("Size = " + h.size());

        h.remove(2);
        System.out.println(h);
        System.out.println("Size = " + h.size());
    }
}