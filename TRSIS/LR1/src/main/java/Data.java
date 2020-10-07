import java.util.*;

public class Data {
    private static Data data = new Data();
    private static ArrayList<User> users = new ArrayList<User>();

    public static void addValue(User user)
    {
        users.add(user);
    }
    public static List<User> getValue()
    {
        return users;
    }

    public static Data get()
    {
        return data;
    }

    public static void del(String name, String surname, String doctor)
    {
        User DEL = null;
       for(User i : users)
       {
           if(name.equals(i.getName()) && surname.equals(i.getSurname()) && doctor.equals(i.getDoctor()))
           {
               DEL = i;
           }
       }
       if(DEL != null)
       {
           users.remove(DEL);
       }
    }
}
