/*. Crear una función llamada aplicarDescuento que reciba como parámetro el precio de un producto y devuelva el valor del producto
con un descuento del 5%. Realizar la llamada desde el main.
. Crear una función que se llame contarCaracteres que reciba una cadena de caracteres como primer parámetro y
un carácter como segundo y devuelva la cantidad de veces que ese carácter aparece en la cadena *

3. Dada la estructura Notebook(id, procesador, marca, precio) generar una función que permita ordenar un array
 de dicha estructura por marca. Ante igualdad de marca deberá ordenarse por precio. Hardcodear datos y mostrarlos desde el main. *
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define TAM 2
    typedef struct{
        int id;
        char procesador[20];
        char marca[20];
        int precio;
    }eNotebook;
float aplicarDescuento(float* pPrecio);
int contarCaracteres(char vect[], char caracterABuscar);
int ordenarPorMarcaYPrecio(eNotebook notebooks[], int tam);
int main()
{
    eNotebook notebooks[TAM] = {
        {0, "core", "intel", 1500},
        {1, "amd", "ryzen", 2000},
    };


    char cadena[5] = {'a', 'a', 'a', 'b'};
    float precio = 5;
    float totalConDescuento;
    int cantidadLetras;
    totalConDescuento = aplicarDescuento(&precio);
    cantidadLetras = contarCaracteres(cadena, 'a');
    ordenarPorMarcaYPrecio(notebooks, TAM);
    printf("%f", totalConDescuento);
    printf("\n%d", cantidadLetras);
    return 0;
}

float aplicarDescuento(float* pPrecio){
    float total;
    total = (*pPrecio)-((*pPrecio)*5)/100;
    return total;
}

int contarCaracteres(char vect[], char caracterABuscar)
{   int tam = strlen(vect);
    int contador = 0;
    for(int i=0; i<tam; i++){
         if(vect[i]== caracterABuscar){
            contador++;
         }
    }
    return contador;
}

int ordenarPorMarcaYPrecio(eNotebook notebooks[], int tam){
    eNotebook auxNotebook;
    for(int i=0; i<tam-1; i++)
    {
        for(int j=i+1; j<tam; j++)
        {
            if(strcmp(notebooks[i].marca, notebooks[j].marca) < 0 || (strcmp(notebooks[i].marca, notebooks[j].marca) == 0 && notebooks[i].precio < notebooks[j].precio))
             {
                auxNotebook = notebooks[i];
                notebooks[i] = notebooks[j];
                notebooks[j] = auxNotebook;
            }
        }
    }
}

