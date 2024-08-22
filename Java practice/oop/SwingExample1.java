import javax.swing.*;  
public class SwingExample1 extends JFrame
 {  
   JFrame f;
   JButton b;
   SwingExample1()
   {
    f=new JFrame();
    b=new JButton("click");
    b.setBounds(50,50,100, 100);//x axis, y axis,  width, height  
    f.add(b);//adding button in JFrame  
    f.setSize(1920,1080);//400 width and 500 height  
    f.setLayout(null);//using no layout managers  
    f.setVisible(true);//making the frame visible  
   //f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
   }
public static void main(String[] args)
   {  
  
    new SwingExample1();        
  }
}