#ifndef DIA_H
#define DIA_H
#include <string>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include "MeiaHora.h"
#include "Trabalhador.h"
#define MEIASHORAS 48

class Dia {
public:
	int trabalhadores[MEIASHORAS];
	MeiaHora meias_horas[MEIASHORAS];
	std::vector<Trabalhador*> _trabalhadores_sairam;
	Dia() {
		for(int i = 0; i < MEIASHORAS; i++) {
			meias_horas[i].Set(i/2,i%2*30);
			trabalhadores[i] = 3;
		}
	}
	int GetTrabalhadores(int horas, int minutos) {
		if(horas < 24 && horas >= 0) {
			if(minutos < 30 && minutos >= 0) {
				return meias_horas[horas*2+1].GetTrabalhadoresSize();
			}
			if(minutos >= 30 && minutos < 60){
				return meias_horas[horas*2].GetTrabalhadoresSize();
			}
		}
		return 0;
	}
	bool contains(Trabalhador *worker) {
		for(int i; i < _trabalhadores_sairam.size(); i++) {
			if(worker == _trabalhadores_sairam[i]) {
				return true;
			}
		}
		return false;
	}
	void TrabalhadorSaiu(Trabalhador *worker) {
		if(worker != nullptr)
			_trabalhadores_sairam.push_back(worker);
	}
	bool AddTrabalhador(int horas, int minutos, Trabalhador *worker) {
		if(horas < 24 && horas >= 0) {
			if(minutos < 30 && minutos >= 0) {
				if(meias_horas[horas*2].GetTrabalhadoresSize() < trabalhadores[horas*2] && !contains(worker)) {
					if(meias_horas[horas*2].AddTrabalhador(worker))
						return true;
				}
			}
			if(minutos >= 30 && minutos < 60){
				if(meias_horas[horas*2+1].GetTrabalhadoresSize() < trabalhadores[horas*2+1] && !contains(worker)) {
					if(meias_horas[horas*2+1].AddTrabalhador(worker))
						return true;
				}
			}
		}
		return false;
	}
	void render() {
		for(int i = 0; i < 48; i++)
			meias_horas[i].render();
	}
};
#endif
