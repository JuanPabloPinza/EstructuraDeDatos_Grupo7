/*******************************
 UNIVERSIDAD DE LAS FUERZAS ARMADAS (ESPE)
 Asignatura: Estructuras de Datos
 Nombre: Juan Pablo Pinza Armijos
 Fecha de creacion: 07/06/23 9:10
 Fecha de modificacion: 31/05/23 10:10
 Enunciado General: Conjunta 1 Parcial 1
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
	    void mostrarAnioDeContratacion(int anio);
	    void modificar(T, T);
};

#endif