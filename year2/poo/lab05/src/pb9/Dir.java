/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pb9;

import java.io.*;
import java.util.*;

/**
 *
 * @author master
 */
public class Dir{
    public static void main (String args[]) throws IOException {
        String dname =".";
        if (args.length ==1)
            dname=args[0];
        Dir d= new Dir();
        System.out.println("Introduceti sirul cautat");
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        System.out.println("Sirul " + str + " se gaseste in urmatoarele fisiere:");
        d.dirlist(new File(dname)," ",str);
    }
    
    public void dirlist (File d, String sp, String str) throws IOException {
        String [] files=d.list();
        if (files == null ) return;
        String path =d.getAbsolutePath();
        for(int i = 0 ;i < files.length; i++){
            File f = new File(d+"/"+files[i]);
            if (f.isDirectory()) {
            dirlist (f,sp + " ", str);
            }
            else {
                BufferedReader br = new BufferedReader(new FileReader(f));
                String line;
                while (( line = br.readLine()) != null){
                    int indexfound = line.indexOf(str);
                    if (indexfound > -1) {
                        System.out.println (sp + path + "/" + files[i]);
                    }
                }
            br.close();
            }
        }
    }
}