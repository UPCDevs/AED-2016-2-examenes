#pragma once
#include <iostream>
#include <string.h>
#include <string>
//#include <cstring>

using namespace std;

/**
* Ejercicio 03: Invierta las letras de un string
*
*/

class Inversor
{
public:
	//Inversor();
	//~Inversor();

	string invertir(string str) {
		string val = "";
		for (int i = str.size() - 1; i >= 0; i--)
		{
			val = val + str.at(i);
		}
		return (val);
	}
	int contarCaracteresRepetidos(string s, char d) {
		int longitud = s.size();
		int contador = 0;
		for (int i = 0; i < longitud; i++)
		{
			if (s.at(i) == d)
			{
				contador++;
			}
		}
		cout << contador << endl;
		return(contador);
	}

//private:

};



int main(){

	// TEST

	string oracion = "Hola como estas";

	//Declaración de un objeto de la clase
	Inversor* objInversor = new Inversor();

	string oracionInvertida = objInversor->invertir(oracion);



	cout << oracionInvertida << endl;

	system("PAUSE");
	return 0;
}
