/*******************************
 UNIVERSIDAD DE LAS FUERZAS ARMADAS (ESPE)
 Asignatura: Estructuras de Datos
 Nombre: Juan Pablo Pinza Armijos
 Fecha de creacion: 07/06/23 9:10
 Fecha de modificacion: 31/05/23 10:10
 Enunciado General: Conjunta 1 Parcial 1
 ********************************/
#include "Nodo.h"

template<typename T>
Nodo<T>::Nodo() {
	this->dato = nullptr;
	this->siguiente = nullptr;
	this->anterior = nullptr;
}

template<typename T>
Nodo<T>::Nodo(T dato){
	this->dato = dato;
	this->siguiente = nullptr;
	this->anterior = nullptr;
}

template<typename T>
Nodo<T>::~Nodo() {
}

template<typename T>
void Nodo<T>::setDato(T nuevoDato){
	this->dato = nuevoDato;
}

template<typename T>
void Nodo<T>::setSiguiente(Nodo<T>* nuevoSiguiente){
	this->siguiente = nuevoSiguiente;
}

template<typename T>
T Nodo<T>::getDato(void){
	return dato;
}

template<typename T>
Nodo<T>* Nodo<T>::getSiguiente(void){
	return siguiente;
}

template<typename T>
Nodo<T>* Nodo<T>::getAnterior(void){
	return anterior;
}

template<typename T>
void Nodo<T>::setAnterior(Nodo<T>* nuevoAnterior){
	this->anterior = nuevoAnterior;
}