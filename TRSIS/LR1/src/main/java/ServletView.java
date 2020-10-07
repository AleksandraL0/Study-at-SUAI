import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;

@WebServlet(name = "ServletView")
public class ServletView extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        response.setContentType("text/html;charset=UTF-8");
        Data data = Data.get();
        PrintWriter red = response.getWriter();
        red.println("<!DOCTYPE html>");
        red.println("<html>");
        red.println("<head>");
        red.println("<title>Запись к врачу</title>");
        red.println("</head>");
        red.println("<body bgcolor=\"#f0e68c\"><div align=\"center\">");
        if(data.getValue().isEmpty())
        {
            red.println("Список записи пуст");
        }
        else
        {
            for(User i : data.getValue())
            {
                red.println(i.getName() + " " + i.getMiddlename() + " " + i.getSurname() + " " + i.getAge() + " " + i.getDoctor() + "<br><br>");
            }
        }
        red.println("<form action=\"index.jsp\">");
        red.println("<input type=\"submit\" value=\"Вернуться на главную\">");
        red.println("</form></div></body></html>");
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

    }
}
