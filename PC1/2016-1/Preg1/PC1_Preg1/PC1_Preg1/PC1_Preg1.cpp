#include "stdafx.h"
#include "Organizaciones.h"

int main()
{
	COrganizaciones *objOrga;
	char opcion = objOrga->Menu();
	Console::Clear();

	while (opcion != '6')
	{
		if (opcion == '1')
			objOrga->Guaradarentxt();
		else if (opcion == '2')
			objOrga->imprimir_desdel_archivo();
		else if (opcion == '3')
			objOrga->buscar();
		else if (opcion == '4')
			objOrga->modificar();
		else if (opcion == '5')
			objOrga->eliminar();

		Console::Clear();
		opcion = objOrga->Menu();
		Console::Clear();
	}
}
