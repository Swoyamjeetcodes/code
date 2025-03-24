<%@ page import="java.util.Date" %>

<%
    // Define keys for session attributes
    String title = "Hello";
    String visitCountKey = "visitCount";
    String userID = "user1"; // Usually should be fetched from a login system
    String userIDKey = "userID";

    // Initializing visit count
    Integer visitCount = (Integer) session.getAttribute(visitCountKey);
    if (visitCount == null) {
        visitCount = 0; // Set default value if not set
    }

    // Setting the maximum session timeout (30 minutes)
    session.setMaxInactiveInterval(30 * 60);

    // Get session creation time and last accessed time
    Date createTime = new Date(session.getCreationTime());
    Date lastAccessTime = new Date(session.getLastAccessedTime());

    // Check if session is new
    if (session.isNew()) {
        title = "Welcome to JSP";
        session.setAttribute(userIDKey, userID);
    }

    // Incrementing visit count
    visitCount += 1;
    session.setAttribute(visitCountKey, visitCount);

    userID = (String) session.getAttribute(userIDKey);
%>

<html>
<head>
    <title>Session Tracking</title>
</head>
<body>
    <center>
        <h1><%= title %></h1>
    </center>
    
    <table border="1" align="center">
        <tr bgcolor="red">
            <th>Session Information</th>
            <th>Value</th>
        </tr>
        <tr>
            <td>Session ID</td>
            <td><%= session.getId() %></td>
        </tr>
        <tr>
            <td>Session Creation Time</td>
            <td><%= createTime %></td>
        </tr>
        <tr>
            <td>Last Accessed Time</td>
            <td><%= lastAccessTime %></td>
        </tr>
        <tr>
            <td>User ID</td>
            <td><%= userID %></td>
        </tr>
        <tr>
            <td>Number of Visits</td>
            <td><%= visitCount %></td>
        </tr>
    </table>
</body>
</html>
