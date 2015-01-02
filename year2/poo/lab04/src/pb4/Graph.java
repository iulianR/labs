/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pb4;

import java.util.Vector;

/**
 *
 * @author master
 */
public class Graph extends Vector {
    
    int n;
    public Graph(int n) {
//        super(n + 1);
        for (int i = 0; i <= n; i++) {
            this.add(new Vector());
        }
        this.n = n;
    }
    
    @Override
    public int size() {
        return n;
    }
    
    public void addArc(int v, int w) {
        if (!isArc(v, w)) {
            ((Vector) elementAt(v)).add(w);
        }
    }
    
    public boolean isArc(int v, int w) {
        if (((Vector) elementAt(v)).contains(w)) {
            return true;
        }
        return false;
    }
    
    public String toString() {
        String result = "";
        for (int i = 1; i <= size(); i++) {
            result += this.elementAt(i) + "\n";
        }
        return result;
    }
    
    public int gradExt(int n) {
        return ((Vector)this.get(n)).size();
    }
    
    public int gradInt(int n) {
        int grad = 0;
        for (int i = 1; i <= size(); i++) {
            if (((Vector) elementAt(i)).contains(n)) {
                grad++;
            }
        }
        return grad;
    }
    
    public static void main(String args[]) {
        Graph g = new Graph(5);
        g.addArc(1, 5);
        g.addArc(3, 5);
        g.addArc(5, 2);
        g.addArc(3, 4);
        System.out.println(g);
        System.out.println ("Grad exterior " + g.gradExt(3));
        System.out.println ("Grad interior " + g.gradInt(5));
    }
}
