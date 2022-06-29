#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionesUTN.h"
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{

	setbuf(stdout,NULL);
    int option = 0;
    int contadorPasajeros = 0;
    int id;
    int flagArchivos=0;
    int flagGuardado = 0;

    LinkedList* listaPasajeros = ll_newLinkedList();
    do{
    	limpiarConsola();
		separadorMenu();
		option = utn_getNumero("\n==========MENU==========\n"
				"1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).\n"
				"2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).\n"
				"3. Alta de pasajero.\n"
				"4. Modificar datos de pasajero.\n"
				"5. Baja de pasajero.\n"
				"6. Listar pasajeros.\n"
				"7. Ordenar pasajeros.\n"
				"8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).\n"
				"9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).\n"
				"10. Salir.\n "
				"ELIJA UNA OPCION...\n","ERROR ELIJA UNA OPCION ENTRE 1 Y 10...",1,10);
		separadorMenu();
        switch(option)
        {
            case 1:
            	if(flagArchivos == 0)
            	{
            		if(!controller_loadFromText("data.csv",listaPasajeros))
					{
						if(contadorPasajeros != 0)
						{
							 controller_checkId("data.csv",listaPasajeros,&id,contadorPasajeros);


						}
						flagArchivos=1;
					}
					else
					{
						printf("No se pudo realizar la operacion...\n");
					}
            	}
            	else
            	{
            		printf("ERROR Ya hay un archivo cargado...\n");
            	}

                break;
            case 2:

            	if(flagArchivos == 0)
            	{
            		if(!controller_loadFromBinary("data.bin",listaPasajeros))
					{
            			if(contadorPasajeros != 0)
						{
							 controller_checkId("data.csv",listaPasajeros,&id,contadorPasajeros);
							 controller_checkId("data.bin",listaPasajeros,&id,contadorPasajeros);
						}




						flagArchivos =1;
					}
					else
					{
						printf("No se pudo realizar la operacion...\n");
					}
            	}
				else
				{
					printf("ERROR Ya hay un archivo cargado...\n");
				}
				break;
            case 3:
            	if(!controller_addPassenger(listaPasajeros))
            	{
            		contadorPasajeros++;
            		printf("Pasajero agregado correctamente...\n");
            	}
            	else
            	{
            		printf("No se pudo realizar la operacion...\n");
            	}
            	break;
            case 4:
            	if(ll_len(listaPasajeros) != 0)
            	{
            		if(!controller_editPassenger(listaPasajeros))
            		{
            			printf("Se modifico el pasajero correctamente...\n");
            		}
            		else
            		{
            			printf("No se pudo modificar...\n");
            		}
            	}
            	else
            	{
            		printf("No se pudo realizar la operacion...\n");
            	}
            	break;
            case 5:
            	if(ll_len(listaPasajeros) != 0)
            	{
            		if(!controller_removePassenger(listaPasajeros))
            		{
            			printf("Baja exitosa...\n");
            			contadorPasajeros--;
            		}
            		else
            		{
            			printf("No se dio de baja...\n");
            		}
            	}
            	else
				{
					printf("No se pudo realizar la operacion...\n");
				}
            	break;
            case 6:
            	if(ll_len(listaPasajeros) != 0)
            	{
            		if(!controller_ListPassenger(listaPasajeros))
					{
						printf("FIN LISTADO...\n");
					}
            	}
            	else
            	{
            		printf("No se pudo realizar la operacion...\n");
            	}
            	break;
            case 7:
            	if(ll_len(listaPasajeros) != 0)
            	{
            		if(!controller_sortPassenger(listaPasajeros))
					{
						printf("Pasajeros ordenados correctamente...\n");
					}
            	}
            	else
				{
					printf("No se pudo realizar la operacion...\n");
				}

            	break;
            case 8:
            	if(ll_len(listaPasajeros) != 0)
            	{
            		if(flagArchivos == 0)
            		{
            			controller_checkId("data.csv",listaPasajeros,&id,contadorPasajeros);
            			controller_checkId("data.bin",listaPasajeros,&id,contadorPasajeros);
            		}
					 if(!controller_saveAsText("data.csv",listaPasajeros))
					 {

						 flagGuardado = 1;
					 }
					 else
					 {
						 printf("No se pudo guardar...\n");
					 }
            	}
            	else
				{
					printf("No se pudo realizar la operacion...\n");
				}

            	break;
            case 9:


            	if(ll_len(listaPasajeros) != 0)
				{
            		controller_checkId("data.csv",listaPasajeros,&id,contadorPasajeros);

            		 if(!controller_saveAsBinary("data.bin",listaPasajeros))
					 {

						 flagGuardado = 1;
						 printf("Se pudo guardar con exito...\n");
					 }
					 else
					 {
						 printf("No se pudo guardar...\n");
					 }
				}
				else
				{
					printf("No se pudo realizar la operacion...\n");
				}
            	break;
            default:
                       	if(flagGuardado == 0)
                       	{
                       		printf("\nERROR Debe guardar los cambios antes de salir.\n");
                       	}
                       	else
                       	{
                       		if(option==10)
							{
									printf("\n====FIN DEL PROGRAMA====\n");
							}
                       	}

        }
    }while(option != 10 ||flagGuardado == 0);


    return 0;
}

