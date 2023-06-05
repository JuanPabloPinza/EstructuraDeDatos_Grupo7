#ifndef USUARIO_H
#define USUARIO_H

class Usuario
{
	
	private:
	long cedula;
	string Nombre;
	string Apellido;
	int edad;
	Cargo cargo;	
	
	public:
	void setCedula(long);
	long getCedula(void);
	void setNombre(string);
	string getNombre(void);
	void setApellido(string);
	string getApellido(void);
	void setEdad(int);
	int getEdad(void);
	

};

#endif