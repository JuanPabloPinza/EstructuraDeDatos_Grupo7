/*******************************
 UNIVERSIDAD DE LAS FUERZAS ARMADAS (ESPE)
 Asignatura: Estructuras de Datos
 Nombre: Juan Pablo Pinza Armijos
 Fecha de creacion: 07/06/23 9:10
 Fecha de modificacion: 31/05/23 10:10
 Enunciado General: Conjunta 1 Parcial 1
 ********************************/
#ifndef MENUS_H
#define MENUS_H
#include "Empleado.h"
#include "ListaDoble.h"

class Menus{
	
	public:
	int menuPrincipal(void);
	Empleado pedirDatosDeEmpleado();
	std::string pedirCargo(void);
	template <typename T>
	ListaDoble<T>* cargarDatosDeArchivoEnLista(ListaDoble<T>* empleadosRegistrados);
	
	void guardarEmpleadosEnArchivo(Empleado);
	void imprimirArchivoTxt(void);
	void buscarEmpleadoPorCedula();
		
};

#endif