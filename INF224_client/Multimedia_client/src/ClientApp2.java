import java.awt.BorderLayout;
import java.awt.event.ActionEvent;
import java.io.IOException;
import java.net.UnknownHostException;
import java.util.regex.Pattern;

import javax.swing.AbstractAction;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.JToolBar;


public class ClientApp2 extends JFrame {

	private static final long serialVersionUID = 1L;
	private static final Pattern PATTERN = Pattern.compile("^(\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}):(\\d+)$");
	
	private ActionBouton1 ab1 = new ActionBouton1();
	private ActionBouton2 ab2 = new ActionBouton2();
	
	private Client client;
	
	public ClientApp2() {
		super("Client App V2");
		initializeToolBar();
		this.setSize(800, 600);
		this.setVisible(true);
		this.setLocationRelativeTo(null);
	}
	
	private void initializeToolBar() {
		JToolBar jtb = new JToolBar("My super toolbar");
		jtb.add(ab1);
		jtb.add(ab2);
		jtb.add(new ActionBouton3());
		getContentPane().add(jtb, BorderLayout.NORTH);
	}
	
	public static boolean validate(final String ip) {
	    return PATTERN.matcher(ip).matches();
	}
	
	public static void main(String[] args) {
		new ClientApp2();
	}
	
	class ActionBouton1 extends AbstractAction {

		private static final long serialVersionUID = 1L;

		public ActionBouton1() {
			super("Connect to host");
		}
		
		@Override
		public boolean isEnabled() {
			return client == null;
		}
		
		@Override
		public void actionPerformed(ActionEvent e) {
			String addr = "";
			while(!validate(addr)){
				addr = JOptionPane.showInputDialog("Please fill the adress and port of host", "127.0.0.1:3331");
			}
			String host = addr.substring(0, addr.lastIndexOf(":"));
			int port = Integer.parseInt(addr.substring(addr.lastIndexOf(":")+1, addr.length()));
			try {
				client = new Client(host, port);
			} catch (UnknownHostException e1) {
				JOptionPane.showMessageDialog(getParent(), "error", "Address provided is unreachable", JOptionPane.ERROR_MESSAGE);
			} catch (IOException e1) {
				JOptionPane.showMessageDialog(getParent(), "error", "Error", JOptionPane.ERROR_MESSAGE);
			}
			
			ab1.setEnabled(false);
			ab2.setEnabled(true);
		}
		
		
		
	}
	
	class ActionBouton2 extends AbstractAction {

		private static final long serialVersionUID = 1L;

		public ActionBouton2() {
			super("Retrieve List of media");
		}
		
		
		@Override
		public void actionPerformed(ActionEvent e) {
			String content = client.send("listeMedia");
			String nContent = content.replaceAll("#", "\n");
			
		}
		
	}
	
	class ActionBouton3 extends AbstractAction {

		private static final long serialVersionUID = 1L;

		public ActionBouton3() {
			super("Exit App");
		}
		
		@Override
		public void actionPerformed(ActionEvent e) {
			System.exit(0);
		}
		
	}
	
	
	
}
