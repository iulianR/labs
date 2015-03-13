/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pb5;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import javax.swing.JComponent;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JSpinner;
import javax.swing.JTextField;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;

/**
 *
 * @author master
 */
public class Problem5 extends JFrame implements ChangeListener {

    JPanel spinners;
    JTextField jtf;
    JSpinner[] js;
    
    public Problem5() {
        this.setPreferredSize(new Dimension(800, 400));
        this.setVisible(true);
        
        spinners = new JPanel();
        js = new JSpinner[3];
        
        Dimension prefSize = new Dimension(30, 20);
        JComponent field;
        
        for (int i = 0; i < js.length; i++) {
            js[i] = new JSpinner();
            js[i].addChangeListener(this);
            
            field = ((JSpinner.DefaultEditor) js[i].getEditor());
            field.setPreferredSize(prefSize);
            spinners.add(js[i]);
        }

        this.add(spinners, BorderLayout.NORTH);
        
        jtf = new JTextField();
        jtf.setEditable(false);
        jtf.setBackground(new Color(0, 0, 0));
        this.add(jtf);
        
        this.pack();
        this.setDefaultCloseOperation(EXIT_ON_CLOSE);
    }
    
    @Override
    public void stateChanged(ChangeEvent e) {
        System.out.println(js[0].getValue());
        jtf.setBackground(new Color((int) js[0].getValue(),
                                    (int) js[1].getValue(),
                                    (int) js[2].getValue()));
    }
    
    public static void main(String[] args) {
        Problem5 f = new Problem5();
    }
}
