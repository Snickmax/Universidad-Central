// Víctor Ibarra
// Javier Valdez 
#include <stdio.h>
#define n 5
int matrz1 [n][n], matrz2 [n][n], matrzR [n][n]; //matriz 1 y 2
int numero; // Aquí alojaremos el valor leído
int contador = 1; // contador de filas

int imprimirMR(){
    for(int i = 0; i < n; i++) // recorrer fila matriz 2
    {
        for(int j = 0 ; j < n; j++) // recorrer columna matriz 2
        {
            printf("%i ",matrzR[i][j]); // print de los elementos de matriz 2
        }
        printf("\n"); // salto de linea
    }
}

int main(){
    // RELLENAMOS MATRIZ 1
    printf("matriz 1 (5x5): \n"); // print "matriz 1 (5x5)"
    for(int i = 0; i < n; i++) // recorrer filas en matriz 1 
    {
        printf("ingrese uno a uno cada valor de la fila %i:\n",contador); // imprimo donde en cual fila se estan ingresando los valores
        for(int j = 0 ; j < n; j++) // recorrer  columnas matriz1
        {
            scanf("%i", &numero); // ingreso elemento por teclado
            matrz1 [i][j] = numero; // ingreso elementos mediante columnas
        }
        contador++; // contador aumenta en uno 
    }
    
    
    contador = 1; // reinicio el contador para volver a utilizar la variable
    
    // RELLENAMOS MATRIZ 2
    printf("\nmatriz 2 (5x5): \n"); // print "matriz 2 (5x5)"
    
    for(int i = 0; i < n; i++)// recorrer filas en matriz 2
    {
        printf("ingrese uno a uno cada valor de la fila %i:\n",contador);// imprimo donde en cual fila se estan ingresando los valores
        for(int j = 0 ; j < n; j++)  // imprimo donde en cual fila se estan ingresando los valores
        {
            scanf("%i", &numero);// ingreso elemento por teclado
            matrz2 [i][j] = numero; // ingreso elementos mediante columnas
        }
        contador++; // contador aumenta en uno 
    }
    
    //IMPRIMIMOS MATRIZ 1
    printf("\nvalores en matriz 1 (5x5): \n"); // print "valores en matriz 1 (5x5): "
    
    for(int i = 0; i < n; i++) // recorrer fila matriz 1
    {
        for(int j = 0 ; j < n; j++) // recorrer columna matriz 1
        {
            printf("%i ",matrz1[i][j]); // print de los elementos de matriz 1
        }
        printf("\n"); // salto de linea
    }
    
    //IMPRIMIMOS MATRIZ 2
    printf("\nvalores en matriz 2 (5x5): \n"); // print "valores en matriz 2 (5x5): "
    
    for(int i = 0; i < n; i++) // recorrer fila matriz 2
    {
        for(int j = 0 ; j < n; j++) // recorrer columna matriz 2
        {
            printf("%i ",matrz2[i][j]); // print de los elementos de matriz 2
        }
        printf("\n"); // salto de linea
    }
    
    //SUMA DE MATRIZ 1 Y 2
    printf("\nMatriz 1 + Matriz 2 =\n"); // print "valores en matriz 2 (5x5): "
    
    for(int i = 0; i < n; i++) // recorrer filas
    {
        for(int j = 0 ; j < n; j++) // recorrer columnas
        {
            matrzR[i][j] = matrz1[i][j]+matrz2[i][j]; // sumo las matrices
        }
    }
    
    // IMPRIMIMOS SUMA RESULTANTE
    imprimirMR();
    
    //SUMA DE MATRIZ 2 Y MATRIZ 1
    printf("\nMatriz 2 + Matriz 1 =\n"); // print "valores en matriz 2 (5x5): "
    
    for(int i = 0; i < n; i++) // recorrer filas
    {
        for(int j = 0 ; j < n; j++) // recorrer columnas
        {
            matrzR[i][j] = matrz2[i][j]+matrz1[i][j]; // sumo las matrices
        }
    }
    
    //SUMA RESULTANTE
    imprimirMR();
    
    //PRODUCTO DE MATRIZ 1 Y 2
    printf("\nMatriz 2 * Matriz 1 =\n"); // print "valores en matriz 2 (5x5): "

    for (int k = 0; k < n; k++) 
    {
        for (int i = 0; i < n; i++) 
        {
            contador = 0;
            for (int j = 0; j < n; j++) 
            {
                contador += matrz1[i][j] * matrz2[j][k];
            }
            matrzR[i][k]= contador;
        }
    }
    
    //MATRIZ RESULTANTE
    imprimirMR();
    
    //PRODUCTO DE MATRIZ 2 Y 1
    printf("\nMatriz 2 * Matriz 1 =\n"); // print "valores en matriz 2 (5x5): "

    for (int k = 0; k < n; k++) 
    {
        for (int i = 0; i < n; i++) 
        {
            contador = 0;
            for (int j = 0; j < n; j++) 
            {
                contador += matrz2[i][j] * matrz1[j][k];
            }
            matrzR[i][k]= contador;
        }
    }
    
    //MATRIZ RESULTANTE
    imprimirMR();
    
    //INVERSA DE LA MATRIZ 1
    
    //MATRIZ RESULTANTE
    imprimirMR();
    
    //INVERSA DE LA MATRIZ 2
    
    //MATRIZ RESULTANTE
    imprimirMR();
    
    return 0; //vacio
}


