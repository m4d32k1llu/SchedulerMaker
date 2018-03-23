using System;

namespace SchedulerMaker
{
    internal class Trabalhador
    {
        static int DIAS = 7;
        static int HORAS_SEMANA = 40;
        static int HORAS_DIA = 10;
        string _nome;
        Semana horario;
        double horas_trabalho_semana;
        double[] horas_trabalho_dia = new double[DIAS];
        bool[] folgas = new bool[DIAS];

        public Trabalhador(string nome, int folga1, int folga2)
        {
            _nome = nome;
            horario = new Semana();
            horas_trabalho_semana = 0;
            for (int i = 0; i < DIAS; i++)
            {
                horas_trabalho_dia[i] = 0;
                folgas[i] = false;
            }
            folgas[folga1 - 1] = true;
            folgas[folga2 - 1] = true;
        }
        public Trabalhador(string nome, int folga)
        {
            _nome = nome;
            horario = new Semana();
            horas_trabalho_semana = 0;
            for (int i = 0; i < DIAS; i++)
            {
                horas_trabalho_dia[i] = 0;
                folgas[i] = false;
            }
            folgas[folga - 1] = true;
        }
        public Trabalhador(string nome)
        {
            _nome = nome;
            horario = new Semana();
            horas_trabalho_semana = 0;
            for (int i = 0; i < DIAS; i++)
                horas_trabalho_dia[i] = 0;
        }
        public Trabalhador()
        {
            horario = new Semana();
            horas_trabalho_semana = 0;
            for (int i = 0; i < DIAS; i++)
                horas_trabalho_dia[i] = 0;
        }
        public Semana GetHorario() {
            return horario;
        }
        public void SetMeiaHora(int dia, int hora, int minuto) {
            horario.dias[dia].meias_horas[hora+minuto].SetValid();
        }
        public string GetNome()
        {
            return _nome;
        }
        public bool DeFolga(int dia)
        {
            if (folgas[dia]) return true;
            return false;
        }
        public bool IncHorasTrabalho(int dia)
        {
            if (folgas[dia]) return false;
            if (horas_trabalho_semana >= HORAS_SEMANA || horas_trabalho_dia[dia] >= HORAS_DIA)
            {
                return false;
            }
            horas_trabalho_semana += 0.5;
            horas_trabalho_dia[dia] += 0.5;
            return true;
        }
        public double GetHorasTrabalhoSemana()
        {
            return horas_trabalho_semana;
        }
        public double GetHorasTrabalhoDia(int dia)
        {
            //printf("horas dia : %d\n", horas_trabalho_dia[dia]);
            return horas_trabalho_dia[dia];
        }
        public void Reset()
        {
            ResetHorasTrabalhoDia();
            ResetHorasTrabalhoSemana();
        }
        void ResetHorasTrabalhoDia()
        {
            for (int i = 0; i < DIAS; i++)
                horas_trabalho_dia[i] = 0;
        }
        void ResetHorasTrabalhoSemana()
        {
            horas_trabalho_semana = 0;
            for (int i = 0; i < DIAS; i++)
                horas_trabalho_dia[i] = 0;
        }
        public void render()
        {
            Console.WriteLine("TRABALHADOR : " + _nome + " , HORAS SEMANA : " + horas_trabalho_semana);
            //for (int i = 0; i < DIAS; i++)
              //  Console.WriteLine(" HORAS DIA " + (i + 1) + " : " + horas_trabalho_dia[i]);
        }
        public void render1()
        {
            Console.WriteLine("TRABALHADOR : " + _nome + " , HORAS SEMANA : " + horas_trabalho_semana);
            for (int i = 0; i < DIAS; i++)
                Console.WriteLine(" HORAS DIA " + (i + 1) + " : " + horas_trabalho_dia[i]);
        }
    }
}