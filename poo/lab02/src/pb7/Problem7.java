package pb7;


public class Problem7 {
    
    static String a[][];
    static int n;
    
    public static void main(String args[]) {
        n = 3;
        a = new String[n][n];
        for (int i = 0; i < n; i++) {
            a[i] = pb6.Problem6.build(n);
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print(a[i][j] + " ");
            }
            System.out.println();
        }
        sortBy(a, 0);
        System.out.println();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print(a[i][j] + " ");
            }
            System.out.println();
        }
    }
    
    static void sortBy(String a[][], int i) {
        String[] temp = new String[a.length];
        for (int j = 0; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (a[j][i].compareTo(a[k][i]) > 0) {
                    temp = a[j];
                    a[j] = a[k];
                    a[k] = temp;
                }
            }
        }
        
    }
}
