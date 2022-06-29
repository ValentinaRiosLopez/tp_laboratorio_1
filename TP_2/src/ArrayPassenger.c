/*
 * ArrayPassenger.c
 *
 *  Created on: 13 may. 2022
 *      Author: ogfri
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionesUTN.h"
#include "ArrayPassenger.h"
#define LIBRE 1
#define OCUPADO 0

/**
 * Inicializa todas las posiciones en libre (1)
 * @param list
 * @param len
 * @return 0 si se realizo correctamente sino -1
 */
int initPassengers(Passenger* list, int len)
{
	int retorno =-1;
	int i;
	if(list !=NULL && len > 0)
	{
		for(i=0;i<len;i++)
		{
			list[i].isEmpty = LIBRE;
		}

		retorno = 0;
	}

	return retorno;
}

/**
 * BUSCA ESPACIO PARA CARGAR UN PASAJERO
 * @param list
 * @param len
 * @param lugar
 * @return 0 si se encontro -1 si no se encontro
 */
int buscarEspacio(Passenger* list, int len, int* lugar)
{
	int retorno = -1;
	int i;

	if(list != NULL && len > 0)
	{

		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty==LIBRE)
			{
				*lugar = i;
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

/**
 * BUSCA UN PASAJERO ESPECIFICO MEDIANTE UN ID PROVISTO POR EL USUARIO
 * @param list
 * @param len
 * @param id
 * @return 0 si se encontro, -1 si no se encontro
 */
int findPassengerById(Passenger* list, int len,int id)
{
	int i;
	int indice = -1;

	if(list != NULL && len > 0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty == OCUPADO && list[i].id == id)
			{
				indice = i;
			}
		}
	}

	return indice;
}

/**
 * AGREGA UN PASAJERO AL SISITEMA
 * @param list
 * @param len
 * @param id
 * @param name
 * @param lastName
 * @param price
 * @param typePassenger
 * @param flycode
 * @return 0 si se pudo agregar, -1 si no se pudo
 */
int addPassenger(Passenger* list, int len, int* id, char name[],char
				lastName[],float price,int typePassenger, char flycode[])
{
	int retorno =-1;
	int indice;
	if(list != NULL && len >  0 && id > 0 && name != NULL && lastName != NULL && flycode != NULL)
	{
		if(buscarEspacio(list, len, &indice)==0)
		{
			list[indice].id = *id;
			*id = *id + 1;
			fflush(stdin);

			utn_getStringSoloLetras(list[indice].name,"Ingrese el nombre del pasajero: ",
							"\nERROR Ingrese un nombre valido: ",3,51);
			fflush(stdin);
			utn_getStringSoloLetras(list[indice].lastName,"Ingrese el apellido del pasajero: ",
							"\nERROR Ingrese un apellido valido: ",3,51);
			fflush(stdin);
			list[indice].price = utn_getFloat("Ingrese el precio del vuelo: ",
						"ERROR Ingrese un precio valido (entre 1000 y 100000):",1000,100000);
			fflush(stdin);
			list[indice].typePassenger= utn_getNumero("Ingrese el numero correspondiente al tipo de pasajero\n"
												  "1-Niño.\n2-Adulto.\n3-Jubilado.\nTipo de pasajero: ",
												  "ERROR Ingrese un tipo valido [1(niño), 2(adulto) o 3(jubilado)]: ",1, 3);

			fflush(stdin);
			utn_getStringAlfaNumerico(list[indice].flycode,"Ingrese el codigo de vuelo: ", "ERROR El codigo debe tener 6 caracteres, letras y numeros: ",
										6,6);


			list[indice].statusFlight = utn_getNumero("Ingrese el estado de vuelo (1 para activo y 0 para inactivo): ",
																	"Error ingrese 1(Activo) o 0 (Inactivo): ",0,1);
			list[indice].isEmpty = OCUPADO;

			imprimirUnPasajero(list[indice]);
			retorno = 0;
		}
		else
		{
			printf("No hay espacio disponible para mas altas.");
		}

	}


	return retorno;
}

/**
 * MUESTRA LOS DATOS DE UN PASAJERO POR CONSOLA
 * @param list
 */
void imprimirUnPasajero(Passenger list)
{
	char auxTipo[10];
	char auxEstado[10];
	utn_convertirFirstUpper(list.name);
	utn_convertirFirstUpper(list.lastName);
	switch(list.typePassenger)
	{
	case 1:
		strcpy(auxTipo, "Niño");
		break;
	case 2:
		strcpy(auxTipo, "Adulto");
		break;
	case 3:
		strcpy(auxTipo, "Jubilado");
		break;
	}

	switch(list.statusFlight)
	{
	case 0:
		strcpy(auxEstado, "INACTIVO");
		break;
	case 1:
		strcpy(auxEstado, "ACTIVO");
		break;
	}

	printf("%4d  %-15s  %-15s  $%-8.2f  %-8s  %-6s  %-8s\n",
		   list.id, list.name, list.lastName, list.price, auxTipo, list.flycode, auxEstado);



}

/**
 * MUESTRA LOS DATOS DE TODOS LOS PASAJEROS POR CONSOLA
 * @param list
 * @param len
 * @return 0 si se logro, -1 si no
 */
int printPassenger(Passenger* list, int len)
{
	int i;
	int retorno = -1;

	if(list != NULL && len > 0)
	{
		printf("%4s  %-15s  %-15s  %-10s  %-8s  %-6s  %-8s\n"
			"------------------------------------------------------------------------------\n",
			"ID","NOMBRE","APELLIDO","PRECIO","TIPO","CODIGO","ESTADO");

		for(i = 0;i < len; i++)
		{
			if(list[i].isEmpty == OCUPADO)
			{
				imprimirUnPasajero(list[i]);
			}

			retorno = 0;
		}
		printf("-------------------------------------------------------------------------------\n");
	}



	return retorno;
}

/**
 * MODIFICA LOS DATOS DE UN PASAJERO
 * @param list
 * @param len
 * @return 0 si se modifico, -1 si no
 */
int modificarPasajero(Passenger* list, int len)
{
	int retorno = -1;
	int idIngresada;
	int indice;
	int opcion;

	if(list != NULL && len > 0)
	{

		idIngresada = utn_getNumero("Ingrese el numero de ID del pasajero que desea modificar: ",
									"ERROR ingrese un ID valido (desde 1000 hasta 3000)", 1000, 3000);

		indice = findPassengerById(list, len, idIngresada);



		if(indice != -1)
		{
			printf("Pasajero a modificar: \n");
			imprimirUnPasajero(list[indice]);
			do{
				opcion = utn_getNumero("---MENU DE MODIFICACION---\n"
							  "1)Modificar nombre.\n"
							  "2)Modificar apellido.\n"
							  "3)Modificar precio.\n"
							  "4)Modificar tipo de pasajero.\n"
							  "5)Modificar codigo de vuelo.\n"
							  "6)Volver.\n"
							  "ELIJA UNA OPCION...\n","ERROR Elija una opcion valida: ", 1,6);

				switch(opcion)
				{
				case 1:
					fflush(stdin);
					utn_getStringSoloLetras(list[indice].name,"Ingrese nuevo nombre: ",
								   "ERROR Ingrese un nombre valido (menos de 50 caracteres): ",1,51);
					retorno = 0;
					break;
				case 2:
					fflush(stdin);
					utn_getStringSoloLetras(list[indice].lastName,"Ingrese nuevo apellido: ",
									"ERROR Ingrese un apellido valido: ",1,51);
					retorno = 0;
					break;
				case 3:
					fflush(stdin);
					list[indice].price = utn_getFloat("Ingrese el nuevo precio del vuelo: ","ERROR Ingrese un precio valido (entre 1000 y 100000):",1000,100000);
					retorno = 0;
					break;
				case 4:
					fflush(stdin);
					list[indice].typePassenger= utn_getNumero("Ingrese el numero correspondiente al tipo de pasajero\n"
															  "1-Niño.\n2-Adulto.\n3-Jubilado.\nTipo de pasajero: ",
															  "ERROR Ingrese un tipo valido [1(niño), 2(adulto) o 3(jubilado)]: ",1, 3);
					retorno = 0;
					break;
				case 5:
					fflush(stdin);
					utn_getStringAlfaNumerico(list[indice].flycode,"Ingrese el codigo de vuelo: ", "ERROR El codigo debe tener 6 caracteres, letras y numeros: ",
															6,6);
					retorno = 0;
					break;
				}

			}while(opcion != 6);

			if(retorno == 0)
			{
				imprimirUnPasajero(list[indice]);
				printf("Pasajero modificado con exito...");
			}
		}
		else
		{
			printf("ERROR No existe pasajero con ese ID.\n");
		}
	}

	return retorno;
}

/**
 * ELIMINA UN PASAJERO DEL SISTEMA
 * @param list
 * @param len
 * @param id
 * @return 0 si se elimino, -1 si no
 */
int removePassenger(Passenger* list, int len, int id)
{
	int retorno = -1;
	int indice;
	char opcion;

	if(list != NULL && len > 0)
	{


		indice = findPassengerById(list, len, id);
		if(indice != -1)
		{
			printf("Pasajero a eliminar: \n");
			imprimirUnPasajero(list[indice]);
			opcion = utn_getRespuesta("Seguro que desea eliminar este pasajero? (s/n):",
					"ERROR ingrese 's' para si o 'n' para no: ");
			if(opcion=='s')
			{
				list[indice].isEmpty = LIBRE;
				printf("Pasajero eliminado exitosamente...");
				retorno = 0;
			}
		}
		else
		{
			printf("ERROR No existe ningun pasajero con ese ID");
		}


	}

	return retorno;
}

/**
 * ORDENA LOS PASAJEROS PREVIAMENTE INGRESADOS POR APELLIDO Y TIPO
 * @param list
 * @param len
 * @param order
 * @return
 */
int sortPassengers(Passenger* list, int len, int order)
{
	int retorno = -1;
	int i;
	int flagSwap;
	Passenger auxPassenger;
	int nuevoLimite;

	if(list != NULL && len > -1 && (order == 0 || order ==1))
		{
			nuevoLimite = len - 1;
			do{
				flagSwap = 0;
				for(i=0; i<nuevoLimite; i++)
				{
					switch(order)
					{
					case 0:
						if(strcmp(list[i].lastName,list[i+1].lastName)<0 || (strcmp(list[i].lastName,list[i+1].lastName)== 0
								&& list[i].typePassenger < list[i+1].typePassenger))
						{
							auxPassenger = list[i];
							list[i] = list[i+1];
							list[i+1] = auxPassenger;
							flagSwap = 1;
						}
						break;
					case 1:
						if(strcmp(list[i].lastName,list[i+1].lastName)>0 || (strcmp(list[i].lastName,list[i+1].lastName)== 0
								&& list[i].typePassenger > list[i+1].typePassenger))
						{
							auxPassenger = list[i];
							list[i] = list[i+1];
							list[i+1] = auxPassenger;
							flagSwap = 1;
						}
						break;

					}
				}
				nuevoLimite--;
			}while(flagSwap);
			retorno = 0;
		}




	return retorno;
}

/**
 * ORDENA LOS PASAJEROS INGRESADOS PREVIAMENTE POR CODIGO DE VUELO Y ESTADO DE VUELO
 * @param list
 * @param len
 * @param order
 * @return
 */
int sortPassengersByCode(Passenger* list, int len, int order)
{
	int retorno = -1;
	int i;
	int flagSwap;
	Passenger auxPassenger;
	int nuevoLimite;

	if(list != NULL && len > -1 && (order == 0 || order ==1))
	{
		nuevoLimite = len - 1;
		do{
			flagSwap = 0;
			for(i=0; i<nuevoLimite; i++)
			{
				switch(order)
				{
				case 0:
					if(strcmp(list[i].flycode,list[i+1].flycode)<0 || (strcmp(list[i].flycode,list[i+1].flycode)== 0
						&& list[i].statusFlight > list[i+1].statusFlight))
					{
						auxPassenger = list[i];
						list[i] = list[i+1];
						list[i+1] = auxPassenger;
						flagSwap = 1;
					}
					break;
				case 1:
					if(strcmp(list[i].flycode,list[i+1].flycode)>0 || (strcmp(list[i].flycode,list[i+1].flycode)== 0
						&& list[i].statusFlight < list[i+1].statusFlight))
					{
						auxPassenger = list[i];
						list[i] = list[i+1];
						list[i+1] = auxPassenger;
						flagSwap = 1;
					}
					break;
				}

			}
			nuevoLimite--;
		}while(flagSwap);
			retorno = 0;
		}




	return retorno;
}

/**
 * HACE LA SUMA DE TODOS LOS PRECIOS Y EL PROMEDIO
 * @param list
 * @param len
 * @param total
 * @param promedio
 * @return 0 si se realizaron los calculos, -1 si no
 */
int calculosPrecio(Passenger* list, int len, float* total, float* promedio)
{
	int retorno = -1;
	int i;
	float auxTotal = 0;
	int pasajeros = 0;

	if(list != NULL && len > 0 && total != NULL && promedio != NULL)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty == OCUPADO)
			{
				auxTotal = auxTotal + list[i].price;
				pasajeros++;
			}
		}

		*promedio = auxTotal / pasajeros;
		*total = auxTotal;

		retorno = 0;
	}




	return retorno;
}

/**
 * CALCULA LA CANTIDAD DE PASAJEROS QUE TIENEN UN PRECIO MAYOR AL PROMEDIO
 * @param list
 * @param len
 * @param promedio
 * @return cantidad de pasajeros que superan el precio promedio
 */
int cantidadDeMayores(Passenger* list, int len, float* promedio)
{
	int i;
	int cantidadPasajeros = 0;

	if(list != NULL && len > 0 && promedio != NULL)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty == OCUPADO && list[i].price > *promedio)
			{
				cantidadPasajeros++;
			}
		}
	}



	return cantidadPasajeros;
}

/**
 * CARGA FORZADAMENTE 10 PASAJEROS AL SISTEMA
 * @param list
 * @param len
 * @param id
 * @return 0 si se cargaron, -1 si no
 */
int hardcodePassengers(Passenger* list, int len, int* id)
{
	int retorno = -1;
	int i;
	int j = 0;

	Passenger hardcode[] =
	{
			{0,"Amanda","Rodriguez", 50300, "AR1260", 2, 1, OCUPADO},
			{0,"Lorenzo","Perez", 70000, "AR2309", 1, 1, OCUPADO},
			{0,"Maria Eugenia","Juarez",39000, "AR0054", 2, 0, OCUPADO},
			{0,"Pedro","Gonzalez", 23900, "AR1260", 3,1, OCUPADO},
			{0,"Victoria","Afione",27500, "AR2309", 2, 1, OCUPADO},
			{0,"Jorge","Martinez", 34250, "AR0054", 1, 0, OCUPADO},
			{0,"Sonia","Aubone", 21900, "AR2309", 2, 1, OCUPADO},
			{0,"Marcos","Fernandez", 27800, "AR1260", 3, 0, OCUPADO},
			{0,"Sol","Peretti",27500, "AR2309", 1, 0, OCUPADO},
			{0,"Rogelio","Lopez", 55480, "AR0054", 3, 1, OCUPADO}
	};

	if(list != NULL && len > 0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty == LIBRE)
			{
				list[i] = hardcode[j];
				list[i].id = *id;
				*id = *id + 1 ;
				j++;
			}
			if(j==10)
			{
				break;
			}

		}
		retorno = 0;
	}


	return retorno;
}
