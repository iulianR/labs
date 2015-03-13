/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pb1;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.Toolkit;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.HashMap;
import java.util.Map;
import javax.swing.JFrame;
import javax.swing.JTextField;

/**
 *
 * @author master
 */
public final class Problem1 extends JFrame implements ActionListener {
    
    Map<String, Color> colorMap;
    private final JTextField jtf;
    
    public Problem1() {
        this.setPreferredSize(new Dimension(200, 100));
        this.setVisible(true);
        
        mapColors();
        jtf = new JTextField();
        jtf.setText("black");
        jtf.addActionListener(this);
        this.add(jtf);
        
        this.pack();
        this.setDefaultCloseOperation(EXIT_ON_CLOSE);
    }
    
    @Override
    public void actionPerformed(ActionEvent e) {
        Color c = colorMap.get(e.getActionCommand());
        jtf.setForeground(c);
    }
    
    public void mapColors() {
        colorMap = new HashMap<>();
        colorMap.put("red", Color.red);
        colorMap.put("blue", Color.blue);
        colorMap.put("orange", Color.orange);
        colorMap.put("magenta", Color.magenta);
    }
    
    public static void main(String[] args) {
        Problem1 f = new Problem1();
    }
}
