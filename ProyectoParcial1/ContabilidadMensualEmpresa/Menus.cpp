#include <iostream>
#include <string>
#include "Validaciones.h"
#include "Nodo.cpp"
#include "ListaDoble.cpp"
#include "Menus.h"
#include <fstream>



int Menus::menuPrincipal(void){
	int opc;
	Empleado emp1;
	//AL LLAMAR AL MENÚ, PRIMERO CREAMOS UNA LISTA DOBLEMENTE ENLAZADA CON LOS DATOS DEL ARCHIVO
	Nodo<Empleado>* nodo;
	
	//Creamos una lista doblemente enlazada
	ListaDoble<int>* nuevaLista = new ListaDoble<int>();
	ListaDoble<Empleado>* empleadosRegistrados = new ListaDoble<Empleado>();
	
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

			//Crear el Objeto Empleado
			Empleado empleado(cedula,nombre,apellido,edad,cargo);
			
            // Inserta el vehículo en la lista
            empleadosRegistrados->insertar(empleado);
        }
    }
    file.close();
	
	
	do{
	system("cls");
	std::cout<<"\n============MENU============"<<std::endl;
	std::cout<<"1. Registro de Nuevo Empleado"<<std::endl;
	std::cout<<"2. Modificar Empleado"<<std::endl;
	std::cout<<"3. Eliminar un empleado"<<std::endl;
	std::cout<<"4. Buscar un empleado"<<std::endl;
	std::cout<<"5. Imprimir total a cancelar mensual"<<std::endl;
	std::cout<<"6. Mostrar Registro de Usuarios"<<std::endl;
	std::cout<<"7. Salir"<<std::endl;
	std::cout<<"\nPor favor, seleccione una opcion: ";
	
	
	opc=Validaciones::validarMenuOpc('1', '7');
	
	switch(opc){
		case 1:
			emp1=pedirDatosDeEmpleado();
			std::cout<<"\n---------------------Usuario Registrado Exitosamente---------------------";
			std::cout<<"\nNombre:   "<<emp1.getNombre();
			std::cout<<"\nApellido: "<<emp1.getApellido();
			std::cout<<"\nEdad:     "<<emp1.getEdad();
			std::cout<<"\nCargo:    "<<emp1.getCargo();
			std::cout<<"\nCedula:   "<<emp1.getCedula();
			std::cout<<"\nSalario:  "<<"$"<<emp1.getSalario()<<"\n";
			guardarEmpleadosEnArchivo(emp1);
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
			empleadosRegistrados->mostrar();
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

Empleado Menus::pedirDatosDeEmpleado(){
	
	std::string nombre;
	std::string apellido;
	std::string cargo;
	std::string cedula;
	bool boleanoCedula;
	int edad;

	/*std::cout<<"\nIngrese la cedula del empleado a registrar: ";
	std::cin>>cedula;*/
	/*do{
		std::cin>>cedula;
		boleanoCedula=Validaciones::validarCedulaEcuatoriana(cedula); */
	std::cout<<"\nIngrese la Cedula: ";
	cedula = Validaciones::validarCedulaEcuatoriana();
	std::cout<<"\nIngrese el Nombre: ";
	nombre = Validaciones::validarStrings();
	std::cout<<"\nIngrese el Apellido: ";
	apellido = Validaciones::validarStrings();
	std::cout<<"\nIngrese su edad: ";
	std::cin>>edad;
	//edad = Validaciones::validarMenuOpc('18','80');
	cargo = pedirCargo();
	
	Empleado empleado(cedula,nombre,apellido,edad,cargo);
	
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
        return;
    }
    archive <<"Nombre:   "<<emp1.getNombre();
    archive <<"\nApellido: "<<emp1.getApellido();
    archive <<"\nEdad:     "<<emp1.getEdad();
    archive <<"\nCargo:    "<<emp1.getCargo();
    archive <<"\nCedula:   "<<emp1.getCedula();
    archive <<"\nSalario:  "<<emp1.getSalario();

    archive << "\n---------------------------------" << std::endl;

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

//Cargar los Empleados desde un archivo de texto
void Menus::cargarDatosDeArchivoEnLista(){
	Nodo<Empleado>* nodo;
	
	//Creamos una lista doblemente enlazada
	ListaDoble<int>* nuevaLista = new ListaDoble<int>();
	ListaDoble<Empleado>* empleadosRegistrados = new ListaDoble<Empleado>();
	
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

			//Crear el Objeto Empleado
			Empleado empleado(cedula,nombre,apellido,edad,cargo);
			
            // Inserta el vehículo en la lista
            empleadosRegistrados->insertar(empleado);
        }
    }
    file.close();
	
}