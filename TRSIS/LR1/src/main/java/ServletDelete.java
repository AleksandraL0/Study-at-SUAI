import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;

@WebServlet(name = "ServletDelete")
public class ServletDelete extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        response.setContentType("text/html;charset=UTF-8");
        Data data = Data.get();
        PrintWriter red = response.getWriter();
        red.println("<!DOCTYPE html>");
        red.println("<html>");
        red.println("<head>");
        red.println("<title>Отмена записи</title>");
        red.println("</head>");
        red.println("<body bgcolor=\"#f0e68c\"><div align=\"center\">");
        red.println("<form method=\"GET\" action=\"/delete\"<br><br>");
        red.println("Имя    " + "<input type=\"text\" name=\"name\"><br><br>");
        red.println("Фамилия    " + "<input type=\"text\" name=\"surname\"><br><br>");
        red.println("Врач   " + "<input type=\"text\" name=\"doctor\"><br><br>");
        red.println("<input type=\"submit\" value=\"Отменить запись\"><br><br>");
        red.println("</form></div></body></html>");

    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        response.setContentType("text/html;charset=UTF-8");
        String name = request.getParameter("name");
        String surname = request.getParameter("surname");
        String doctor = request.getParameter("doctor");
        Data data = Data.get();
        data.del(name, surname, doctor);
        PrintWriter red = response.getWriter();
        red.println("<body bgcolor=\"#f0e68c\"><div align=\"center\">");
        red.println("Ваша запись успешно отменена");
        red.println("<form action=\"index.jsp\">");
        red.println("<input type=\"submit\" value=\"Вернуться на главную\">");
        red.println("</form></div></body></html>");

    }
}
