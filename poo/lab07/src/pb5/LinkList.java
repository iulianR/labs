/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pb5;

import java.util.AbstractList;
import java.util.Collections;
import java.util.Iterator;

/**
 *
 * @author master
 */
public class LinkList extends AbstractList {
    private Node head;
    private int size;
    
    public LinkList() {
        this.head = null;
        this.size = 0;
    }
    	
    @Override
    public Iterator iterator() {
        return new ListIterator(this.head, this.size);
    }
    
    @Override
    public boolean add(Object o) {
        Node newNode = new Node(o);
        
        if (head == null)
            head = newNode;
        else {
            Node temp = this.head;
            while (temp.next != null) {
                temp = temp.next;
            }
            temp.next = newNode;
            this.size++;
        }
        return true;
    }
    
    @Override
    public Object get(int index) {
        Node temp = this.head.next;
        for (int i = 0; i < index; i++)
                temp = temp.next;
        return temp.data;
    }

    @Override
    public Object set(int index, Object o) {
        Node temp = this.head.next;
        for (int i = 0; i < index; i++)
                temp = temp.next;
        temp.data = o;
        return temp.data;
    }

    @Override
    public int size() {
        return this.size;
    }
    
    public static void main(String[] args) {
        LinkList l = new LinkList();
        l.add(3); l.add(4); l.add(5); l.add(7); l.add(8);
        
        System.out.println("Print with iterator:");
        for (Iterator it = l.iterator(); it.hasNext();)
            System.out.print(it.next() + " ");
        
        System.out.println("\n Print with get:");
            for (int i = 0; i < l.size; i++)
                System.out.print(l.get(i) + " ");
            System.out.println();
            
        Collections.sort(l);
        System.out.println("Sortare cu Collections.sort:");
        System.out.println(l);
        
        System.out.println("Set everything to 'empty'");
        for (int i = 0; i < l.size; i++)
            l.set(i, "empty");
        System.out.println(l);
    }
}
