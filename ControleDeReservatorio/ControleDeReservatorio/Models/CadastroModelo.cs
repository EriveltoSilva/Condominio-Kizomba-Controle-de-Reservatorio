using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SMCNC_NIVEL_COMBUSTIVEL.Modelo
{
    internal class CadastroModelo
    {
        private String emailUtilizador;
        private String username;
        private String senhaUtilizador;
        private String senhaAdmin;

        public CadastroModelo()
        {

        }
        public CadastroModelo(String email, String username,String senhaU, String senhaA)
        {
            this.emailUtilizador = email;
            this.username = username;
            this.senhaUtilizador = senhaU;
            this.senhaAdmin = senhaA;
        }

        void setEmailUtilizador(String email)
        {
            this.emailUtilizador = email;
        }
        void setSenhaUtilizador(String senha)
        {
            this.senhaUtilizador = senha;
        }
        void setSenhaAdmin(String senha)
        {
            this.senhaAdmin = senha;
        }
        void setUsername(String username)
        {
            this.username = username;
        }

        public String getEmailUtilizador()
        {
            return this.emailUtilizador;
        }

        public String getSenhaUtilizador()
        {
            return this.senhaUtilizador;
        }
        public String getSenhaAdmin()
        {
            return this.senhaAdmin;
        }
        public String getUsername()
        {
            return this.username;
        }
    }
}
