/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pb4;

import java.awt.Component;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.util.Vector;
import javax.swing.DefaultListModel;
import javax.swing.JButton;
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
public class Problem4 extends JFrame implements ActionListener, ListSelectionListener {
    JList jl;
    JTextField jt, jt2, jt3;
    JPanel jp;
    JScrollPane jsp, jsp2;
    DefaultListModel dlm;
    String[] list;
    
    Problem4() {
        this.setTitle("");
        this.setLayout(new FlowLayout());
        this.setPreferredSize(new Dimension(300, 600));
        
        jp = new JPanel();
        jp.setLayout(new GridLayout(6, 0));

        jl = new JList();
        jl.setPreferredSize(new Dimension(100, 100));
        jl.addListSelectionListener(this);
        jl.setCellRenderer(new Renderer());
        jl.setVisibleRowCount(5);
        
        jsp = new JScrollPane(jl);
        this.add(jsp);
        
        JLabel jlab = new JLabel("Directory");
        jp.add(jlab);
        
        jt = new JTextField("");
        jt.setPreferredSize(new Dimension(100, 50));
        jt.addActionListener(this);
        jp.add(jt);
        
        JLabel jlab2 = new JLabel("Selected");
        jp.add(jlab2);
        jt2 = new JTextField("");
        jt2.setPreferredSize(new Dimension(200, 50));
        jp.add(jt2);
      
        this.add(jp);
        
        JButton jb = new JButton("Delete");
        jb.setPreferredSize(new Dimension(100,30));
        jb.setVisible(true);
        jb.addActionListener(this);
        this.add(jb);
        
        jt3 = new JTextField("");
        jt3.setPreferredSize(new Dimension(200, 50));
        jp.add(jt3);
        
        dlm = new DefaultListModel();
        this.pack();
        this.setVisible(true);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);  
    }
    
    @Override
    public void actionPerformed(ActionEvent e) {  
        if(e.getSource().equals(jt)) {
            File f = new File(e.getActionCommand());
            list = f.list();

            for (String l : list) {
                dlm.addElement(l);
            }
            jl.setModel(dlm);
        }
        else {
            dlm.removeElement(jl.getSelectedValue().toString());
            jl.setModel(dlm);
            int dim = dlm.size();
            jt3.setText("Remaining files:" + dim );
        }
    }
    
    @Override
    public void valueChanged(ListSelectionEvent e) {
        if (jl.isSelectionEmpty()) return;
        jl = (JList) e.getSource();
        jt2.setText(jl.getSelectedValue().toString());
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
        Problem4 pb4 = new Problem4();
    }
}
