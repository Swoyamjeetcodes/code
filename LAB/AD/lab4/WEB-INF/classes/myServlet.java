import javax.servlet.http.*;
import javax.servlet.*;
import javax.servlet.annotation.WebServlet;
import java.io.*;
import java.util.Date;

@WebServlet("/myServlet")
public class MyServlet extends HttpServlet {
    public void doGet(HttpServletRequest req, HttpServletResponse res)
            throws ServletException, IOException {
        res.setContentType("text/html"); // Setting the content type
        try (PrintWriter pw = res.getWriter()) { // Using try-with-resources
            Date d = new Date();
            pw.println("<html><body>");
            pw.println("<h1>Welcome to Java Servlet</h1>");
            pw.println("<p>Today date and time is " + d.toString() + "</p>");
            pw.println("</body></html>");
        }
    }
}
