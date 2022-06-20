
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionesUTN.h"
#include "ArrayPassenger.h"
#define TAM 100

void ejecutarMenu();


int main(void) {
	setbuf(stdout, NULL);
	ejecutarMenu();


}


void ejecutarMenu(){
	int opcion;
	int opcionMostrar;
	int orden;
	int flag = 0;
	int contadorId = 1000;
	float promedioPrecios;
	float totalPrecios;
	int pasajerosMasPromedio;
	int id;
	Passenger auxiliar[TAM];

	initPassengers(auxiliar, TAM);

	do{
		limpiarConsola();
		separadorMenu();
		opcion = utn_getNumero("\n==========MENU==========\n"
						  "1)ALTAS PASAJEROS.\n"
						  "2)MODIFICAR PASAJERO.\n"
						  "3)BAJA PASAJERO.\n"
						  "4)INFORMAR.\n"
						  "5)CARGA FORZADA.\n"
						  "6)Salir.\n"
						  "ELIJA UNA OPCION...\n","ERROR ELIJA UNA OPCION ENTRE 1 Y 6...",1,6);
		separadorMenu();

		switch(opcion)
		{
		case 1:

			if(addPassenger(auxiliar, TAM, &contadorId, auxiliar->name, auxiliar->lastName, auxiliar->price, auxiliar->typePassenger, auxiliar->flycode)==0)
			{
				flag = 1;

				printf("Pasajero agregado correctamente...\n");
				system("pause");
			}
			else
			{
				printf("No se pudo agregar pasajero...\n");
				system("pause");
			}

			break;
		case 2:
			if(flag != 0)
			{
				modificarPasajero(auxiliar, TAM);
				system("pause");
			}
			else
			{
				printf("ERROR Para realizar esta operacion primero tiene que ingesar pasajeros...\n");
				system("pause");
			}

			break;
		case 3:
			if(flag != 0)
			{
				id = utn_getNumero("Ingrese el numero de ID del pasajero que desea eliminar: ",
													"ERROR ingrese un ID valido (desde 1000 hasta 3000)", 1000, 3000);

				removePassenger(auxiliar, TAM, id);
				system("pause");
			}
			else
			{
				printf("ERROR Para realizar esta operacion primero tiene que ingesar pasajeros...\n");
				system("pause");
			}

			break;
		case 4:
			if(flag != 0)
			{


				do{
					opcionMostrar = utn_getNumero("\n======MENU INFORMES======\n"
											  "1)Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero.\n"
											  "2)Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio.\n"
											  "3)Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’.\n"
											  "4)Volver.\n"
											  "Ingrese una opcion...\n", "ERROR Elija una opcion entre 1 y 4\n", 1, 4) ;

					switch(opcionMostrar)
					{
					case 1:
						orden = utn_getOrder();
						sortPassengers(auxiliar, TAM, orden);
						printPassenger(auxiliar, TAM);
						system("pause");
						break;
					case 2:
						calculosPrecio(auxiliar, TAM, &totalPrecios, &promedioPrecios);
						pasajerosMasPromedio = cantidadDeMayores(auxiliar, TAM, &promedioPrecios);
						printf("Total de los precios: %.2f\n", totalPrecios);
						printf("Promedio de precio: %.2f\n", promedioPrecios);
						printf("Cantidad de pasajeros que superan el promedio: %d\n", pasajerosMasPromedio);
						system("pause");
						break;
					case 3:
						orden = utn_getOrder();
						sortPassengersByCode(auxiliar, TAM, orden);
						printPassenger(auxiliar, TAM);
						system("pause");
						break;
					}

				}while(opcionMostrar != 4);
			}
			else
			{
				printf("ERROR Para realizar esta operacion primero tiene que ingesar pasajeros...\n");
				system("pause");
			}


			break;
		case 5:
			if(hardcodePassengers(auxiliar, TAM, &contadorId)==0)
			{
				printPassenger(auxiliar, TAM);
				system("pause");
			}
			else
			{
				printf("ERROR No se pudo realizar la carga forzada.\n");
				system("pause");
			}
			break;


		}

	}while(opcion!=6);

	if(opcion==5){
		printf("\n====FIN DEL PROGRAMA====\n");
	}

}


