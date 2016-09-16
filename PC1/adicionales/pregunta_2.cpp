#pragma once
#include<iostream>
#include<string>
#include<fstream>

using namespace std;

#define max 100

template <typename T>

/**
 Pregunta 2 | 2016-1

**/


class Vector
{
	T *x;
	T *y;
	T m;
public:


	void Menu(){

		// aqui menu

		leerArchivo();


		cout << "¿Cuantos vectores vectores desea obtener (valor de m)?";
		cin >> m;
		cout << endl;

		asignarValores(m);

		imprimirVectores(m);

		sumaVectores(m);

		// guardamos la data
		guardarArchivo(m);


	}


	void asignarValores(T &m){

		x = new T[m];
		y = new T[m];

		for (int i = 0; i < m; i++)
		{
			x[i] = (-10) + rand() % 100;
			y[i] = (-10) + rand() % 200;
		}

	}

	void imprimirVectores(T &m){

		cout << "{";


		for (int i = 0; i < m; i++)
		{
			cout << "(";
			cout << x[i];
			cout << ",";
			cout << y[i];
			cout << ");"<<endl;
		}

	}


	void sumaVectores(T &m){


		cout << "El vector resultante es: ";
		cout << "(";

		T suma_absisa=0;
		T suma_ordenada=0;

		// (sumando x's, sumando y's)

		for (int i = 0; i < m; i++)
		{
			suma_absisa += x[i];
			suma_ordenada += y[i];
		}

		cout << suma_absisa;
		cout << ",";
		cout << suma_ordenada;

		cout << ")";
		cout << endl;



	}

	void guardarArchivo(T &m){
	    // guardar en un archivo de texto

		ofstream archivo;

		archivo.open("data_vectores.txt");

		if (archivo.good())
		{
			for (int i = 0; i < m; i++)
			{
				archivo << x[i] << " " << y[i]<< endl;
			}

			archivo.close();

			cout << endl;
			cout << " Se ha guardado la informacion correctamente en data_vectores.txt" <<endl;
		}

		else{

			cout << "ERROR: No se puede guardar el archivo.";
		}


	}

	void leerArchivo(){
		ifstream archivo_leer;
		char linea[200];

		archivo_leer.open("data_vectores.txt", ios::_Noreplace);

		if (archivo_leer.good())
		{
			cout << "Se han encontrado valores anteriores: "<<endl;

			while (!archivo_leer.eof())
			{
				archivo_leer.getline(linea, sizeof(linea));
				cout << linea<<endl;

			}
			archivo_leer.close();
		}


	}


};



int main(){

	Vector<int> objVector;

	// Mostrar menu
	objVector.Menu();

	system("PAUSE");

	return 0;

}
