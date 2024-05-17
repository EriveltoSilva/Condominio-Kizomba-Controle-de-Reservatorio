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

    public partial class Form1 : Form
    {
        private bool flagMute = false;

        public Form1()
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
            cbBaudRate.SelectedIndex = 2;
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

        private void receiveDataFromArduino(object sender, EventArgs e)
        {
            //0 - R, 1 - nivelRes1, 2- sensorRes1, 3- estadoBomba1, 4- vazao1, 5 - nivelRes2, 6- sensorRes2, 7- estadoBomba2, 8- vazao2

            String[] dados = serialPort1.ReadLine().Split('*');
            if (dados.Length == 12)
            {
                if (dados[0] == "R")
                {
                    lblWaterLevel1.Text = dados[1];
                    lblWaterLevel2.Text = dados[2];
                    if (dados[1] == "VAZIO" || dados[1] == "CRITICO")
                    {
                        lblWaterLevel1.ForeColor = Color.Red;
                    }
                    else
                    {
                        lblWaterLevel1.ForeColor = Color.FromArgb(0, 126, 249);
                    }

                    if (dados[2] == "VAZIO" || dados[2] == "CRITICO" || dados[2] == "EXCASSO")
                    {
                        lblWaterLevel2.ForeColor = Color.Red;
                    }
                    else
                    {
                        lblWaterLevel2.ForeColor = Color.FromArgb(0, 126, 249);
                    }

                    imageReserve1.Load("../../Resources/bomba" + dados[3] + ".png");
                    imageReserve2.Load("../../Resources/bomba" + dados[7] + ".png");

                    if (dados[4] == "1")
                    {
                        turnOnAlarme();
                    }

                    if (dados[8] == "1")
                    {
                        turnOnAlarme();
                    }

                    
                }
            }
        }

    }
}
