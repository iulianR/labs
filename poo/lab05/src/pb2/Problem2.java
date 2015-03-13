/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pb2;

import java.io.FileReader;
import java.io.IOException;
import java.io.LineNumberReader;
import java.util.StringTokenizer;

/**
 *
 * @author master
 */
public class Problem2 {
    static int getWordsInString(String s) {
        StringTokenizer st = new StringTokenizer(s, " ");
        int count = 0;
        while (st.hasMoreTokens()) {
            String token = st.nextToken();
            count++;
        }
        
        return count;
    }
    
    public static void main(String args[]) throws IOException {
        LineNumberReader lnr = new LineNumberReader(new FileReader("text"));
        String s;
        int wordsCount = 0;
        int lineNumber;
        while ((s = lnr.readLine()) != null) {
            wordsCount += getWordsInString(s);
        }
        
        lineNumber = lnr.getLineNumber();
        lnr.close();
        
        System.out.println(lineNumber + " " + wordsCount);
    }
}
