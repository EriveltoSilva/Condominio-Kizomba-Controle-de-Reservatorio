using SMCNC_NIVEL_COMBUSTIVEL.Modelo;
using System;
using System.Collections.Generic;
using System.Data.OleDb;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace SMCNC_NIVEL_COMBUSTIVEL
{
    internal class CadastroDAO
    {
        private const String PASTA = "B.Dados\\";
        private const String NOME_DB = "db_bombas_combustivel.mdb";
        private OleDbConnection conexao;

        public CadastroDAO() {
            conexao = new OleDbConnection("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=" + PASTA + NOME_DB);
            conexao.Open();
        }

        public bool isSenhaAdmin(String senha)
        {
            string query = "SELECT * FROM tbl_usuario WHERE id = 1 AND senha = '" + senha + "';";
            OleDbCommand cmd = new OleDbCommand(query, conexao);
            OleDbDataReader reader = cmd.ExecuteReader();
            bool resultado = reader.Read();
            return resultado;
        }

        public bool adicionar(CadastroModelo usuario)
        {  
            string statement = "INSERT INTO tbl_usuario (email, username,senha) VALUES ('"+usuario.getEmailUtilizador()+"', '"+ usuario.getUsername()+"', '"+usuario.getSenhaUtilizador()+"');";
            OleDbCommand cmd = new OleDbCommand(statement, conexao);
            cmd.ExecuteNonQuery();
            return true;
        }

        public void fecharConexao()
        { 
            conexao.Close();
        }
    }
}
