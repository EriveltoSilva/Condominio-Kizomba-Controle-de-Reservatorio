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
    public partial class FormRegister : Form
    {
        private UserModel user;

        public FormRegister()
        {
            InitializeComponent();
        }
        public FormRegister(UserModel user)
        {
            InitializeComponent();
            this.user = user;
        }

        private void btnExit_Click(object sender, EventArgs e)
        {

        }

        private void cbShowPassword_CheckedChanged(object sender, EventArgs e)
        {
            txtBoxPassword.PasswordChar = (cbShowPassword.Checked) ? '\0' : '*';
            txtBoxPasswordAdmin.PasswordChar = (cbShowPassword.Checked) ? '\0' : '*';
            txtBoxConfirmationPassword.PasswordChar = (cbShowPassword.Checked) ? '\0' : '*';
        }

        private void btnRegister_Click(object sender, EventArgs e)
        {
            if (validateForm())
            {
                UserModel userModel = new UserModel(txtBoxEmail.Text, txtBoxUsername.Text, txtBoxPassword.Text, txtBoxPasswordAdmin.Text);
                UserDAO userDAO = new UserDAO();
                //if (userDAO.isPasswordAdmin(userModel.getPasswordAdmin()))
                if (userDAO.isAdmin(user.getEmail(), userModel.getPasswordAdmin()))
                {
                    if (userDAO.save(userModel))
                        MessageBox.Show("Usuário Cadastrado!", "Cadastro de Usuário", MessageBoxButtons.OK, MessageBoxIcon.Information);
                    else
                        MessageBox.Show("Erro Cadastrando Usuario!", "Cadastro de Usuário", MessageBoxButtons.OK, MessageBoxIcon.Error);
                        cleanFields();
                }
                else
                {
                    MessageBox.Show("Senha Admin Errada!", "Cadastro de Usuário", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
                userDAO.closeConnection();
            }
        }

        private bool validateForm()
        {
            if (txtBoxEmail.Text.Equals(""))
            {
                MessageBox.Show("Campo Email Vazio. Preencha-o!", "ERRO de Cadastro", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return false;
            }
            else if (!txtBoxEmail.Text.Contains("@"))
            {
                MessageBox.Show("Campo Email o caracter @.", "ERRO de Cadastro", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return false;
            }
            else if (txtBoxPassword.Text.Equals(""))
            {
                MessageBox.Show("Campo Senha Utilizador Vazio. Preencha-o!", "ERRO de Cadastro", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return false;
            }
            else if (txtBoxConfirmationPassword.Text.Equals(""))
            {
                MessageBox.Show("Campo Senha de Confirmação do Utilizador Vazio. Preencha-o!", "ERRO de Cadastro", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return false;
            }
            else if (!txtBoxPassword.Text.Equals(txtBoxConfirmationPassword.Text))
            {
                MessageBox.Show("Campos Senha do Utilizador e Senha de Confirmação Diferentes. Preencha-o correctamente!", "ERRO de Cadastro", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return false;
            }
            else if (txtBoxPasswordAdmin.Text.Equals(""))
            {
                MessageBox.Show("Campo Senha Admin Vazio. Preencha-o!", "ERRO de Cadastro", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return false;
            }
            return true;
        }

        private void cleanFields()
        {
            txtBoxEmail.Text = "";
            txtBoxPassword.Text = "";
            txtBoxPasswordAdmin.Text = "";
            txtBoxEmail.Focus();
        }

        private void label6_Click(object sender, EventArgs e)
        {

        }

        private void btnExit_Click_1(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void FormRegister_Load(object sender, EventArgs e)
        {

        }
    }
}
