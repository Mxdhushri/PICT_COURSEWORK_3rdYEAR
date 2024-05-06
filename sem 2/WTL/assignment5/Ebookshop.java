import java.io.*;
import java.util.*;
import jakarta.servlet.*;
import jakarta.servlet.http.*;
import jakarta.servlet.annotation.WebServlet;
import java.sql.*;
@WebServlet("/servlet")
public class Ebookshop extends HttpServlet{

   public void doGet(HttpServletRequest request, HttpServletResponse response)
      throws ServletException, IOException {
   
      // JDBC driver name and database URL
      final String JDBC_DRIVER = "com.mysql.jdbc.Driver";  
      final String DB_URL="jdbc:mysql://localhost/wtl";

      //  Database credentials
      final String USER = "root";
      final String PASS = "te31272";

      // Set response content type
      response.setContentType("text/html");
      PrintWriter out = response.getWriter();
      String title = "Database Result";
      
      String docType =
         "<!doctype html public \"-//w3c//dtd html 4.0 " + "transitional//en\">\n";
      
      out.println(docType +
         "<html>\n" +
         "<head><title>" + title + "</title> </head>\n" +
         "<body >\n" +
         "<h1 align = \"center\">"  + "</h1>\n");
      out.println("<h1 style='text-align: center;'>EBOOKSHOP</h1>");
      out.println("<table  align='center'>" );
      out.println("<tr style='background-color: #f2f2f2;' ><th>Book ID</th><th>Book Title</th><th>Book Author</th><th>Book Price</th><th>Book Quantity</th></tr>");
      try {
         // Register JDBC driver
         Class.forName("com.mysql.jdbc.Driver");

         // Open a connection9
         Connection conn = DriverManager.getConnection(DB_URL, USER, PASS);

         // Execute SQL query	=
         Statement stmt = conn.createStatement();
         String sql;
         sql = "SELECT * from Ebookshop";
         ResultSet rs = stmt.executeQuery(sql);

         // Extract data from result set
         while(rs.next()){
            //Retrieve by column name
        	int book_id = rs.getInt("book_id");
            String book_title = rs.getString("book_title");
            String book_author = rs.getString("book_author");
            float book_price = rs.getFloat("book_price");
            int quantity = rs.getInt("quantity");
            
            
            out.println("<tr><th style='border: 1px solid black;  padding: 8px;'>"+book_id+"</th>");
            out.println("<th style='border: 1px solid black;  padding: 8px;'>"+book_title+"</th>");
            out.println("<th style='border: 1px solid black; padding: 8px;'>"+book_author+"</th>");
            out.println("<th style='border: 1px solid black; padding: 8px;'>"+book_price+"</th>");
            out.println("<th style='border: 1px solid black; padding: 8px;'>"+quantity+"</th></tr>");
           
            
         }
         out.println("</table>");
         out.println("</body></html>");

         // Clean-up environment
         rs.close();
         stmt.close();
         conn.close();
      } catch(SQLException se) {
         //Handle errors for JDBC
         se.printStackTrace();
      } catch(Exception e) {
         //Handle errors for Class.forName
         e.printStackTrace();
      }
      finally {
         //finally block used to close resources
    	  System.out.println("closed");
      } //end try
   }
}