/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pb3;

import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.text.SimpleDateFormat;
import javax.swing.*;
import javax.swing.event.ListSelectionEvent;
import javax.swing.event.ListSelectionListener;
import javax.swing.table.DefaultTableModel;

/**
 *
 * @author master
 */

class Problem3 extends JFrame implements ActionListener, ListSelectionListener
{
	JTextField text_field, text_row, text_col;
	JTable jt;
	JScrollPane scroll;
	final String[] names = {"Name", "Size", "Last modified", "Directory"};
	SimpleDateFormat sdf;
	DefaultTableModel tmodel;
        File f;
        File[] files;
        
	public Problem3() {
            this.setVisible(true);
            this.setTitle("");
            this.setLayout(new FlowLayout());

            text_field = new JTextField(20);
            text_field.addActionListener(this);
            this.add(text_field);

            tmodel = new DefaultTableModel(names, 0);
            jt = new JTable(tmodel);
            jt.setColumnSelectionAllowed(true);
            jt.setCellSelectionEnabled(true);
            scroll = new JScrollPane(jt);
            scroll.setPreferredSize(new Dimension(700, 300));
            this.add(scroll);

            ListSelectionModel rowSM = jt.getSelectionModel();
            ListSelectionModel colSM = jt.getColumnModel().getSelectionModel();
            rowSM.addListSelectionListener(this);
            colSM.addListSelectionListener(this);

            text_row = new JTextField();
            text_row.setEditable(false);
            text_col = new JTextField();
            text_col.setEditable(false);
            JPanel p = new JPanel(new GridLayout());
            p.add(new JLabel("Linia"));
            p.add(text_row);
            p.add(new JLabel("Coloana"));
            p.add(text_col);
            this.add(p);

            sdf = new SimpleDateFormat("MM/dd/yyyy HH:mm:ss");

            this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            this.pack();
	}
	
	@Override
	public void actionPerformed(ActionEvent e) {
            f = new File(this.text_field.getText());
            files = f.listFiles();
            Object[] data = new Object[this.names.length];

            for (int i = 0; i < this.tmodel.getRowCount(); i++)
                this.tmodel.removeRow(i);

            for (int i = 0; i < files.length; i++) {
                data[0] = files[i].getName();
                data[1] = files[i].length();
                data[2] = this.sdf.format(files[i].lastModified());
                data[3] = files[i].isDirectory();
                this.tmodel.addRow(data);
            }
	}

	@Override
	public void valueChanged(ListSelectionEvent e) {
            if (e.getValueIsAdjusting()) return;
            ListSelectionModel s = (ListSelectionModel) e.getSource();
            if(e.getSource() == this.jt.getColumnModel().getSelectionModel())
                this.text_col.setText("" + s.getMinSelectionIndex());
            if(e.getSource() == this.jt.getSelectionModel())
                this.text_row.setText("" + s.getMinSelectionIndex());
	}
        
        public static void main(String[] args) {
            Problem3 pb3 = new Problem3();
	}
}
