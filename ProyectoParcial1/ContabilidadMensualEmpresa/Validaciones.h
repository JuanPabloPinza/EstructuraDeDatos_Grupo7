#ifndef VALIDACIONES_H
#define VALIDACIONES_H

#include <string>

class Validaciones{
	
	public:
	static int validarMenuOpc(char, char);
	static char* validarStrings();
	static bool validarCedulaEcuatoriana(const char* cedula);
	
};

#endif