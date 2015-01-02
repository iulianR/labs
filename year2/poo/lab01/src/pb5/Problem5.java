package pb5;

import static java.lang.Math.pow;


public class Problem5 {

    static int power(int base, int exponent) {
        if (exponent == 0)
            return 1;
        return base * power (base, exponent - 1);
    }

    public static void main(String args[]) {
        System.out.println(power(6, 2) + " " + pow(6, 2));
    }
}

