public class User
{
    private String name;
    private String surname;
    private String middlename;
    private String age;
    private String doctor;

    public User(String name, String surname, String middlename, String age, String doctor)
    {
        this.name = name;
        this.surname = surname;
        this.middlename = middlename;
        this.age = age;
        this.doctor = doctor;
    }

    public String getName() {return this.name;}
    public String getSurname() {return this.surname;}
    public String getMiddlename() {return this.middlename;}
    public String getAge() {return this.age;}
    public String getDoctor() {return this.doctor;}

}