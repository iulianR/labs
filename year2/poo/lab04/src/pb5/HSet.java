/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pb5;

import java.util.Enumeration;
import java.util.Hashtable;

/**
 *
 * @author master
 */
public class HSet extends Hashtable
{
    public boolean contains(int x)
    {
        return containsValue(x);
    }

    public void add(int x)
    {
        if (!contains(x))
            put(x, x);
    }

    @Override
    public int size()
    {
        return super.size();
    }

    public static void main (String args[])
    {
        HSet h = new HSet();

        h.add(4);
        h.add(2);
        System.out.println(h);
        h.add(3);
        h.add(2);
        System.out.println(h);
        System.out.println("size = " + h.size());
    }
}