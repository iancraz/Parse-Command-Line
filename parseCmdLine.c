/*GUIA 1 EDA
Integrantes:
Martina Maspero
Nicolás Mestanza
Ian Diaz

Se compila de la siguiente manera gcc parseCmdLine.c prscmd.c -o parsecmd
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prscmd.h"

///////////////////////////////////////////////////////////////////////////////////////////////////
//BANCO DE PRUEBAS: EJECUTAR EL PROGRAMA CON LOS ARGUMENTOS 1)-key1 value1 -key2 value2 parameter//
//                                                          2)-key value1 parameter1 parameter2  //
//                                                          3)-  value1 parameter1 parameter2    //
//                                                          4)-key                               //
//															5)--key 							 //
//															6) parameter parameter -			 //
//															7)-key -key2 						 //
//															8)-key 		value 					 //
//															9) - value 							 //
///////////////////////////////////////////////////////////////////////////////////////////////////	

//DEBE SER LLAMADA PARA PROCESAR ESA OPCION O PARAMETRO CADA VEZ QUE PARSECMD ENCUENTRA UNA//

int parseCallback (char * key, char * value, void * userdata);


int main(int argc, char* argv[]) 
{    
    Estructura hola;
    int OptionsandParameters;
    
        if((OptionsandParameters=ParseCmdLine(argc, argv, parseCallback, &hola))>0) //chequea si hubo error 
        {
            printf("Cantidad de parametros y opciones: %d\n",OptionsandParameters);
        }
        else if (OptionsandParameters==-1)
        {
            printf("Error de forma\n");
        }     
    return (EXIT_SUCCESS);
}

int parseCallback (char *key, char *value, void *UserData)
{
    Estructura *temp =  UserData;
    int state= FALSE;
    if (key != NULL)                                        //CASO: ESTA PROCESANDO UNA OPCION//
    {
        temp->key= key;
        temp->value=value;
        printf("Opcion\nclave:");
        printf("%s\n",temp->key);
        printf("valor:");
        printf("%s\n",temp->value);
        state = TRUE;
    }
    else if (key == NULL)                                   //CASO: ESTA PROCESANDO UN PARAMETRO//
    {
        temp->parameter=value;
        printf("Parametro:%s\n",temp->parameter);
        state = TRUE;
    }
    return state;
}
