package pb5;


public class Problem5 {
    
    static String s, s1, s2, smallString, largeString;
    static int index;
    
    static void iterative() {
        index = 0;
        for (int i = 0; i < smallString.length(); i++) {
            if (!largeString.startsWith(smallString.substring(0, i)))
                break;
            index++;
        }
        System.out.println("Rezultat metoda iterativa: " + s1.substring(0, index - 1));
    }
    
    static int recursive(int i) {
        if (i == smallString.length())
            return 0;
        if (!largeString.startsWith(smallString.substring(0, i)))
            return 0;
        return 1 + recursive(i + 1);
    }
    
    public static void main(String args[]) {
        s1 = "obiects";
        s2 = "obiectiv";
        
        if (s1.length() > s2.length()) {
            smallString = s2; largeString = s1;
        } else {
            smallString = s1; largeString = s2;
        }
        
        iterative();
        index = recursive(0);
        System.out.println("Rezultat metoda recursivă: " + s1.substring(0, index - 1));
    }
}
