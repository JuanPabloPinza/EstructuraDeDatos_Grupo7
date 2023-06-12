/*******************************
 UNIVERSIDAD DE LAS FUERZAS ARMADAS (ESPE)
 Asignatura: Estructuras de Datos
 Grupo 7
 Integrantes: Juan Pablo Pinza, Sebastián Lasso, Dylan Alvarado
 Fecha de creacion: 31/05/23 9:10
 Fecha de modificacion: 10/06/23 10:10
 Enunciado General: Programa De Contabilidad Mensual.
 ********************************/
#ifndef LISTADOBLE_H
#define LISTADOBLE_H

#include "Nodo.h"
#include <iostream>

template <typename T>
class ListaDoble{
	private:
    	Nodo<T>* primero;
    	Nodo<T>* ultimo;
    	
	public:
		~ListaDoble();
	    ListaDoble();
	    void insertar(T);
	    Nodo<T>* buscar(std::string);
	    void eliminar(T);
	    void mostrar();
	    void eliminarPorCedula(std::string cedula);
	    void guardarListaEnArchivo();
	    void imprimirPorAnioDeContratacion(int anio);
	    void modificar(T, T);
	    double sumaDeSueldosTotales();
};

#endif