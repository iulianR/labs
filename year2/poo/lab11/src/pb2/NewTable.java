import javax.swing.*;
import javax.swing.table.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Arrays;

class NewTable extends JFrame implements ActionListener{
    JTextField jtf, text;
    JTable jt;
    File f;
    SimpleDateFormat sdf;
    DefaultTableModel dtm;
    ArrayList<File> files;
    Object[] row;
    
    @Override
    public void actionPerformed(ActionEvent e) {
        for (int i = 0; i < dtm.getRowCount(); i++) {
            dtm.removeRow(i);
        }
        
        f = new File(jtf.getText());
        files = new ArrayList<>(Arrays.asList(f.listFiles()));
        row = new Object[4];
        sdf = new SimpleDateFormat();
        for (File file : files) {
            row[0] = file.getName();
            row[1] = (long) file.length();
            row[2] = sdf.format(file.lastModified());
            row[3] = file.isDirectory();
            dtm.addRow(row);
        }
    }
    
    public NewTable() {
        super("Table");
        setLayout(new FlowLayout());
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        jtf = new JTextField("");
        jtf.setPreferredSize(new Dimension(100, 30));
        jtf.addActionListener(this);
        this.add(jtf);

        final String[] names = {"Nume", "Dimensiune",  "Ultima modificare",
                                "Este director?"};
        dtm = new DefaultTableModel(names, 0);
        jt = new JTable(dtm);
        JScrollPane scrollpane = new JScrollPane(jt);

        scrollpane.setPreferredSize(new Dimension(700, 300));
        this.add(scrollpane);
        this.pack();
        this.setVisible(true);
    }

    public static void main(String[] args) {
        NewTable nt = new NewTable();
    }
}
