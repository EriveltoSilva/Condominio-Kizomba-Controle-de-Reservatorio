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
            if (nivel == "0") path = "0";
            else if (nivel == "1") path = "10";
            else if (nivel == "2") path = "20";
            else if (nivel == "3") path = "30";
            else if (nivel == "4") path = "30";
            else if (nivel == "5") path = "50";
            else if (nivel == "6") path = "50";
            else if (nivel == "7") path = "70";
            else if (nivel == "8") path = "80";
            else if (nivel == "9") path = "80";
            else if (nivel == "10") path = "100";

            if (numReserve == 1)
                imageReserve1.Load("../../Resources/reservatorio" + path + ".png");
            else
                imageReserve2.Load("../../Resources/reservatorio" + path + ".png");
        }

        

        public void setData(String[] dados)
        {
            Console.WriteLine(dados.Length);
            if (dados.Length == 4)
            {
                setDataReservoir(dados[1], dados[2]);
                if (dados[1].Equals("0") || dados[1].Equals("1") || dados[1].Equals("2"))
                {
                    lblWaterLevel1.ForeColor = Color.FromArgb(220, 53, 69);     // VERMELHO danger
                    lblWaterReading1.ForeColor = Color.FromArgb(220, 53, 69);   // VERMELHO danger
                }
                else
                {
                    lblWaterLevel1.ForeColor = Color.FromArgb(0, 126, 249);
                    lblWaterReading1.ForeColor = Color.FromArgb(0, 126, 249);
                }


                if (dados[2] == "0" || dados[2] == "1" || dados[2] == "2")
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
                setImage(2, dados[2]);
            }
        }

        private void setDataReservoir(String value1, String value2)
        {
            if(value1.Equals("0"))
            {
                lblWaterLevel1.Text = "VAZIO";
                lblWaterReading1.Text = "0%";
            }
            else if (value1.Equals("1"))
            {
                lblWaterLevel1.Text = "CRITICO";
                lblWaterReading1.Text = "10%";
            }
            else if (value1.Equals("2"))
            {
                lblWaterLevel1.Text = "QUASE VAZIO";
                lblWaterReading1.Text = "20%";
            }
            else if (value1.Equals("3"))
            {
                lblWaterLevel1.Text = "BAIXO";
                lblWaterReading1.Text = "30%";
            }
            else if (value1.Equals("4"))
            {
                lblWaterLevel1.Text = "MEDIO BAIXO";
                lblWaterReading1.Text = "40%";
            }
            else if (value1.Equals("5"))
            {
                lblWaterLevel1.Text = "MEDIO";
                lblWaterReading1.Text = "50%";
            }
            else if (value1.Equals("6"))
            {
                lblWaterLevel1.Text = "MEDIO ALTO";
                lblWaterReading1.Text = "60%";
            }
            else if (value1.Equals("7"))
            {
                lblWaterLevel1.Text = "ALTO";
                lblWaterReading1.Text = "70%";
            }
            else if (value1.Equals("8"))
            {
                lblWaterLevel1.Text = "MUITO ALTO";
                lblWaterReading1.Text = "80%";
            }
            else if (value1.Equals("9"))
            {
                lblWaterLevel1.Text = "QUASE CHEIO";
                lblWaterReading1.Text = "90%";
            }
            else if (value1.Equals("10"))
            {
                lblWaterLevel1.Text = "CHEIO";
                lblWaterReading1.Text = "100%";
            }

            //-------------------------------------------------------------
            if (value2 == "0")
            {
                lblWaterLevel2.Text = "VAZIO";
                lblWaterReading2.Text = "0%";
            }
            else if ("1".Equals(value2))
            {
                lblWaterLevel2.Text = "CRITICO";
                lblWaterReading2.Text = "10%";
            }
            else if ("2".Equals(value2))
            {
                lblWaterLevel2.Text = "QUASE VAZIO";
                lblWaterReading2.Text = "20%";
            }
            else if ("3".Equals(value2))
            {
                lblWaterLevel2.Text = "BAIXO";
                lblWaterReading2.Text = "30%";
            }
            else if ("4".Equals(value2))
            {
                lblWaterLevel2.Text = "MEDIO BAIXO";
                lblWaterReading2.Text = "40%";
            }
            else if ("5".Equals(value2))
            {
                lblWaterLevel2.Text = "MEDIO";
                lblWaterReading2.Text = "50%";
            }
            else if ("6".Equals(value2))
            {
                lblWaterLevel2.Text = "MEDIO ALTO";
                lblWaterReading2.Text = "60%";
            }
            else if ("7".Equals(value2))
            {
                lblWaterLevel2.Text = "ALTO";
                lblWaterReading2.Text = "70%";
            }
            else if ("8".Equals(value2))
            {
                lblWaterLevel2.Text = "MUITO ALTO";
                lblWaterReading2.Text = "80%";
            }
            else if ("9".Equals(value2))
            {
                lblWaterLevel2.Text = "QUASE CHEIO";
                lblWaterReading2.Text = "90%";
            }
            else if ("10".Equals(value2))
            {
                lblWaterLevel2.Text = "CHEIO";
                lblWaterReading2.Text = "100%";
            }


        }

        private void btnExit_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }
    }
}
