#ifndef SCHEDULE_H
#define SCHEDULE_H
#include <string>
#include <stdio.h>
#include <cmath>
#include <cstdlib>
#include "Semana.h"
#include "Trabalhador.h"

class Schedule {
public:
	int dias = 7;
	int horas_dia = 24;
	int folgas = 2;
	int horas_semanais = 40;
	int horas_por_dia = 8;
	float horas_semana_da_loja = 0;
	float horas_semana_da_loja_cumpridas = 0;
	Semana semana;
	std::vector<Trabalhador*> _trabalhadores;
	std::string _nome;
	int entrada = 17, saida1 = 24, saida2 = 36, saida3 = 46;
	int pessoas = 6;
	Schedule(std::string nome) 
	{
		_nome = nome;
  		srand (time(NULL));
		/*for(int i = 0; i < dias; i++)
			for(int j = 0; j < horas_trabalho*2; j++)
				horas_trabalho[i][j] = false;*/
	}
	Schedule() {
		srand (time(NULL));
		/*for(int i = 0; i < dias; i++)
			for(int j = 0; j < horas_trabalho*2; j++)
				horas_trabalho[i][j] = false;*/
	}
	void shuffle_trabalhadores() {
		Trabalhador *aux;
		int random = 0;
		int size = _trabalhadores.size();
		for(int i = 0; i < size; i++) {
			aux = _trabalhadores[i];
			random = rand() % size;
			_trabalhadores[i] = _trabalhadores[random];
			_trabalhadores[random] = aux;
		}
	}
	void TryCreate() {
		int horas = 0;
		for(int d = 0; d < dias; d++) {
			for(auto worker : _trabalhadores) {
				for(int h = entrada; h < saida3 + 1; h++) {
					//printf("%d %d %d\n",h/2, h%2, i);
					if(semana.dias[d].AddTrabalhador(h/2, h%2*30, worker) && worker->IncHorasTrabalho(d)) {
						horas_semana_da_loja_cumpridas += 0.5; 
					}
					if(worker->GetHorasTrabalhoDia(d) >= horas_por_dia) {
						//printf("TRABALHADOR SAIU\n");
						semana.dias[d].TrabalhadorSaiu(worker);
						break;
					}
					if(worker->GetHorasTrabalhoSemana() >= horas_semanais) {
						break;
					}
				}
				//worker->ResetHorasTrabalhoDia();
			}
			shuffle_trabalhadores();
		}
	}
	void InitTrabalhador(std::string nome) {
		horas_semana_da_loja += horas_semanais;
		_trabalhadores.push_back(new Trabalhador(nome));
	}
	void render() {
		semana.render();
		for(auto worker : _trabalhadores) {
			worker->render1();
		}
		printf("HORAS SEMANA DA LOJA A CUMPRIR: %f\n", horas_semana_da_loja);
		printf("HORAS SEMANA DA LOJA CUMPRIDAS: %f\n", horas_semana_da_loja_cumpridas);
	}
};
#endif
