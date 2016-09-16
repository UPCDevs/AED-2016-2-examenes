#pragma once
#include<iostream>
#include<string.h>

using namespace std;

/**
* Ejercicio 01: Cuenta las vocales que hay en un string
*
*/

int contarCaracteres(char *oracion, char vocal) {
	int longitud = strlen(oracion); //obtiene longitud
	int cont = 0;
	for (int i = 0; i < longitud; i++)
  	{
		//Si en la oracion encontramos la vocal solicitada, aumentamos el contador
		if (oracion[i] == vocal)
		{
			cont++;
		}
	}

	return(cont);
}
void contadorDeVocales(char *oracion, char vocales[]) {

	int sizeVoc = sizeof(oracion) / sizeof(char);//Recordar no me olvides

	cout << "Tamaño de sizeVoc:" << sizeVoc <<endl;

	for (int i = 0; i < sizeVoc; i++)
	{
		int numVocales = contarCaracteres(oracion, vocales[i]);
		cout << "Numero de vocales(" << vocales[i] << ")=>" << numVocales << endl;
	}
}
int main() {

	//Cuenta las vocales que hay en un string (Un string es un arreglo de caracteres)

	char vocales[5] = { 'a', 'e', 'i', 'o', 'u' };
	char* oracion = (char*)("dabale arroz a la zorra el abad");

	contadorDeVocales(oracion, vocales);
	system("pause");
	return(0);
}
