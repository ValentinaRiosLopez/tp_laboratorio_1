

#ifndef FUNCIONESUTN_H_
#define FUNCIONESUTN_H_

int utn_getNumero(char* mensaje, char* mensajeError, int minimo, int maximo);
char utn_getChar(char* mensaje, char* mensajeError);
float utn_getFloat(char* mensaje, char* mensajeError, int minimo, int maximo);
float utn_sumarFloat(float numeroUno, float numeroDos);
float utn_restarFloat(float numeroUno, float numeroDos);
float utn_dividirFloat(float numeroUno, float numeroDos);
float utn_multiplicarFloat(float numeroUno, float numeroDos);
float utn_porcentajeFloat(float numero, int porcentaje);

#endif /* FUNCIONESUTN_H_ */
