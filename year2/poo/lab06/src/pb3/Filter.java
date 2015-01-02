/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pb3;

import java.io.File;
import java.io.FilenameFilter;
import java.io.IOException;

/**
 *
 * @author master
 */
public class Filter implements FilenameFilter {

    String[] extensions = new String[3];
    
    Filter(String[] extensions) {
        this.extensions = extensions;
    }

    @Override
    public boolean accept(File dir, String name) {
        String lowercaseName = name.toLowerCase();
        
        return lowercaseName.endsWith(extensions[0]) ||
               lowercaseName.endsWith(extensions[1]) ||
               lowercaseName.endsWith(extensions[2]);
    }
    
    public static void main(String[] args) throws IOException {
        String[] extensions = {".java", ".jar", ".class"};
        
        Filter filter = new Filter(extensions);
        
        File file = new File("./src/pb3/test_directory");
        File[] files = file.listFiles(filter);
        for (File f : files) {
            System.out.println(f.getCanonicalPath());
        }
    }
}
