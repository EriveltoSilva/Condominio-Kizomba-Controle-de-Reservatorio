using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data.OleDb;
using SMCNC_NIVEL_COMBUSTIVEL.Modelo;
using System.Windows.Forms;

namespace SMCNC_NIVEL_COMBUSTIVEL.DAO
{

    internal class LoginDAO
    {
        private const String PASTA = "B.Dados\\" ;
        private const String NOME_DB = "db_bombas_combustivel.mdb";
        private OleDbConnection conexao;

        public LoginDAO()
        {
            conexao = new OleDbConnection("Provider=Microsoft.Jet.OLEDB.4.0;Data Source="+PASTA+NOME_DB);
            conexao.Open();
        }

        public String existeUsuario(LoginModelo usuario)
        {
            string query = "SELECT * FROM tbl_usuario WHERE email ='"+usuario.getEmail()+"' AND senha='"+usuario.getSenha()+"';";
            OleDbCommand cmd = new OleDbCommand(query, conexao);
            OleDbDataReader reader = cmd.ExecuteReader();
            String nome =null; 
            if(reader.Read())
                nome = reader.GetString(4);
            conexao.Close();
            return nome;
        }
    }
}
