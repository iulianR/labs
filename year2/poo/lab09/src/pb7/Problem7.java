/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pb7;

import java.awt.Dimension;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.BoxLayout;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JTextField;

/**
 *
 * @author master
 */
public class Problem7 extends JFrame implements ActionListener {

    JTextField[] jtf;
    JButton jb;
    public Problem7() {
        this.setPreferredSize(new Dimension(300, 200));
        this.setVisible(true);
        
        JPanel jp = (JPanel) this.getContentPane();
        this.setLayout(new BoxLayout(jp, BoxLayout.Y_AXIS));
        
        jtf = new JTextField[4];
        for (int i = 0; i < jtf.length; i++) {
            jtf[i] = new JTextField();
            jp.add(jtf[i]);
        }
        jtf[3].setEditable(false);
        
        jb = new JButton("Open");
        jb.addActionListener(this);
        jp.add(jb);
        
        this.pack();
        this.setDefaultCloseOperation(EXIT_ON_CLOSE);
    }
    
    @Override
    public void actionPerformed(ActionEvent e) {
        String[] results = new String[3];
        
        for (int i = 0; i < jtf.length - 1; i++) {
            String text = jtf[i].getText();
            if (text.contains(":")) {
                results[0] = text;
            } else if (text.contains("\\")) {
                results[1] = text;
            } else {
                results[2] = text;
            }
        }
        
        String result = "";
        for (String s : results) {
            result += s;
        }
        jtf[3].setText(result);
    }
    
    public static void main(String[] args) {
        Problem7 f = new Problem7();
    }
}
