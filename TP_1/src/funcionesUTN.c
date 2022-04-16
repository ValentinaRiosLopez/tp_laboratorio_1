
#include <stdio.h>
#include <stdlib.h>

/**
 *
 * @param mensaje
 * @param mensajeError
 * @param minimo
 * @param maximo
 * @return int
 * PIDE AL USUARIO UN NUMERO ENTERO
 */
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
/**
 *
 * @param mensaje
 * @param mensajeError
 * @param minimo
 * @param maximo
 * @return float
 * PIDE AL USUARIO UN NUMERO FLOTANTE
 */

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
/**
 *
 * @param numeroUno
 * @param numeroDos
 * @return float
 * SUMA DOS NUMEROS FLOTANTES Y DEVUELVE EL RESULTADO
 */
float utn_sumarFloat(float numeroUno, float numeroDos)
{
	float total;

	total = numeroUno + numeroDos;

	return total;
}
/**
 *
 * @param numeroUno
 * @param numeroDos
 * @return float
 * RESTA DOS NUMEROS FLOTANTES Y DEVUELVE EL RESULTADO
 */
float utn_restarFloat(float numeroUno, float numeroDos)
{
	float total;

	total = numeroUno - numeroDos;

	return total;
}
/**
 *
 * @param numeroUno
 * @param numeroDos
 * @return float
 * DIVIDE DOS NUMEROS FLOTANTES Y DEVUELVE EL RESULTADO
 */
float utn_dividirFloat(float numeroUno, float numeroDos)
{
	float resultado = 0;

	if(numeroUno != 0 && numeroDos != 0)
	{
		resultado = numeroUno / numeroDos;
	}

	return resultado;
}

/**
 *
 * @param numeroUno
 * @param numeroDos
 * @return float
 * MULTIPLICA DOS NUMEROS FLOTANTES Y DEVUELVE EL RESULTADO
 */

float utn_multiplicarFloat(float numeroUno, float numeroDos)
{
	float resultado;

	resultado = numeroUno * numeroDos;

	return resultado;
}

/**
 *
 * @param numero
 * @param porcentaje
 * @return float
 * REALIZA EL  PORCENTAJE DE UN NUMERO FLOTANTE Y DEVUELVE EL RESULTADO
 */
float utn_porcentajeFloat(float numero, int porcentaje)
{
	float resultado;

	resultado = (numero * porcentaje)/100;

	return resultado;
}
