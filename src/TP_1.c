/*
 ============================================================================
 Name        : TP.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "funcionesUTN.h"
#include "funcionesTP1.h"


void ejecutarMenu();

int main(void)
{
	setbuf(stdout,NULL);
	ejecutarMenu();
}

void ejecutarMenu(){
	int opcion;
	int opcionSubMenu;
	//Banderas
	int precioVuelos = 0;
	int calculoRealizado = 0;
	//Ingreso de datos
	float kilometros = 0;
	float precioVueloA = 0;
	float precioVueloL = 0;

	//resultados Aerolineas
	float totalDebitoA;
	float totalCreditoA;
	float totalBitcoinA;
	float precioPorKmA;
	//resultados Latam
	float totalDebitoL;
	float totalCreditoL;
	float totalBitcoinL;
	float precioPorKmL;
	float diferenciaPrecio;

	do{
		tp1_limpiarConsola();
		tp1_separadorMenu();
		opcion = utn_getNumero("\n==========MENU==========\n"
						  "1)Ingresar Datos.\n"
						  "2)Calcular todos los costos.\n"
						  "3)Informar resultados.\n"
						  "4)Carga forzada de datos.\n"
						  "5)Salir.\n"
						  "ELIJA UNA OPCION...\n","ERROR ELIJA UNA OPCION ENTRE 1 Y 5...",1,5);
		tp1_separadorMenu();

		switch(opcion)
		{
		case 1:
			do{
				if(precioVuelos==0)
				{
					printf("\n======MENU INGRESO======\n"
						  "1)Ingresar kilometros.\n"
						  "2)Ingresar precios de vuelos.(Aerolineas = x Latam = y)\n"
						  "3)Volver a menu principal.\n");
					opcionSubMenu = utn_getNumero("ELIJA UNA OPCION...","ERROR ELIJA UNA OPCION ENTRE 1 Y 3...",1,3);
				}
				else
				{
					printf("\n======MENU INGRESO======\n"
						  "1)Ingresar kilometros.\n"
						  "2)Ingresar precios de vuelos.(Aerolineas = %.2f Latam = %.2f)\n"
						  "3)Volver al menu principal.\n",precioVueloA, precioVueloL);
					opcionSubMenu = utn_getNumero("ELIJA UNA OPCION...","ERROR ELIJA UNA OPCION ENTRE 1 Y 3...",1,3);
				}
				;
				switch(opcionSubMenu)
				{
				case 1:
					kilometros = utn_getFloat("\nIngrese la cantidad de kilometros: ",
										"\nERROR Ingrese una cantidad valida (entre 1 y 20000): ",1,20000);
					printf("Kilometros: %.2f", kilometros);
					break;
				case 2:
					precioVueloA = utn_getFloat("Ingrese el precio de Aerolineas:","ERROR Ingrese un precio valido (entre 1000 y 999999):", 1000,999999);
					precioVueloL = utn_getFloat("Ingrese el precio de Latam:","ERROR Ingrese un precio valido (entre 1000 y 999999):", 1000,999999);
					precioVuelos=1;
					break;
				}
			}while(opcionSubMenu != 3);

			system("pause");
			break;
		case 2:
			if(kilometros!=0 && precioVuelos!=0)
			{
				tp1_calcularResultados(precioVueloA, kilometros, &totalDebitoA, &totalCreditoA, &totalBitcoinA, &precioPorKmA);
				tp1_calcularResultados(precioVueloL, kilometros, &totalDebitoL, &totalCreditoL, &totalBitcoinL, &precioPorKmL);

				if(precioVueloA > precioVueloL)
				{
					diferenciaPrecio = utn_restarFloat(precioVueloA, precioVueloL);
				}
				else
				{
					if(precioVueloA < precioVueloL)
					{
						diferenciaPrecio = utn_restarFloat(precioVueloL, precioVueloA);
					}
				}
				calculoRealizado =1;

				printf("\nCalculos realizados correctamente.\n");
			}
			else
			{
				printf("\nERROR Asegurese de haber ingresado todos los datos correctamente.\n");
			}

			system("pause");
			break;
		case 3:
			if(calculoRealizado ==1)
			{
				printf("Kilometros Ingresados: %.2f.\n\n", kilometros);
				tp1_mostrarResultados("Aerolineas",precioVueloA, &totalDebitoA, &totalCreditoA, &totalBitcoinA, &precioPorKmA);
				tp1_mostrarResultados("Latam",precioVueloL, &totalDebitoL, &totalCreditoL, &totalBitcoinL, &precioPorKmL);
				printf("La diferencia de precio es: $%.2f.\n\n", diferenciaPrecio);
			}
			else
			{
				printf("ERROR Todavia falta realizar los calculos.\n");
			}

			system("pause");
			break;
		case 4:

			kilometros = 7090;
			precioVueloA = 162965;
			precioVueloL = 159339;

			precioVuelos =1;

			printf("Carga forzada realizada.\n");

			system("pause");
			break;

		}

	}while(opcion!=5);

	if(opcion==5){
		printf("\n====FIN DEL PROGRAMA====\n");
	}


}

