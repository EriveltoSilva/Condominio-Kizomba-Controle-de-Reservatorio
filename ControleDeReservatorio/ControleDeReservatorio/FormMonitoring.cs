using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ControleDeReservatorio
{
    public partial class FormMonitoring : Form
    {
        public FormMonitoring()
        {
            InitializeComponent();
        }

        public FormMonitoring(String title)
        {
            InitializeComponent();
            lbl_active_menu.Text = title;

        }

        private void FormMonitoring_Load(object sender, EventArgs e)
        {

        }

        private void setImage(int numReserve, String nivel)
        {
            // 100-CHEIO, 90-QUASE CHEIO, 80-MUITO ALTO, 70-ALTO, 60-MEDIO ALTO, 50-MEDIO , 40-MEDIO BAIXO , 30-BAIXO , 20-QUASE VAZIO , 10-CRITICO , 0-VAZIO
            String path = "";
            if (nivel == "VAZIO") path = "0";
            else if (nivel == "CRITICO") path = "10";
            else if (nivel == "QUASE VAZIO") path = "20";
            else if (nivel == "BAIXO") path = "30";
            else if (nivel == "MEDIO BAIXO") path = "30";
            else if (nivel == "MEDIO") path = "50";
            else if (nivel == "MEDIO ALTO") path = "50";
            else if (nivel == "ALTO") path = "70";
            else if (nivel == "MUITO ALTO") path = "80";
            else if (nivel == "QUASE CHEIO") path = "80";
            else if (nivel == "CHEIO") path = "100";

            if (numReserve == 1)
                imageReserve1.Load("../../Resources/reservatorio" + path + ".png");
            else
                imageReserve2.Load("../../Resources/reservatorio" + path + ".png");
        }

        public void setData(String[] dados)
        {
            if (dados.Length == 6)
            {
                if (dados[0] == "R")
                {
                    lblWaterLevel1.Text = dados[1];
                    lblWaterReading1.Text = dados[2];

                    lblWaterLevel2.Text = dados[3];
                    lblWaterReading2.Text = dados[4];

                    if (dados[1] == "VAZIO" || dados[1] == "CRITICO" || dados[1] == "QUASE VAZIO")
                    {
                        lblWaterLevel1.ForeColor = Color.FromArgb(220, 53, 69);     // VERMELHO danger
                        lblWaterReading1.ForeColor = Color.FromArgb(220, 53, 69);   // VERMELHO danger
                    }
                    else
                    {
                        lblWaterLevel1.ForeColor = Color.FromArgb(0, 126, 249);
                        lblWaterReading1.ForeColor = Color.FromArgb(0, 126, 249);
                    }


                    if (dados[3] == "VAZIO" || dados[3] == "CRITICO" || dados[3] == "QUASE VAZIO")
                    {
                        lblWaterLevel2.ForeColor = Color.FromArgb(220, 53, 69);
                        lblWaterReading2.ForeColor = Color.FromArgb(220, 53, 69);
                    }
                    else
                    {
                        lblWaterLevel2.ForeColor = Color.FromArgb(0, 126, 249);     // verde success
                        lblWaterReading2.ForeColor = Color.FromArgb(0, 126, 249);   // verde success
                    }

                    setImage(1, dados[1]);
                    setImage(2, dados[3]);
                }
            }
        }


    }
}
