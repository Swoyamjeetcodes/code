import javax.swing.*;  
public class SwingExample2 extends JFrame
 {  
 JFrame f;  
 JButton b;
 JLabel l1;
JTextField t1;
    SwingExample2()
     {  
       f=new JFrame();//creating instance of JFrame  
          
        b=new JButton("click");//creating instance of JButton  
       b.setBounds(130,100,100, 40);  

       l1=new JLabel("Displaying Swing Component");
       l1.setBounds(50,50,200,20);

       t1=new JTextField();
       t1.setBounds(150,180,100,20);
   
      f.add(b);//adding button in JFrame  
      f.add(l1);
      f.add(t1);    
      f.setSize(400,500);//400 width and 500 height  
      f.setLayout(null);//using no layout managers  
      f.setVisible(true);//making the frame visible  
      f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }  
  
public static void main(String[] args)
 {  
SwingExample2 ob=new SwingExample2();  
}  
}  