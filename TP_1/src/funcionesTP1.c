

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "funcionesUTN.h"
/**
 *
 * @param precio
 * @param kilometros
 * @param debito
 * @param credito
 * @param bitcoin
 * @param unidad
 * @return int
 * CALCULA LOS PRECIOS DE UN VUELO CON LOS DISTINTOS MEDIOS DE PAGO
 *
 */
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

/**
 *
 * @param mensaje
 * @param precio
 * @param debito
 * @param credito
 * @param bitcoin
 * @param unidad
 * @return int
 * MUESTRA LOS RESULTADOS DE LOS CALCULOS DE UNA AEROLINEA POR CONSOLA
 */

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
/**
 * @return void
 * FUNCION GRAFICA QUE MUESTRA UN SEPARADOR POR CONSOLA
 */
void tp1_separadorMenu()
{
	printf("\n*~~~~~~~~~~~~~~~~~~~~~~*\n");
}
/**
 * @return void
 * FUNCION GRAFICA QUE HACE ESPACIO EN LA CONSOLA
 */
void tp1_limpiarConsola()
{
	printf("\n\n\n\n");
}
