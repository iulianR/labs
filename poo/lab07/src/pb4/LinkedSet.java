/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pb4;

import java.util.AbstractSet;
import java.util.Iterator;

/**
 *
 * @author master
 */
public class LinkedSet extends AbstractSet {
    Node head;
    private int size;

    public LinkedSet()
    {
        this.head = new Node(null);
        this.size = 0;
    }

    @Override
    public Iterator iterator() {
        return new ListIterator(this.head, this.size);
    }

    @Override
    public int size() {
        return this.size;
    }

    @Override
    public boolean add(Object o)
    {
        Node temp = this.head;
        while (temp.next != null) {
            temp = temp.next;
            if (temp.data.equals(o))
                return false;
        }
        Node nou = new Node(o);
        temp.next = nou;
        this.size++;
        
        return true;
    }

    public static void main(String argsp[])
    {
        LinkedSet l = new LinkedSet();

        l.add(4); l.add(1); l.add(5);
        l.add(4); l.add(5); l.add(3);

        for (Iterator it = l.iterator(); it.hasNext();)
            System.out.print(it.next() + " ");
    }
}
