/*******************************
 UNIVERSIDAD DE LAS FUERZAS ARMADAS (ESPE)
 Asignatura: Estructuras de Datos
 Grupo 7
 Integrantes: Juan Pablo Pinza, Sebastián Lasso, Dylan Alvarado
 Fecha de creacion: 31/05/23 9:10
 Fecha de modificacion: 10/06/23 10:10
 Enunciado General: Programa De Contabilidad Mensual.
 ********************************/
#ifndef MENUS_H
#define MENUS_H
#include "Empleado.h"
#include "ListaDoble.h"

class Menus{
	
	public:
	int menuPrincipal(void);
	Empleado pedirDatosDeEmpleado(std::string);
	std::string pedirCargo(void);
	template <typename T>
	void modificarEmpleado(std::string cedula,ListaDoble<T>* empleadosRegistrados);
	template <typename T>
	ListaDoble<T>* cargarDatosDeArchivoEnLista(ListaDoble<T>* empleadosRegistrados);
	void guardarEmpleadosEnArchivo(Empleado);
	void imprimirArchivoTxt(void);
	void buscarEmpleadoPorCedula();
		
};

#endif