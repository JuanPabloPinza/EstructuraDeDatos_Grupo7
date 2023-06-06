
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

bool Validaciones::validarCedulaEcuatoriana(const char* cedula) {
    // Verificar que la cédula tenga 10 dígitos
    if (std::strlen(cedula) != 10) {
        return false;
    }

    // Verificar que todos los caracteres sean dígitos
    for (int i = 0; i < 10; i++) {
        if (!std::isdigit(cedula[i])) {
            return false;
        }
    }

    // Verificar el último dígito utilizando el algoritmo de validación
    int total = 0;
    int coeficientes[9] = {2, 1, 2, 1, 2, 1, 2, 1, 2};
    for (int i = 0; i < 9; i++) {
        int digito = (cedula[i] - '0') * coeficientes[i];
        if (digito > 9) {
            digito -= 9;
        }
        total += digito;
    }

    int residuo = total % 10;
    int verificador = (residuo == 0) ? 0 : 10 - residuo;
    int ultimoDigito = cedula[9] - '0';

    return (verificador == ultimoDigito);
}

