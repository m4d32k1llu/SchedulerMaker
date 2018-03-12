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
	int horas_semanais_minimas = 38;
	int horas_por_dia = 10;
	float horas_semana_da_loja = 0;
	float horas_semana_da_loja_cumpridas = 0;
	Semana *semana;
	std::vector<Trabalhador*> _trabalhadores;
	std::string _nome;
	int entrada = 17, saida1 = 28, saida2 = 36, saida3 = 46;
	int pessoas = 6;
	Schedule(std::string nome) 
	{
		_nome = nome;
		semana = new Semana();
  		srand (time(NULL));
		/*for(int i = 0; i < dias; i++)
			for(int j = 0; j < horas_trabalho*2; j++)
				horas_trabalho[i][j] = false;*/
	}
	Schedule() {
		semana = new Semana();
		srand (time(NULL));
		/*for(int i = 0; i < dias; i++)
			for(int j = 0; j < horas_trabalho*2; j++)
				horas_trabalho[i][j] = false;*/
	}
	~Schedule() {
		for(auto worker : _trabalhadores)
			delete worker;
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
	bool completed() {
		for(auto worker : _trabalhadores) {
			if(worker->GetHorasTrabalhoSemana() < horas_semanais_minimas)
				return false;
		}
		return true;
	}
	void Reset() {
		//delete semana;
		//semana = new Semana();
		semana->Reset();
		for(auto worker : _trabalhadores)
			worker->Reset();
	}
	void TryCreate() {
		int i = 0;
		while(1) {
			i++;
			printf("Creating...\n");
			horas_semana_da_loja_cumpridas = 0;
			Create();
			printf("HORAS SEMANA DA LOJA CUMPRIDAS : %f\n", horas_semana_da_loja_cumpridas);
			if(horas_semana_da_loja_cumpridas > horas_semana_da_loja*0.97) return;
			else Reset();
		}
	}
	void Create() {
		Trabalhador *worker = nullptr;
		int x = 1;
		shuffle_trabalhadores();
		while(x < 100) {
		//while(!completed()) {
			x++;
			for(int d = 0; d < dias; d++) {
				//shuffle_trabalhadores();
				for(int i = 0; i < _trabalhadores.size(); i++) {
					//worker = _trabalhadores[i];
				//for(auto worker : _trabalhadores) {
					if(_trabalhadores[i]->DeFolga(d)) continue;
					if(_trabalhadores[i]->GetHorasTrabalhoSemana() >= horas_semanais) continue;
					for(int h = entrada; h <= saida3 + 1; h++) {
						//printf("%d %d %d\n",h/2, h%2, i);
						if(semana->dias[d].AddTrabalhador(h/2, h%2*30, _trabalhadores[i])) {
							if(_trabalhadores[i]->IncHorasTrabalho(d)) {
								horas_semana_da_loja_cumpridas += 0.5; 
							}						
						}
						if(_trabalhadores[i]->GetHorasTrabalhoDia(d) >= horas_por_dia) {
							//printf("TRABALHADOR SAIU\n");
							semana->dias[d].TrabalhadorSaiu(_trabalhadores[i]);
							//break;
						}
						if(h == saida1 || h == saida2) {
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
	void InitTrabalhador(std::string nome) {
		horas_semana_da_loja += horas_semanais;
		_trabalhadores.push_back(new Trabalhador(nome));
	}
	void InitTrabalhador(std::string nome, int folga) {
		horas_semana_da_loja += horas_semanais;
		_trabalhadores.push_back(new Trabalhador(nome, folga));
	}
	void InitTrabalhador(std::string nome, int folga1,int folga2) {
		horas_semana_da_loja += horas_semanais;
		_trabalhadores.push_back(new Trabalhador(nome, folga1, folga2));
	}
	void render() {
		semana->render();
		for(auto worker : _trabalhadores) {
			worker->render1();
		}
		printf("HORAS SEMANA DA LOJA A CUMPRIR: %f\n", horas_semana_da_loja);
		printf("HORAS SEMANA DA LOJA CUMPRIDAS: %f\n", horas_semana_da_loja_cumpridas);
	}
};
#endif
