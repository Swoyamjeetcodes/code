import javax.servlet.*;
import javax.servlet.http.*;
import java.io.*;

public class FirstServlet extends HttpServlet {
    public void doPost(HttpServletRequest req, HttpServletResponse res) throws IOException, ServletException {
        try {
            res.setContentType("text/html");
            PrintWriter out = res.getWriter();

            String n = req.getParameter("Welcome");
            out.print("Welcome " + n);

            Cookie ck = new Cookie("uname", n);
            res.addCookie(ck);

            out.print("<form action='Servlet2' method='post'>");
            out.print("<input type='submit' value='pname'>");
            out.print("</form>");

            out.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}