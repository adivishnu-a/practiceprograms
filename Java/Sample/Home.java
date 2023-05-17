import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class Home extends JFrame implements ActionListener {

    private JTextField userField;
    private JPasswordField passwordField;
    private JButton loginBtn;
    private JButton registerBtn;
    private JLabel userLabel;
    private JLabel passwordLabel;
    private JLabel messageLabel;

    public Home() {
        setTitle("Online Exam System");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(600, 400);
        setResizable(false);
        setLocationRelativeTo(null);
        setLayout(null);

        userLabel = new JLabel("Username: ");
        userLabel.setBounds(100, 100, 100, 25);
        add(userLabel);

        userField = new JTextField(20);
        userField.setBounds(200, 100, 200, 25);
        add(userField);

        passwordLabel = new JLabel("Password: ");
        passwordLabel.setBounds(100, 150, 100, 25);
        add(passwordLabel);

        passwordField = new JPasswordField(20);
        passwordField.setBounds(200, 150, 200, 25);
        add(passwordField);

        loginBtn = new JButton("Login");
        loginBtn.setBounds(100, 200, 100, 25);
        loginBtn.addActionListener(this);
        add(loginBtn);

        registerBtn = new JButton("Register");
        registerBtn.setBounds(200, 200, 100, 25);
        registerBtn.addActionListener(this);
        add(registerBtn);

        messageLabel = new JLabel("");
        messageLabel.setBounds(100, 250, 300, 25);
        add(messageLabel);

        setVisible(true);
    }

    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == loginBtn) {
            String user = userField.getText();
            String password = new String(passwordField.getPassword());

            if (user.equals("admin") && password.equals("password")) {
                // Show admin panel
            } else if (user.equals("student") && password.equals("password")) {
                // Show student panel
            } else {
                messageLabel.setText("Invalid username or password");
            }
        } else if (e.getSource() == registerBtn) {
            // Show registration form
        }
    }

    public static void main(String[] args) {
        new Home();
    }
}
