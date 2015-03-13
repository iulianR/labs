package pb4;

import java.util.StringTokenizer;

/**
 *
 * @author master
 */
public class Problem4 {
    
    static String s;
    static StringTokenizer st;
    public static void main(String args[]) {
        st = new StringTokenizer("this.is, a:very ; long:test!.@", " ,.;:");
        while (st.hasMoreTokens()) {
            System.out.println(st.nextToken());
        }
    }
}
