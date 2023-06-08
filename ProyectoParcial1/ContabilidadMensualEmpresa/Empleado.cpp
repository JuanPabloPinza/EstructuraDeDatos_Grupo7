/*******************************
 UNIVERSIDAD DE LAS FUERZAS ARMADAS (ESPE)
 Asignatura: Estructuras de Datos
 Nombre: Juan Pablo Pinza Armijos
 Fecha de creacion: 07/06/23 9:10
 Fecha de modificacion: 31/05/23 10:10
 Enunciado General: Conjunta 1 Parcial 1
 ********************************/
#include "Empleado.h"
#include <iostream>

	Empleado::Empleado(){
		this->cedula = "";	
		this->nombre ="";
		this->apellido="";
		this->salario = 0.0;
		this->cargo="";
		this->edad = 0;
		this->anioDeContratacion = 0;
	}
	
	Empleado::Empleado(std::string cedula,std::string nombre,std::string apellido, int edad, std::string cargo){
		
		this->cedula=cedula;
		this->nombre=nombre;
		this->apellido=apellido;
		this->cargo=cargo;
		this->salario=calcularSueldo();
		this->edad=edad;
	}
	
	Empleado::Empleado(std::string cedula,std::string nombre,std::string apellido, int edad, std::string cargo, int anioDeContratacion){
		
		this->cedula=cedula;
		this->nombre=nombre;
		this->apellido=apellido;
		this->cargo=cargo;
		this->salario=calcularSueldo();
		this->edad=edad;
		this->anioDeContratacion = anioDeContratacion;
	}
	
	Empleado::~Empleado(){
	}
	
	double Empleado::calcularSueldo(){
		if (cargo == "CEO") {
            return 1500.0;
        } else if (cargo == "Oficinista") {
            return 800.0;
        } else if (cargo == "Personal de Limpieza") {
            return 450.0;
        } else {
            return 0.0; // Cargo inválido
        }
	}
	
std::ostream& operator<<(std::ostream& os, const Empleado& empleado) {
    os << "Nombre: " << empleado.nombre << " " << empleado.apellido << std::endl
       << "Edad: " << empleado.edad << std::endl
       << "Cedula: " << empleado.cedula << std::endl
       << "Cargo: " << empleado.cargo << std::endl
       << "Salario: $" << empleado.salario<< std::endl
       << "Anio de Contratacion: "<<empleado.anioDeContratacion << std::endl;
    return os;
}
	
	void Empleado::setNombre(std::string nombre){
		this->nombre = nombre;
	}
	
	std::string Empleado::getNombre(){
		return nombre;
	}
	
	void Empleado::setApellido(std::string apellido){
		this->apellido=apellido;
	}
	
	std::string Empleado::getApellido(){
		return apellido;
	}
	void Empleado::setSalario(double salario){
		this->salario=salario;
	}
	double Empleado::getSalario(){
		return salario;
	}
	void Empleado::setCargo(std::string cargo){
		this->cargo = cargo;
	}
	std::string Empleado::getCargo(){
		return cargo;
	}
	void Empleado::setCedula(std::string cedula){
		this->cedula = cedula;
	}
	
	std::string Empleado::getCedula(void){
		return cedula;
	}
	
	void Empleado::setEdad(int edad){
		this->edad=edad;
	}
	
	int Empleado::getEdad (){
		return edad;
	}
	
	void Empleado::setAnioDeContratacion(int anioDeContratacion){
		this->anioDeContratacion=anioDeContratacion;
	}
	
	int Empleado::getAnioDeContratacion(){
		return anioDeContratacion;
	}
	
	
	