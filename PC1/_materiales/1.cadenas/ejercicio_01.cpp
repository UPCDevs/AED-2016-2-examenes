#include<iostream>
#include<string.h>
using namespace std;

/**
 * Ejercicio 01: Cuenta las vocales que hay en un string
 *
 */

int contarCaracteres(char *s, char d) {
	int longitud = strlen(s);
	int cont = 0;
	for (int i = 0; i < longitud; i++)
	{
		if (s[i] == d)
		{
			cont++;
		}
	}
	return(cont);
}
void contadorDeVocales(char *s, char v[]) {
	int sizeVoc = sizeof(s) / sizeof(char);//Recordar no me olvides
	for (int i = 0; i < sizeVoc; i++)
	{
		int numVocales = contarCaracteres(s, v[i]);
		cout << "numero de vocales(" << v[i] << ")=>" << numVocales << endl;
	}
}
int main() {
	//Cuenta las vocales que hay en un string (Un string es un arreglo de caracteres)
	char vocales[5] = { 'a', 'e', 'i', 'o', 'u' };
	char* palabra = (char*)("dabale arroz a la zorra el abad");
	contadorDeVocales(palabra, vocales);
	system("pause");
	return(0);
}
