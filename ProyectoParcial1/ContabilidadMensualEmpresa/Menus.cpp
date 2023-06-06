#include <iostream>
#include "Validaciones.h"
#include "Menus.h"


int Menus::menuPrincipal(void){
	int opc;
	Empleado emp1;
	do{
	system("cls");
	std::cout<<"\n============MENU============"<<std::endl;
	std::cout<<"1. Registro de Nuevo Empleado"<<std::endl;
	std::cout<<"2. Modificar Empleado"<<std::endl;
	std::cout<<"3. Eliminar un empleado"<<std::endl;
	std::cout<<"4. Buscar un empleado"<<std::endl;
	std::cout<<"5. Imprimir total a cancelar mensual"<<std::endl;
	std::cout<<"6. Salir"<<std::endl;
	std::cout<<"\nPor favor, seleccione una opcion: ";
	
	
	opc=Validaciones::validarMenuOpc('1', '6');
	
	switch(opc){
		case 1:
			emp1=pedirDatosDeEmpleado();
			std::cout<<"\n---------------------Usuario Registrado Exitosamente---------------------";
			std::cout<<"\nNombre:   "<<emp1.getNombre();
			std::cout<<"\nApellido: "<<emp1.getApellido();
			std::cout<<"\nCargo:    "<<emp1.getCargo();
			std::cout<<"\nCedula:   "<<emp1.getCedula();
			std::cout<<"\nSalario:  "<<emp1.getSalario()<<"$\n";
			
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			exit(0);
			break;
		default:
			std::cout<<"Por favor, seleccione una opción válida";
			break;
	}
	system("PAUSE");
}while(opc!=6);
	return 0;
}

Empleado Menus::pedirDatosDeEmpleado(){
	
	std::string nombre;
	std::string apellido;
	double salario;
	std::string cargo;
	char* cedula;
	bool boleanoCedula;


	/*std::cout<<"\nIngrese la cedula del empleado a registrar: ";
	std::cin>>cedula;*/
	/*do{
		std::cin>>cedula;
		boleanoCedula=Validaciones::validarCedulaEcuatoriana(cedula); 
	}while(boleanoCedula==false);*/
	std::cout<<"\nIngrese el Nombre: ";
	std::cin>>nombre;
	//nombre = Validaciones::validarStrings();
	std::cout<<"\nIngrese el Apellido: ";
	std::cin>>apellido;
	//apellido = Validaciones::validarStrings();
	
	
	
	
	Empleado empleado("1726723545",nombre,apellido,pedirCargo());
	
	return empleado;	 
}

std::string Menus::pedirCargo(void){
	std::string cargo;
	int opc;
		std::cout<<"\nElija el cargo del empleado: "<<std::endl;
		std::cout<<"1. CEO"<<std::endl;
		std::cout<<"2. Oficinista"<<std::endl;
		std::cout<<"3. Personal de Limpieza"<<std::endl;
		std::cout<<"Seleccione el cargo: ";
		opc=Validaciones::validarMenuOpc('1','3') ;	
	
	if(opc==1){
		return "CEO";
	}else if(opc==2){
		return "Oficinista";
	}else if(opc==3){
		return "Personal de Limpieza";
	}
		
}