using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

using System.Threading;
using System.IO.Ports;  //SerialPort.GetPortNames()

namespace RF_MOTOR_simulation
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
//*****************************************************************
//*********************** TERMINAL ********************************
//*****************************************************************
        int intlen = 0;
        private void timerPortUpdate_Tick(object sender, EventArgs e)
        {
            string[] ports = SerialPort.GetPortNames();
            if (intlen != ports.Length)
            {
                intlen = ports.Length;
                CbSellectCom.Items.Clear();
                for (int j = 0; j < intlen; j++)
                    CbSellectCom.Items.Add(ports[j]);
            }
        }

        private void PbOpen_Click(object sender, EventArgs e)
        {
            if (PbOpen.Text == "Open")
            {
                COM.BaudRate = 9600;
                COM.PortName = CbSellectCom.Text;
                COM.Open();
                if (COM.IsOpen == true)
                    label.Text = "Connected";
                PbOpen.Text = "Close";
                Cursor.Position = new Point(300, 300);
            }
            else
            {
                COM.Close();
                if (COM.IsOpen == false)
                {
                    PbOpen.Text = "Open";
                    label.Text = "Disconnected";
                }
            }
        }

        private void PbSend_Click(object sender, EventArgs e)
        {
            string send_text;
            send_text = txtSend.Text;
            COM.Write(send_text);
            // if(txtSend.KeyDown)
            txtSend.Text = "";
        }

//*****************************************************************
//********************** Receive Data *****************************
//*****************************************************************
        public int offsetX = 0, offsetY = 0;
        private void COM_DataReceived(object sender, System.IO.Ports.SerialDataReceivedEventArgs e)
        {
            string Receive_text;
            if (COM.IsOpen == true)
            {
                Receive_text = COM.ReadLine();

                if (Receive_text == "D")
                {
                    offsetX = 1;
                    offsetY = 0;
                }
                if (Receive_text == "A")
                {
                    offsetX = -1;
                    offsetY = 0;
                }
                if (Receive_text == "S")
                {
                    offsetX = 0;
                    offsetY = 0;
                }
                if (Receive_text == "W")
                {
                    offsetX = 0;
                    offsetY = -1;
                }
                if (Receive_text == "X")
                {
                    offsetX = 0;
                    offsetY = 1;
                }
                //ltxtReceive.Items.Add(Receive_text);
                AddString_Lstbox(Receive_text);
            }
        }
        private delegate void AddString(string s);
        private void AddString_Lstbox(string s)
        {
            if (ltxtCommand.InvokeRequired)
            {
                AddString sd = new AddString(AddString_Lstbox);
                ltxtCommand.Invoke(sd, new object[] { s });
            }
            else
                ltxtCommand.Items.Add(s);
        }
//*****************************************************************
//*********************** SIMULATION ******************************
//*****************************************************************
        public int x = 0, y = 0;
        public int[] offset = new int[2];
        private void timerCarMove_Tick(object sender, EventArgs e)
        {
            /*double a = 0, x1, y1;

            x1 = Math.Sin(a * 10 * 3.1416 / 360);
            y1 = Math.Cos(a * 10 * 3.1416 / 360);

            x = Convert.ToInt16(x1); ;
            y = Convert.ToInt16(y1); ;
            Object.Location = new Point(Object.Location.X + x, Object.Location.Y + y);*/
            if (offsetX == 1)
            {
                if (x < 0)
                    x++;
                x++;
            }
            else if (offsetX == -1)
            {
                if (x > 0)
                    x--;
                x--;
            }
            else if (x > 0)     //offset[0] = 0
                x = x - 2;
            else if (x < 0)
                x++;

            if (offsetY == 1)
            {
                if (y < 0)
                    y++;
                y++;
            }
            else if (offsetY == -1)
            {
                if (y > 0)
                    y--;
                y--;
            }
            else if (y > 0)     //offset[1] = 0
                y = y - 2;
            else if (y < 0)
                y++;

            if (x > 10)
                x = 10;
            if (x < -10)
                x = -10;
            if (y > 10)
                y = 10;
            if (y < -10)
                y = -10;
            Object.Location = new Point(Object.Location.X + x, Object.Location.Y + y);
        }
// Update Display every 100ms
        int start = 0;
        public int[] Calib_Location = new int[2];
        private void timer100ms_Tick(object sender, EventArgs e)
        {
            int x1, y1;
            if (start == 0)
            {
                Calib_Location[0] = Object.Location.X;
                Calib_Location[1] = Object.Location.Y;
                start = 1;
            }
            x1 = Object.Location.X - Calib_Location[0];
            y1 = Object.Location.Y - Calib_Location[1];
            txtX.Text = x1.ToString();
            txtY.Text = y1.ToString();
        }
//*****************************************************************
//********************** CLEAR DISPLAY ****************************
//*****************************************************************
        private void Clearltxt_Click(object sender, EventArgs e)
        {
            ltxtCommand.Items.Clear();
        }

        private void PbReset_Click(object sender, EventArgs e)
        {
            ltxtCommand.Items.Clear();
            offsetX = 0;
            offsetY = 0;
            Object.Location = new Point(269, 121);
        }
//*****************************************************************
//********************* BUTTON HANDLING ***************************
//*****************************************************************
        private void PbUp_MouseDown(object sender, MouseEventArgs e)
        {
            COM.Write("W");
        }
        private void PbDown_MouseDown(object sender, MouseEventArgs e)
        {
            COM.Write("X");
        }
        private void PbLeft_MouseDown(object sender, MouseEventArgs e)
        {
            COM.Write("A");
        }
        private void PbRight_MouseDown(object sender, MouseEventArgs e)
        {
            COM.Write("D");
        }


        private void PbUp_MouseUp(object sender, MouseEventArgs e)
        {
            COM.Write("S");
        }
        private void PbDown_MouseUp(object sender, MouseEventArgs e)
        {
            COM.Write("S");
        }
        private void PbLeft_MouseUp(object sender, MouseEventArgs e)
        {
            COM.Write("S");
        }
        private void PbRight_MouseUp(object sender, MouseEventArgs e)
        {
            COM.Write("S");
        }
    }
}
