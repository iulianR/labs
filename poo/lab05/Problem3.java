/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pb3;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

/**
 *
 * @author master
 */
public class Problem3 {
    public static void main(String args[]) throws IOException {
        FileReader fr = new FileReader("text");
        FileWriter fw = new FileWriter("pb3.out");
        char c;
        while ((c = (char) fr.read()) != (char) -1) {
            fw.write(Character.toUpperCase(c));
        }
        fr.close();
        fw.close();
    }
}
