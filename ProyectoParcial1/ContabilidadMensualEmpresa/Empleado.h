/*******************************
 UNIVERSIDAD DE LAS FUERZAS ARMADAS (ESPE)
 Asignatura: Estructuras de Datos
 Grupo 7
 Integrantes: Juan Pablo Pinza, Sebastián Lasso, Dylan Alvarado
 Fecha de creacion: 31/05/23 9:10
 Fecha de modificacion: 10/06/23 10:10
 Enunciado General: Programa De Contabilidad Mensual.
 ********************************/
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
		int anioDeContratacion;
		
	public:
		void setNombre(std::string);
		std::string getNombre();
		void setApellido(std::string);
		std::string getApellido();
		void setEdad(int);
		int getEdad(void);
		void setAnioDeContratacion(int);
		int getAnioDeContratacion(void);
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
		Empleado(std::string cedula,std::string nombre,std::string apellido,int edad, std::string cargo, int anioDeContratacion);
		Empleado(std::string cedula,std::string nombre,std::string apellido, int edad, std::string cargo, double salario, int anioDeContratacion);
		~Empleado();
};

