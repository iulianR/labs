package pb3;

/**
 *
 * @author master
 */
public class Problem3 {
   
    static String s;
    static int i, j;
    public static void main(String args[]){
        s = "The night is full of terrors";
        i = -1; j = s.indexOf(" ");
        while (j != -1) {
            System.out.println(s.substring(i + 1, j));
            i = j;
            j = s.indexOf(" ", j + 1);
        }
        System.out.println(s.substring(i + 1, s.length()));
    }
}
