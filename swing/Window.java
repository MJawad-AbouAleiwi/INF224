import java.awt.BorderLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.GridLayout;

import javax.swing.*;

public class Window extends JFrame {
	
	private static final long serialVersionUID = 1L;
			
	Client client;
	JButton button1 = null;
	JButton button2 = null;
	JButton button3 = null;
	JTextArea textArea = null;
        JTextField textField;
	
	JPanel panel = new JPanel();
	
	JMenuBar menuBar = new JMenuBar();
	JMenu menu = new JMenu("Menu");
	JToolBar toolBar = new JToolBar();
	
	
	public static void main(String argv[]){
		Window client_multimedia = new Window();
	}
	
	public Window(){
		try {
		      client = new Client(Client.DEFAULT_HOST, Client.DEFAULT_PORT);
		    } catch (java.io.IOException e) {
		      client = null;
		    }
		  
		
		button1 = new JButton("Search");
		button2 = new JButton("Play");
		button3 = new JButton("exit");
		
		button1.addActionListener(new SearchListener());
		button2.addActionListener(new PlayListener());
		button3.addActionListener(new CloseListener());
		
		textField = new JTextField();
		textArea = new JTextArea(30,30);
		textArea.setEditable(false);
		JScrollPane scrollPane = new JScrollPane(textArea);
		
		panel.setLayout(new GridLayout(1, 4));
		panel.add(textField);
		panel.add(button1);
		panel.add(button2);
		panel.add(button3);
	
		add(panel, BorderLayout.EAST);
		add(scrollPane,BorderLayout.CENTER);
		

		JMenuItem menuItem1 = new JMenuItem("Search");
		menuItem1.addActionListener(new SearchListener());
		menu.add(menuItem1);
		
		JMenuItem menuItem2 = new JMenuItem("Play");
		menuItem2.addActionListener(new PlayListener());
		menu.add(menuItem2);
		
		JMenuItem menuItem3 = new JMenuItem("Exit");
		menuItem3.addActionListener(new CloseListener());
		menu.add(menuItem3);
		
		toolBar.add(panel);
		menuBar.add(menu);
		setJMenuBar(menuBar);
		add(toolBar, BorderLayout.NORTH);
		
		
	
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setTitle("Java Client");
		pack();
		setVisible(true);
	}
	
	class SearchListener implements ActionListener{

	    public void actionPerformed(ActionEvent e) {
	        String text = textField.getText();

	        System.out.println("Search: "+ text);
	        text = client.send("Search "+ text);
	        text = text.replace(';', '\n') + '\n';
	        textArea.append(text);
	    }
	}
	
	class PlayListener implements ActionListener{
		public void actionPerformed(ActionEvent e) {
	        String text = textField.getText();

	        System.out.println("PLAY: "+ text);
	        text = client.send("play "+ text);
	        textArea.append(text);
	    }
	}
	
	class CloseListener implements ActionListener{
		public void actionPerformed(ActionEvent e){
			System.exit(0);
		}	
	}
	

}