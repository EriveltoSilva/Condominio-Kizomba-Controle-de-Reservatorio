using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SMCNC_NIVEL_COMBUSTIVEL.Modelo
{
    internal class LoginModelo
    {
        private String email;
        private String senha;
        private String username;

        public  LoginModelo()
        {

        }

        public LoginModelo(String email, String senha)
        {
            this.email = email;
            this.senha = senha;
        }


        public void setEmail(String email)
        { 
            this.email = email; 
        }
        public void setSenha(String senha)
        {
            this.senha = senha;
        }
        public void setUsername(String username)
        {
            this.username = username;
        }
        
        public String getEmail()
        {
            return this.email;
        }

        public String getSenha()
        {
            return this.senha;
        }

        public String getUsername()
        {
            return this.username;
        }

    }
}
