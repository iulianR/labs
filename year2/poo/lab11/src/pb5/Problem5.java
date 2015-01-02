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
import javax.swing.event.TreeSelectionEvent;
import javax.swing.event.TreeSelectionListener;
import javax.swing.tree.DefaultMutableTreeNode;
import javax.swing.tree.DefaultTreeModel;
import javax.swing.tree.TreeSelectionModel;

public class Problem5 extends JFrame implements ActionListener, TreeSelectionListener {
    File [] files;
    File file;
    DefaultMutableTreeNode node, selectedNode;
    JTree jt;
    JTextField jtf, jtf2;
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
    
    Problem5(){
        this.setLayout(new FlowLayout());
        jtf = new JTextField("");
        jtf.setPreferredSize(new Dimension(200, 30));
        jtf.addActionListener(this);
        this.add(jtf);

        node = new DefaultMutableTreeNode();
        dtm = new DefaultTreeModel(node);
        jt = new JTree(dtm);
        jt.setPreferredSize(new Dimension(500, 700));
        jt.getSelectionModel().setSelectionMode(TreeSelectionModel.SINGLE_TREE_SELECTION);
        jt.addTreeSelectionListener(this);
        this.add(jt);

        jtf2 = new JTextField("");
        jtf2.setPreferredSize(new Dimension(200, 100));
        this.add(jtf2);
        
        this.pack();
        this.setVisible(true);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
       
    public static void main(String args[]){
        Problem5 problem5 = new Problem5(); 
    }

    @Override
    public void valueChanged(TreeSelectionEvent e) {
        selectedNode =(DefaultMutableTreeNode) jt.getLastSelectedPathComponent();
        if (selectedNode == null) return;
        // Obtinem informatia din nod
        Object nodeInfo = selectedNode.getUserObject();
        jtf2.setText(nodeInfo.toString());
    }
}
