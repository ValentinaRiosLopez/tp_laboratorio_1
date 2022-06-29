/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char codigoVuelo[8];
	int tipoPasajero;
	int estadoDeVuelo;

}Passenger;

Passenger* Passenger_new();
Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char* precioStr,char* codigoVuelo,char* tipoPasajeroStr,char*estadoDeVueloStr);
void Passenger_delete(Passenger* this);

int Passenger_setId(Passenger* this,int id);
int Passenger_getId(Passenger* this,int* id);

int Passenger_setNombre(Passenger* this,char* nombre);
int Passenger_getNombre(Passenger* this,char* nombre);

int Passenger_setApellido(Passenger* this,char* apellido);
int Passenger_getApellido(Passenger* this,char* apellido);

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero);

int Passenger_setPrecio(Passenger* this,float precio);
int Passenger_getPrecio(Passenger* this,float* precio);

int Passenger_setEstadoDeVuelo(Passenger* this, int estadoDeVuelo);
int Passenger_getEstadoDeVuelo(Passenger* this, int* estadoDeVuelo);


int Passenger_lastId(LinkedList* this);
void Passenger_listOne(Passenger* this);
int Passenger_findId(LinkedList* this, int length, int id);
int Passenger_ordenarId(void* paramUno, void* paramDos);
int Passenger_ordenarNombreyApellido(void* paramUno, void* paramDos);
int Passenger_ordenarPrecio(void* paramUno, void* paramDos);
int Passenger_ordenarCodigoVuelo(void* paramUno, void* paramDos);
#endif /* PASSENGER_H_ */
