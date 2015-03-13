/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pb3;

import java.awt.Dimension;
import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import javax.swing.BoxLayout;
import javax.swing.JCheckBox;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JTextField;

/**
 *
 * @author master
 */
public class Problem3 extends JFrame implements ItemListener {

    JTextField jtf;
    JTextField jtf2;
    JCheckBox[] boxes;
    final String abc = "ABC";
    Map<String, Boolean> checkedMap;

    public Problem3() {
        this.setPreferredSize(new Dimension(300, 200));
        this.setVisible(true);
        
        JPanel jp = (JPanel) this.getContentPane();
        this.setLayout(new BoxLayout(jp, BoxLayout.Y_AXIS));

        checkedMap = new HashMap<>();
        checkedMap.put("A", false);
        checkedMap.put("B", false);
        checkedMap.put("C", false);

        jtf = new JTextField();
        jtf.setText("Ce alegeți?");
        jtf.setEditable(false);
        jp.add(jtf);

        boxes = new JCheckBox[3];
        for (int i = 0; i < boxes.length; i++) {
            char c = abc.charAt(i);
            boxes[i] = new JCheckBox("" + c);
            boxes[i].setName("" + c);
            boxes[i].addItemListener(this);
            jp.add(boxes[i]);
        }

        jtf2 = new JTextField();
        jtf2.setEditable(false);
        jtf2.setVisible(true);
        jp.add(jtf2);

        this.pack();
        this.setDefaultCloseOperation(EXIT_ON_CLOSE);
    }

    @Override
    public void itemStateChanged(ItemEvent e) {
        JCheckBox checked = (JCheckBox) e.getSource();
        String name = checked.getName();
        checkedMap.put(name, !checkedMap.get(name));
        jtf2.setText(stringifyMap(checkedMap));
    }

    public static String stringifyMap(Map map) {
        String result = "";

        Iterator it = map.entrySet().iterator();
        while (it.hasNext()) {
            Map.Entry pairs = (Map.Entry) it.next();
            if ("true".equals(pairs.getValue().toString())) {
                result += pairs.getKey();
            }
        }
        return result;
    }

    public static void main(String[] args) {
        Problem3 f = new Problem3();
    }
}
