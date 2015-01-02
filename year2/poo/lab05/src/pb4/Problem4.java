/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pb4;

import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.io.RandomAccessFile;

/**
 *
 * @author master
 */
public class Problem4 {
    public static void main(String args[]) throws FileNotFoundException, IOException {
        PrintStream ps = new PrintStream( new FileOutputStream("4ps.out"));
        PrintWriter pw = new PrintWriter( new FileWriter("4pw.out"));
        for (int i = 0; i < 100; i++) {
            ps.print(i);
        }
        ps.close();
        for (int i = 0; i < 100; i++) {
            pw.print(i);
        }
        pw.close();
        
        RandomAccessFile raf = new RandomAccessFile("4ps.out", "r");
        int i;
        while ((i = raf.read()) != -1) {
            System.out.println(i);
        }
    }
}
