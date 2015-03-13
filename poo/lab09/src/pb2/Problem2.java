/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pb2;

import java.awt.Dimension;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.BoxLayout;
import javax.swing.ButtonGroup;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JRadioButton;
import javax.swing.JTextField;

/**
 *
 * @author master
 */
public class Problem2 extends JFrame implements ActionListener {

    JTextField jtf;
    JTextField jtf2;
    ButtonGroup bg;
    JRadioButton[] buttons;
    final String abc = "ABC";
    
    public Problem2() {
        this.setVisible(true);
        this.setPreferredSize(new Dimension(300, 200));
        
        JPanel jp = (JPanel) this.getContentPane();
        this.setLayout(new BoxLayout(jp, BoxLayout.Y_AXIS));
        
        jtf = new JTextField();
        jtf.setText("Ce alegeți?");
        jtf.setEditable(false);
        jp.add(jtf);
        
        bg = new ButtonGroup();
        buttons = new JRadioButton[3];
        for (int i = 0; i < buttons.length; i++) {
            char c = abc.charAt(i);
            buttons[i] = new JRadioButton("" + c);
            buttons[i].addActionListener(this);
            bg.add(buttons[i]);
            jp.add(buttons[i]);
        }
        
        jtf2 = new JTextField();
        jtf2.setEditable(false);
        jtf2.setVisible(true);
        jp.add(jtf2);
        
        this.pack();
        this.setDefaultCloseOperation(EXIT_ON_CLOSE);
    }
    
    @Override
    public void actionPerformed(ActionEvent e) {
        jtf2.setText(e.getActionCommand());
        jtf2.setVisible(true);
    }
    
    public static void main(String[] args) {
        Problem2 f = new Problem2();
    }
}
