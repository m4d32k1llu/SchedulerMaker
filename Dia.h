#ifndef DIA_H
#define DIA_H
#include <string>
#include <vector>
#include <stdio.h>
#include "MeiaHora.h"
#include "Trabalhador.h"
#define MEIASHORAS 48

class Dia {
public:
	//int meiashoras = 48
	int trabalhadores = 3;
	MeiaHora meias_horas[MEIASHORAS];
	
	Dia() {
		for(int i = 0; i < MEIASHORAS; i++)
			meias_horas[i].Set(i/2,i%2*30);
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
	bool AddTrabalhador(int horas, int minutos, Trabalhador *worker) {
		if(horas < 24 && horas >= 0) {
			if(minutos < 30 && minutos >= 0) {
				if(meias_horas[horas*2].GetTrabalhadoresSize() < trabalhadores) {
					if(meias_horas[horas*2].AddTrabalhador(worker))
						return true;
				}
			}
			if(minutos >= 30 && minutos < 60){
				if(meias_horas[horas*2+1].GetTrabalhadoresSize() < trabalhadores) {
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
