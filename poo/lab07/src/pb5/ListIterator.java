/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pb5;

import java.util.Iterator;

/**
 *
 * @author master
 */
class ListIterator implements Iterator {

	private Node head;
	private int size;

	public ListIterator(Node head, int size)
	{
            this.head = head;
            this.size = size;
	}

	@Override
	public boolean hasNext()
	{
            return this.size > 0;
	}

	@Override
	public Object next()
	{
            this.size--;
            this.head = this.head.next;
            return this.head.data;
	}
}
