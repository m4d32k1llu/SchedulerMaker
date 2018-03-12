#include "Schedule.h"

int main() {
	Schedule s;
	s.InitTrabalhador("Arminda");
	s.InitTrabalhador("Andre");
	s.InitTrabalhador("Diogo");
	s.InitTrabalhador("Joao");
	s.InitTrabalhador("Jose");
	s.InitTrabalhador("Ruben");
	s.InitTrabalhador("Cacia");
	s.TryCreate();
	s.render();
	return 0;
}
