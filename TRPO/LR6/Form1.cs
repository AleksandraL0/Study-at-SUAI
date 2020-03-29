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

namespace LR6
{
    public partial class Form1 : Form
    {
        SqlConnection cnn = new SqlConnection(@"Data Source=DESKTOP-J0JI3DH;Initial Catalog= Polyclinic; Integrated Security = True");
        SqlDataAdapter da = new SqlDataAdapter();
        DataSet ds = new DataSet();
        public Form1()
        {
            InitializeComponent();
        }

        private void DataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {
            dataGridView1[dataGridView1.CurrentCellAddress.X, dataGridView1.CurrentCellAddress.Y].Value = textBox1.Text;
        }

        private void Button1_Click(object sender, EventArgs e)
        {
            cnn.Open();
            SqlDataAdapter da = new SqlDataAdapter("select Номер_карты, Фамилия from Люди", cnn);
            da.Fill(ds, "Люди");
            dataGridView1.DataSource = ds.Tables[0];
            cnn.Close();
        }

        private void Button2_Click(object sender, EventArgs e)
        {
            DataRow row = ds.Tables[0].NewRow();
            row["Номер_карты"] = textBox1.Text;
            row["Фамилия"] = textBox2.Text;
            ds.Tables[0].Rows.Add(row);
        }

        private void Button3_Click(object sender, EventArgs e)
        {
            ds.Tables[0].AcceptChanges();
            ds.Tables[0].Rows[Convert.ToInt32(textBox3.Text) - 1].Delete();
        }

        private void Button4_Click(object sender, EventArgs e)
        {
            ds.Tables[0].RejectChanges();
        }

        private void Button5_Click(object sender, EventArgs e)
        {
            string filter = string.Format("Номер_карты <='{0}'", textBox4.Text);
            DataRow[] row = ds.Tables[0].Select(filter, "Номер_карты DESC");
            if (row.Length == 0) MessageBox.Show("Нет значений");
            else
            {
                for(int i = 0; i < row.Length; i++)
                {
                    richTextBox1.Text += row[i]["Номер_карты"] + " " + row[i][1] + "\n";
                }
            }
        }

        private void Button6_Click(object sender, EventArgs e)
        {
            ds.Tables[0].Rows[0][0] = textBox1.Text;
            dataGridView1.DataSource = ds.Tables[0];
        }

        private void Button7_Click(object sender, EventArgs e)
        {
            dataGridView1[dataGridView1.CurrentCellAddress.X, dataGridView1.CurrentCellAddress.Y].Value = textBox1.Text;
        }
    }
}
