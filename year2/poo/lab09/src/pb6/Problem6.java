/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pb6;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import javax.swing.JButton;
import javax.swing.JFrame;
import static javax.swing.JFrame.EXIT_ON_CLOSE;

/**
 *
 * @author master
 */
public class Problem6 extends JFrame implements ActionListener {
    
    private final JButton jb;
    private final Color[] colors;
    int current;
    
    public Problem6() {
        this.setPreferredSize(new Dimension(100, 100));
        this.setVisible(true);
        
        this.setLayout(new FlowLayout());
        
        current = 0;
        colors = new Color[]{Color.red, Color.blue,
                             Color.magenta, Color.orange};
        
        jb = new JButton("Colors");
        jb.addActionListener(this);
        jb.setMnemonic(KeyEvent.VK_C);
        this.add(jb);
        
        this.pack();
        this.setDefaultCloseOperation(EXIT_ON_CLOSE);
    }
    
    @Override
    public void actionPerformed(ActionEvent e) {
        jb.setBackground(colors[current]);
        
        if (current < colors.length - 1) {
            current++;
        } else {
            current = 0;
        }
    }
    
    public static void main(String[] args) {
        Problem6 f = new Problem6();
    }
}
