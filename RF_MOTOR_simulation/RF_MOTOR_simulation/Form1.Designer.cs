namespace RF_MOTOR_simulation
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.Object = new System.Windows.Forms.PictureBox();
            this.timerCarMove = new System.Windows.Forms.Timer(this.components);
            this.CbSellectCom = new System.Windows.Forms.ComboBox();
            this.label = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.txtSend = new System.Windows.Forms.TextBox();
            this.PbSend = new System.Windows.Forms.Button();
            this.PbOpen = new System.Windows.Forms.Button();
            this.COM = new System.IO.Ports.SerialPort(this.components);
            this.timerPortUpdate = new System.Windows.Forms.Timer(this.components);
            this.Clearltxt = new System.Windows.Forms.Button();
            this.timer100ms = new System.Windows.Forms.Timer(this.components);
            this.txtY = new System.Windows.Forms.TextBox();
            this.txtX = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.ltxtCommand = new System.Windows.Forms.ListBox();
            this.label6 = new System.Windows.Forms.Label();
            this.txtReceive = new System.Windows.Forms.RichTextBox();
            this.PbReset = new System.Windows.Forms.Button();
            this.PbUp = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            this.PbRight = new System.Windows.Forms.Button();
            this.PbDown = new System.Windows.Forms.Button();
            this.PbLeft = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.Object)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.SuspendLayout();
            // 
            // Object
            // 
            this.Object.Image = ((System.Drawing.Image)(resources.GetObject("Object.Image")));
            this.Object.Location = new System.Drawing.Point(269, 121);
            this.Object.Name = "Object";
            this.Object.Size = new System.Drawing.Size(30, 32);
            this.Object.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.Object.TabIndex = 3;
            this.Object.TabStop = false;
            // 
            // timerCarMove
            // 
            this.timerCarMove.Enabled = true;
            this.timerCarMove.Tick += new System.EventHandler(this.timerCarMove_Tick);
            // 
            // CbSellectCom
            // 
            this.CbSellectCom.FormattingEnabled = true;
            this.CbSellectCom.Location = new System.Drawing.Point(741, 118);
            this.CbSellectCom.Name = "CbSellectCom";
            this.CbSellectCom.Size = new System.Drawing.Size(149, 21);
            this.CbSellectCom.TabIndex = 118;
            // 
            // label
            // 
            this.label.AutoSize = true;
            this.label.Font = new System.Drawing.Font("Copperplate Gothic Light", 24F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label.Location = new System.Drawing.Point(679, 258);
            this.label.Name = "label";
            this.label.Size = new System.Drawing.Size(261, 35);
            this.label.TabIndex = 117;
            this.label.Text = "Disconnected";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(673, 8);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(47, 13);
            this.label4.TabIndex = 115;
            this.label4.Text = "Receive";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(686, 192);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(49, 13);
            this.label2.TabIndex = 112;
            this.label2.Text = "Sendtext";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(682, 121);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(53, 13);
            this.label1.TabIndex = 111;
            this.label1.Text = "COM Port";
            // 
            // txtSend
            // 
            this.txtSend.Location = new System.Drawing.Point(741, 189);
            this.txtSend.Name = "txtSend";
            this.txtSend.Size = new System.Drawing.Size(149, 20);
            this.txtSend.TabIndex = 110;
            this.txtSend.Text = "A";
            // 
            // PbSend
            // 
            this.PbSend.Location = new System.Drawing.Point(780, 215);
            this.PbSend.Name = "PbSend";
            this.PbSend.Size = new System.Drawing.Size(75, 40);
            this.PbSend.TabIndex = 109;
            this.PbSend.Text = "Send";
            this.PbSend.UseVisualStyleBackColor = true;
            this.PbSend.Click += new System.EventHandler(this.PbSend_Click);
            // 
            // PbOpen
            // 
            this.PbOpen.Location = new System.Drawing.Point(780, 145);
            this.PbOpen.Name = "PbOpen";
            this.PbOpen.Size = new System.Drawing.Size(75, 38);
            this.PbOpen.TabIndex = 108;
            this.PbOpen.Text = "Open";
            this.PbOpen.UseVisualStyleBackColor = true;
            this.PbOpen.Click += new System.EventHandler(this.PbOpen_Click);
            // 
            // COM
            // 
            this.COM.DataReceived += new System.IO.Ports.SerialDataReceivedEventHandler(this.COM_DataReceived);
            // 
            // timerPortUpdate
            // 
            this.timerPortUpdate.Enabled = true;
            this.timerPortUpdate.Tick += new System.EventHandler(this.timerPortUpdate_Tick);
            // 
            // Clearltxt
            // 
            this.Clearltxt.Location = new System.Drawing.Point(598, 216);
            this.Clearltxt.Name = "Clearltxt";
            this.Clearltxt.Size = new System.Drawing.Size(75, 40);
            this.Clearltxt.TabIndex = 109;
            this.Clearltxt.Text = "Clear";
            this.Clearltxt.UseVisualStyleBackColor = true;
            this.Clearltxt.Click += new System.EventHandler(this.Clearltxt_Click);
            // 
            // timer100ms
            // 
            this.timer100ms.Enabled = true;
            this.timer100ms.Tick += new System.EventHandler(this.timer100ms_Tick);
            // 
            // txtY
            // 
            this.txtY.Location = new System.Drawing.Point(179, 306);
            this.txtY.Name = "txtY";
            this.txtY.Size = new System.Drawing.Size(42, 20);
            this.txtY.TabIndex = 119;
            // 
            // txtX
            // 
            this.txtX.Location = new System.Drawing.Point(131, 306);
            this.txtX.Name = "txtX";
            this.txtX.Size = new System.Drawing.Size(42, 20);
            this.txtX.TabIndex = 120;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(147, 290);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(12, 13);
            this.label3.TabIndex = 121;
            this.label3.Text = "x";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(196, 290);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(12, 13);
            this.label5.TabIndex = 122;
            this.label5.Text = "y";
            // 
            // pictureBox1
            // 
            this.pictureBox1.Image = ((System.Drawing.Image)(resources.GetObject("pictureBox1.Image")));
            this.pictureBox1.Location = new System.Drawing.Point(269, 121);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(30, 34);
            this.pictureBox1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pictureBox1.TabIndex = 123;
            this.pictureBox1.TabStop = false;
            // 
            // ltxtCommand
            // 
            this.ltxtCommand.FormattingEnabled = true;
            this.ltxtCommand.Location = new System.Drawing.Point(601, 24);
            this.ltxtCommand.Name = "ltxtCommand";
            this.ltxtCommand.Size = new System.Drawing.Size(69, 186);
            this.ltxtCommand.TabIndex = 116;
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(598, 8);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(54, 13);
            this.label6.TabIndex = 115;
            this.label6.Text = "Command";
            // 
            // txtReceive
            // 
            this.txtReceive.Location = new System.Drawing.Point(676, 24);
            this.txtReceive.Name = "txtReceive";
            this.txtReceive.Size = new System.Drawing.Size(214, 70);
            this.txtReceive.TabIndex = 125;
            this.txtReceive.Text = "";
            // 
            // PbReset
            // 
            this.PbReset.Location = new System.Drawing.Point(598, 263);
            this.PbReset.Name = "PbReset";
            this.PbReset.Size = new System.Drawing.Size(75, 40);
            this.PbReset.TabIndex = 109;
            this.PbReset.Text = "Reset";
            this.PbReset.UseVisualStyleBackColor = true;
            this.PbReset.Click += new System.EventHandler(this.PbReset_Click);
            // 
            // PbUp
            // 
            this.PbUp.Location = new System.Drawing.Point(63, 8);
            this.PbUp.Name = "PbUp";
            this.PbUp.Size = new System.Drawing.Size(45, 40);
            this.PbUp.TabIndex = 108;
            this.PbUp.Text = "Up";
            this.PbUp.UseVisualStyleBackColor = true;
            this.PbUp.MouseDown += new System.Windows.Forms.MouseEventHandler(this.PbUp_MouseDown);
            this.PbUp.MouseUp += new System.Windows.Forms.MouseEventHandler(this.PbUp_MouseUp);
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(63, 54);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(45, 40);
            this.button2.TabIndex = 108;
            this.button2.Text = "Down";
            this.button2.UseVisualStyleBackColor = true;
            // 
            // PbRight
            // 
            this.PbRight.Location = new System.Drawing.Point(114, 54);
            this.PbRight.Name = "PbRight";
            this.PbRight.Size = new System.Drawing.Size(45, 40);
            this.PbRight.TabIndex = 108;
            this.PbRight.Text = "Right";
            this.PbRight.UseVisualStyleBackColor = true;
            this.PbRight.MouseDown += new System.Windows.Forms.MouseEventHandler(this.PbRight_MouseDown);
            this.PbRight.MouseUp += new System.Windows.Forms.MouseEventHandler(this.PbRight_MouseUp);
            // 
            // PbDown
            // 
            this.PbDown.Location = new System.Drawing.Point(63, 54);
            this.PbDown.Name = "PbDown";
            this.PbDown.Size = new System.Drawing.Size(45, 40);
            this.PbDown.TabIndex = 108;
            this.PbDown.Text = "Down";
            this.PbDown.UseVisualStyleBackColor = true;
            this.PbDown.MouseDown += new System.Windows.Forms.MouseEventHandler(this.PbDown_MouseDown);
            this.PbDown.MouseUp += new System.Windows.Forms.MouseEventHandler(this.PbDown_MouseUp);
            // 
            // PbLeft
            // 
            this.PbLeft.Location = new System.Drawing.Point(12, 54);
            this.PbLeft.Name = "PbLeft";
            this.PbLeft.Size = new System.Drawing.Size(45, 40);
            this.PbLeft.TabIndex = 108;
            this.PbLeft.Text = "Left";
            this.PbLeft.UseVisualStyleBackColor = true;
            this.PbLeft.MouseDown += new System.Windows.Forms.MouseEventHandler(this.PbLeft_MouseDown);
            this.PbLeft.MouseUp += new System.Windows.Forms.MouseEventHandler(this.PbLeft_MouseUp);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(944, 338);
            this.Controls.Add(this.txtReceive);
            this.Controls.Add(this.pictureBox1);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.txtX);
            this.Controls.Add(this.txtY);
            this.Controls.Add(this.CbSellectCom);
            this.Controls.Add(this.label);
            this.Controls.Add(this.ltxtCommand);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.txtSend);
            this.Controls.Add(this.PbReset);
            this.Controls.Add(this.Clearltxt);
            this.Controls.Add(this.PbSend);
            this.Controls.Add(this.PbRight);
            this.Controls.Add(this.PbLeft);
            this.Controls.Add(this.PbDown);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.PbUp);
            this.Controls.Add(this.PbOpen);
            this.Controls.Add(this.Object);
            this.Name = "Form1";
            this.Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)(this.Object)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.PictureBox Object;
        private System.Windows.Forms.Timer timerCarMove;
        private System.Windows.Forms.ComboBox CbSellectCom;
        private System.Windows.Forms.Label label;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox txtSend;
        private System.Windows.Forms.Button PbSend;
        private System.Windows.Forms.Button PbOpen;
        private System.IO.Ports.SerialPort COM;
        private System.Windows.Forms.Timer timerPortUpdate;
        private System.Windows.Forms.Button Clearltxt;
        private System.Windows.Forms.Timer timer100ms;
        private System.Windows.Forms.TextBox txtY;
        private System.Windows.Forms.TextBox txtX;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.ListBox ltxtCommand;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.RichTextBox txtReceive;
        private System.Windows.Forms.Button PbReset;
        private System.Windows.Forms.Button PbUp;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Button PbRight;
        private System.Windows.Forms.Button PbDown;
        private System.Windows.Forms.Button PbLeft;
    }
}

