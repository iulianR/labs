package pb1;


public class Problem1 {
    
    static String s1, s2;
    static int index, count;
        
    public static void main(String args[]) {
        s1 = "si";
        s2 = "sir1 si cu sir2 fac un sir3";
        
        count = 0;
        index = s2.indexOf(s1, 0);
        while (index != -1) {
            count++;
            index = s2.indexOf(s1, index + 1);
        }
        System.out.println("Rezultat " + count);
    }
}
