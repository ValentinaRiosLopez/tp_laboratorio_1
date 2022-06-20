/*
 * ArrayPassenger.h
 *
 *  Created on: 13 may. 2022
 *      Author: ogfri
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

typedef struct{
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flycode[10];
	int typePassenger;
	int statusFlight;
	int isEmpty;
}Passenger;




int initPassengers(Passenger* list, int len);
int addPassenger(Passenger* list, int len, int* id, char name[],char
				lastName[],float price,int typePassenger, char flycode[]);
int findPassengerById(Passenger* list, int len,int id);
int removePassenger(Passenger* list, int len, int id);
int printPassenger(Passenger* list, int len);
int buscarEspacio(Passenger* list, int len, int* lugar);
int modificarPasajero(Passenger* list, int len);
void imprimirUnPasajero(Passenger list);
int sortPassengers(Passenger* list, int len, int order);
int sortPassengersByCode(Passenger* list, int len, int order);
int calculosPrecio(Passenger* list, int len, float* total, float* promedio);
int cantidadDeMayores(Passenger* list, int len, float* promedio);
int hardcodePassengers(Passenger* list, int len, int* id);

#endif /* ARRAYPASSENGER_H_ */
