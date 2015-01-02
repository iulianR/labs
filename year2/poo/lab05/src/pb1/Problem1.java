/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pb1;

import java.io.FileReader;
import java.io.IOException;
import java.io.LineNumberReader;

/**
 *
 * @author master
 */
public class Problem1 {
    public static void main (String argv[]) throws IOException {
        LineNumberReader lnr = new LineNumberReader(new FileReader(argv[0]));
        String s;
        int line;
        while ((s = lnr.readLine()) != null) {
            line = lnr.getLineNumber();
            System.out.println(line + " " + s);
        }
        lnr.close();
    }
}
