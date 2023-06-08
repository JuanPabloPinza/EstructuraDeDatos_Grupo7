/*******************************
 UNIVERSIDAD DE LAS FUERZAS ARMADAS (ESPE)
 Asignatura: Estructuras de Datos
 Nombre: Juan Pablo Pinza Armijos
 Fecha de creacion: 07/06/23 9:10
 Fecha de modificacion: 31/05/23 10:10
 Enunciado General: Conjunta 1 Parcial 1
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
	
};

#endif