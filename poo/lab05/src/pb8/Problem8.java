/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pb8;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.RandomAccessFile;

/**
 *
 * @author master
 */
public class Problem8 {
    public static void main(String args[]) throws FileNotFoundException, IOException {
        RandomAccessFile raf = new RandomAccessFile("text", "r");
        byte[] arr = new byte[(int)raf.length()];
        raf.readFully(arr);
        String s = new String(arr);
        System.out.println(s);
        
        raf.close();
        
        BufferedReader br = new BufferedReader(new FileReader("text"));
        String sc;
        String result = "";
        while((sc = br.readLine()) != null) {
            result += sc;
        }
        System.out.println("Result = " + result);
        br.close();
    }
}
