package pb2;


public class Problem2 {
    
    static String s, s1, s2;
    static StringBuffer b;
    static int index;
    public static void main(String args[]) {
        s = "Ana are mere mere";
        s1 = "mere";
        s2 = "pere";
        
        s = s.replace(s1, s2);
        System.out.println(s);
        
        b = new StringBuffer("Ana are mere mere");
        index = b.indexOf(s1);
        while (index != -1) {
            b.replace(index, index + s1.length(), s2);
            index = b.indexOf(s1);
        }
        System.out.println(b);
    }
}
