#ifndef LISTADOBLE_H
#define LISTADOBLE_H

#include "Nodo.h"

template <typename T>
class ListaDoble{
	private:
    	Nodo<T>* primero;
    	Nodo<T>* ultimo;
    	
	public:
		~ListaDoble();
	    ListaDoble();
	    void insertar(T);
	    Nodo<T>* buscar(T);
	    void eliminar(T);
	    void mostrar();
	    void modificar(T, T);
};

#endif