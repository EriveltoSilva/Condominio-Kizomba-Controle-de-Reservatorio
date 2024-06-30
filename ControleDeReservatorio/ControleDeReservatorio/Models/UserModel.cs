using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ControleDeReservatorio.Models
{
    public class UserModel
    {
        private String email;
        private String username;
        private String password;
        private String passwordAdmin;
        private String type;

        public UserModel()
        {

        }

        public UserModel(String email, String password)
        {
            this.email = email;
            this.password = password;
        }

        public UserModel(String email, String username, String passwordUser, String passwordAdmin)
        {
            this.email = email;
            this.username = username;
            this.password = passwordUser;
            this.passwordAdmin = passwordAdmin;
        }
        public UserModel(String email, String username, String type)
        {
            this.email = email;
            this.username = username;
            this.type = type;
        }

        public UserModel(String email, String username, String passwordUser, String passwordAdmin, String type)
        {
            this.email = email;
            this.username = username;
            this.password = passwordUser;
            this.passwordAdmin = passwordAdmin;
            this.type = type;
        }


        public void setEmail(String email)
        {
            this.email = email;
        }
        public void setPassword(String password)
        {
            this.password = password;
        }
        public void setPasswordAdmin(String passwordAdmin)
        {
            this.passwordAdmin = passwordAdmin;
        }

        public void setUsername(String username)
        {
            this.username = username;
        }
        public void setType(String type)
        {
            this.type = type;
        }


        public String getEmail()
        {
            return this.email;
        }

        public String getPassword()
        {
            return this.password;
        }

        public String getPasswordAdmin()
        {
            return this.passwordAdmin;
        }

        public String getUsername()
        {
            return this.username;
        }

        public String getType()
        {
            return this.type;
        }
    }
}

