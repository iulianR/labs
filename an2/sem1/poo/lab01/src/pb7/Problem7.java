package pb7;

import pb6.Problem6;

public class Problem7 {
    
    final static int n = 20;
    
    public static void main(String args[]) {
        for (int i = 0; i <= n; i += 2) {
            for (int j = 0; j <= i; j++) {
                if (Problem6.isPrime(j)) {
                    if (Problem6.isPrime(i - j)) {
                        System.out.println(i + " = " + (i - j) + " + " + j);
                    }
                }
            }
        }
    }
}
