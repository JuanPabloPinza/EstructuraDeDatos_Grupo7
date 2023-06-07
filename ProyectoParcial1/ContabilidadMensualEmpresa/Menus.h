#ifndef MENUS_H
#define MENUS_H
#include "Empleado.h"

class Menus{
	
	public:
	int menuPrincipal(void);
	Empleado pedirDatosDeEmpleado();
	std::string pedirCargo(void);
	void cargarDatosDeArchivoEnLista();
	void guardarEmpleadosEnArchivo(Empleado);
	void imprimirArchivoTxt(void);
	void buscarEmpleadoPorCedula();
		
};

#endif