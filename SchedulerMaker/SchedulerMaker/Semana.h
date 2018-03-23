#ifndef Semana_H
#define Semana_H
#include <string>
#include <vector>
#include <stdio.h>
#include "Dia.h"

class Semana {
public:
	Dia dias[7];
	
	Semana() {
		
	}
	~Semana() {
		
	}

	void render() {
		printf("SEMANA\n");
		for(int i = 0; i < 7; i++) {
			printf("\nDia %d\n", i+1);
			dias[i].render();
		}
	}
	void Reset() {
		for(int i = 0; i < 7; i++) {
			dias[i].Reset();
		}	
	}
};
#endif
