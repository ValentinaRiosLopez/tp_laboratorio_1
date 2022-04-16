/*
 * funcionesUTN.c
 *
 *  Created on: 15 abr. 2022
 *      Author: ogfri
 */
#include <stdio.h>
#include <stdlib.h>

int utn_getNumero(char* mensaje, char* mensajeError, int minimo, int maximo)
{
	int numeroIngresado;

	printf("%s", mensaje);
	fflush(stdin);
	scanf("%d", &numeroIngresado);

	while(numeroIngresado < minimo || numeroIngresado > maximo)
	{
		printf("%s", mensajeError);
		fflush(stdin);
		scanf("%d", &numeroIngresado);
	}

	return numeroIngresado;
}


float utn_getFloat(char* mensaje, char* mensajeError, int minimo, int maximo)
{
	float numeroIngresado;

	printf("%s", mensaje);
	fflush(stdin);
	scanf("%f", &numeroIngresado);

	while(numeroIngresado < minimo || numeroIngresado > maximo)
	{
		printf("%s", mensajeError);
		fflush(stdin);
		scanf("%f", &numeroIngresado);
	}

	return numeroIngresado;
}

float utn_sumarFloat(float numeroUno, float numeroDos)
{
	float total;

	total = numeroUno + numeroDos;

	return total;
}

float utn_restarFloat(float numeroUno, float numeroDos)
{
	float total;

	total = numeroUno - numeroDos;

	return total;
}

float utn_dividirFloat(float numeroUno, float numeroDos)
{
	float resultado = 0;

	if(numeroUno != 0 && numeroDos != 0)
	{
		resultado = numeroUno / numeroDos;
	}

	return resultado;
}

float utn_multiplicarFloat(float numeroUno, float numeroDos)
{
	float resultado;

	resultado = numeroUno * numeroDos;

	return resultado;
}

float utn_porcentajeFloat(float numero, int porcentaje)
{
	float resultado;

	resultado = (numero * porcentaje)/100;

	return resultado;
}
