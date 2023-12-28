#include <stdio.h>

void intercambio(int *a, int * b){
    int temporal = *a;
    *a = *b;
    *b = temporal;
}

int particion(int arreglo[], int izquierda, int derecha){
    int pivote = arreglo[izquierda];
    
    while(1){
        while(arreglo[izquierda] < pivote ){
            izquierda++;
        }
        while(arreglo[derecha] > pivote){
            derecha--;
        }
        if(izquierda >= derecha){
            return derecha;
        }else{
            intercambio(&arreglo[izquierda], &arreglo[derecha]);
            izquierda++;
            derecha--;
        }
    }
}
void quicksort(int arreglo[], int izquierda, int derecha){
    if (izquierda < derecha){
        int indiceParticion = particion(arreglo, izquierda, derecha);
        quicksort(arreglo, izquierda, indiceParticion);
        quicksort(arreglo, indiceParticion + 1, derecha);
    }
}
int main()
{
    int arreglo[] = {28,11,96,-5,21,18,12,22,30,97,-1,-40,-500};
    
    int longitud = sizeof arreglo / sizeof arreglo[0];
    
    printf("Imprimiendo arreglo antes de ordenar...\n");
    for (int x = 0; x < longitud; x++ ){
        printf("%d ", arreglo[x]);
    }
    printf("\n");
    quicksort(arreglo, 0, longitud-1);
    
    printf("Imprimiendo arreglo despues de ordenar...\n");
    for (int x= 0; x < longitud; x++)
        printf("%d ", arreglo[x]);
    return 0;
}