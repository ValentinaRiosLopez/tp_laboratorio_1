#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "LinkedList.h"
#include "Passenger.h"
#include "funcionesUTN.h"


/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	FILE* pFile;

	if(path != NULL && pArrayListPassenger != NULL)
	{
		pFile = fopen(path,"r");

		if(pFile != NULL)
		{
			if(!parser_PassengerFromText(pFile,pArrayListPassenger))
			{
				retorno = 0;
				printf("Lectura realizada...\n");
			}
			else
			{
				printf("ERROR\n");
			}
		}

	}

	fclose(pFile);

    return retorno;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	FILE* pFile;

	if(path != NULL && pArrayListPassenger != NULL)
	{
		pFile = fopen(path,"rb");

		if(pFile != NULL)
		{

			if(!parser_PassengerFromBinary(pFile,pArrayListPassenger))
			{
				retorno = 0;
				printf("Lectura realizada...\n");
				fclose(pFile);
			}
			else
			{
				printf("ERROR.\n");
			}
		}

	}

	fclose(pFile);

	return retorno;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	int auxId;
	char id[10];
	char auxName[50];
	char auxSurname[50];
	float auxPrecio;
	char precio[10];
	char auxCodigo[8];
	int auxTipo;
	char tipo[50];
	int auxEstado;
	char estado[50];
	Passenger* auxPassenger;

	if(pArrayListPassenger != NULL)
	{

		auxId = Passenger_lastId(pArrayListPassenger);
		itoa(auxId,id,10);
		utn_getStringSoloLetras(auxName,"Ingrese el Nombre del pasajero: ","ERROR debe tener solo letras y menos de 50 caracteres: ", 3, 50);
		utn_getStringSoloLetras(auxSurname,"Ingrese el Apellido del pasajero: ","ERROR debe tener solo letras y menos de 50 caracteres: ", 3, 50);
		auxPrecio = utn_getFloat("Ingrese el precio: ","ERROR Ingrese un numero entre 1000 y 100000: ",1000,100000);
		gcvt(auxPrecio,2,precio);

		utn_getStringAlfaNumerico(auxCodigo, "Ingrese el codigo de vuelo: ", "ERROR el codigo debe ser de menos de 8 caracteres y tener letras y numeros:  ",3,8);

		auxTipo = utn_getNumero("Ingrese el numero correspondiente al tipo de pasajero:\n"
								"1)First Class.\n"
								"2)Executive Class.\n"
								"3)Economy Class.\n", "EROR Ingrese un numero valido: \n",1,3);
		switch(auxTipo)
		{
		case 1:
			strcpy(tipo,"FirstClass");
			break;
		case 2:
			strcpy(tipo,"ExecutiveClass");
			break;
		case 3:
			strcpy(tipo,"EconomyClass");
			break;
		}

		auxEstado = utn_getNumero("Ingrese el numero correspondiente al estado de vuelo:\n"
								"1)En Horario.\n"
								"2)En Vuelo.\n"
								"3)Aterrizado.\n"
								"4)Demorado.\n", "EROR Ingrese un numero valido: \n",1,4);

		switch(auxEstado)
		{
		case 1:
			strcpy(estado,"En Horario");
			break;
		case 2:
			strcpy(estado,"En Vuelo");
			break;
		case 3:
			strcpy(estado,"Aterrizado");
			break;
		case 4:
			strcpy(estado,"Demorado");
			break;
		}

		auxPassenger = Passenger_newParametros(id,auxName,auxSurname,precio,auxCodigo,tipo,estado);

		if(auxPassenger != NULL)
		{
			ll_add(pArrayListPassenger,auxPassenger);
			retorno = 0;
		}

	}


    return retorno;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	int id;
	int opcion;
	int i;
	int tam;
	Passenger* auxPasajero;
	char auxNombre[50];
	char auxApellido[50];
	float auxPrecio;
	char auxCodigo[10];
	int auxTipo;
	int auxEstado;

	if(pArrayListPassenger != NULL)
	{
		id = utn_getNumero("Ingrese el id del pasajero a modificar: ","ERROR ingrese un id valido: ",1,1000000);

		tam = ll_len(pArrayListPassenger);

		i = Passenger_findId(pArrayListPassenger, tam, id);
		auxPasajero = ll_get(pArrayListPassenger, i);

		if(i != -1)
		{
			printf("Pasajero a modificar: \n");


			do{
				Passenger_listOne(auxPasajero);
				opcion = utn_getNumero("\n---MENU MODIFICAR---\n"
									   "1)Modificar Nombre.\n"
									   "2)Modificar Apelldo.\n"
									   "3)Modificar precio.\n"
									   "4)Modificar codigo de vuelo.\n"
									   "5)Modificar tipo de pasajero.\n"
									   "6)Modificar estado de vuelo.\n"
									   "7)Volver al menu principal.\n"
									   "Ingrese una opcion...","ERROR Ingrese una opcion valida...",1,7);

				switch(opcion)
				{
				case 1:

					utn_getStringSoloLetras(auxNombre,"Ingrese el Nombre del pasajero: ","ERROR debe tener solo letras y menos de 50 caracteres: ", 3, 50);
					Passenger_setNombre(auxPasajero,auxNombre);
					retorno = 0;

					break;
				case 2:
					utn_getStringSoloLetras(auxApellido,"Ingrese el Apellido del pasajero: ","ERROR debe tener solo letras y menos de 50 caracteres: ", 3, 50);
					Passenger_setApellido(auxPasajero, auxApellido);
					retorno = 0;
					break;
				case 3:
					auxPrecio = utn_getFloat("Ingrese el precio: ","ERROR Ingrese un numero entre 1000 y 100000: ",1000,100000);
					Passenger_setPrecio(auxPasajero,auxPrecio);
					retorno = 0;
					break;
				case 4:
					utn_getStringAlfaNumerico(auxCodigo, "Ingrese el codigo de vuelo: ", "ERROR el codigo debe ser de menos de 8 caracteres y tener letras y numeros:  ",3,8);
					Passenger_setCodigoVuelo(auxPasajero,auxCodigo);
					retorno = 0;
					break;
				case 5:
					auxTipo = utn_getNumero("Ingrese el numero correspondiente al tipo de pasajero:\n"
											"1)First Class.\n"
											"2)Executive Class.\n"
											"3)Economy Class.\n", "EROR Ingrese un numero valido: \n",1,3);
					Passenger_setTipoPasajero(auxPasajero, auxTipo);
					retorno = 0;

					break;
				case 6:
					auxEstado = utn_getNumero("Ingrese el numero correspondiente al estado de vuelo:\n"
											  "1)En Horario..\n"
											  "2)En Vuelo.\n"
											  "3)Aterrizado.\n"
											  "4)Demorado", "EROR Ingrese un numero valido: \n",1,4);
					Passenger_setEstadoDeVuelo(auxPasajero, auxEstado);
					retorno = 0;

					break;

				}
			}while(opcion != 7);

		}


	}

    return retorno;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	int id;
	int tam;
	int i;
	char rta;
	Passenger* auxPasajero;

	if(pArrayListPassenger != NULL)
	{
		id = utn_getNumero("Ingrese el id del pasajero a eliminar: ","ERROR ingrese un id valido: ",1,1000000);

		tam = ll_len(pArrayListPassenger);

		i = Passenger_findId(pArrayListPassenger, tam, id);

		if(i != -1)
		{
			auxPasajero = ll_get(pArrayListPassenger, i);
			Passenger_listOne(auxPasajero);
			rta = utn_getRespuesta("Seguro que quiere eliminar este pasajero?(s/n): ","ERROR introduzca 's' para si o 'n' para no: ");

			if(rta == 's')
			{
				ll_remove(pArrayListPassenger, i);

				retorno = 0;
			}
		}
	}

    return retorno;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	int i;
	int tam;
	Passenger* auxPasajero;

	if(pArrayListPassenger != NULL)
	{
		tam = ll_len(pArrayListPassenger);
		printf("%-6s  %-25s  %-25s  %-10s  %-10s  %-20s  %-15s\n","ID","NOMBRE","APELLIDO","PRECIO","CODIGO","TIPO","ESTADO");

		for(i=0;i<tam;i++)
		{
			auxPasajero =(Passenger*)ll_get(pArrayListPassenger,i);

			Passenger_listOne(auxPasajero);

			retorno=0;
		}

	}

    return retorno;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	int opcion;
	int orden;

	if(pArrayListPassenger != NULL)
	{
		do{
		opcion = utn_getNumero("\n---ORDENAR---\n"
							   "1)Ordenar por ID.\n"
							   "2)Ordenar por nombre y apellido.\n"
							   "3)Ordenar por precio.\n"
							   "4)Ordenar por codigo de vuelo.\n"
							   "5)Volver al menu principal.\n"
							   "Ingrese una opcion...\n","ERROR Ingrese una opcion valida...\n",1,5);

		if(opcion !=5)
		{
			orden = utn_getNumero("Ingrese el 1 para ordenar de forma ascendente y 0 para forma descendente:'\n ","ERROR Ingrese un numero valido...\n",0,1);
		}

		switch(opcion)
		{
		case 1:
			if(!ll_sort(pArrayListPassenger,Passenger_ordenarId,orden))
			{
				retorno = 0;
			}
			break;
		case 2:
			if(!ll_sort(pArrayListPassenger,Passenger_ordenarNombreyApellido,orden))
			{
				retorno = 0;
			}
			break;
		case 3:
			if(!ll_sort(pArrayListPassenger,Passenger_ordenarPrecio,orden))
			{
				retorno = 0;
			}
			break;
		case 4:
			if(!ll_sort(pArrayListPassenger,Passenger_ordenarCodigoVuelo,orden))
			{
				retorno = 0;
			}
			break;
		}
	}while(opcion != 5);
	}



    return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	int auxId;
	char auxNombre[50];
	char auxApellido[50];
	float auxPrecio;
	char auxCodigo[10];
	int auxTipo;
	char tipo[20];
	int auxEstado;
	char estado[20];
	FILE* pFile;
	Passenger* auxPasajero;
	int tam;
	int i;

	if(path != NULL && pArrayListPassenger != NULL)
	{
		tam = ll_len(pArrayListPassenger);

		if(tam>0)
		{
			pFile = fopen(path,"w");

			if(pFile != NULL)
			{
				fprintf(pFile,"id,name,lastname,price,flycode,typePassenger,statusFlight\n");

				for(i=0;i<tam;i++)
				{
					auxPasajero = (Passenger*)ll_get(pArrayListPassenger, i);

					if(auxPasajero != NULL)
					{
						Passenger_getId(auxPasajero,&auxId);
						Passenger_getNombre(auxPasajero,auxNombre);
						Passenger_getApellido(auxPasajero,auxApellido);
						Passenger_getPrecio(auxPasajero,&auxPrecio);
						Passenger_getCodigoVuelo(auxPasajero,auxCodigo);
						Passenger_getTipoPasajero(auxPasajero,&auxTipo);
						switch(auxTipo)
						{
						case 1:
							strcpy(tipo,"FirstClass");
							break;
						case 2:
							strcpy(tipo,"ExecutiveClass");
							break;
						case 3:
							strcpy(tipo,"EconomyClass");
							break;
						}
						Passenger_getEstadoDeVuelo(auxPasajero,&auxEstado);

						switch(auxEstado)
						{
						case 1:
							strcpy(estado,"En Horario");
							break;
						case 2:
							strcpy(estado,"En Vuelo");
							break;
						case 3:
							strcpy(estado,"Aterrizado");
							break;
						case 4:
							strcpy(estado,"Demorado");
							break;
						}

						fprintf(pFile,"%d,%s,%s,%.2f,%s,%s,%s\n",auxId,auxNombre,auxApellido,auxPrecio,auxCodigo,tipo,estado);
					}


				}
				fclose(pFile);
				if(i==tam)
				{
					retorno = 0;
					printf("Se pudo guardar con exito...");
				}


			}
		}
	}


    return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	int retorno=-1;
	FILE* pFile;
	Passenger* auxPasajero;
	int tam;
	int i;

		if(pArrayListPassenger != NULL)
		{
			pFile = fopen(path,"wb");
			if(pFile != NULL)
			{
				tam = ll_len(pArrayListPassenger);
				for(i=0;i<tam;i++)
				{
					auxPasajero = (Passenger*)ll_get(pArrayListPassenger,i);
					fwrite(auxPasajero,sizeof(Passenger),1,pFile);
				}
			}

			fclose(pFile);
			retorno = 0;
		}
		return retorno;

}

int controller_checkId(char* path, LinkedList* pArrayListPassenger,int* lastId,int contador)
{
	int retorno = -1;
	FILE* pFile;
	Passenger* auxPassenger;
	char buf[2000];
	char auxId[10];
	int id;
	int i;

	if(path != NULL && pArrayListPassenger != NULL)
	{
		pFile = fopen(path, "r");
		if(pFile != NULL)
		{
			fscanf(pFile,"%[^\n]\n", buf);

			while(!feof(pFile))
			{
				fscanf(pFile,"%[^,]%[^\n]\n", auxId,buf);

			}

			id = atoi(auxId);

			printf("Se alteraron los id de los siguientes pasajeros para poder cargarlos  al sistema: \n");


			for(i=0;i<contador;i++)
			{
				auxPassenger = ll_get(pArrayListPassenger, i);
				id = id + 1;
				Passenger_setId(auxPassenger, id);
				ll_set(pArrayListPassenger, i,auxPassenger);
				printf("-%s %s nuevo id: %d\n",auxPassenger->nombre, auxPassenger->apellido,auxPassenger->id);
			}

			*lastId = id;
			retorno = 0;
		}
		fclose(pFile);
	}

	return retorno;
}
