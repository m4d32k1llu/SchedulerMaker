#ifndef TRABALHADOR_H
#define TRABALHADOR_H
#include <string>
#include <vector>
#include <iostream>

class Trabalhador {
public:
	std::string _nome;
	int horario;
	float horas_trabalho_semana;
	float horas_trabalho_dia;
	Trabalhador(std::string nome) {
		_nome = nome;
		horas_trabalho_semana = 0;
		horas_trabalho_dia = 0;
	}
	Trabalhador() {
		horas_trabalho_semana = 0;
		horas_trabalho_dia = 0;
	}
	bool IncHorasTrabalho() {
		horas_trabalho_semana += 0.5;
		horas_trabalho_dia += 0.5;
		if(horas_trabalho_semana >= 40 || horas_trabalho_dia == 8) {
			horas_trabalho_semana--;
			horas_trabalho_dia--;
			return false;
		}
		return true;
	}
	float GetHorasTrabalhoSemana() {
		return horas_trabalho_semana;
	}
	float GetHorasTrabalhoDia() {
		return horas_trabalho_dia;
	}
	float ResetHorasTrabalhoDia() {
		horas_trabalho_dia = 0;
	}
	float ResetHorasTrabalhoSemana() {
		horas_trabalho_dia = 0;
		horas_trabalho_semana = 0;
	}
	void render() {
		std::cout << "TRABALHADOR : " << _nome << /*" , HORAS DIA : " << horas_trabalho_dia/2.0 << " , HORAS SEMANA : " << horas_trabalho_semana/2.0 <<*/ std::endl;
	}
};
#endif
