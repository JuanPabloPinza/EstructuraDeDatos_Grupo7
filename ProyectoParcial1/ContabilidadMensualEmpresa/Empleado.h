#pragma once

#include <iostream>
#include <string>


class Empleado{
	private:
		std::string nombre;
		std::string apellido;
		double salario;
		std::string cargo;
		char *cedula;
		
	public:
		void setNombre(std::string);
		std::string getNombre();
		void setApellido(std::string);
		std::string getApellido();
		void setSalario(double);
		double getSalario();
		void setCargo(std::string);
		std::string getCargo();
		void setCedula(char* cedula);
		char* getCedula(void);
		
		Empleado();
		Empleado(char* cedula,std::string nombre,std::string apellido,std::string cargo);
		~Empleado();
		
};

