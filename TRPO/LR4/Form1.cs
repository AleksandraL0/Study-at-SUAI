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

namespace LR4
{
    public partial class Form1 : Form
    {
        SqlConnection cnn = new SqlConnection(@"Data Source=DESKTOP-J0JI3DH;Initial Catalog= Polyclinic; Integrated Security = True");
        SqlCommand cmd = new SqlCommand();
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void Button1_Click(object sender, EventArgs e)
        {
            cnn.Open();
            cmd.CommandText = "select Результат from Результаты order by Результат DESC";
            cmd.Connection = cnn;
            textBox1.Text = "Результат # " + Convert.ToString(cmd.ExecuteScalar());
            cnn.Close();
        }

        private void Button2_Click_1(object sender, EventArgs e)
        {
            cnn.Open();
            cmd.CommandText = "select sum([Результат]) from Результаты";
            cmd.Connection = cnn;
            textBox1.Text = "Всего результатов # " + Convert.ToString(cmd.ExecuteScalar());
            cnn.Close();
        }

        private void Button3_Click(object sender, EventArgs e)
        {
            cnn.Open();
            cmd.Connection = cnn;
            cmd.CommandText = "insert into Диагностика values (106, 11, 100, 120, 'Диабет', 1)"; 
            cmd.ExecuteScalar();
            cnn.Close();
        }

        private void Button4_Click(object sender, EventArgs e)
        {
            cnn.Open();
            cmd.Connection = cnn;
            cmd.CommandText = "update Диагностика set ID_болезни = 110 where [Название_болезни] = 'Артрит'";
            cmd.ExecuteScalar();
            cnn.Close();
        }

        private void Button5_Click(object sender, EventArgs e)
        {
            cnn.Open();
            cmd.Connection = cnn;
            cmd.CommandText = "delete from Люди where [Номер_карты] = 3";
            cmd.ExecuteScalar();
            cnn.Close();
        }

        private void Button6_Click(object sender, EventArgs e)
        {
            cnn.Open();
            cmd.Connection = cnn;
            cmd.CommandText = "insert into Люди values (" + textBox2.Text +  ", 'Иванов', 'Михаил', 'Петрович', '21.09.1990')";
            textBox2.Text = "Изменено = " + Convert.ToString(cmd.ExecuteNonQuery());
            cnn.Close();
        }

        private void Button7_Click(object sender, EventArgs e)
        {
            cnn.Open();
            cmd.Connection = cnn;
            cmd.CommandText = "delete from Люди where Номер_карты = " + textBox3.Text;
            textBox3.Text = "Удалено " + Convert.ToString(cmd.ExecuteNonQuery());
            cnn.Close();
        }

        private void Button8_Click(object sender, EventArgs e)
        {
            cnn.Open();
            cmd.Connection = cnn;
            cmd.CommandText = "create table Врач (Фамилия varchar(100) primary key, Имя varchar(100), Отчество varchar(100)) ";
            cmd.ExecuteNonQuery();
            cnn.Close();
        }

        private void Button9_Click(object sender, EventArgs e)
        {
            cnn.Open();
            cmd.Connection = cnn;
            cmd.CommandText = "drop table Врач";
            cmd.ExecuteNonQuery();
            cnn.Close();
        }
    }
}
