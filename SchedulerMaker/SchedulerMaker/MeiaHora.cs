using System;
using System.Collections.Generic;

namespace SchedulerMaker
{
    internal class MeiaHora
    {
        int _hora, _minutos;
        bool _valid;
        //std::vector<std::string> _trabalhadores;
        List<Trabalhador> _trabalhadores = new List<Trabalhador>();
       public  MeiaHora(bool valid)
        {
            _valid = valid;
        }
        public MeiaHora()
        {
            _valid = false;
        }
        public MeiaHora(int hora, int minutos)
        {
            _hora = hora;
            _minutos = minutos;
            _valid = true;
        }
        public void Set(int hora, int minutos)
        {
            _hora = hora;
            _minutos = minutos;
            _valid = true;
        }
        public bool IsValid()
        {
            return _valid;
        }
        bool contains(Trabalhador worker)
        {
            for (int i = 0; i < _trabalhadores.Count; i++)
            {
                if (worker == _trabalhadores[i])
                {
                    return true;
                }
            }
            return false;
        }
        public bool AddTrabalhador(Trabalhador worker)
        {
            if (_valid && !contains(worker))
            {
                _trabalhadores.Add(worker);
                return true;
            }
            return false;
        }
        public int GetTrabalhadoresSize()
        {
            return _trabalhadores.Count;
        }
        public List<Trabalhador> GetTrabalhadores()
        {
            return _trabalhadores;
        }
        public void Reset()
        {
            _trabalhadores.Clear();
        }
        public void render()
        {
            Console.WriteLine( "" + _hora + " : " + _minutos);
            for (int i = 0; i < _trabalhadores.Count; i++)
                _trabalhadores[i].render();
            Console.WriteLine("");
        }

        public void SetValid()
        {
            _valid = true;
        }
    }
}