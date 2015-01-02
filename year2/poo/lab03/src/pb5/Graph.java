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
public class Graph {
    
    private boolean a[][];
    private int n;
    
    public Graph(int n) {
        this.a = new boolean[n + 1][n + 1];
        this.n = n;
    }
    
    int size() {
        return n;
    }
    
    void addArc(int v, int w) {
        a[v][w] = true;
        a[w][v] = true;
    }
    
    boolean isArc(int v, int w) {
        return a[v][w];
    }
    
    void print() {
        for (int i = 1; i <= size(); i++) {
            for (int j = 1; j <= size(); j++) {
                if (a[i][j] == true) {
                    System.out.print(1);
                }
                else {
                    System.out.print(0);
                }
                System.out.print(" ");
            }
            System.out.println();
        }
    }
    
    public void dfs(int v, boolean vazut[]) {
        int w;
        vazut[v] = true;
        for (w = 1; w <= size(); w++) {
            if (isArc(v, w) && !vazut[w]) {
                System.out.println (v + "-" + w);
                dfs (w, vazut);
            }
        }
    }
    
    public static void main(String args[]) {
        Graph g = new Graph(5);
        
        g.addArc(2, 3); g.addArc(1, 4);
        g.addArc(4, 1); g.addArc(2, 4);
        
        g.print();
        
        System.out.println();
        boolean vazut[] = new boolean[g.size()];
        g.dfs(1, vazut);
    }
}
