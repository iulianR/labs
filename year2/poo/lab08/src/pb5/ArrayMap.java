/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pb5;

import java.util.HashSet;
import java.util.Iterator;
import java.util.Map;
import java.util.Set;
import java.util.Vector;

/**
 *
 * @author master
 */
public class ArrayMap {
    
    Vector keys = new Vector();
    Vector values = new Vector();
    
    public ArrayMap() {
        
    }
    
    public boolean contains(Object key) {
        return keys.contains(key);
    }
    
    public Object put(Object key, Object value) {
        Object oldValue = value;
        
        if (this.contains(key)) { 
            values.set(values.indexOf(value), value);
        } else {
            keys.add(key);
            values.add(value);
        }
        
        return oldValue;
    }
    
    public Object get(Object key) {
        if (!contains(key))
            return null;
       
        return values.get(keys.indexOf(key));
    }
    
    public HashSet keySet() {
        return new HashSet(keys);
    }
    
    @Override
    public String toString() {
        String result = "";
        for (Object o : keys) {
            result += "{" + o + ", " + this.get(o) + "}\n";
        }
        
        return result;
    }
    
    public static void main(String[] args) {
        ArrayMap am = new ArrayMap();
        
        am.put("ana", "2");
        am.put("mere", "2");
        am.put("pere", "1");
        am.put("are", "2");
//        Iterator it = am.keySet().iterator();
//        while (it.hasNext()) {
//            Map.Entry pair = (Map.Entry) it.next();
//            System.out.println(pair);
//        }
        System.out.println(am);
    }
}
