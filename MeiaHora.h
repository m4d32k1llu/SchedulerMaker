#ifndef MEIAHORA_H
#define MEIAHORA_H
#include <string>
#include <vector>
#include <stdio.h>
#include "Trabalhador.h"

class MeiaHora {
public:
	int _hora, _minutos;
	bool _valid;
	//std::vector<std::string> _trabalhadores;
	std::vector<Trabalhador*> _trabalhadores;
	MeiaHora(bool valid) {
		_valid = valid;
	}
	MeiaHora() {
		_valid = false;
	}
	MeiaHora(int hora, int minutos) {
		_hora = hora;
		_minutos = minutos;
		_valid = true;
	}
	void Set(int hora, int minutos) {
		_hora = hora;
		_minutos = minutos;
		//_valid = true;
	}
	bool IsValid() {
		return _valid;
	}
	bool contains(Trabalhador *worker) {
		for(int i = 0; i < _trabalhadores.size(); i++) {
			if(worker == _trabalhadores[i]) {
				return true;
			}
		}
		return false;
	}	
	bool AddTrabalhador(Trabalhador *worker) {
		if(_valid && !contains(worker)) {
			_trabalhadores.push_back(worker);
			return true;
		}
		return false;
	}
	int GetTrabalhadoresSize() {
		return _trabalhadores.size();
	}
	std::vector<Trabalhador*> GetTrabalhadores() {
		return _trabalhadores;
	}
	void Reset() {
		_trabalhadores.clear();
	}
	void render() {
		printf("%d:%d\n", _hora, _minutos);
		for(int i = 0; i < _trabalhadores.size(); i++)
			_trabalhadores[i]->render();
		printf("\n");
	}
};
#endif
