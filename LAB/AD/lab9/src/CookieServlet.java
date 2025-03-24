import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

@WebServlet("/CookieServlet")
public class CookieServlet extends HttpServlet {
    private static final long serialVersionUID = 1L;

    // Book recommendations based on language selection
    private static final String[][] BOOKS = {
        {"C", "The C Programming Language - Kernighan & Ritchie"},
        {"C++", "Effective C++ - Scott Meyers"},
        {"Java", "Java: The Complete Reference - Herbert Schildt"},
        {"VB 6", "Programming Microsoft Visual Basic 6.0 - Francesco Balena"}
    };

    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String selectedLanguage = request.getParameter("language");

        if (selectedLanguage != null) {
            Cookie languageCookie = new Cookie("favoriteLanguage", selectedLanguage);
            languageCookie.setMaxAge(60 * 60 * 24 * 7); // Store for 7 days
            response.addCookie(languageCookie);
        }

        response.setContentType("text/html");
        PrintWriter out = response.getWriter();
        out.println("<html><head><title>Language Selected</title></head><body>");
        out.println("<h2>Your favorite language has been saved!</h2>");
        out.println("<a href=\"CookieSelectLanguage.html\">Select Another Language</a><br>");
        out.println("<a href=\"CookieServlet\">View Book Recommendations</a>");
        out.println("</body></html>");
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String favoriteLanguage = null;

        // Retrieve cookies
        Cookie[] cookies = request.getCookies();
        if (cookies != null) {
            for (Cookie cookie : cookies) {
                if ("favoriteLanguage".equals(cookie.getName())) {
                    favoriteLanguage = cookie.getValue();
                    break;
                }
            }
        }

        response.setContentType("text/html");
        PrintWriter out = response.getWriter();
        out.println("<html><head><title>Book Recommendations</title></head><body>");

        if (favoriteLanguage != null) {
            out.println("<h2>Book Recommendation for " + favoriteLanguage + ":</h2>");
            for (String[] book : BOOKS) {
                if (book[0].equals(favoriteLanguage)) {
                    out.println("<p>" + book[1] + "</p>");
                    break;
                }
            }
        } else {
            out.println("<h2>No favorite language selected yet!</h2>");
        }

        out.println("<a href=\"CookieSelectLanguage.html\">Back to Selection</a>");
        out.println("</body></html>");
    }
}
