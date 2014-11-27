/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pb6;

import static java.lang.Math.sqrt;

/**
 *
 * @author master
 */
public class Problem6 {
    public static boolean isPrime(int x) {
        if (x == 0 || x == 1) { 
            return false;
        } else {
            for (int i = 2; i < sqrt(x) + 1; i++) {
                if (x % i == 0) {
                    return false;
                }
            }
            return true;
        }
    }
    
    public static void main(String args[]) {
        for (int i = 0; i < 20; i++) {
            if (isPrime(i)) {
                System.out.println(i + " este prim!");
            } else {
                System.out.println(i + " nu este prim!");
            }
        }
    }
}
