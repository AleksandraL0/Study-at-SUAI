using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

using System.Data.SqlClient;

namespace LR3
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        SqlConnection cnn = new SqlConnection(@"Data Source=DESKTOP-J0JI3DH;Initial Catalog= Polyclinic; Integrated Security = True");
        SqlCommand cmd = new SqlCommand();
        SqlDataReader reader;
        SqlConnection cnn2 = new SqlConnection(@"Data Source=DESKTOP-J0JI3DH;Initial Catalog= Polyclinic; Integrated Security = True");
        SqlCommand cmd2 = new SqlCommand();
        SqlDataReader reader2;
        int num = 0;

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void Button2_Click(object sender, EventArgs e)
        {
            cnn.Open();
            cmd.CommandText = "select Номер_карты, Фамилия, Имя, Отчетство, Дата_рождения from Люди";
            cmd.Connection = cnn;
            reader = cmd.ExecuteReader();
            listBox2.Items.Clear();
            listBox2.Items.Add("Информация о пациентах");
            while (reader.Read())
            {
                listBox2.Items.Add("Номер карты: " + System.Convert.ToString(reader[0]) + " " + System.Convert.ToString(reader[1]) + " " + System.Convert.ToString(reader[2]) + " " + System.Convert.ToString(reader[3]) + " " + System.Convert.ToString(reader[4]));
            }
            listBox2.Items.Add("===================");
            cnn.Close();
        }

        private void Button3_Click(object sender, EventArgs e)
        {
            num = 0;
            cnn.Open();
            cmd.CommandText = "select ID_результата, Номер_карты, Биоматериал, Анализ, Дата_сдачи, Результат from Результаты";
            cmd.Connection = cnn;
            reader = cmd.ExecuteReader();
            listBox3.Items.Clear();
            listBox3.Items.Add("Информация о анализах");
            while (reader.Read())
            {
                if (System.Convert.ToString(textBox1.Text) == System.Convert.ToString(reader[1]))
                {
                    num++;
                    listBox3.Items.Add("ID анализа: " + System.Convert.ToString(reader[0]) + " " + System.Convert.ToString(reader[2]) + " " + System.Convert.ToString(reader[3]) + " Результат " + System.Convert.ToString(reader[5]) + "   Дата сдачи: " + System.Convert.ToString(reader[4]));
                }
            }
            cnn.Close();
            if(num == 0) listBox3.Items.Add("Этот человек не сдавала анализы");
        }

        private void Button4_Click(object sender, EventArgs e)
        {
            listBox4.Items.Clear();
            int num2 = 0;
            cnn.Open();
            cmd.CommandText = "select ID_болезни, ID_результата, Верхняя_норма, Нижняя_норма, Название_болезни, Продолжение_обследования from Диагностика";
            cmd.Connection = cnn;
            reader = cmd.ExecuteReader();
            cnn2.Open();
            cmd2.CommandText = "select ID_результата, Номер_карты from Результаты";
            cmd2.Connection = cnn2;
            reader2 = cmd2.ExecuteReader();
            listBox4.Items.Add("Рекомендуется диагностика по следующим заболеваниям");
            while (reader2.Read())
            {
                while (reader.Read())
                {
                    if (System.Convert.ToString(textBox1.Text) == System.Convert.ToString(reader2[1]) && System.Convert.ToString(reader2[0]) == System.Convert.ToString(reader[1]) && System.Convert.ToInt32(reader[5]) == 1)
                    {
                        num2++;
                        listBox4.Items.Add("ID болезни " + System.Convert.ToString(reader[0]) + " " + System.Convert.ToString(reader[4]) + " от " + System.Convert.ToString(reader[3]) + " до " + System.Convert.ToString(reader[2]));
                    }
                }
                cnn.Close();
                cnn.Open();
                cmd.CommandText = "select ID_болезни, ID_результата, Верхняя_норма, Нижняя_норма, Название_болезни, Продолжение_обследования from Диагностика";
                cmd.Connection = cnn;
                reader = cmd.ExecuteReader();
            }
                if(num2 == 0) listBox4.Items.Add("Таких нет");
                cnn.Close();
                cnn2.Close();
        }
    }
}
