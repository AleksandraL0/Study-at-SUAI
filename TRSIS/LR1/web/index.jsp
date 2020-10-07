<%--
  Created by IntelliJ IDEA.
  User: aleks
  Date: 10.09.2020
  Time: 0:25
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
  <head>
    <title>Запись к врачу</title>
  </head>
  <body bgcolor="#f0e68c">
  <div align="center">
  <h1><font size="45" face="Arrial" color="maroon">Здравствуйте, Вы попали на портал для записи к врачу</font></h1>
  <p><font size="5" face="Arrial", color="maroon">ВНИМАНИЕ: Без действующей справки об отсутсвии COVID Вам может быть отказано в оказании мед. помощи</font></p>
  <form method="post">
    <input formaction="/zapis" type="submit" value="Запись">
    <input formaction="/delete" type="submit" value="Отмена записи">
    <input formaction="/view" type="submit" value="Просмотр записи">
  </div>
  </body>
</html>
