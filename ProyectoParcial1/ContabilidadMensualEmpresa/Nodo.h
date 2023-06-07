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