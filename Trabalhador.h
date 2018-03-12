#ifndef TRABALHADOR_H
#define TRABALHADOR_H
#include <string>
#include <vector>
#include <iostream>
#define DIAS 7
class Trabalhador {
public:
	std::string _nome;
	int horario;
	float horas_trabalho_semana;
	float horas_trabalho_dia[DIAS];
	bool folgas[DIAS];

	Trabalhador(std::string nome, int folga1, int folga2) {
		_nome = nome;
		horas_trabalho_semana = 0;
		for(int i = 0; i < DIAS; i++) {
			horas_trabalho_dia[i] = 0;
			folgas[i] = false;
		}
		folgas[folga1-1] = true;
		folgas[folga2-1] = true;
	}
	Trabalhador(std::string nome, int folga) {
		_nome = nome;
		horas_trabalho_semana = 0;
		for(int i = 0; i < DIAS; i++) {
			horas_trabalho_dia[i] = 0;
			folgas[i] = false;
		}
		folgas[folga-1] = true;
	}
	Trabalhador(std::string nome) {
		_nome = nome;
		horas_trabalho_semana = 0;
		for(int i = 0; i < DIAS; i++)
			horas_trabalho_dia[i] = 0;
	}
	Trabalhador() {
		horas_trabalho_semana = 0;
		for(int i = 0; i < DIAS; i++)
			horas_trabalho_dia[i] = 0;
	}
	bool DeFolga(int dia) {
		if(folgas[dia]) return true;
		return false;
	}
	bool IncHorasTrabalho(int dia) {
		if(folgas[dia]) return false;
		if(horas_trabalho_semana >= 40 || horas_trabalho_dia[dia] >= 8) {
			return false;
		}
		horas_trabalho_semana += 0.5;
		horas_trabalho_dia[dia] += 0.5;
		return true;
	}
	float GetHorasTrabalhoSemana() {
		return horas_trabalho_semana;
	}
	float GetHorasTrabalhoDia(int dia) {
		//printf("horas dia : %d\n", horas_trabalho_dia[dia]);
		return horas_trabalho_dia[dia];
	}
	void ResetHorasTrabalhoDia() {
		for(int i = 0; i < DIAS; i++)
			horas_trabalho_dia[i] = 0;
	}
	void ResetHorasTrabalhoSemana() {
		horas_trabalho_semana = 0;
		for(int i = 0; i < DIAS; i++)
			horas_trabalho_dia[i] = 0;
	}
	void render() {
		std::cout << "TRABALHADOR : " << _nome << /*" , HORAS SEMANA : " << horas_trabalho_semana << */std::endl;
		/*for(int i = 0; i < DIAS; i++)
			std::cout << " HORAS DIA " << i+1 << " : " << horas_trabalho_dia[i] << std::endl;*/
	}
	void render1() {
		std::cout << "TRABALHADOR : " << _nome << " , HORAS SEMANA : " << horas_trabalho_semana << std::endl;
		for(int i = 0; i < DIAS; i++)
			std::cout << " HORAS DIA " << i+1 << " : " << horas_trabalho_dia[i] << std::endl;
	}
};
#endif
