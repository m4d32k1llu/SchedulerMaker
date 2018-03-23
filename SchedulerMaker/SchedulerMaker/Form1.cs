using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace SchedulerMaker
{
    public partial class Form1 : Form
    {
        Schedule _s;
        public Form1()
        {
            InitializeComponent();
            Init();
            InitTableLayout();
        }
        void Init() {
            _s = new Schedule();
            _s.InitTrabalhador("Arminda", 1, 2);
            _s.InitTrabalhador("Andre", 2, 3);
            _s.InitTrabalhador("Diogo", 3, 4);
            _s.InitTrabalhador("Joao", 4, 5);
            _s.InitTrabalhador("Jose", 5, 6);
            _s.InitTrabalhador("Ruben", 7, 1);
            _s.InitTrabalhador("Cacia", 1, 2);
        }
        public void CreateNewSchedule() {
            _s.TryCreate();
            //_s.render();
        }
        void fill_grid(Trabalhador x) {
            string txt = "";
            for (int j = 1; j < 8; j++)
            {
                for (int i = 17; i <= 46; i++)
                {
                    foreach (Trabalhador worker in _s.semana.dias[j - 1].meias_horas[i].GetTrabalhadores())
                    {
                        if(worker == x)
                            txt += worker.GetNome() + ",";
                    }
                    if(tableLayoutPanel1.GetControlFromPosition(j, i-16) == null)
                        tableLayoutPanel1.Controls.Add(new Label() { Text = txt }, j, i - 16);
                    else
                        tableLayoutPanel1.GetControlFromPosition(j, i - 16).Text += txt;
                    //tableLayoutPanel1.Controls.Add(new Label() { Text = txt }, j, i - 16);
                    txt = "";
                }
            }
        }
        void generate() {
            _s.Reset();
            checkedListBox.Items.Clear();

            InitTableLayout();        }
        void select() {
            InitTable();
           foreach (Trabalhador s in  _s.GetTrabalhadores()) {
                if (checkedListBox.CheckedItems.Contains(s.GetNome())) {
                    fill_grid(s);
                }
            }
        }
        void ResetTableLayout() {
            tableLayoutPanel1.ResetText();
            tableLayoutPanel1.Controls.Clear();
            checkedListBox.ResetText();
            checkedListBox.Controls.Clear();
        }
        void InitTable()
        {
            int hora = 0, minuto = 0;
            ResetTableLayout();
            tableLayoutPanel1.Controls.Add(new Label() { Text = "Horas/Dias" }, 0, 0);
            tableLayoutPanel1.Controls.Add(new Label() { Text = "Segunda" }, 1, 0);
            tableLayoutPanel1.Controls.Add(new Label() { Text = "Terça" }, 2, 0);
            tableLayoutPanel1.Controls.Add(new Label() { Text = "Quarta" }, 3, 0);
            tableLayoutPanel1.Controls.Add(new Label() { Text = "Quinta" }, 4, 0);
            tableLayoutPanel1.Controls.Add(new Label() { Text = "Sexta" }, 5, 0);
            tableLayoutPanel1.Controls.Add(new Label() { Text = "Sábado" }, 6, 0);
            tableLayoutPanel1.Controls.Add(new Label() { Text = "Domingo" }, 7, 0);
            for (int i = 17; i <= 46; i++)
            {
                hora = i;
                minuto = i % 2 * 30;
                tableLayoutPanel1.Controls.Add(new Label() { Text = hora / 2 + ":" + minuto }, 0, i - 16);

            }
        }
        public void InitTableLayout()
        {
            string txt = "";
            InitTable();
            CreateNewSchedule();
            for (int j = 1; j < 8; j++)
            {
                for (int i = 17; i <= 46; i++)
                {
                    foreach (Trabalhador worker in _s.semana.dias[j - 1].meias_horas[i].GetTrabalhadores()) {
                        txt += worker.GetNome() + ",";
                    }
                    tableLayoutPanel1.Controls.Add(new Label() { Text = txt}, j, i - 16);
                    txt = "";
                }
            }
            
            checkedListBox.Items.AddRange(_s.Nomes());
        }
        private void tableLayoutPanel1_Paint(object sender, PaintEventArgs e)
        {
           
        }

        private void genButton_Click(object sender, EventArgs e)
        {
            select();
        }

        private void novoHorárioToolStripMenuItem_Click(object sender, EventArgs e)
        {
            generate();
        }
    }
}
