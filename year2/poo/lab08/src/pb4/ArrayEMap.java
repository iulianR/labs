/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pb4;

import java.util.AbstractMap;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Set;

/**
 *
 * @author master
 */
public class ArrayEMap extends AbstractMap {
    ArrayList<MEntry> mapArray = new ArrayList<>();

    @Override
    public int size() {
        return this.mapArray.size();
    }
    
    @Override
    public Object put(Object key, Object value) {
        mapArray.add(new MEntry(key, value));
        return key;
    }
    
    @Override
    public Set entrySet() {
        return new HashSet(mapArray);
    }
    
}
