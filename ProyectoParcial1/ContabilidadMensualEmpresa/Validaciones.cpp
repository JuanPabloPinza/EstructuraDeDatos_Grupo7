
//REFERENCIAS: Validaciones - Stephen Drouet | Grupo 2
#include "Validaciones.h"
#include <iostream>
#include <cstdlib> //funcion atoi()
#include <conio.h> //getch()
#include <cctype>
#include <cstring> //Para usar strlen y validar la cédula Ecuatoriana

int Validaciones::validarMenuOpc(char cnum1, char cnum2) {		
	char *entrada = new char[30];
	char tecla;
	int i = 0;
	
	while (true) {
		tecla = getch(); // lee la tecla ingresada por el usuario sin mostrarla en la consola
		
		if (tecla == '\r' && i==1) { // si el usuario presiona Enter
		  std::cout << std::endl;
		  break;
		} else if (tecla == '\b' && i > 0) { // si el usuario presiona Backspace y hay caracteres en la entrada			
			i--;						
			std::cout << "\b \b"; // borra el último caracter de la consola
			entrada[i] = 0; // elimina el último caracter de la entrada
		} else if (tecla >= cnum1 && tecla <= cnum2 && i<1) { // si el usuario ingresa un dígito
			  entrada[i++] = tecla;
			  std::cout << tecla; // muestra el caracter ingresado en la consola
		}
	}

	return atoi(entrada); // convierte la entrada a un número int y lo retorna
}

char* Validaciones::validarStrings(){
	char *dato=new char[0];
	char c;
	int i=0;    
	
	while((c=getch())!=13) {
		if(c>='A' && c<='Z' ||c>='a' && c<='z'){ 
			dato[i++]=toupper(c);
			printf("%c",c);
		}else if(c==8 && i!=0){
		
			*(dato+(i-1))=0;
			i--;
				
			putchar(8);
			putchar(32);
			putchar(8);			
		}
	}
	dato[i]='\0';
	return dato;
	delete []dato;
}

std::string Validaciones::validarCedulaEcuatoriana() {
    while (true) {
        char *entrada = new char[10];
		char tecla;
		int i = 0;
		while (true) {
			tecla = getch(); // lee la tecla ingresada por el usuario sin mostrarla en la consola
			
			if (tecla == '\r' && i == 10) { // si el usuario presiona Enter
			  std::cout << std::endl;
			  break;
			} else if (tecla == '\b' && i > 0) { // si el usuario presiona Backspace y hay caracteres en la entrada			
				i--;						
				std::cout << "\b \b"; // borra el último caracter de la consola
				entrada[i] = 0; // elimina el último caracter de la entrada
			} else if (i<10 &&	isdigit(tecla)) { // si el usuario ingresa un caracter (3 primeros caracteres de la placa)
				entrada[i++] = tecla;
				std::cout << tecla; // muestra el caracter ingresado en la consola
			} 
		}
		entrada[i] = '\0';
		
		// Obtener dígitos de la cédula
	    int digitos[10];
	    for (int i = 0; i < 10; i++) {
	        digitos[i] = entrada[i] - '0';
	    }
		
	    // Validar el último dígito
	    int suma = 0;
	    for (int i = 0; i < 9; i += 2) {
	        int producto = digitos[i] * 2;
	        if (producto > 9) {
	            producto -= 9;
	        }
	        suma += producto;
	    }
	    for (int i = 1; i < 8; i += 2) {
	        suma += digitos[i];
	    }
	    int digitoVerificador = 10 - (suma % 10);
	    if (digitoVerificador == 10) {
	        digitoVerificador = 0;
	    }
		entrada[i] = '\0';
	    // Comparar el último dígito calculado con el de la cédula
	    if(digitos[9] == digitoVerificador) {
	   		return entrada;
	   	};
        
        delete[] entrada;
        std::cout << "Cedula invalida. Intente nuevamente: ";
     
	}
}