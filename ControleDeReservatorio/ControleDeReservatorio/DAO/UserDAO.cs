using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data.OleDb;
using ControleDeReservatorio.Models;

namespace ControleDeReservatorio.DAO
{
    internal class UserDAO
    {
        private const string PASTA = "Database\\";
        private const string NOME_DB = "db_reservatorio.mdb";
        private OleDbConnection connection;

        public UserDAO()
        {
            connection = new OleDbConnection("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=" + PASTA + NOME_DB);
            connection.Open();
        }

        public bool isPasswordAdmin(string password)
        {
            string query = "SELECT * FROM tbl_user WHERE id = 1 AND password = '" + password + "';";
            OleDbCommand cmd = new OleDbCommand(query, connection);
            OleDbDataReader reader = cmd.ExecuteReader();
            bool resultado = reader.Read();
            return resultado;
        }

        public bool save(UserModel user)
        {
            string statement = "INSERT INTO tbl_user (email, username, password, type) VALUES ('" + user.getEmail() + "', '" + user.getUsername() + "', '" + user.getPassword()+ "', '"+ user.getType() + "');";
            OleDbCommand cmd = new OleDbCommand(statement, connection);
            cmd.ExecuteNonQuery();
            return true;
        }

        public UserModel userExists(UserModel user)
        {
            string query = "SELECT * FROM tbl_user WHERE email ='" + user.getEmail() + "' AND password='" + user.getPassword() + "';";
            OleDbCommand cmd = new OleDbCommand(query, connection);
            OleDbDataReader reader = cmd.ExecuteReader();
            UserModel gotUser = (!reader.Read())? null: new UserModel(reader.GetString(1), reader.GetString(3), reader.GetString(4));
            reader.Close();
            connection.Close();
            return gotUser;
        }


        public void closeConnection()
        {
            connection.Close();
        }
    }
}
