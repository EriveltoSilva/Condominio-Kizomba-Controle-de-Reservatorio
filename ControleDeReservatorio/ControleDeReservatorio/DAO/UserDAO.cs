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
            
        }

        private void openConnection()
        {
            connection = new OleDbConnection("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=" + PASTA + NOME_DB);
            connection.Open();
        }
        public bool isPasswordAdmin(string password)
        {
            openConnection();
            string query = "SELECT * FROM tbl_user WHERE email='admin@gmail.com' AND password = '" + password + "';";
            OleDbCommand cmd = new OleDbCommand(query, connection);
            OleDbDataReader reader = cmd.ExecuteReader();
            bool resultado = reader.Read();

            reader.Close();
            closeConnection();
            return resultado;
        }

        public bool isAdmin(String email, string password)
        {
            openConnection();
            string query = "SELECT * FROM tbl_user WHERE email ='"+ email+ "' AND password = '" + password + "' AND type='admin';";
            OleDbCommand cmd = new OleDbCommand(query, connection);
            OleDbDataReader reader = cmd.ExecuteReader();
            bool result = reader.Read();
            reader.Close();
            closeConnection();
            return result;
        }

        

    public bool save(UserModel user)
    {
        openConnection();
            string statement = "INSERT INTO tbl_user (email, username,password) VALUES ('" + user.getEmail() + "', '" + user.getUsername() + "', '" + user.getPassword() + "');";
            OleDbCommand cmd = new OleDbCommand(statement, connection);
            cmd.ExecuteNonQuery();
            closeConnection();
            return true;
    }

    public UserModel userExists(UserModel user)
        {
            string query = "SELECT * FROM tbl_user WHERE email ='" + user.getEmail() + "' AND password='" + user.getPassword() + "';";
            openConnection();
            OleDbCommand cmd = new OleDbCommand(query, connection);
            OleDbDataReader reader = cmd.ExecuteReader();
            //UserModel gotUser = (!reader.Read())? null: new UserModel(reader.GetString(1), reader.GetString(3), reader.GetString(4));
            UserModel gotUser = (!reader.Read()) ? null : new UserModel(reader.GetString(0), reader.GetString(2), reader.GetString(3));
            reader.Close();
            closeConnection();
            return gotUser;
        }


        public void closeConnection()
        {
            connection.Close();
        }
    }
}
