/*******************************
 UNIVERSIDAD DE LAS FUERZAS ARMADAS (ESPE)
 Asignatura: Estructuras de Datos
 Grupo 7
 Integrantes: Juan Pablo Pinza, Sebastián Lasso, Dylan Alvarado
 Fecha de creacion: 31/05/23 9:10
 Fecha de modificacion: 10/06/23 10:10
 Enunciado General: Programa De Contabilidad Mensual.
 ********************************/
#ifndef VALIDACIONES_H
#define VALIDACIONES_H

#include <string>

class Validaciones{
	
	public:
	static int validarMenuOpc(char, char);
	static char* validarStrings();
	static std::string validarCedulaEcuatoriana();
	static int validarAnioDeContratacion();
	static int validarEdad();
	static bool validarEdad(int);
	static bool validarC(int);
};

#endif