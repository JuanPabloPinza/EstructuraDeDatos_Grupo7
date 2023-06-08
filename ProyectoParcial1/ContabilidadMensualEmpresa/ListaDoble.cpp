/*******************************
 UNIVERSIDAD DE LAS FUERZAS ARMADAS (ESPE)
 Asignatura: Estructuras de Datos
 Nombre: Juan Pablo Pinza Armijos
 Fecha de creacion: 07/06/23 9:10
 Fecha de modificacion: 31/05/23 10:10
 Enunciado General: Conjunta 1 Parcial 1
 ********************************/
#include "ListaDoble.h"
#include "Empleado.h"
#include <fstream>
#include <iostream>

template <typename T>
ListaDoble<T>::~ListaDoble(){	
}

template <typename T>
ListaDoble<T>::ListaDoble(){
	this->primero = nullptr;
	this->ultimo = nullptr;
}

template<typename T>
void ListaDoble<T>::insertar(T dato){
	Nodo<T>* nuevo = new Nodo<T>(dato);
    if (primero == nullptr) {
        primero = nuevo;
        ultimo = nuevo;
    } else {
        ultimo->setSiguiente(nuevo);
        nuevo->setAnterior(ultimo);
        ultimo = nuevo;
    }
}

template<typename T>
Nodo<T>* ListaDoble<T>::buscar(std::string cedula) {
    Nodo<T>* actual = primero;
    
    while (actual != nullptr) {
        if (actual->getDato().getCedula() == cedula) {
            return actual;
        }
        actual = actual->getSiguiente();
    }
    
    return nullptr;
}



template<typename T>
void ListaDoble<T>::modificar(T dato, T nuevoDato){
	Nodo<T>* nodo = buscar(dato);
    if (nodo != NULL) {
        nodo->setDato(nuevoDato);
        std::cout << "Elemento actualizado correctamente." << std::endl;
    } else {
        std::cout << "Elemento no encontrado." << std::endl;
    }
}

template<typename T>
void ListaDoble<T>::eliminarPorCedula(std::string cedula) {
    Nodo<T>* nodo = buscar(cedula);
    
    if (nodo != nullptr) {
        if (nodo == primero && nodo == ultimo) {
            primero = nullptr;
            ultimo = nullptr;
        } else if (nodo == primero) {
            primero = nodo->getSiguiente();
            primero->setAnterior(nullptr);
        } else if (nodo == ultimo) {
            ultimo = nodo->getAnterior();
            ultimo->setSiguiente(nullptr);
        } else {
            nodo->getAnterior()->setSiguiente(nodo->getSiguiente());
            nodo->getSiguiente()->setAnterior(nodo->getAnterior());
        }
        delete nodo;
        std::cout << "Empleado eliminado correctamente." << std::endl;
    } else {
        std::cout << "Empleado no encontrado." << std::endl;
    }
}

template<typename T>
void ListaDoble<T>::guardarListaEnArchivo(){
    std::ofstream archivo("empleados.txt");
    
    if (!archivo.is_open()) {
        std::cerr << "No se pudo abrir o crear el archivo." << std::endl;
        return;
    }
    
    Nodo<T>* actual = primero;
    
    while (actual != nullptr) {
        archivo << "Nombre:   " << actual->getDato().getNombre() << std::endl;
        archivo << "Apellido: " << actual->getDato().getApellido() << std::endl;
        archivo << "Edad:     " << actual->getDato().getEdad() << std::endl;
        archivo << "Cargo:    " << actual->getDato().getCargo() << std::endl;
        archivo << "Cedula:   " << actual->getDato().getCedula() << std::endl;
        archivo << "Salario:  " << actual->getDato().getSalario() << std::endl;
        archivo << "Anio De Contratacion:  " << actual->getDato().getAnioDeContratacion() << std::endl;
        archivo << "---------------------------------" << std::endl;
        
        actual = actual->getSiguiente();
    }
    
    archivo.close();
}


template<typename T>
void ListaDoble<T>::eliminar(T dato){
    Nodo<T>* nodo = buscar(dato);
    
    if (nodo != nullptr) {
        if (nodo == primero && nodo == ultimo) {
            primero = nullptr;
            ultimo = nullptr;
        } else if (nodo == primero) {
            primero = nodo->getSiguiente();
            primero->setAnterior(nullptr);
        } else if (nodo == ultimo) {
            ultimo = nodo->getAnterior();
            ultimo->setSiguiente(nullptr);
        } else {
            nodo->getAnterior()->setSiguiente(nodo->getSiguiente());
            nodo->getSiguiente()->setAnterior(nodo->getAnterior());
        }
        delete nodo;
        std::cout << "Elemento eliminado correctamente." << std::endl;
    } else {
        std::cout << "Elemento no encontrado." << std::endl;
    } 	
}

template<typename T>
void ListaDoble<T>::mostrar() {
	Nodo<T>* actual = primero;
	
    while (actual != NULL) {
        std::cout << actual->getDato() << std::endl;
        actual = actual->getSiguiente();
    }
    std::cout << std::endl;
}


template<typename T>
void ListaDoble<T>::mostrarAnioDeContratacion(int anio) {
    Nodo<T>* actual = primero;
	
    while (actual != nullptr) {
        if (actual->getDato().getAnioContratacion() == anio) {
            std::cout << actual->getDato() << std::endl;
        }
        actual = actual->getSiguiente();
    }
    std::cout << std::endl;
}

