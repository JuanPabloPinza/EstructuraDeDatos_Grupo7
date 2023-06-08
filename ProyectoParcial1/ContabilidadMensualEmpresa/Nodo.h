/*******************************
 UNIVERSIDAD DE LAS FUERZAS ARMADAS (ESPE)
 Asignatura: Estructuras de Datos
 Nombre: Juan Pablo Pinza Armijos
 Fecha de creacion: 07/06/23 9:10
 Fecha de modificacion: 31/05/23 10:10
 Enunciado General: Conjunta 1 Parcial 1
 ********************************/
#ifndef NODO_H
#define NODO_H

template <typename T>
class Nodo
{
	private:
	T dato;
	Nodo* siguiente;
	Nodo* anterior;
	
	public:
	Nodo();
	~Nodo();
	Nodo(T);
	void setDato(T);
	void setSiguiente(Nodo*);		
	T getDato(void);
	Nodo<T>* getSiguiente(void);
	void setAnterior(Nodo*);
	Nodo<T>* getAnterior(void);
};

#endif