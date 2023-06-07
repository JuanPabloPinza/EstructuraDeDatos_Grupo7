#pragma once

#include <iostream>
#include <string>


class Empleado{
	private:
		std::string nombre;
		std::string apellido;
		int edad;
		double salario;
		std::string cargo;
		std::string cedula;
		
	public:
		void setNombre(std::string);
		std::string getNombre();
		void setApellido(std::string);
		std::string getApellido();
		void setEdad(int);
		int getEdad(void);
		void setSalario(double);
		double getSalario();
		void setCargo(std::string);
		std::string getCargo();
		void setCedula(std::string cedula);
		std::string getCedula(void);
		double calcularSueldo();
		friend std::ostream& operator<<(std::ostream&, const Empleado&);	

		
		Empleado();
		Empleado(std::string cedula,std::string nombre,std::string apellido,int edad, std::string cargo);
		~Empleado();
};

