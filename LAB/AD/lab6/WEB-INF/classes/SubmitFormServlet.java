
import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;

public class SubmitFormServlet extends HttpServlet {

    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

        response.setContentType("text/html");
        
        PrintWriter out = response.getWriter();
        String name = request.getParameter("name");
        String email = request.getParameter("email");
        String message = request.getParameter("message");

        
        out.println("<html><body>");
        out.println("<h1>Error: All fields are required!</h1>");
        out.println("<a href='index.html'>Go back to the form</a>");
        out.println("</body></html>");
        out.println("<html><body>");
        out.println("<h1>Submitted Details</h1>");

        out.println("<p><strong>Name:</strong> " + name + "</p>");
        out.println("<p><strong>Email:</strong> " + email + "</p>");
        out.println("<p><strong>Message:</strong> " + message + "</p>");

        out.println("<a href='index.html'>Go back to the form</a>");
        out.println("</body></html>");
    }
}
