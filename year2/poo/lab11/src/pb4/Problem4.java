/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author master
 */
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import javax.swing.*;
import javax.swing.tree.DefaultMutableTreeNode;
import javax.swing.tree.DefaultTreeModel;

public class Problem4 extends JFrame implements ActionListener{
    File [] files;
    File file;
    DefaultMutableTreeNode node;
    JTree jt;
    JTextField jtf;
    DefaultTreeModel dtm;
    
    @Override
    public void actionPerformed(ActionEvent e) {
        file = new File(jtf.getText());
        node.removeAllChildren();
        dirlist(file, node);
        dtm.setRoot(node);
        dtm.reload();
        jt.setModel(dtm);
    }
    
    /* Functia recursiva de creare a arborelui pe baza unui director dat. */
    static void dirlist ( File d, DefaultMutableTreeNode r ) {
        if( !d.isDirectory() ) return;
	File [] files = d.listFiles(); // fisiere din directorul d
            for( int i = 0; i < files.length; i ++ ){
                File file = files[i];
                DefaultMutableTreeNode s = new DefaultMutableTreeNode( file );
		r.add( s );
                dirlist( file, s );
            }
    }
    
    Problem4(){
        this.setLayout(new FlowLayout());
        jtf = new JTextField("");
        jtf.setPreferredSize(new Dimension(200, 30));
        jtf.addActionListener(this);
        this.add(jtf);

        node = new DefaultMutableTreeNode();
        dtm = new DefaultTreeModel(node);
        jt = new JTree(dtm);
        jt.setPreferredSize(new Dimension(500,700));
        this.add(jt);
        this.pack();
        this.setVisible(true);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
       
    public static void main(String args[]){
        Problem4 problem4 = new Problem4(); 
    }
}
