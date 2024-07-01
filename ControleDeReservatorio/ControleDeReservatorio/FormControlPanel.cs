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
using ControleDeReservatorio.Models;



namespace ControleDeReservatorio
{

    public partial class FormControlPanel : Form
    {
        private bool flagMute = false;
        private FormMonitoring formMonitoringRF;
        private FormMonitoring formMonitoringRW;
        private FormMonitoring formMonitoringWW;
        private FormRegister formRegister;
        private UserModel user;

        public FormControlPanel()
        {
            InitializeComponent();
            initSerial();
            lbl_login_date.Text = DateTime.Now.ToString("dd/MM/yyyy HH:mm:ss");
            pnl_nav.Height = btnMenuRF.Height;
            pnl_nav.Top = btnMenuRF.Top;
            pnl_nav.Left = btnMenuRF.Left;
            btnMenuRF.BackColor = Color.FromArgb(46, 51, 73);

            formMonitoringRF = new FormMonitoring("PAINEL  FW1 e FW2") { Dock = DockStyle.Fill, TopLevel = false, TopMost = true };
            formMonitoringRF.FormBorderStyle = FormBorderStyle.None;

            formMonitoringRW = new FormMonitoring("PAINEL RW1 e RW2") { Dock = DockStyle.Fill, TopLevel = false, TopMost = true };
            formMonitoringRW.FormBorderStyle = FormBorderStyle.None;

            formMonitoringWW = new FormMonitoring("PAINEL WW1 e WW2") { Dock = DockStyle.Fill, TopLevel = false, TopMost = true };
            formMonitoringWW.FormBorderStyle = FormBorderStyle.None;

            formRegister = new FormRegister(this.user) { Dock = DockStyle.Fill, TopLevel = false, TopMost = true };
            formRegister.FormBorderStyle = FormBorderStyle.None;

            this.pnl_form_loader.Controls.Clear();
            this.pnl_form_loader.Controls.Add(formMonitoringRF);
            formMonitoringRF.Show();
        }

        public FormControlPanel(UserModel user)
        {
            InitializeComponent();
            initSerial();
            this.user = user;
            lbl_username.Text = user.getUsername();
            lbl_login_date.Text = DateTime.Now.ToString("dd/MM/yyyy HH:mm:ss");
            pnl_nav.Height = btnMenuRF.Height;
            pnl_nav.Top = btnMenuRF.Top;
            pnl_nav.Left = btnMenuRF.Left;
            btnMenuRF.BackColor = Color.FromArgb(46, 51, 73);
        
            formMonitoringRF = new FormMonitoring("CONTROLE DO FW1 & FW2") { Dock = DockStyle.Fill, TopLevel = false, TopMost = true };
            formMonitoringRF.FormBorderStyle = FormBorderStyle.None;

            formMonitoringRW = new FormMonitoring("CONTROLE DO RW1 & RW2") { Dock = DockStyle.Fill, TopLevel = false, TopMost = true };
            formMonitoringRW.FormBorderStyle = FormBorderStyle.None;

            formMonitoringWW = new FormMonitoring("CONTROLE DO WW1 & WW2") { Dock = DockStyle.Fill, TopLevel = false, TopMost = true };
            formMonitoringWW.FormBorderStyle = FormBorderStyle.None;

            formRegister = new FormRegister(this.user) { Dock = DockStyle.Fill, TopLevel = false, TopMost = true };
            formRegister.FormBorderStyle = FormBorderStyle.None;

            this.pnl_form_loader.Controls.Clear();
            this.pnl_form_loader.Controls.Add(formMonitoringRF);
            formMonitoringRF.Show();
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
                btnConnect.ForeColor = Color.Green;
                cbBaudRate.Enabled = true;
                cbSerialPort.Enabled = true;
                btnUpdateSerialPorts.Enabled = true;
                pnl_serial.Visible = true;
            }
            else
            {
                serialPort1.PortName = cbSerialPort.Text;
                serialPort1.BaudRate = Int16.Parse(cbBaudRate.Text);
                try
                {
                    serialPort1.Open();
                    btnConnect.Text = "Desconectar";
                    btnConnect.ForeColor = Color.Red;
                    cbBaudRate.Enabled = false;
                    cbSerialPort.Enabled = false;
                    btnUpdateSerialPorts.Enabled = false;
                    pnl_serial.Visible = false;
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

        

        private void receiveDataFromArduino(object sender, EventArgs e)
        {
            // 0-R, 1-nivelReservatorio1, 2- leituraReservatorio1, 3-nivelReservatorio2, 4- leituraReservatorio2,
            String[] dados = serialPort1.ReadLine().Split('*');
            if (dados.Length==4)
            {

            if(dados[0]=="FW" && formMonitoringRF != null)
                formMonitoringRF.setData(dados);
            else if(dados[0] == "RW" && formMonitoringRW != null)
                formMonitoringRW.setData(dados);
            else if (dados[0] == "WW" && formMonitoringWW != null)
                formMonitoringWW.setData(dados);
            }
        }

        private void cleanAllBackground()
        {
            btnMenuRF.BackColor = Color.FromArgb(24, 30, 54);
            btnMenuRW.BackColor = Color.FromArgb(24, 30, 54);
            btnMenuWW.BackColor = Color.FromArgb(24, 30, 54);
            btnRegiterUser.BackColor = Color.FromArgb(24, 30, 54);
        }

        private void hideFields()
        {
            this.pnl_form_loader.Controls.Clear();
            formMonitoringRF.Hide();
            formMonitoringRW.Hide();
            formMonitoringWW.Hide();
            formRegister.Hide();
        }
        private void btnMenuRF_Click(object sender, EventArgs e)
        {
            cleanAllBackground();
            pnl_nav.Height = btnMenuRF.Height;
            pnl_nav.Top = btnMenuRF.Top;
            pnl_nav.Left = btnMenuRF.Left;
            btnMenuRF.BackColor = Color.FromArgb(46, 51, 73);
           
            hideFields();
            this.pnl_form_loader.Controls.Add(formMonitoringRF);
            formMonitoringRF.Show();
        }

        private void btnMenuRW_Click(object sender, EventArgs e)
        {
            cleanAllBackground();
            pnl_nav.Height = btnMenuRW.Height;
            pnl_nav.Top = btnMenuRW.Top;
            pnl_nav.Left = btnMenuRW.Left;
            btnMenuRW.BackColor = Color.FromArgb(46, 51, 73);
            
            hideFields();
            this.pnl_form_loader.Controls.Add(formMonitoringRW);
            formMonitoringRW.Show();
        }

        private void bntMenuWW_Click(object sender, EventArgs e)
        {
            cleanAllBackground();
            pnl_nav.Height = btnMenuWW.Height;
            pnl_nav.Top = btnMenuWW.Top;
            pnl_nav.Left = btnMenuWW.Left;
            btnMenuWW.BackColor = Color.FromArgb(46, 51, 73);

            hideFields();
            this.pnl_form_loader.Controls.Add(formMonitoringWW);
            formMonitoringWW.Show();
        }

        private void btnMenuRF_Leave(object sender, EventArgs e)
        {
            btnMenuRF.BackColor = Color.FromArgb(24, 30, 54);
        }

        private void btnMenuRW_Leave(object sender, EventArgs e)
        {
            btnMenuRW.BackColor = Color.FromArgb(24, 30, 54);
        }

        private void btnMenuWW_Leave(object sender, EventArgs e)
        {
            btnMenuWW.BackColor = Color.FromArgb(24, 30, 54);
        }

        private void btnExit_Click_1(object sender, EventArgs e)
        {
            closeCOMPort();
            Application.Exit();
        }

        private void btnRegiterUser_Click(object sender, EventArgs e)
        {
            cleanAllBackground();
            pnl_nav.Height = btnRegiterUser.Height;
            pnl_nav.Top = btnRegiterUser.Top;
            pnl_nav.Left = btnRegiterUser.Left;
            btnRegiterUser.BackColor = Color.FromArgb(46, 51, 73);

            hideFields();
            this.pnl_form_loader.Controls.Add(formRegister);
            formRegister.Show();
        }
    }
}
