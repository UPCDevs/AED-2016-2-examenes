#pragma once
class COrganizaciones
{
public:
	COrganizaciones();
	~COrganizaciones();
	typedef  struct Candidato
	{
		char nombre[100];
		char DNI[100];
		char dirección[100];
		char fechaNacimiento[100];
	};
	typedef struct Congresistas
	{
		char nom[50];
	};
	typedef struct OrganizacionPolitica
	{
		Candidato cant;
		Congresistas congre[numCongresistas];
	};
	void limpiarRegistroOrganizacionPolitica(OrganizacionPolitica *miorga);
	void llenaDatosPresidente(OrganizacionPolitica *miorga);
	void llenaDatosCongresista(OrganizacionPolitica *miorga);
	void LlenaDatos(OrganizacionPolitica *miorga);
	void Guaradarentxt();
	void Imprimirdatos(OrganizacionPolitica *miorga);
	void imprimir_desdel_archivo();
	bool Buscador(char *nombre, fpos_t *pos, OrganizacionPolitica *miorga);
	void buscar();
	void modificar();
	void eliminar();
	char Menu();
};

