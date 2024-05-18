namespace ControleDeReservatorio
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.serialPort1 = new System.IO.Ports.SerialPort(this.components);
            this.panel1 = new System.Windows.Forms.Panel();
            this.panel3 = new System.Windows.Forms.Panel();
            this.cbBaudRate = new System.Windows.Forms.ComboBox();
            this.btnUpdateSerialPorts = new System.Windows.Forms.Button();
            this.label3 = new System.Windows.Forms.Label();
            this.btnConnect = new System.Windows.Forms.Button();
            this.cbSerialPort = new System.Windows.Forms.ComboBox();
            this.label2 = new System.Windows.Forms.Label();
            this.btnSilent = new System.Windows.Forms.Button();
            this.panel2 = new System.Windows.Forms.Panel();
            this.panel4 = new System.Windows.Forms.Panel();
            this.lbl_login_date = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.btnExit = new System.Windows.Forms.Button();
            this.panel5 = new System.Windows.Forms.Panel();
            this.panel6 = new System.Windows.Forms.Panel();
            this.lblWaterLevel1 = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.panel7 = new System.Windows.Forms.Panel();
            this.panel8 = new System.Windows.Forms.Panel();
            this.label6 = new System.Windows.Forms.Label();
            this.lblWaterLevel2 = new System.Windows.Forms.Label();
            this.label9 = new System.Windows.Forms.Label();
            this.imageReserve2 = new System.Windows.Forms.PictureBox();
            this.imageReserve1 = new System.Windows.Forms.PictureBox();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.lblWaterReading1 = new System.Windows.Forms.Label();
            this.lblWaterReading2 = new System.Windows.Forms.Label();
            this.panel1.SuspendLayout();
            this.panel3.SuspendLayout();
            this.panel2.SuspendLayout();
            this.panel5.SuspendLayout();
            this.panel6.SuspendLayout();
            this.panel7.SuspendLayout();
            this.panel8.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.imageReserve2)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.imageReserve1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.SuspendLayout();
            // 
            // serialPort1
            // 
            this.serialPort1.DataReceived += new System.IO.Ports.SerialDataReceivedEventHandler(this.serialPort1_DataReceived);
            // 
            // panel1
            // 
            this.panel1.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(24)))), ((int)(((byte)(30)))), ((int)(((byte)(54)))));
            this.panel1.Controls.Add(this.panel3);
            this.panel1.Controls.Add(this.btnSilent);
            this.panel1.Controls.Add(this.panel2);
            this.panel1.Dock = System.Windows.Forms.DockStyle.Left;
            this.panel1.Location = new System.Drawing.Point(0, 0);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(250, 718);
            this.panel1.TabIndex = 0;
            // 
            // panel3
            // 
            this.panel3.Controls.Add(this.cbBaudRate);
            this.panel3.Controls.Add(this.btnUpdateSerialPorts);
            this.panel3.Controls.Add(this.label3);
            this.panel3.Controls.Add(this.btnConnect);
            this.panel3.Controls.Add(this.cbSerialPort);
            this.panel3.Controls.Add(this.label2);
            this.panel3.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.panel3.Location = new System.Drawing.Point(0, 465);
            this.panel3.Name = "panel3";
            this.panel3.Size = new System.Drawing.Size(250, 253);
            this.panel3.TabIndex = 1;
            // 
            // cbBaudRate
            // 
            this.cbBaudRate.FormattingEnabled = true;
            this.cbBaudRate.Items.AddRange(new object[] {
            "4800",
            "9600",
            "19200",
            "115200"});
            this.cbBaudRate.Location = new System.Drawing.Point(0, 102);
            this.cbBaudRate.Name = "cbBaudRate";
            this.cbBaudRate.Size = new System.Drawing.Size(250, 24);
            this.cbBaudRate.TabIndex = 5;
            // 
            // btnUpdateSerialPorts
            // 
            this.btnUpdateSerialPorts.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.btnUpdateSerialPorts.FlatAppearance.BorderSize = 0;
            this.btnUpdateSerialPorts.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnUpdateSerialPorts.Font = new System.Drawing.Font("Nirmala UI", 10.2F, System.Drawing.FontStyle.Underline, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnUpdateSerialPorts.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(45)))), ((int)(((byte)(218)))), ((int)(((byte)(188)))));
            this.btnUpdateSerialPorts.Location = new System.Drawing.Point(0, 146);
            this.btnUpdateSerialPorts.Name = "btnUpdateSerialPorts";
            this.btnUpdateSerialPorts.Size = new System.Drawing.Size(250, 44);
            this.btnUpdateSerialPorts.TabIndex = 2;
            this.btnUpdateSerialPorts.Text = "Actualizar";
            this.btnUpdateSerialPorts.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.btnUpdateSerialPorts.UseVisualStyleBackColor = true;
            this.btnUpdateSerialPorts.Click += new System.EventHandler(this.btnUpdateSerialPorts_Click);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Nirmala UI", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(226)))), ((int)(((byte)(226)))), ((int)(((byte)(249)))));
            this.label3.Location = new System.Drawing.Point(3, 76);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(97, 23);
            this.label3.TabIndex = 4;
            this.label3.Text = "Baud Rate:";
            // 
            // btnConnect
            // 
            this.btnConnect.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.btnConnect.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnConnect.Font = new System.Drawing.Font("Nirmala UI", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnConnect.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(192)))), ((int)(((byte)(0)))));
            this.btnConnect.Location = new System.Drawing.Point(0, 190);
            this.btnConnect.Name = "btnConnect";
            this.btnConnect.Size = new System.Drawing.Size(250, 63);
            this.btnConnect.TabIndex = 3;
            this.btnConnect.Text = "Conectar";
            this.btnConnect.UseVisualStyleBackColor = true;
            this.btnConnect.Click += new System.EventHandler(this.btnConnect_Click);
            // 
            // cbSerialPort
            // 
            this.cbSerialPort.FormattingEnabled = true;
            this.cbSerialPort.Location = new System.Drawing.Point(0, 35);
            this.cbSerialPort.Name = "cbSerialPort";
            this.cbSerialPort.Size = new System.Drawing.Size(250, 24);
            this.cbSerialPort.TabIndex = 1;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Nirmala UI", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(226)))), ((int)(((byte)(226)))), ((int)(((byte)(249)))));
            this.label2.Location = new System.Drawing.Point(3, 9);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(107, 23);
            this.label2.TabIndex = 0;
            this.label2.Text = "Porta Serial:";
            // 
            // btnSilent
            // 
            this.btnSilent.Dock = System.Windows.Forms.DockStyle.Top;
            this.btnSilent.FlatAppearance.BorderSize = 0;
            this.btnSilent.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnSilent.Font = new System.Drawing.Font("Nirmala UI", 10.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnSilent.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(126)))), ((int)(((byte)(249)))));
            this.btnSilent.Location = new System.Drawing.Point(0, 181);
            this.btnSilent.Name = "btnSilent";
            this.btnSilent.Size = new System.Drawing.Size(250, 59);
            this.btnSilent.TabIndex = 1;
            this.btnSilent.Text = "Silenciar Alarme";
            this.btnSilent.UseVisualStyleBackColor = true;
            this.btnSilent.Click += new System.EventHandler(this.btnSilent_Click);
            // 
            // panel2
            // 
            this.panel2.Controls.Add(this.panel4);
            this.panel2.Controls.Add(this.lbl_login_date);
            this.panel2.Controls.Add(this.label1);
            this.panel2.Controls.Add(this.pictureBox1);
            this.panel2.Dock = System.Windows.Forms.DockStyle.Top;
            this.panel2.Location = new System.Drawing.Point(0, 0);
            this.panel2.Name = "panel2";
            this.panel2.Size = new System.Drawing.Size(250, 181);
            this.panel2.TabIndex = 1;
            // 
            // panel4
            // 
            this.panel4.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(126)))), ((int)(((byte)(249)))));
            this.panel4.Location = new System.Drawing.Point(0, 193);
            this.panel4.Name = "panel4";
            this.panel4.Size = new System.Drawing.Size(3, 100);
            this.panel4.TabIndex = 2;
            // 
            // lbl_login_date
            // 
            this.lbl_login_date.AutoSize = true;
            this.lbl_login_date.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbl_login_date.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(158)))), ((int)(((byte)(161)))), ((int)(((byte)(178)))));
            this.lbl_login_date.Location = new System.Drawing.Point(45, 136);
            this.lbl_login_date.Name = "lbl_login_date";
            this.lbl_login_date.Size = new System.Drawing.Size(158, 15);
            this.lbl_login_date.TabIndex = 2;
            this.lbl_login_date.Text = "Ligado desde: 14:31:02";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(126)))), ((int)(((byte)(249)))));
            this.label1.Location = new System.Drawing.Point(67, 106);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(94, 20);
            this.label1.TabIndex = 1;
            this.label1.Text = "Username";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Nirmala UI", 16.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label4.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(158)))), ((int)(((byte)(161)))), ((int)(((byte)(176)))));
            this.label4.Location = new System.Drawing.Point(291, 27);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(430, 38);
            this.label4.TabIndex = 1;
            this.label4.Text = "CONTROLE DE RESERVATÓRIOS";
            // 
            // btnExit
            // 
            this.btnExit.FlatAppearance.BorderSize = 0;
            this.btnExit.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnExit.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnExit.ForeColor = System.Drawing.Color.White;
            this.btnExit.Location = new System.Drawing.Point(1528, 12);
            this.btnExit.Name = "btnExit";
            this.btnExit.Size = new System.Drawing.Size(40, 42);
            this.btnExit.TabIndex = 2;
            this.btnExit.Text = "x";
            this.btnExit.UseVisualStyleBackColor = true;
            this.btnExit.Click += new System.EventHandler(this.btnExit_Click);
            // 
            // panel5
            // 
            this.panel5.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(38)))), ((int)(((byte)(43)))), ((int)(((byte)(63)))));
            this.panel5.Controls.Add(this.lblWaterReading1);
            this.panel5.Controls.Add(this.imageReserve1);
            this.panel5.Controls.Add(this.panel6);
            this.panel5.Controls.Add(this.label5);
            this.panel5.Location = new System.Drawing.Point(299, 82);
            this.panel5.Name = "panel5";
            this.panel5.Size = new System.Drawing.Size(557, 560);
            this.panel5.TabIndex = 3;
            // 
            // panel6
            // 
            this.panel6.Controls.Add(this.lblWaterLevel1);
            this.panel6.Controls.Add(this.label8);
            this.panel6.Location = new System.Drawing.Point(287, 65);
            this.panel6.Name = "panel6";
            this.panel6.Size = new System.Drawing.Size(267, 115);
            this.panel6.TabIndex = 2;
            // 
            // lblWaterLevel1
            // 
            this.lblWaterLevel1.AutoSize = true;
            this.lblWaterLevel1.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblWaterLevel1.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(9)))), ((int)(((byte)(120)))), ((int)(((byte)(236)))));
            this.lblWaterLevel1.Location = new System.Drawing.Point(93, 45);
            this.lblWaterLevel1.Name = "lblWaterLevel1";
            this.lblWaterLevel1.Size = new System.Drawing.Size(166, 25);
            this.lblWaterLevel1.TabIndex = 1;
            this.lblWaterLevel1.Text = "NÃO DEFINIDO";
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Font = new System.Drawing.Font("Nirmala UI", 10.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label8.ForeColor = System.Drawing.Color.White;
            this.label8.Location = new System.Drawing.Point(142, 10);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(117, 23);
            this.label8.TabIndex = 1;
            this.label8.Text = "Nível de Água";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Font = new System.Drawing.Font("Nirmala UI", 13.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label5.ForeColor = System.Drawing.Color.White;
            this.label5.Location = new System.Drawing.Point(347, 12);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(207, 32);
            this.label5.TabIndex = 0;
            this.label5.Text = "Reservatorio nº1";
            // 
            // panel7
            // 
            this.panel7.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(38)))), ((int)(((byte)(43)))), ((int)(((byte)(63)))));
            this.panel7.Controls.Add(this.lblWaterReading2);
            this.panel7.Controls.Add(this.imageReserve2);
            this.panel7.Controls.Add(this.panel8);
            this.panel7.Controls.Add(this.label9);
            this.panel7.Location = new System.Drawing.Point(968, 82);
            this.panel7.Name = "panel7";
            this.panel7.Size = new System.Drawing.Size(532, 560);
            this.panel7.TabIndex = 4;
            // 
            // panel8
            // 
            this.panel8.Controls.Add(this.label6);
            this.panel8.Controls.Add(this.lblWaterLevel2);
            this.panel8.Location = new System.Drawing.Point(283, 65);
            this.panel8.Name = "panel8";
            this.panel8.Size = new System.Drawing.Size(246, 115);
            this.panel8.TabIndex = 2;
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Font = new System.Drawing.Font("Nirmala UI", 10.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label6.ForeColor = System.Drawing.Color.White;
            this.label6.Location = new System.Drawing.Point(119, 10);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(117, 23);
            this.label6.TabIndex = 1;
            this.label6.Text = "Nível de Água";
            // 
            // lblWaterLevel2
            // 
            this.lblWaterLevel2.AutoSize = true;
            this.lblWaterLevel2.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblWaterLevel2.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(9)))), ((int)(((byte)(120)))), ((int)(((byte)(236)))));
            this.lblWaterLevel2.Location = new System.Drawing.Point(70, 50);
            this.lblWaterLevel2.Name = "lblWaterLevel2";
            this.lblWaterLevel2.Size = new System.Drawing.Size(166, 25);
            this.lblWaterLevel2.TabIndex = 1;
            this.lblWaterLevel2.Text = "NÃO DEFINIDO";
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Font = new System.Drawing.Font("Nirmala UI", 13.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label9.ForeColor = System.Drawing.Color.White;
            this.label9.Location = new System.Drawing.Point(313, 12);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(207, 32);
            this.label9.TabIndex = 0;
            this.label9.Text = "Reservatorio nº2";
            // 
            // imageReserve2
            // 
            this.imageReserve2.Image = global::ControleDeReservatorio.Properties.Resources.reservatorio80;
            this.imageReserve2.Location = new System.Drawing.Point(139, 227);
            this.imageReserve2.Name = "imageReserve2";
            this.imageReserve2.Size = new System.Drawing.Size(197, 318);
            this.imageReserve2.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.imageReserve2.TabIndex = 0;
            this.imageReserve2.TabStop = false;
            // 
            // imageReserve1
            // 
            this.imageReserve1.Image = global::ControleDeReservatorio.Properties.Resources.reservatorioVAZIO;
            this.imageReserve1.Location = new System.Drawing.Point(139, 227);
            this.imageReserve1.Name = "imageReserve1";
            this.imageReserve1.Size = new System.Drawing.Size(249, 318);
            this.imageReserve1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.imageReserve1.TabIndex = 0;
            this.imageReserve1.TabStop = false;
            // 
            // pictureBox1
            // 
            this.pictureBox1.Image = global::ControleDeReservatorio.Properties.Resources.Usuario;
            this.pictureBox1.Location = new System.Drawing.Point(83, 27);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(65, 65);
            this.pictureBox1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.pictureBox1.TabIndex = 1;
            this.pictureBox1.TabStop = false;
            // 
            // lblWaterReading1
            // 
            this.lblWaterReading1.AutoSize = true;
            this.lblWaterReading1.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblWaterReading1.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(9)))), ((int)(((byte)(120)))), ((int)(((byte)(236)))));
            this.lblWaterReading1.Location = new System.Drawing.Point(222, 199);
            this.lblWaterReading1.Name = "lblWaterReading1";
            this.lblWaterReading1.Size = new System.Drawing.Size(166, 25);
            this.lblWaterReading1.TabIndex = 2;
            this.lblWaterReading1.Text = "NÃO DEFINIDO";
            this.lblWaterReading1.Click += new System.EventHandler(this.lblWaterReading1_Click);
            // 
            // lblWaterReading2
            // 
            this.lblWaterReading2.AutoSize = true;
            this.lblWaterReading2.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblWaterReading2.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(9)))), ((int)(((byte)(120)))), ((int)(((byte)(236)))));
            this.lblWaterReading2.Location = new System.Drawing.Point(181, 199);
            this.lblWaterReading2.Name = "lblWaterReading2";
            this.lblWaterReading2.Size = new System.Drawing.Size(166, 25);
            this.lblWaterReading2.TabIndex = 3;
            this.lblWaterReading2.Text = "NÃO DEFINIDO";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(46)))), ((int)(((byte)(51)))), ((int)(((byte)(73)))));
            this.ClientSize = new System.Drawing.Size(1580, 718);
            this.Controls.Add(this.panel7);
            this.Controls.Add(this.panel5);
            this.Controls.Add(this.btnExit);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.panel1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
            this.Name = "Form1";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.panel1.ResumeLayout(false);
            this.panel3.ResumeLayout(false);
            this.panel3.PerformLayout();
            this.panel2.ResumeLayout(false);
            this.panel2.PerformLayout();
            this.panel5.ResumeLayout(false);
            this.panel5.PerformLayout();
            this.panel6.ResumeLayout(false);
            this.panel6.PerformLayout();
            this.panel7.ResumeLayout(false);
            this.panel7.PerformLayout();
            this.panel8.ResumeLayout(false);
            this.panel8.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.imageReserve2)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.imageReserve1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.IO.Ports.SerialPort serialPort1;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Panel panel2;
        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.Button btnSilent;
        private System.Windows.Forms.Label lbl_login_date;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Panel panel3;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Button btnConnect;
        private System.Windows.Forms.ComboBox cbSerialPort;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.ComboBox cbBaudRate;
        private System.Windows.Forms.Panel panel4;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Button btnExit;
        private System.Windows.Forms.Panel panel5;
        private System.Windows.Forms.PictureBox imageReserve1;
        private System.Windows.Forms.Panel panel6;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label lblWaterLevel1;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Panel panel7;
        private System.Windows.Forms.PictureBox imageReserve2;
        private System.Windows.Forms.Panel panel8;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label lblWaterLevel2;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.Button btnUpdateSerialPorts;
        private System.Windows.Forms.Label lblWaterReading1;
        private System.Windows.Forms.Label lblWaterReading2;
    }
}

