/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pb2;

import java.util.Arrays;

/**
 *
 * @author master
 */
public class Stiva {
    
    int a[];
    int top;
    int size;
    
    public Stiva() {
        a = new int[100];
        top = 0;
        this.size = 100;
    }
    
    public Stiva(int size) {
        a = new int[size];
        top = 0;
        this.size = size;
    }
    
    void push(int x) {
        if (top == size) {
            a = Arrays.copyOf(a, size * 2);
        } else {
            a[top++] = x;
        }
    }
    
    int pop() {
        if (top == 0) {
            return 0;
        } else { 
            int popped = a[top-1];
            a[top--] = 0;
            return popped;
        }
    }
    
    boolean isEmpty() {
        return !(top == 0);
    }
    
    @Override
    public String toString() {
        if (top == 0) {
            return "Stiva este goala";
        }
        String result = "";
        for (int i = 0; i < top; i++) {
            result += this.a[i] + " ";
        }
        
        return result;
    }
    
    public static void main(String args[]) {
        Stiva st = new Stiva(10);
        System.out.println(st.isEmpty());
        st.push(2); st.push(3); st.push(5);
        System.out.println(st);
        st.pop();
        System.out.println(st);
        System.out.println(st.isEmpty());
    }
}
