#include "stdafx.h"
#include "Organizaciones.h"


COrganizaciones::COrganizaciones()
{
}


COrganizaciones::~COrganizaciones()
{
}
void COrganizaciones::limpiarRegistroOrganizacionPolitica(OrganizacionPolitica *miorga)
{
	int i;
	for (i = 0; i < 100; i++)
	{
		miorga->cant.nombre[i] = '\0';
		miorga->cant.DNI[i] = '\0';
		miorga->cant.dirección[i] = '\0';
		miorga->cant.fechaNacimiento[i] = '\0';
	}
}
void COrganizaciones::llenaDatosPresidente(OrganizacionPolitica *miorga)
{
	cout << "\n\nINGRESE LOS DATOS DEL CANDIDATO PRESIDENCIAL POR FAVOR" << endl << endl;
	cout << "INGRESE el nombre de su candidato: " << endl;
	fflush(stdin); gets_s(miorga->cant.nombre);

	cout << "Ingrese el dni de su candidato: " << endl;
	fflush(stdin); gets_s(miorga->cant.DNI);

	cout << "Ingrese La fecha de nacimiento: " << endl;
	fflush(stdin); gets_s(miorga->cant.fechaNacimiento);

	cout << "Ingrese la direcciuon de su candidato: " << endl;
	fflush(stdin); gets_s(miorga->cant.dirección);
}
void COrganizaciones::llenaDatosCongresista(OrganizacionPolitica *miorga)
{
	int i = 0;
	char opcion;
	do
	{
		cout << "Ingrese el nombre del congresista " << i + 1 << ": " << endl;
		fflush(stdin); gets_s(miorga->congre[i].nom);
		i++;
	} while (i<numCongresistas);
}
void COrganizaciones::LlenaDatos(OrganizacionPolitica *miorga)
{
	llenaDatosPresidente(miorga);

	cout << "\nINGRESE LOS DATOS DE LOS 5 CONGRESISTAS" << endl << endl;
	llenaDatosCongresista(miorga);
}
void COrganizaciones::Guaradarentxt()
{
	OrganizacionPolitica miorga;
	FILE *Archivo = fopen("JNE_elecciones2016.txt", "a+");
	LlenaDatos(&miorga);
	fwrite(&miorga, sizeof(OrganizacionPolitica), 1, Archivo);
	fclose(Archivo);
	system("pause");
}
void COrganizaciones::Imprimirdatos(OrganizacionPolitica *miorga){
	cout << "\nMOSTRANDO DATOS PRESIDENTE" << endl;
	cout << "Nombre: " << miorga->cant.nombre << endl;
	cout << "Dni: " << miorga->cant.DNI << endl;
	cout << "Fecha nacimiento: " << miorga->cant.fechaNacimiento << endl;
	cout << "Direccion: " << miorga->cant.dirección << endl;
	cout << "\nMOSTRANDO DATOS DE LOS CONGRESISTAS" << endl;
	int i = 0;
	do
	{
		cout << "Nombre: " << miorga->congre[i].nom << endl;
		i++;
	} while (i<numCongresistas);
}
void COrganizaciones::imprimir_desdel_archivo()
{
	OrganizacionPolitica miorga;
	int i = 0;
	FILE *Archivo = fopen("JNE_elecciones2016.txt", "r+");
	fread(&miorga, sizeof(OrganizacionPolitica), 1, Archivo);

	while (feof(Archivo) == false)
	{
		if (miorga.cant.nombre[0] != '\0')
		{
			cout << "\nPARTIDO POLITICO NUMERO " << i + 1 << " -------------------------------";
			Imprimirdatos(&miorga);
			cout << "---------------------------------------------------------\n";
			i++;
		}
		fread(&miorga, sizeof(OrganizacionPolitica), 1, Archivo);
	}
	fclose(Archivo);
	system("pause");
}
bool COrganizaciones::Buscador(char *nombre, fpos_t *pos, OrganizacionPolitica *miorga){
	//l posicion entre registros
	bool encontrado = false;
	FILE *Archivo = fopen("JNE_elecciones2016.txt", "r+");

	fgetpos(Archivo, pos);
	fread(miorga, sizeof(OrganizacionPolitica), 1, Archivo);

	while (feof(Archivo) == false && encontrado == false)
	{
		if (strcmp(nombre, miorga->cant.nombre) == 0)
			encontrado = true;
		else
		{
			fgetpos(Archivo, pos);
			fread(miorga, sizeof(OrganizacionPolitica), 1, Archivo);
		}
	}
	fclose(Archivo);
	return encontrado;
}
void COrganizaciones::buscar()
{
	char buscape[100];
	fpos_t pos;

	OrganizacionPolitica miorga;
	cout << "INGRESE EL nombre a buscar: "; gets_s(buscape);

	if (Buscador(buscape, &pos, &miorga) == true) cout << "El candidato presidencial si existe" << endl;
	else cout << "El candidato presidencial NO existe" << endl;
	system("pause");
}
void COrganizaciones::modificar()
{
	char buscape[100];
	fpos_t pos;
	OrganizacionPolitica miorga;

	cout << "\nIngrese el candidato presidencial a modificar\n";
	gets_s(buscape);

	if (Buscador(buscape, &pos, &miorga) == true)
	{
		cout << "\nModificando.....";
		llenaDatosPresidente(&miorga);
		FILE *Archivo = fopen("JNE_elecciones2016.txt", "r+");
		fseek(Archivo, pos, SEEK_SET);
		fwrite(&miorga, sizeof(OrganizacionPolitica), 1, Archivo);
		fclose(Archivo);
	}
	else
		cout << "No se encontro al candidato!\n";
	system("pause");
}
void COrganizaciones::eliminar()
{
	char buscape[100];
	fpos_t pos;
	OrganizacionPolitica miorga;

	cout << "\nIngrese el candidato presidencial del partido a eliminar\n";
	gets_s(buscape);

	if (Buscador(buscape, &pos, &miorga) == true)
	{
		cout << "\nEliminando.....";
		limpiarRegistroOrganizacionPolitica(&miorga);
		FILE *Archivo = fopen("JNE_elecciones2016.txt", "r+");
		fseek(Archivo, pos, SEEK_SET);
		fwrite(&miorga, sizeof(OrganizacionPolitica), 1, Archivo);
		fclose(Archivo);
	}
	else
		cout << "No se encontro al candidato!\n";
	system("pause");
}
char COrganizaciones::Menu(){

	cout << "1.-INGRESE DATOS" << endl;
	cout << "2.-MOSTRAR DATOS" << endl;
	cout << "3.-BUSCAR POR NOMBRE DE CANDIDATO " << endl;
	cout << "4.-MODIFICAR" << endl;
	cout << "5.-ELIMINAR " << endl;
	cout << "6.-SALIR " << endl;

	return _getch();
}