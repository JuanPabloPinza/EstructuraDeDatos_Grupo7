/*******************************
 UNIVERSIDAD DE LAS FUERZAS ARMADAS (ESPE)
 Asignatura: Estructuras de Datos
 Grupo 7
 Integrantes: Juan Pablo Pinza, Sebastián Lasso, Dylan Alvarado
 Fecha de creacion: 31/05/23 9:10
 Fecha de modificacion: 10/06/23 10:10
 Enunciado General: Programa De Contabilidad Mensual.
 ********************************/

#include <iostream>
#include <string>
#include "Validaciones.h"
#include "Nodo.cpp"
#include "ListaDoble.cpp"
#include "Menus.h"
#include <fstream>



int Menus::menuPrincipal(void){
	int opc;
	int anio;
	Empleado emp1;
	std::string cedula;
	double totalAPagar;
	//AL LLAMAR AL MENÚ, PRIMERO CREAMOS UNA LISTA DOBLEMENTE ENLAZADA CON LOS DATOS DEL ARCHIVO
	//Creamos una lista doblemente enlazada
	//ListaDoble<Empleado>* empleadosRegistrados = new ListaDoble<Empleado>();
	//empleadosRegistrados = cargarDatosDeArchivoEnLista(empleadosRegistrados);
	do{
	Nodo<Empleado>* nodo;
	ListaDoble<Empleado>* empleadosRegistrados = new ListaDoble<Empleado>();
	empleadosRegistrados = cargarDatosDeArchivoEnLista(empleadosRegistrados);

	system("cls");
	std::cout<<"\n============PROGRAMA DE REGISTRO============"<<std::endl;
	std::cout<<"1. Registro de Nuevo Empleado"<<std::endl;
	std::cout<<"2. Lista de Empleados Contratados por anio"<<std::endl;	
	std::cout<<"3. Mostrar Registro de Usuarios"<<std::endl;
	std::cout<<"4. Eliminar un empleado"<<std::endl;
	std::cout<<"5. Modificar Empleado"<<std::endl;
	std::cout<<"6. Total a Pagar Del Mes a los Empleados: "<<std::endl;
	std::cout<<"7. Salir"<<std::endl;
	std::cout<<"\nPor favor, seleccione una opcion: ";
	
	
	opc=Validaciones::validarMenuOpc('1', '7');
	
switch(opc){
		case 1:
				std::cout<<"\nIngrese la Cedula: ";
				cedula = Validaciones::validarCedulaEcuatoriana();
				nodo = empleadosRegistrados->buscar(cedula);
				if (nodo == nullptr) {	
					emp1=pedirDatosDeEmpleado(cedula);
					guardarEmpleadosEnArchivo(emp1);
					std::cout << "Dato ingresado correctamente" << std::endl;
					std::cout<<"\n---------------------Usuario Registrado Exitosamente---------------------";
					std::cout<<"\nNombre:   "<<emp1.getNombre();
					std::cout<<"\nApellido: "<<emp1.getApellido();
					std::cout<<"\nEdad:     "<<emp1.getEdad();
					std::cout<<"\nCargo:    "<<emp1.getCargo();
					std::cout<<"\nCedula:   "<<emp1.getCedula();
					std::cout<<"\nContrato desde: "<<emp1.getAnioDeContratacion();
					std::cout<<"\nSalario:  "<<"$"<<emp1.getSalario()<<"\n";
				} else {
					std::cout << "Cedula anteriormente registrada" << std::endl;				
				}
			break;
		case 2:
			std::cout<<"Ingrese El Anio de Contratacion: ";
			anio = Validaciones::validarAnioDeContratacion();
			empleadosRegistrados->imprimirPorAnioDeContratacion(anio);
			break;
		case 3:
			//empleadosRegistrados = cargarDatosDeArchivoEnLista(empleadosRegistrados);
			empleadosRegistrados->mostrar();
			break;
		case 4:
		    system("cls");
		    std::cout << "Ingrese la cedula del empleado a eliminar: ";
		    cedula = Validaciones::validarCedulaEcuatoriana();
		    empleadosRegistrados->eliminarPorCedula(cedula);
		    empleadosRegistrados->guardarListaEnArchivo();
		    break;
		case 5:
			std::cout << "Ingrese la cedula del empleado del cual quiere modificar los datos: ";
		    cedula = Validaciones::validarCedulaEcuatoriana();
		    modificarEmpleado(cedula, empleadosRegistrados);
		    break;
		case 6:
			//CASO A IMPLEMENTAR:
			totalAPagar = empleadosRegistrados->sumaDeSueldosTotales();
			std::cout<<"El total a pagar este mes es: "<< totalAPagar <<std::endl;
			
			//imprimirArchivoTxt();
			break;
		case 7:
			exit(0);
		break;
		default:
			std::cout<<"Por favor, seleccione una opción válida";
			break;
	}
	system("PAUSE");
}while(opc!=7);
	return 0;
}

Empleado Menus::pedirDatosDeEmpleado(std::string cedula){
	
	std::string nombre;
	std::string apellido;
	std::string cargo;
	
	bool boleanoCedula;
	int anioDeContratacion;
	int edad;
	
	
	std::cout<<"\nIngrese el Nombre: ";
	nombre = Validaciones::validarStrings();
	std::cout<<"\nIngrese el Apellido: ";
	apellido = Validaciones::validarStrings();
	std::cout<<"\nIngrese su edad: ";
	edad = Validaciones::validarEdad();
	std::cout<<"\nIngrese el anio en el que fue contratado: ";
	anioDeContratacion = Validaciones::validarAnioDeContratacion();
	cargo = pedirCargo();
	
	Empleado empleado(cedula,nombre,apellido,edad,cargo,anioDeContratacion);
	
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
		cargo= "CEO";
	}else if(opc==2){
		cargo= "Oficinista";
	}else if(opc==3){
		cargo= "Personal de Limpieza";
	}
	return cargo;
}

void Menus::guardarEmpleadosEnArchivo(Empleado emp1) {
	
    std::ofstream archive;
    archive.open("empleados.txt", std::ios::app);

    if (archive.fail()) {
        std::cout << "ERROR, no se pudo abrir o encontrar el archivo" << std::endl;
    }else{

    archive <<"Nombre:   "<<emp1.getNombre();
    archive <<"\nApellido: "<<emp1.getApellido();
    archive <<"\nEdad:     "<<emp1.getEdad();
    archive <<"\nCargo:    "<<emp1.getCargo();
    archive <<"\nCedula:   "<<emp1.getCedula();
    archive <<"\nSalario:  "<<emp1.getSalario();
    archive <<"\nAnio De Contratacion:  "<<emp1.getAnioDeContratacion();
    archive << "\n---------------------------------" << std::endl;
	}
    archive.close(); 
}

void Menus::imprimirArchivoTxt() {
    std::ifstream entrada("empleados.txt");

    if (!entrada) {
        std::cout << "ERROR no se pudo abrir o encontrar el archivo" << std::endl;
        return;
    }

    std::string linea;

    while (std::getline(entrada, linea)) {
        std::cout << linea << std::endl;
    }

    entrada.close();
}
/*
//Cargar los Empleados desde un archivo de texto
template <typename T>
ListaDoble<T>* Menus::cargarDatosDeArchivoEnLista(ListaDoble<T>* empleadosRegistrados){

	std::ifstream file("empleados.txt");
	if (!file) {
        std::cerr << "No se ha podido abrir el archivo\n";
        menuPrincipal();
    }
	
    std::string line;
    while (std::getline(file, line)) {
        if (line.find("Nombre:") != std::string::npos) {
            std::string nombre = line.substr(10);  // Extrae el nombre del Empleado
            std::getline(file, line);
            std::string apellido = line.substr(10);  // Extrae el Apellido del Empleado
            std::getline(file, line);
            int edad = std::stoi(line.substr(10));  // Extrae la edad del Empleado
            std::getline(file, line);
            std::string cargo = line.substr(10);  // Extrae el cargo del Empleado
            std::getline(file, line);
            std::string cedula = line.substr(10);  // Extrae la cédula del Empleado
            std::getline(file, line);
            double salario = std::stod(line.substr(10));  // Extrae el salario del Empleado
            std::getline(file, line);
			int anioDeContratacion = std::stoi(line.substr(23));    // Extrae el año de contratacion del Empleado

			//Crear el Objeto Empleado
			Empleado empleado(cedula,nombre,apellido,edad,cargo,anioDeContratacion);
			
            // Inserta el empleado en la lista
            empleadosRegistrados->insertar(empleado);
        }
    }
    file.close();
    return empleadosRegistrados;
}*/

template <typename T>
ListaDoble<T>* Menus::cargarDatosDeArchivoEnLista(ListaDoble<T>* empleadosRegistrados){

	std::ifstream file("empleados.txt");
	if (!file) {
        std::cerr << "No se ha podido abrir el archivo\n";
        menuPrincipal();
    }
	
    std::string line;
    while (std::getline(file, line)) {
        if (line.find("Nombre:") != std::string::npos) {
            std::string nombre = line.substr(10);  // Extrae el nombre del Empleado
            std::getline(file, line);
            std::string apellido = line.substr(10);  // Extrae el Apellido del Empleado
            std::getline(file, line);
            int edad = std::stoi(line.substr(10));  // Extrae la edad del Empleado
            std::getline(file, line);
            std::string cargo = line.substr(10);  // Extrae el cargo del Empleado
            std::getline(file, line);
            std::string cedula = line.substr(10);  // Extrae la cédula del Empleado
            std::getline(file, line);
            double salario = std::stod(line.substr(10));  // Extrae el salario del Empleado
            std::getline(file, line);
			int anioDeContratacion = std::stoi(line.substr(23));    // Extrae el año de contratacion del Empleado

			//Crear el Objeto Empleado
			//Empleado empleado(cedula,nombre,apellido,edad,cargo,anioDeContratacion);
			Empleado empleado(cedula,nombre,apellido,edad,cargo,salario,anioDeContratacion);
			
            // Inserta el empleado en la lista
            empleadosRegistrados->insertar(empleado);
        }
    }
    file.close();
    return empleadosRegistrados;
}


template <typename T>
void Menus::modificarEmpleado(std::string cedula,ListaDoble<T>* empleadosRegistrados) {
    Nodo<Empleado>* nodo = empleadosRegistrados->buscar(cedula);

    if (nodo != nullptr) {
        Empleado empleadoActual = nodo->getDato();
        Empleado nuevoEmpleado = pedirDatosDeEmpleado(cedula);

        // Modificar los atributos necesarios del empleado actual con los valores del nuevo empleado
        empleadoActual.setNombre(nuevoEmpleado.getNombre());
        empleadoActual.setApellido(nuevoEmpleado.getApellido());
        empleadoActual.setEdad(nuevoEmpleado.getEdad());
        empleadoActual.setCargo(nuevoEmpleado.getCargo());
        empleadoActual.setSalario(nuevoEmpleado.getSalario());
        empleadoActual.setAnioDeContratacion(nuevoEmpleado.getAnioDeContratacion());

        // Actualizar el nodo con el nuevo empleado modificado
        nodo->setDato(empleadoActual);

        // Guardar la lista actualizada en el archivo
        empleadosRegistrados->guardarListaEnArchivo();

        std::cout << "Empleado modificado correctamente." << std::endl;
    } else {
        std::cout << "Empleado no encontrado." << std::endl;
    }
}

