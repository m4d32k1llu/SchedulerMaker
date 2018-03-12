#include "Schedule.h"

int main() {
	Schedule s;
	s.InitTrabalhador("Arminda",1,2);
	s.InitTrabalhador("Andre",2,3);
	s.InitTrabalhador("Diogo",3,4);
	s.InitTrabalhador("Joao",4,5);
	s.InitTrabalhador("Jose",5,6);
	s.InitTrabalhador("Ruben",7,1);
	s.InitTrabalhador("Cacia",1,2);
	s.TryCreate();
	s.render();
	return 0;
}
