#pragma once
#include <iostream>
#include <string.h>

using namespace std;

/**
* Ejercicio 02: Cuenta las palabras que hay en un string
*
*/

int contarPalabras (string s){

	int contador = 1, pos;

	if (s.empty())//vacio
	{
		contador = 0;
	}
	else
	{
		pos = s.find(" ");//buscar
		while (pos != -1)
		{
			contador++;
			pos = s.find(" ", pos + 1);
		}
	}
	return contador;

}


int main(){
	string palabra = "Daniel codea peor que Jaime";

	//char fraseFormat[200];

	//strcpy_s(fraseFormat, palabra.c_str());

	cout << "Frase: " << palabra<<endl;
	cout << "Cantidad de palabras = " << contarPalabras(palabra) << endl;

	system("PAUSE");
	return 0;
}
