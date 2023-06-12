/*******************************
 UNIVERSIDAD DE LAS FUERZAS ARMADAS (ESPE)
 Asignatura: Estructuras de Datos
 Grupo 7
 Integrantes: Juan Pablo Pinza, Sebastián Lasso, Dylan Alvarado
 Fecha de creacion: 31/05/23 9:10
 Fecha de modificacion: 10/06/23 10:10
 Enunciado General: Programa De Contabilidad Mensual.
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