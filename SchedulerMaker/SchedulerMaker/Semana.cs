using System;

namespace SchedulerMaker
{
    internal class Semana
    {
        public Dia[] dias = new Dia[7];

        public Semana()
        {
            for (int i = 0; i < 7; i++)
            {
                dias[i] = new Dia();
            }
        }


        public void render()
        {
            for (int i = 0; i < 7; i++)
            {
                Console.WriteLine("Dia "+(i+1));
                dias[i].render();
            }
        }
        public void Reset()
        {
            for (int i = 0; i < 7; i++)
            {
                dias[i].Reset();
            }
        }
    }
}