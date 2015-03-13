/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pb5;

/**
 *
 * @author master
 */
public class Node {
    public Object data;
    public Node next;
    
    public Node(Object data) {
        this.data = data;
        this.next = null;
    }
}
