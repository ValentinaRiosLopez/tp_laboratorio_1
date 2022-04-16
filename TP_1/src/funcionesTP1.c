

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "funcionesUTN.h"

int tp1_calcularResultados(float precio, float kilometros, float* debito, float* credito, float* bitcoin, float* unidad)
{
	int retorno = 0;
	float descuento;
	float interes;


	descuento = utn_porcentajeFloat(precio, 10);
	interes = utn_porcentajeFloat(precio, 25);

	*debito = utn_restarFloat(precio, descuento);
	*credito = utn_sumarFloat(precio, interes);
	*bitcoin = precio / 4606954.55;
	*unidad = precio / kilometros;

	retorno = 1;



	return retorno;
}

int tp1_mostrarResultados(char* mensaje, float precio, float* debito, float* credito, float* bitcoin, float* unidad)
{
	int retorno = 0;

	printf("Precio de %s: $%.2f.\n",mensaje, precio);
	printf("a)Precio con tarjeta de debito: $%.2f.\n", *debito);
	printf("b)Precio con tarjeta de credito: $%.2f.\n", *credito);
	printf("c)Precio pagando en bitcoins: $%.4f.\n", *bitcoin);
	printf("d)Precio por kilometro: $%.2f.\n\n", *unidad);
	retorno = 1;

	return retorno;

}

void tp1_separadorMenu()
{
	printf("\n*~~~~~~~~~~~~~~~~~~~~~~*\n");
}

void tp1_limpiarConsola()
{
	printf("\n\n\n\n");
}
