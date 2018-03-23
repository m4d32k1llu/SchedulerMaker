using System;
using System.Collections.Generic;

namespace SchedulerMaker
{
    class Schedule
    {
        int dias = 7;
        int horas_semanais = 40;
        int horas_semanais_minimas = 38;
        int horas_por_dia = 10;
        double horas_semana_da_loja = 0;
        double horas_semana_da_loja_cumpridas = 0;
        public Semana semana;
        List<Trabalhador> _trabalhadores;
        string _nome;
        int entrada = 17, saida1 = 28, saida2 = 36, saida3 = 46;
        public Schedule(string nome)
        {
            _nome = nome;
            semana = new Semana();
            _trabalhadores = new List<Trabalhador>();
            //srand(time(NULL));
            /*for(int i = 0; i < dias; i++)
                for(int j = 0; j < horas_trabalho*2; j++)
                    horas_trabalho[i][j] = false;*/
        }
        public Schedule(int _entrada, int _saida1, int _saida2, int _saida3)
        {
            entrada = _entrada;
            saida1 = _saida1;
            saida2 = _saida2;
            saida3 = _saida3;
            _trabalhadores = new List<Trabalhador>();
            semana = new Semana();
            /*for(int i = 0; i < dias; i++)
                for(int j = 0; j < horas_trabalho*2; j++)
                    horas_trabalho[i][j] = false;*/
        }
        public Schedule()
        {
            semana = new Semana();
            _trabalhadores = new List<Trabalhador>();

            /*for(int i = 0; i < dias; i++)
                for(int j = 0; j < horas_trabalho*2; j++)
                    horas_trabalho[i][j] = false;*/
        }
        ~Schedule()
        {
            //foreach (Trabalhador worker in _trabalhadores) { }
               // delete(worker);
        }
        public Semana GetHorario(string nome) {
            foreach (Trabalhador worker in _trabalhadores) {
                if (nome.Equals(worker.GetNome())) {
                    return worker.GetHorario();
                }
            }
            return null;
        }
        public string[] Nomes() {
            string[] nomes = new string[_trabalhadores.Count];
            for(int i = 0; i <  _trabalhadores.Count;i++) {
                nomes[i] = _trabalhadores[i].GetNome();
            }
            return nomes;
        }
        public List<Trabalhador> GetTrabalhadores() {
            return _trabalhadores;
        }
        void shuffle_trabalhadores()
        {
            Trabalhador aux;
            int random = 0;
            Random rnd = new Random();
            int size = _trabalhadores.Count;
            for (int i = 0; i < size; i++)
            {
                aux = _trabalhadores[i];
                random = rnd.Next(1,size);
                _trabalhadores[i] = _trabalhadores[random];
                _trabalhadores[random] = aux;
            }
        }
        bool completed()
        {
            foreach (Trabalhador worker in _trabalhadores)
            {
                if (worker.GetHorasTrabalhoSemana() < horas_semanais_minimas)
                    return false;
            }
            return true;
        }
        public void Reset()
        {
            //delete semana;
            //semana = new Semana();
            semana.Reset();
            foreach (Trabalhador worker in _trabalhadores)
                worker.Reset();
        }
        void collect_data() {
            for (int i = 0; i < dias; i++) {
                for (int h = 0; h < 48; h++)
                {
                    foreach (Trabalhador worker in _trabalhadores) {
                        if (semana.dias[i].meias_horas[h].GetTrabalhadores().Contains(worker)) {
                            worker.SetMeiaHora(i, h, h % 2);
                        }
                    }
                }
            }
        }
        public void TryCreate()
        {
            int i = 0;
            Console.WriteLine("Creating...");
            while (true)
            {
                i++;
                horas_semana_da_loja_cumpridas = 0;
                Create1();
                if (horas_semana_da_loja_cumpridas > horas_semana_da_loja * 0.87)
                {
                    //collect_data();
                    return;
                }
                else Reset();
            }
        }
        void Create1()
        {
            int x = 1, horas = 0 ;
            shuffle_trabalhadores();
            while (x < 100)
            {
                //while(!completed()) {
                x++;
                for (int d = 0; d < dias; d++)
                {
                    shuffle_trabalhadores();
                    for (int i = 0; i < _trabalhadores.Count; i++)
                    {
                        if (_trabalhadores[i].DeFolga(d)) continue;
                        if (_trabalhadores[i].GetHorasTrabalhoSemana() >= horas_semanais) continue;
                        if ((horas = semana.dias[d].AddTrabalhadorTurno1(_trabalhadores[i])) > 0)
                        {
                            horas_semana_da_loja_cumpridas += horas;
                            continue;
                        }
                        shuffle_trabalhadores();

                        if ((horas = semana.dias[d].AddTrabalhadorTurno2(_trabalhadores[i])) > 0)
                        {
                            horas_semana_da_loja_cumpridas += horas;
                            continue;
                        }
                        shuffle_trabalhadores();

                        if ((horas = semana.dias[d].AddTrabalhadorTurno3(_trabalhadores[i])) > 0)
                        {
                            horas_semana_da_loja_cumpridas += horas;
                            continue;
                        }
                        shuffle_trabalhadores();
                    }
                }
            }
        }
        void Create()
        {
            int x = 1;
            shuffle_trabalhadores();
            while (x < 100)
            {
                //while(!completed()) {
                x++;
                for (int d = 0; d < dias; d++)
                {

                    //shuffle_trabalhadores();
                    for (int i = 0; i < _trabalhadores.Count; i++)
                    {
                        if (_trabalhadores[i].DeFolga(d)) continue;
                        if (_trabalhadores[i].GetHorasTrabalhoSemana() >= horas_semanais) continue;
                        for (int h = entrada; h <= saida3; h++)
                        {
                            if (semana.dias[d].AddTrabalhador(h / 2, h % 2 * 30, _trabalhadores[i]))
                            {
                                if (_trabalhadores[i].IncHorasTrabalho(d))
                                {
                                    horas_semana_da_loja_cumpridas += 0.5;
                                }
                            }
                            if (_trabalhadores[i].GetHorasTrabalhoDia(d) >= horas_por_dia)
                            {
                                //printf("TRABALHADOR SAIU\n");
                                semana.dias[d].TrabalhadorSaiu(_trabalhadores[i]);
                                //break;
                            }
                            if (h == saida1 || h == saida2)
                            {
                                shuffle_trabalhadores();
                            }
                            /*if(_trabalhadores[i]->GetHorasTrabalhoSemana() >= horas_semanais) {
                                break;
                            }*/
                        }
                        //worker->ResetHorasTrabalhoDia();
                    }
                }
            }
        }
        public void InitTrabalhador(string nome)
        {
            horas_semana_da_loja += horas_semanais;
            _trabalhadores.Add(new Trabalhador(nome));
        }
        public void InitTrabalhador(string nome, int folga)
        {
            horas_semana_da_loja += horas_semanais;
            _trabalhadores.Add(new Trabalhador(nome, folga));
        }
        public void InitTrabalhador(string nome, int folga1, int folga2)
        {
            horas_semana_da_loja += horas_semanais;
            _trabalhadores.Add(new Trabalhador(nome, folga1, folga2));
        }
        public void render()
        {
            semana.render();
            foreach (Trabalhador worker in _trabalhadores)
            {
                //worker.render1();
            }
            Console.WriteLine("HORAS SEMANA DA LOJA A CUMPRIR: " +  horas_semana_da_loja);
            Console.WriteLine("HORAS SEMANA DA LOJA CUMPRIDAS: " + horas_semana_da_loja_cumpridas);
        }

    }
}