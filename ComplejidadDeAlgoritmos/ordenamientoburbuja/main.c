/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

#define SIZE 5

void mostrarLista(long *);

void ordBurvuja(long lista[], int Size);

void ordBurvuja2(long a[], int n);

void ordBurvuja3(long a[], int n);

int main()
{
    printf("Ordenamiento Bubuja 1 (Original):\n");
    long lista[SIZE] = {5,2,4,1,3};
    mostrarLista(lista);
    ordBurvuja(lista,SIZE);
    
    printf("\nOrdenamiento Bubuja 2 (interruptor):\n");
    long lista2[SIZE] = {5,6,1,3,4};
    mostrarLista(lista2);
    ordBurvuja2(lista2,SIZE);
    
    printf("\nOrdenamiento Bubuja 3 (indiceIntercambio):\n");
    long lista3[SIZE] = {7,8,9,6,3};
    mostrarLista(lista3);
    ordBurvuja3(lista3,SIZE);
    
    return 0;
}

void ordBurvuja(long lista[], int Size){
    int n, l = Size, i, temp;
    
    do{
        n = 0;
        // Recorer la lista
        for (i=1; i<l; i++)
        //Verificar si los dos valores estan ordenados
            if(*(lista+i-1)>*(lista+i)){
                //Ordenar si es necesario
                temp = *(lista+i-1);
                *(lista+i-1) = *(lista+i);
                *(lista+i) = temp;
                n=i;
                mostrarLista(lista);
            }
        
        l = n;
    }while(n!=0);
}

void ordBurvuja2(long a[], int n)
{
    int interruptor = 1;
    int pasada, j;
    
    for(pasada = 0 ; pasada < n-1 && interruptor; pasada ++){
        // bucle externo controla la cantidad de pasadas
        interruptor = 0;
        for(j=0; j < n-pasada-1; j++)
            if(a[j] > a[j+1]){
                // elementos desordenados, es necesario intrcambio
                long aux;
                interruptor = 1;
                aux = a[j];
                a[j] = a[j+1];
                a[j+1] = aux;
                
                mostrarLista(a);
            }
    }
}

void ordBurvuja3(long a[], int n){
    int i, j;
    int indiceIntercambio;
    
    // i es el indice del ultimo elemento de la sublista
    i = n-1;
    
    // el proceso continua hasta que no haya intercambios
    while (i > 0){
        indiceIntercambio = 0;
        // explorar la sublista a[0] a a[i]
        for(j=0; j<i; j++)
            // intercambia pareja y actualizar indiceIntercambio
            if (a[j+1] < a[j]){
                long aux = a[j];
                a[j] = a[j+1];
                a[j+1] = aux;
                indiceIntercambio = j;
                
                mostrarLista(a);
            }
            // i se pone al valor del indice del ultimo intercambio
        i = indiceIntercambio;
    }
}

void mostrarLista(long *a){
    int i;
    for(i=0 ; i<SIZE;i++) printf("\t[%ld]", *(a+i));
    printf("\n");
}



