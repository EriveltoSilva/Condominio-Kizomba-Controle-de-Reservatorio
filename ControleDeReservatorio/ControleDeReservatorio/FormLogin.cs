using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using ControleDeReservatorio.DAO;
using ControleDeReservatorio.Models;

namespace ControleDeReservatorio
{
    public partial class FormLogin : Form
    {
        public FormLogin()
        {
            InitializeComponent();
        }

        private void btnLogin_Click(object sender, EventArgs e)
        {
            Hide();
            new FormControlPanel().Show();
        }

        private void btnExit_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void textPassword_TextChanged(object sender, EventArgs e)
        {

        }

        private void btnLogin_Click_1(object sender, EventArgs e)
        {
            if (validateForm())
            {
                UserModel userModel = new UserModel(txtBoxEmail.Text, txtBoxPassword.Text);
                UserDAO userDAO = new UserDAO();
                userModel = userDAO.userExists(userModel);

                if (userModel != null)
                {
                    MessageBox.Show("Usuário Válido!", "Info Login", MessageBoxButtons.OK, MessageBoxIcon.Information);
                    this.Hide();
                    new FormControlPanel(userModel).Show();
                }
                else
                {
                    MessageBox.Show("Usuário Inválido!", "Info Login", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    cleanFields();
                }
            }
        }

        private void cleanFields()
        {
            txtBoxEmail.Text = "";
            txtBoxPassword.Text = "";
            txtBoxEmail.Focus();
        }


        private bool validateForm()
        {
            if (txtBoxEmail.Text == "")
            {
                MessageBox.Show("Campo Email Vazio. Preencha-o!", "ERRO de Cadastro", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return false;
            }
            else if (!txtBoxEmail.Text.Contains("@"))
            {
                MessageBox.Show("Campo Email o caracter @.", "ERRO de Cadastro", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return false;
            }
            else if (txtBoxPassword.Text == "")
            {
                MessageBox.Show("Campo Senha Vazio. Preencha-o!", "ERRO de Cadastro", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return false;
            }
            return true;
        }

        private void cbShowPassword_CheckedChanged(object sender, EventArgs e)
        {
           txtBoxPassword.PasswordChar = (cbShowPassword.Checked)?'\0':'*';
        }

        private void label4_Click(object sender, EventArgs e)
        {

        }

        private void label2_Click(object sender, EventArgs e)
        {

        }
    }
}
