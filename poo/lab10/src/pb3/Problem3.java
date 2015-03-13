/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pb3;

import java.awt.Component;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.util.Vector;
import javax.swing.DefaultListModel;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JList;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextField;
import javax.swing.ListCellRenderer;
import javax.swing.event.ListSelectionEvent;
import javax.swing.event.ListSelectionListener;

/**
 *
 * @author master
 */
public class Problem3 extends JFrame implements ActionListener, ListSelectionListener {
    JList jl, jl2, jltemp;
    JTextField jt;
    Vector v;
    DefaultListModel dlm;
    
    Problem3() {
        dlm = new DefaultListModel();
        this.setTitle("");
        this.setLayout(new FlowLayout());
        
        JPanel jp = new JPanel();
        jp.setLayout(new FlowLayout());

        jl = new JList();
        jl.setPreferredSize(new Dimension(100, 100));
        jl.addListSelectionListener(this);
        jl.setCellRenderer(new Renderer());
        jl.setVisibleRowCount(5);
        
        JScrollPane jsp = new JScrollPane(jl);
        this.add(jsp);
        
        JLabel jlab = new JLabel("Directory");
        jp.add(jlab);
        
        jt = new JTextField("");
        jt.setPreferredSize(new Dimension(100, 50));
        jt.addActionListener(this);
        jp.add(jt);
        
        JLabel jlab2 = new JLabel("Selected");
        jp.add(jlab2);
        
        jl2 = new JList();
        jl2.setPreferredSize(new Dimension(100, 50));
        
        JScrollPane jsp2 = new JScrollPane(jl2);
        jp.add(jsp2);
      
        this.add(jp);
        this.pack();
        this.setVisible(true);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);  
    }
    
    @Override
    public void actionPerformed(ActionEvent e) {
        File f = new File(e.getActionCommand());
        String[] list;
        list = f.list();
        
        v = new Vector();
        for (String l : list) {
            v.addElement(l);
        }
        jl.setListData(v);
    }
    
    @Override
    public void valueChanged(ListSelectionEvent e) {
        if(e.getValueIsAdjusting()) return;
        jltemp = (JList) e.getSource();
        dlm.addElement(jltemp.getSelectedValue());
        jl2.setModel(dlm);
    }
    
    class Renderer extends JLabel implements ListCellRenderer {
        public Renderer() {
            setOpaque(true);
        } 
        
        @Override
        public Component getListCellRendererComponent(JList list,
                                                      Object value,
                                                      int index,
                                                      boolean isSelected,
                                                      boolean cellHasFocus) {
            setText(value.toString());
            if(isSelected) {
                this.setBackground(java.awt.Color.red);
                this.setForeground(java.awt.Color.white);
            }
            else {
                this.setBackground(java.awt.Color.green);
                this.setForeground(java.awt.Color.white);
            }
        
        return this;
        }   
    }
    
    public static void main(String[] args) {
        Problem3 pb3 = new Problem3();
    }
}
