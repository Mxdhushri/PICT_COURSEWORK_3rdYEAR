<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@page import="java.sql.DriverManager"%>
<%@page import="java.sql.ResultSet"%>
<%@page import="java.sql.Statement"%>
<%@page import="java.sql.Connection"%>
<%
String id = request.getParameter("userid");
String driver = "com.mysql.jdbc.Driver";
String connectionUrl = "jdbc:mysql://localhost:3306/";
String database = "Student"; 
String userid = "root";
String password = "te31272";
try {
Class.forName(driver);
} catch (ClassNotFoundException e) {
e.printStackTrace();
}
Connection connection = null;
Statement statement = null;
ResultSet resultSet = null;
%>
<!DOCTYPE html>
<html>
<body>

<h1 align="center" >STUDENT INFO</h1>
<table border="1" align="center">
<tr>
<td style='border: 1px solid #dddddd;  padding: 8px;'>ID</td>
<td style='border: 1px solid #dddddd;  padding: 8px;'>Name</td>
<td style='border: 1px solid #dddddd;  padding: 8px;'>Class</td>
<td style='border: 1px solid #dddddd;  padding: 8px;'>Division</td>
<td style='border: 1px solid #dddddd;  padding: 8px;'>City</td>

</tr>
<%
try{
connection = DriverManager.getConnection(connectionUrl+database, userid, password);
statement=connection.createStatement();
String sql ="select * from student";
resultSet = statement.executeQuery(sql);
while(resultSet.next()){
%>
<tr>
<td style='border: 1px solid #dddddd; background-color: #f2f2f2; padding: 8px;'><%=resultSet.getInt("id") %></td>
<td style='border: 1px solid #dddddd; background-color: #f2f2f2; padding: 8px;'><%=resultSet.getString("name") %></td>
<td style='border: 1px solid #dddddd; background-color: #f2f2f2; padding: 8px;'><%=resultSet.getString("class") %></td>
<td style='border: 1px solid #dddddd; background-color: #f2f2f2; padding: 8px;'><%=resultSet.getString("division") %></td>
<td style='border: 1px solid #dddddd; background-color: #f2f2f2; padding: 8px;'><%=resultSet.getString("city") %></td>

</tr>
<%	
}
connection.close();
} catch (Exception e) {
e.printStackTrace();
}
%>
</table> 

</body>
</html>