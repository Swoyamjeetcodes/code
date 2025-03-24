import javax.servlet.*;
import javax.servlet.http.*;
import java.io.*;

public class SecondServlet extends HttpServlet {
    public void doPost(HttpServletRequest req, HttpServletResponse res) throws IOException, ServletException {
        try 
        {
            res.setContentType("text/html");
            PrintWriter out = res.getWriter();

            // Corrected: Use req.getCookies() instead of res.getCookies()
            Cookie[] ck = req.getCookies();
            out.print("Hello: " + ck[0].getValue());
            out.close();

        } 
        catch (Exception e) 
        {
            e.printStackTrace();
        }
    }
}