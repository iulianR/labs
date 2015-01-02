/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pb4;

import java.util.Map;

/**
 *
 * @author master
 */
public class MEntry implements Map.Entry {
    private Object key;
    private Object value;

    MEntry(Object key, Object value) {
        this.key = key;
        this.value = value;
    }
    
    @Override
    public Object getKey() {
        return this.key;
    }

    @Override
    public Object getValue() {
        return this.value;
    }

    @Override
    public Object setValue(Object value) {
        this.value = value;
        return this.value;
    }
    
    @Override
    public String toString() {
        String result = "";
        result = "{" + this.getKey() + ", " + this.getValue() + "}";
        
        return result;
    }
    
    public boolean equals(MEntry other) {
        return ((String) this.getKey()).equals((String) other.getKey()) &&
               ((String) this.getValue()).equals((String) other.getValue());
    }
}
