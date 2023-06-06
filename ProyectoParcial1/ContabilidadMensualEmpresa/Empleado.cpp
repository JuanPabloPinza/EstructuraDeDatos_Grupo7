#include "Empleado.h"
#include <iostream>

//Implementamos:
	Empleado::Empleado(){
		this->cedula = NULL;	
		this->nombre ="";
		this->apellido="";
		this->salario = 0.0;
		this->cargo="";
	}
	
	Empleado::Empleado(char* cedula,std::string nombre,std::string apellido,std::string cargo){
		this->cedula=cedula;
		this->nombre=nombre;
		this->apellido=apellido;
		this->cargo=cargo;
	}
	
	Empleado::~Empleado(){
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
	void Empleado::setCedula(char* cedula){
		this->cedula = cedula;
	}
	
	char* Empleado::getCedula(void){
		return cedula;
	}