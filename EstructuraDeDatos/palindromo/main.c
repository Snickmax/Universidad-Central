// Victor Ibarra - Brando Imana
// Laboratorio Sistemas Operativos
// 04/04/2023 11:24
// Link: https://onlinegdb.com/HzteACy-5

#include <stdio.h>

#define car 9 //numero de caracteres de la palabra 

char palindromo[car], palabra[car] = "reconocer"; // Arrays de la palabra
int y = 0; // contador que recorre array de 0 hasta el final

int x = 0;// llave que define si es palindromo o no

int main()
{
    for(int i = car-1; i >= 0; i--) // recorre el array desde el final al principio
    {
        palindromo[y] = palabra[i]; // guardo la palabra la palabra al reves
        
        if(palindromo[y] != palabra[y]) // condicion que compara caracteres para verificar si es palindromo o no
        {
            x = 1; // llave cambia porque no es palindromo
        }
        
        y++; // sumador de la variable que recorre el array desde el principio al final
    }
    
    //imprimimos por pantalla
    if(x == 0) // si es palindromo
    {
        printf("Es palindromo\n");
        printf("Original: %s\n",palabra);
        printf("Palindromo: %s\n",palindromo);
    }
    else // no es palindromo
    {
        printf("No es palindromo\n");
        printf("Original: %s\n",palabra);
        printf("Palabra al reves: %s\n",palindromo);
    }
}