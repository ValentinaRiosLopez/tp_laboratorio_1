
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

	if( mensaje != NULL && mensajeError != NULL && minimo <= maximo)
	{
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%d", &numeroIngresado);

		while(numeroIngresado < minimo || numeroIngresado > maximo)
		{
			printf("%s", mensajeError);
			fflush(stdin);
			scanf("%d", &numeroIngresado);
		}
	}

	return numeroIngresado;
}


/**
 * PREGUNTA AL USUARIO POR UNA RESPUESTA DE SI O NO Y LA RETORNA
 * @param mensaje
 * @param mensajeError
 * @return caracter equivalente a la respuesta
 */
char utn_getRespuesta(char* mensaje, char* mensajeError)
{
	char respuesta;

	if(mensaje != NULL && mensajeError != NULL)
	{

		printf("%s", mensaje);
		fflush(stdin);
		scanf("%c", &respuesta);
		respuesta = tolower(respuesta);
		while(respuesta != 's' && respuesta != 'n')
		{
			printf("%s", mensajeError);
			fflush(stdin);
			scanf("%c", &respuesta);
			respuesta = tolower(respuesta);
		}
	}

	return respuesta;
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

	if(mensaje != NULL && mensajeError != NULL && minimo <= maximo)
	{

		printf("%s", mensaje);
		fflush(stdin);
		scanf("%f", &numeroIngresado);

		while(numeroIngresado < minimo || numeroIngresado > maximo)
		{
			printf("%s", mensajeError);
			fflush(stdin);
			scanf("%f", &numeroIngresado);
		}
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

int utn_getString(char* cadena, char* mensaje, char* mensajeError, int min, int max)
{
	int retorno = -1;
	char palabra[1500];

	if(cadena != NULL && mensaje != NULL && mensajeError != NULL && min <= max)
	{
		printf("%s", mensaje);
		fgets(palabra, sizeof(palabra), stdin);
		strcpy(cadena, palabra);
		utn_convertirUpper(cadena);

		while(strlen(palabra)<min || strlen(palabra)>max)
		{
			printf("%s", mensajeError);
			fgets(palabra, sizeof(palabra), stdin);
			strcpy(cadena, palabra);
			utn_convertirUpper(cadena);
		}
		retorno= 0;


	}

	return retorno;
}

/**
 * PIDE AL USUARIO UN STRING Y VALIDA QUE SOLO CONTENGA LETRAS Y ESPACIOS
 *
 * @param cadena
 * @param mensaje
 * @param mensajeError
 * @param min
 * @param max
 * @return 0
 */
int utn_getStringSoloLetras(char* cadena, char* mensaje, char* mensajeError, int min, int max)
{
	int retorno = -1;
	char palabra[100];
	if (cadena != NULL && mensaje != NULL) {
		retorno = 0;
		printf("%s", mensaje);
		fflush(stdin);
		gets(palabra);

		while( strlen(palabra) < min || strlen(palabra) > max || utn_validarCadena(palabra) == 1)
		{
			printf("%s", mensajeError);
			fflush(stdin);
			gets(palabra);
		}

		utn_convertirFirstUpper(palabra);

		strcpy(cadena, palabra);
	}
	return retorno;
}

/**
 * VALIDA QUE UN STRING SOLO TENGA LETRAS Y ESPACIOS
 * @param cadena
 * @return 1 si tiene exito
 */
int utn_validarCadena(char* cadena)
{
	int retorno= 0;
	for (int i = 0; i < strlen(cadena); i++) {
		if (!(isalpha(cadena[i])))
		{
			if(cadena[i] != ' ')
			{
			retorno = 1;
			break;
			}
		}

	}
	return retorno;

}

/**
 * CONVIERTE EL STRING COMPLETO A MAYUSCULAAS
 * @param cadena
 */
void utn_convertirUpper(char* cadena)
{
	int i=0;

	while(cadena[i]!= '\0')
	{
		cadena[i]= toupper(cadena[i]);
		i++;
	}
}
/**
 * CONVIERTE LA PRIMERA LETRA DE CADA PALABRA A MAYUSCULA Y EL RESTO A MINUSCULA
 * @param cadena
 */
void utn_convertirFirstUpper(char* cadena)
{
	int i = 1;

	cadena[0] = toupper(cadena[0]);

	while(cadena[i]!= '\0')
	{
		cadena[i]= tolower(cadena[i]);
		if(cadena[i]==' ')
		{
			cadena[i+1]= toupper(cadena[i+1]);
			i++;
		}
		i++;
	}


}


/**
 * PREGUNTA AL USUARIO EL ORDEN EN EL QUE QUIERE QUE SE MUESTREN LOS DATOS
 * @return 1 si es ascensdente y 0 si es descendente
 */
int utn_getOrder()
{
	int retorno;
	printf("Mostrar en orden ascendente o descendente? (a/d): ");
	fflush(stdin);
	char opcion = getchar();
	opcion = tolower(opcion);
	while (opcion != 'a' && opcion != 'd') {
		printf("Opcion incorrecta, ingrese nuevamente (a/d): ");
		fflush(stdin);
		opcion = getchar();
		opcion = tolower(opcion);
	}
	if (opcion == 'a') {
		retorno = 1;
	} else {
		retorno = 0;
	}
	return retorno;
}

/**
 * FUNCION GRAFICA PARA ORDENAR EL MENU
 */

void separadorMenu()
{
	printf("\n*~~~~~~~~~~~~~~~~~~~~~~*\n");
}
/**
 * FUNCION GRAFICA QUE HACE ESPACIO EN EL MENU
 */
void limpiarConsola()
{
	printf("\n\n\n\n");
}
