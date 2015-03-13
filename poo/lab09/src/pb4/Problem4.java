/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pb4;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JSlider;
import javax.swing.JTextField;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;

/**
 *
 * @author master
 */
public class Problem4 extends JFrame implements ChangeListener {

    JPanel sliders;
    JTextField jtf;
    JSlider[] js;
    
    public Problem4() {
        this.setPreferredSize(new Dimension(800, 400));
        this.setVisible(true);
        
        sliders = new JPanel();
        js = new JSlider[3];
        for (int i = 0; i < js.length; i++) {
            js[i] = new JSlider(JSlider.HORIZONTAL, 0, 255, 0);
            js[i].addChangeListener((javax.swing.event.ChangeListener) this);
            sliders.add(js[i]);
        }

        this.add(sliders, BorderLayout.NORTH);
        
        jtf = new JTextField();
        jtf.setEditable(false);
        jtf.setBackground(new Color(0, 0, 0));
        this.add(jtf);
        
        this.pack();
        this.setDefaultCloseOperation(EXIT_ON_CLOSE);
    }
    
    @Override
    public void stateChanged(ChangeEvent e) {
        jtf.setBackground(new Color(js[0].getValue(),
                                    js[1].getValue(),
                                    js[2].getValue()));
    }
    
    public static void main(String[] args) {
        Problem4 f = new Problem4();
    }
}
