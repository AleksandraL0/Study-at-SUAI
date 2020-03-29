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

namespace LR5
{
    public partial class Form1 : Form
    {
        SqlConnection cnn = new SqlConnection(@"Data Source=DESKTOP-J0JI3DH;Initial Catalog= Polyclinic; Integrated Security = True");
        SqlCommand cmd = new SqlCommand();
        SqlDataReader reader;

        public Form1()
        {
            InitializeComponent();
        }

        private void Button1_Click(object sender, EventArgs e)
        {
            cnn.Open();
            cmd.Connection = cnn;
            cmd.CommandType = CommandType.Text;
            cmd.CommandText = "select Фамилия from Люди";
            reader = cmd.ExecuteReader();
            while(reader.Read())
            {
                richTextBox1.Text += Convert.ToString(reader["Фамилия"]);
                richTextBox1.Text += '\n';
            }
            cnn.Close();
        }

        private void Button2_Click(object sender, EventArgs e)
        {
            cnn.Open();
            cmd.Connection = cnn;
            cmd.CommandType = CommandType.Text;
            cmd.CommandText = "SELECT Фамилия from Люди where Номер_карты = @ID; Select Биоматериал, Анализ, Результат from Результаты where Номер_карты = @ID;" ;
            cmd.Parameters.Add("@ID", SqlDbType.Int);
            cmd.Parameters["@ID"].Value = Convert.ToDecimal(textBox1.Text);
            reader = cmd.ExecuteReader();
            while(reader.Read())
            {
                richTextBox3.Text += Convert.ToString(reader["Фамилия"]);
            }
            richTextBox3.Text += "\n-----------\n";
            reader.NextResult();
            while (reader.Read())
            {
                richTextBox3.Text += Convert.ToString(reader["Биоматериал"]);
                richTextBox3.Text += ' ';
                richTextBox3.Text += Convert.ToString(reader["Анализ"]);
                richTextBox3.Text += ' ';
                richTextBox3.Text += Convert.ToString(reader["Результат"]);
                richTextBox3.Text += '\n';
            }
            cnn.Close();
        }

        private void Button3_Click(object sender, EventArgs e)
        {
            cnn.Open();
            cmd.Connection = cnn;
            cmd.CommandType = CommandType.StoredProcedure;
            cmd.CommandText = "output";
            cmd.Parameters.Add("@years", SqlDbType.Date);
            cmd.Parameters["@years"].Value = "01.01.1990";
            cmd.Parameters.Add("@prevyears", SqlDbType.Date);
            cmd.Parameters["@prevyears"].Direction = ParameterDirection.Output;
            reader = cmd.ExecuteReader();
            richTextBox2.Text += Convert.ToString(cmd.Parameters["@prevyears"].Value);
            cnn.Close();
        }
    }
}
