/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pb11;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.StringTokenizer;

/**
 *
 * @author master
 */
public class Problem11 {
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("Problem3.java"));
        String s, words = "", numbers = "", characters = "";
        while ((s = br.readLine()) != null) {
            StringTokenizer st;
            st = new StringTokenizer(s, "0123456789 , .:,{}\n []=-+_~!@#$%^&*()");
            while (st.hasMoreTokens()) {
                words += st.nextToken() + " ";
            }
            String c = "";
            for (int i = 65; i <= 90; i++) c += (char) i;
            for (int i = 97; i <= 122; i++) c += (char) i;
            StringTokenizer st1 = new StringTokenizer(s, ",.;:!@#$%^&*()~\n" + c);
            while (st1.hasMoreTokens()) {
                numbers += st1.nextToken();
            }
            String delim = c;
            for (int i = 0; i <= 9; i++) characters += i;
            
            StringTokenizer st2 = new StringTokenizer(s, characters);
            while (st2.hasMoreTokens()) {
                characters += st2.nextToken();
            }
        }
        System.out.println("Words = " + words);
        System.out.println("Numbers = " + numbers);
        System.out.println("Special characters = " + characters);
    }
}
