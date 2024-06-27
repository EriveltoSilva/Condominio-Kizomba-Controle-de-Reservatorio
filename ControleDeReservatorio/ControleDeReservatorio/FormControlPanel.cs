using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO.Ports;
using System.Media;

namespace ControleDeReservatorio
{

    public partial class FormControlPanel : Form
    {
        private bool flagMute = false;

        public FormControlPanel()
        {
            InitializeComponent();
            initSerial();
        }

        private void btnExit_Click(object sender, EventArgs e)
        {
            closeCOMPort();
            Application.Exit();
        }

        

        private void btnConnect_Click(object sender, EventArgs e)
        {
            if (serialPort1.IsOpen)
            {
                closeCOMPort();
                btnConnect.Text = "Conectar";
                btnConnect.ForeColor = Color.Red;
                cbBaudRate.Enabled = true;
                cbSerialPort.Enabled = true;
                btnUpdateSerialPorts.Enabled = true;
            }
            else
            {
                serialPort1.PortName = cbSerialPort.Text;
                serialPort1.BaudRate = Int16.Parse(cbBaudRate.Text);
                try
                {
                    serialPort1.Open();
                    btnConnect.Text = "Desconectar";
                    btnConnect.ForeColor = Color.Green;
                    cbBaudRate.Enabled = false;
                    cbSerialPort.Enabled = false;
                    btnUpdateSerialPorts.Enabled = false;
                    MessageBox.Show("Comunicação com os Reservatórios Estabelecida com Sucesso!", "Comunicação", MessageBoxButtons.OK, MessageBoxIcon.Information);
                }
                catch
                {
                    MessageBox.Show("Porta \"" + cbSerialPort.Text + "\" já está sendo usada por outro programa!", "Erro de Conexão com a COM", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
            }
        }

       

        private void btnSilent_Click(object sender, EventArgs e)
        {
            if (flagMute = !flagMute)
                btnSilent.Text = "Silenciado";
            else
                btnSilent.Text = "Silenciar";
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            loadSerialPorts();
        }

        private void btnUpdateSerialPorts_Click(object sender, EventArgs e)
        {
            loadSerialPorts();
        }
        private void serialPort1_DataReceived(object sender, SerialDataReceivedEventArgs e)
        {
            this.Invoke(new EventHandler(receiveDataFromArduino));
        }




        /********************************  My personal fuctions ************************************************/
        private void initSerial()
        {
            cbBaudRate.SelectedIndex = 1;
            loadSerialPorts();
        }

        private void loadSerialPorts()
        {
            cbSerialPort.Items.Clear();
            foreach (string port in SerialPort.GetPortNames())
                cbSerialPort.Items.Add(port);

            if (SerialPort.GetPortNames().Length > 0)
                cbSerialPort.SelectedIndex = 0;
        }


        private void sendDataToArduino(String data)
        {
            serialPort1.Write(data);
        }

        private void closeCOMPort()
        {
            if (serialPort1.IsOpen)
                serialPort1.Close();
        }

        private void turnOnAlarme()
        {
            if (!flagMute)
                SystemSounds.Beep.Play();
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

            if (numReserve==1)
                imageReserve1.Load("../../Resources/reservatorio" + path+ ".png");
            else
                imageReserve2.Load("../../Resources/reservatorio" + path + ".png");
        }

        private void receiveDataFromArduino(object sender, EventArgs e)
        {
            // 0-R, 1-nivelReservatorio1, 2- leituraReservatorio1, 3-nivelReservatorio2, 4- leituraReservatorio2,
            String[] dados = serialPort1.ReadLine().Split('*');
            if (dados.Length == 6)
            {
                if (dados[0] == "R")
                {
                    lblWaterLevel1.Text = dados[1];
                    lblWaterReading1.Text = dados[2];

                    lblWaterLevel2.Text = dados[3];
                    lblWaterReading2.Text = dados[4];

                    if (dados[1] == "VAZIO" || dados[1]== "CRITICO" || dados[1] == "QUASE VAZIO")
                    {
                        lblWaterLevel1.ForeColor = Color.FromArgb(220, 53, 69);     // VERMELHO danger
                        lblWaterReading1.ForeColor = Color.FromArgb(220, 53, 69);   // VERMELHO danger
                        turnOnAlarme();
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
                        turnOnAlarme();
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

        private void lblWaterReading1_Click(object sender, EventArgs e)
        {

        }
    }
}
