#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "funcionesUTN.h"
#include "Passenger.h"


Passenger* Passenger_new()
{
	Passenger* newPassenger = NULL;

	newPassenger = (Passenger*)malloc(sizeof(Passenger));

	return newPassenger;
}

Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char* precioStr,char* codigoVueloStr,char* tipoPasajeroStr,char* estadoDeVueloStr)
{
	Passenger* newPassenger = Passenger_new();
	int tipo;
	int estado;
	if(newPassenger != NULL)
	{

		Passenger_setId(newPassenger,atoi(idStr));
		Passenger_setNombre(newPassenger,nombreStr);
		Passenger_setApellido(newPassenger,apellidoStr);
		Passenger_setPrecio(newPassenger,atof(precioStr));
		Passenger_setCodigoVuelo(newPassenger,codigoVueloStr);
		if(!strcmp(tipoPasajeroStr,"FirstClass"))
		{
			tipo = 1;
		}
		else
		{
			if(!strcmp(tipoPasajeroStr,"ExecutiveClass"))
			{
				tipo = 2;
			}
			else
			{
				tipo = 3;
			}
		}
		Passenger_setTipoPasajero(newPassenger,tipo);

		if(!strcmp(estadoDeVueloStr ,"En Horario"))
		{
			estado = 1;
		}
		else
		{
			if(!strcmp(estadoDeVueloStr,"En Vuelo"))
			{
				estado = 2;
			}
			else
			{
				if(!strcmp(estadoDeVueloStr,"Aterrizado"))
				{
					estado = 3;
				}
				else
				{
					estado = 4;
				}
			}
		}
		Passenger_setEstadoDeVuelo(newPassenger,estado);

	}

	return newPassenger;
}

void Passenger_delete(Passenger* this)
{
	if(this != NULL)
	{
		free(this);
	}

}


int Passenger_setId(Passenger* this,int id)
{
	int retorno = -1;

	if(this != NULL && id > 0)
	{
		retorno = 0;
		this->id = id;
	}

	return retorno;
}

int Passenger_getId(Passenger* this,int* id)
{
	int retorno = -1;

		if(this != NULL && id != NULL)
		{
			retorno = 0;
			*id = this->id;
		}

		return retorno;
}



int Passenger_setNombre(Passenger* this,char* nombre)
{
	int retorno = -1;

	if(this != NULL)
	{
		retorno = 0;
		strcpy(this->nombre,nombre);

	}

	return retorno;
}
int Passenger_getNombre(Passenger* this,char* nombre)
{
	int retorno = -1;

	if(this != NULL)
	{
		retorno = 0;
		strcpy(nombre,this->nombre);

	}

	return retorno;
}




int Passenger_setApellido(Passenger* this,char* apellido)
{

	int retorno = -1;

	if(this != NULL)
	{
		retorno = 0;
		strcpy(this->apellido,apellido);

	}

	return retorno;
}

int Passenger_getApellido(Passenger* this,char* apellido)
{
	int retorno = -1;

	if(this != NULL)
	{
		retorno = 0;
		strcpy(apellido,this->apellido);

	}

	return retorno;
}




int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno = -1;

	if(this != NULL)
	{
		retorno = 0;
		strcpy(this->codigoVuelo,codigoVuelo);

	}

	return retorno;
}

int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno = -1;

	if(this != NULL)
	{
		retorno = 0;
		strcpy(codigoVuelo,this->codigoVuelo);

	}

	return retorno;
}



int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero)
{
	int retorno = -1;

	if(this != NULL && tipoPasajero > 0)
	{
		retorno = 0;
		this->tipoPasajero = tipoPasajero;
	}

		return retorno;
}
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero)
{
	int retorno = -1;

	if(this != NULL && tipoPasajero != NULL)
	{
		retorno = 0;
		*tipoPasajero = this->tipoPasajero;
	}

		return retorno;
}




int Passenger_setPrecio(Passenger* this,float precio)
{
	int retorno = -1;

	if(this != NULL && precio > 0)
	{
		retorno = 0;
		this->precio = precio;
	}

		return retorno;
}
int Passenger_getPrecio(Passenger* this,float* precio)
{
	int retorno = -1;

	if(this != NULL && precio != NULL)
	{
		retorno = 0;
		*precio = this->precio;
	}

		return retorno;
}

int Passenger_setEstadoDeVuelo(Passenger* this, int estadoDeVuelo)
{
	int retorno = -1;

	if(this != NULL)
	{
		retorno = 0;
		this->estadoDeVuelo = estadoDeVuelo;

	}

	return retorno;
}


int Passenger_getEstadoDeVuelo(Passenger* this, int* estadoDeVuelo)
{
	int retorno = -1;

	if(this != NULL && estadoDeVuelo != NULL)
	{
		retorno = 0;
		*estadoDeVuelo = this->estadoDeVuelo;
	}

	return retorno;
}



int Passenger_lastId(LinkedList* this)
{
	int id;
	static int maxId;
	int lastId = 0;
	int i;
	int tam;
	Passenger* auxPassenger;

	if(this != NULL)
	{
		tam= ll_len(this);
		for(i=0;i<tam;i++)
		{
			auxPassenger = (Passenger*)ll_get(this,i);
			Passenger_getId(auxPassenger,&id);

			if(id > lastId)
			{
				lastId = id;
			}


		}

		if(lastId>maxId)
		{
			maxId = lastId+1;
		}
		else
		{
			maxId++;
		}


	}

	return maxId;
}


void Passenger_listOne(Passenger* this)
{
	char tipo[20];
	char estado[15];

	if(this != NULL)
	{
		switch(this->tipoPasajero)
		{
		case 1:
			strcpy(tipo,"FirstClass");
			break;
		case 2:
			strcpy(tipo,"ExecutiveClass");
			break;
		case 3:
			strcpy(tipo,"EconomyClass");
			break;
		}



		switch(this->estadoDeVuelo)
		{
		case 1:
			strcpy(estado,"En Horario");
			break;
		case 2:
			strcpy(estado,"En Vuelo");
			break;
		case 3:
			strcpy(estado,"Aterrizado");
			break;
		case 4:
			strcpy(estado,"Demorado");
			break;
		}
		printf("%-6d  %-25s  %-25s  %-10.2f  %-10s  %-20s  %-15s\n",this->id,this->nombre,this->apellido,this->precio,this->codigoVuelo,tipo,estado);
	}

}

int Passenger_findId(LinkedList* this, int length,int id)
{
	int i;
	int indice = -1;
	Passenger* auxPasajero;

	if(this != NULL && length > 0 && id > 0)
	{
		for(i=0;i<length;i++)
		{
			auxPasajero = ll_get(this,i);

			if(auxPasajero->id==id)
			{
				indice = i;
			}
		}
	}

	return indice;
}

int Passenger_ordenarId(void* paramUno, void* paramDos)
{
	int retorno = 0;
	int auxIdUno;
	int auxIdDos;

	if(paramUno != NULL && paramDos != NULL)
	{
		Passenger_getId(paramUno,&auxIdUno);
		Passenger_getId(paramDos,&auxIdDos);

		if(auxIdUno > auxIdDos)
		{
			retorno = 1;
		}
		else
		{
			retorno = -1;
		}

	}


	return retorno;

}

int Passenger_ordenarNombreyApellido(void* paramUno, void* paramDos)
{
	int retorno = 0;
	char nombreUno[50];
	char nombreDos[50];
	char apellidoUno[50];
	char apellidoDos[50];

	if(paramUno != NULL && paramDos != NULL)
	{
		Passenger_getNombre(paramUno,nombreUno);
		Passenger_getApellido(paramUno,apellidoUno);
		Passenger_getNombre(paramDos,nombreDos);
		Passenger_getApellido(paramDos,apellidoDos);

		if(strcmp(nombreUno,nombreDos)>0 || (strcmp(nombreUno,nombreDos)==0 && strcmp(apellidoUno,apellidoDos)==0))
		{
			retorno = 1;
		}
		else
		{
			retorno = -1;
		}

	}


	return retorno;

}

int Passenger_ordenarPrecio(void* paramUno, void* paramDos)
{
	int retorno = 0;
	float auxPrecioUno;
	float auxPrecioDos;

	if(paramUno != NULL && paramDos != NULL)
	{
		Passenger_getPrecio(paramUno,&auxPrecioUno);
		Passenger_getPrecio(paramDos,&auxPrecioDos);

		if(auxPrecioUno > auxPrecioDos)
		{
			retorno = 1;
		}
		else
		{
			retorno = -1;
		}

	}

	return retorno;
}

int Passenger_ordenarCodigoVuelo(void* paramUno, void* paramDos)
{
	int retorno = 0;
	char codigoUno[10];
	char codigoDos[10];


	if(paramUno != NULL && paramDos != NULL)
	{
		Passenger_getCodigoVuelo(paramUno,codigoUno);
		Passenger_getCodigoVuelo(paramDos,codigoDos);

		if(strcmp(codigoUno,codigoDos)>0)
		{
			retorno = 1;
		}
		else
		{
			retorno = -1;
		}

	}


	return retorno;
}
