namespace ControleDeReservatorio
{
    partial class FormControlPanel
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
            this.panelMenu = new System.Windows.Forms.Panel();
            this.btnMenuWW = new System.Windows.Forms.Button();
            this.btnMenuRW = new System.Windows.Forms.Button();
            this.btnMenuRF = new System.Windows.Forms.Button();
            this.panel3 = new System.Windows.Forms.Panel();
            this.cbBaudRate = new System.Windows.Forms.ComboBox();
            this.btnUpdateSerialPorts = new System.Windows.Forms.Button();
            this.label3 = new System.Windows.Forms.Label();
            this.btnConnect = new System.Windows.Forms.Button();
            this.cbSerialPort = new System.Windows.Forms.ComboBox();
            this.label2 = new System.Windows.Forms.Label();
            this.btnSilent = new System.Windows.Forms.Button();
            this.panel2 = new System.Windows.Forms.Panel();
            this.pnl_nav = new System.Windows.Forms.Panel();
            this.label1 = new System.Windows.Forms.Label();
            this.panel4 = new System.Windows.Forms.Panel();
            this.lbl_login_date = new System.Windows.Forms.Label();
            this.lbl_username = new System.Windows.Forms.Label();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.pnl_form_loader = new System.Windows.Forms.Panel();
            this.panelMenu.SuspendLayout();
            this.panel3.SuspendLayout();
            this.panel2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.SuspendLayout();
            // 
            // serialPort1
            // 
            this.serialPort1.DataReceived += new System.IO.Ports.SerialDataReceivedEventHandler(this.serialPort1_DataReceived);
            // 
            // panelMenu
            // 
            this.panelMenu.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(24)))), ((int)(((byte)(30)))), ((int)(((byte)(54)))));
            this.panelMenu.Controls.Add(this.btnMenuWW);
            this.panelMenu.Controls.Add(this.btnMenuRW);
            this.panelMenu.Controls.Add(this.btnMenuRF);
            this.panelMenu.Controls.Add(this.panel3);
            this.panelMenu.Controls.Add(this.btnSilent);
            this.panelMenu.Controls.Add(this.panel2);
            this.panelMenu.Dock = System.Windows.Forms.DockStyle.Left;
            this.panelMenu.Location = new System.Drawing.Point(0, 0);
            this.panelMenu.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.panelMenu.Name = "panelMenu";
            this.panelMenu.Size = new System.Drawing.Size(307, 898);
            this.panelMenu.TabIndex = 0;
            // 
            // btnMenuWW
            // 
            this.btnMenuWW.Dock = System.Windows.Forms.DockStyle.Top;
            this.btnMenuWW.FlatAppearance.BorderSize = 0;
            this.btnMenuWW.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnMenuWW.Font = new System.Drawing.Font("Nirmala UI", 10.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnMenuWW.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(25)))), ((int)(((byte)(175)))), ((int)(((byte)(215)))));
            this.btnMenuWW.Image = global::ControleDeReservatorio.Properties.Resources.home;
            this.btnMenuWW.Location = new System.Drawing.Point(0, 448);
            this.btnMenuWW.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.btnMenuWW.Name = "btnMenuWW";
            this.btnMenuWW.Size = new System.Drawing.Size(307, 74);
            this.btnMenuWW.TabIndex = 4;
            this.btnMenuWW.Text = "Painel WW";
            this.btnMenuWW.TextImageRelation = System.Windows.Forms.TextImageRelation.TextBeforeImage;
            this.btnMenuWW.UseVisualStyleBackColor = true;
            this.btnMenuWW.Click += new System.EventHandler(this.bntMenuWW_Click);
            this.btnMenuWW.Leave += new System.EventHandler(this.btnMenuWW_Leave);
            // 
            // btnMenuRW
            // 
            this.btnMenuRW.Dock = System.Windows.Forms.DockStyle.Top;
            this.btnMenuRW.FlatAppearance.BorderSize = 0;
            this.btnMenuRW.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnMenuRW.Font = new System.Drawing.Font("Nirmala UI", 10.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnMenuRW.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(25)))), ((int)(((byte)(175)))), ((int)(((byte)(215)))));
            this.btnMenuRW.Image = global::ControleDeReservatorio.Properties.Resources.home;
            this.btnMenuRW.Location = new System.Drawing.Point(0, 374);
            this.btnMenuRW.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.btnMenuRW.Name = "btnMenuRW";
            this.btnMenuRW.Size = new System.Drawing.Size(307, 74);
            this.btnMenuRW.TabIndex = 3;
            this.btnMenuRW.Text = "Painel RW";
            this.btnMenuRW.TextImageRelation = System.Windows.Forms.TextImageRelation.TextBeforeImage;
            this.btnMenuRW.UseVisualStyleBackColor = true;
            this.btnMenuRW.Click += new System.EventHandler(this.btnMenuRW_Click);
            this.btnMenuRW.Leave += new System.EventHandler(this.btnMenuRW_Leave);
            // 
            // btnMenuRF
            // 
            this.btnMenuRF.Dock = System.Windows.Forms.DockStyle.Top;
            this.btnMenuRF.FlatAppearance.BorderSize = 0;
            this.btnMenuRF.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnMenuRF.Font = new System.Drawing.Font("Nirmala UI", 10.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnMenuRF.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(25)))), ((int)(((byte)(175)))), ((int)(((byte)(215)))));
            this.btnMenuRF.Image = global::ControleDeReservatorio.Properties.Resources.home;
            this.btnMenuRF.Location = new System.Drawing.Point(0, 300);
            this.btnMenuRF.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.btnMenuRF.Name = "btnMenuRF";
            this.btnMenuRF.Size = new System.Drawing.Size(307, 74);
            this.btnMenuRF.TabIndex = 2;
            this.btnMenuRF.Text = "Painel RF";
            this.btnMenuRF.TextImageRelation = System.Windows.Forms.TextImageRelation.TextBeforeImage;
            this.btnMenuRF.UseVisualStyleBackColor = true;
            this.btnMenuRF.Click += new System.EventHandler(this.btnMenuRF_Click);
            this.btnMenuRF.Leave += new System.EventHandler(this.btnMenuRF_Leave);
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
            this.panel3.Location = new System.Drawing.Point(0, 582);
            this.panel3.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.panel3.Name = "panel3";
            this.panel3.Size = new System.Drawing.Size(307, 316);
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
            this.cbBaudRate.Location = new System.Drawing.Point(0, 128);
            this.cbBaudRate.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.cbBaudRate.Name = "cbBaudRate";
            this.cbBaudRate.Size = new System.Drawing.Size(304, 28);
            this.cbBaudRate.TabIndex = 5;
            // 
            // btnUpdateSerialPorts
            // 
            this.btnUpdateSerialPorts.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.btnUpdateSerialPorts.FlatAppearance.BorderSize = 0;
            this.btnUpdateSerialPorts.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnUpdateSerialPorts.Font = new System.Drawing.Font("Nirmala UI", 10.2F, System.Drawing.FontStyle.Underline, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnUpdateSerialPorts.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(45)))), ((int)(((byte)(218)))), ((int)(((byte)(188)))));
            this.btnUpdateSerialPorts.Location = new System.Drawing.Point(0, 182);
            this.btnUpdateSerialPorts.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.btnUpdateSerialPorts.Name = "btnUpdateSerialPorts";
            this.btnUpdateSerialPorts.Size = new System.Drawing.Size(307, 55);
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
            this.label3.Location = new System.Drawing.Point(3, 95);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(119, 30);
            this.label3.TabIndex = 4;
            this.label3.Text = "Baud Rate:";
            // 
            // btnConnect
            // 
            this.btnConnect.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.btnConnect.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnConnect.Font = new System.Drawing.Font("Nirmala UI", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnConnect.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(192)))), ((int)(((byte)(0)))));
            this.btnConnect.Location = new System.Drawing.Point(0, 237);
            this.btnConnect.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.btnConnect.Name = "btnConnect";
            this.btnConnect.Size = new System.Drawing.Size(307, 79);
            this.btnConnect.TabIndex = 3;
            this.btnConnect.Text = "Conectar";
            this.btnConnect.UseVisualStyleBackColor = true;
            this.btnConnect.Click += new System.EventHandler(this.btnConnect_Click);
            // 
            // cbSerialPort
            // 
            this.cbSerialPort.FormattingEnabled = true;
            this.cbSerialPort.Location = new System.Drawing.Point(0, 44);
            this.cbSerialPort.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.cbSerialPort.Name = "cbSerialPort";
            this.cbSerialPort.Size = new System.Drawing.Size(304, 28);
            this.cbSerialPort.TabIndex = 1;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Nirmala UI", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(226)))), ((int)(((byte)(226)))), ((int)(((byte)(249)))));
            this.label2.Location = new System.Drawing.Point(3, 11);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(132, 30);
            this.label2.TabIndex = 0;
            this.label2.Text = "Porta Serial:";
            // 
            // btnSilent
            // 
            this.btnSilent.Dock = System.Windows.Forms.DockStyle.Top;
            this.btnSilent.FlatAppearance.BorderSize = 0;
            this.btnSilent.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnSilent.Font = new System.Drawing.Font("Nirmala UI", 10.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnSilent.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(25)))), ((int)(((byte)(175)))), ((int)(((byte)(215)))));
            this.btnSilent.Location = new System.Drawing.Point(0, 226);
            this.btnSilent.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.btnSilent.Name = "btnSilent";
            this.btnSilent.Size = new System.Drawing.Size(307, 74);
            this.btnSilent.TabIndex = 1;
            this.btnSilent.Text = "Silenciar Alarme";
            this.btnSilent.UseVisualStyleBackColor = true;
            this.btnSilent.Visible = false;
            this.btnSilent.Click += new System.EventHandler(this.btnSilent_Click);
            // 
            // panel2
            // 
            this.panel2.Controls.Add(this.pnl_nav);
            this.panel2.Controls.Add(this.label1);
            this.panel2.Controls.Add(this.panel4);
            this.panel2.Controls.Add(this.lbl_login_date);
            this.panel2.Controls.Add(this.lbl_username);
            this.panel2.Controls.Add(this.pictureBox1);
            this.panel2.Dock = System.Windows.Forms.DockStyle.Top;
            this.panel2.Location = new System.Drawing.Point(0, 0);
            this.panel2.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.panel2.Name = "panel2";
            this.panel2.Size = new System.Drawing.Size(307, 226);
            this.panel2.TabIndex = 1;
            // 
            // pnl_nav
            // 
            this.pnl_nav.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(126)))), ((int)(((byte)(249)))));
            this.pnl_nav.Location = new System.Drawing.Point(0, 290);
            this.pnl_nav.Name = "pnl_nav";
            this.pnl_nav.Size = new System.Drawing.Size(3, 100);
            this.pnl_nav.TabIndex = 5;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.ForeColor = System.Drawing.Color.White;
            this.label1.Location = new System.Drawing.Point(41, 177);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(63, 18);
            this.label1.TabIndex = 3;
            this.label1.Text = "Ligado:";
            // 
            // panel4
            // 
            this.panel4.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(126)))), ((int)(((byte)(249)))));
            this.panel4.Location = new System.Drawing.Point(0, 241);
            this.panel4.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.panel4.Name = "panel4";
            this.panel4.Size = new System.Drawing.Size(3, 125);
            this.panel4.TabIndex = 2;
            // 
            // lbl_login_date
            // 
            this.lbl_login_date.AutoSize = true;
            this.lbl_login_date.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbl_login_date.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(158)))), ((int)(((byte)(161)))), ((int)(((byte)(178)))));
            this.lbl_login_date.Location = new System.Drawing.Point(110, 177);
            this.lbl_login_date.Name = "lbl_login_date";
            this.lbl_login_date.Size = new System.Drawing.Size(72, 18);
            this.lbl_login_date.TabIndex = 2;
            this.lbl_login_date.Text = "14:31:02";
            // 
            // lbl_username
            // 
            this.lbl_username.AutoSize = true;
            this.lbl_username.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbl_username.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(126)))), ((int)(((byte)(249)))));
            this.lbl_username.Location = new System.Drawing.Point(75, 132);
            this.lbl_username.Name = "lbl_username";
            this.lbl_username.Size = new System.Drawing.Size(118, 25);
            this.lbl_username.TabIndex = 1;
            this.lbl_username.Text = "Username";
            // 
            // pictureBox1
            // 
            this.pictureBox1.Image = global::ControleDeReservatorio.Properties.Resources.Usuario;
            this.pictureBox1.Location = new System.Drawing.Point(93, 34);
            this.pictureBox1.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(73, 81);
            this.pictureBox1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.pictureBox1.TabIndex = 1;
            this.pictureBox1.TabStop = false;
            // 
            // pnl_form_loader
            // 
            this.pnl_form_loader.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.pnl_form_loader.Location = new System.Drawing.Point(307, 0);
            this.pnl_form_loader.Name = "pnl_form_loader";
            this.pnl_form_loader.Size = new System.Drawing.Size(1471, 898);
            this.pnl_form_loader.TabIndex = 1;
            // 
            // FormControlPanel
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(46)))), ((int)(((byte)(51)))), ((int)(((byte)(73)))));
            this.ClientSize = new System.Drawing.Size(1778, 898);
            this.Controls.Add(this.pnl_form_loader);
            this.Controls.Add(this.panelMenu);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
            this.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.Name = "FormControlPanel";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.panelMenu.ResumeLayout(false);
            this.panel3.ResumeLayout(false);
            this.panel3.PerformLayout();
            this.panel2.ResumeLayout(false);
            this.panel2.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.IO.Ports.SerialPort serialPort1;
        private System.Windows.Forms.Panel panelMenu;
        private System.Windows.Forms.Panel panel2;
        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.Button btnSilent;
        private System.Windows.Forms.Label lbl_login_date;
        private System.Windows.Forms.Label lbl_username;
        private System.Windows.Forms.Panel panel3;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Button btnConnect;
        private System.Windows.Forms.ComboBox cbSerialPort;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.ComboBox cbBaudRate;
        private System.Windows.Forms.Panel panel4;
        private System.Windows.Forms.Button btnUpdateSerialPorts;
        private System.Windows.Forms.Button btnMenuRF;
        private System.Windows.Forms.Button btnMenuWW;
        private System.Windows.Forms.Button btnMenuRW;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Panel pnl_nav;
        private System.Windows.Forms.Panel pnl_form_loader;
    }
}

