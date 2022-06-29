#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	Passenger* auxPassenger = NULL;
	int param;
	char buffer[7][50];


	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3],buffer[4],buffer[5],buffer[6]);

		do{
			param = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3],buffer[4],buffer[5],buffer[6]);
			if(param<7)
			{
				break;
			}

			 auxPassenger = Passenger_newParametros(buffer[0],buffer[1],buffer[2],buffer[3],buffer[4],buffer[5],buffer[6]);
			 if(auxPassenger != NULL)
			 {
				 ll_add(pArrayListPassenger, auxPassenger);
				 retorno = 0;
			 }

		}while(!feof(pFile));
	}

    return retorno;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	Passenger* auxPassenger;
	int param;


	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		while(!feof(pFile))
		{
			auxPassenger = Passenger_new();


			if(auxPassenger != NULL)
			{
				param = fread(auxPassenger,sizeof(Passenger),1,pFile);
				if(param == 1)
				{
					ll_add(pArrayListPassenger, auxPassenger);
				}



			}
			else
			{
				Passenger_delete(auxPassenger);
			}
		}
		retorno = 0;
	}

    return retorno;
}
