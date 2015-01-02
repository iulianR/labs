/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pb4;

/**
 *
 * @author master
 */
public class IntSet {
    
    int a[];
    int pos;
    
    public IntSet(int size) {
        this.a = new int[size];
        this.pos = 0;
    }
    
    void add(int x) {
        
        if (contains(x)) {
            System.out.println("Elementul există deja în mulțime");
            return;
        }
        this.a[pos++] = x;
    }
    
    boolean contains(int x) {
        for (int i = 0; i < pos; i++) {
            if (a[i] == x) {
                return true;
            }
        }
        return false;
    }
    
    @Override
    public String toString() {
        String result = "";
        for (int i = 0; i < pos; i++) {
            result += a[i] + " ";
        }
        
        return result;
    }
    
    public static void main(String args[]) {
        IntSet set = new IntSet(20);
        System.out.println(set);
        set.add(4); set.add(6);
        System.out.println(set);
        set.add(4); set.add(6);
        System.out.println(set.contains(4));
    }
}
