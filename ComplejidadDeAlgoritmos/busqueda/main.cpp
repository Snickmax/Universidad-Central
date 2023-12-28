#include <iostream>
#define n 5

using namespace std;

// estructura de la lista
struct lista{
    int numeros;
    lista *sig;
};

void MaxConListas(lista *num){
    // inicio el maximo con el primer numero de la lista
    int max = num->numeros;
    
    // for para buscar el maximo
    for (int i = 1; i < n; i++){
        // avanzo al siguiente de la lista
        num = num -> sig;
        
        // si el siguiente es mayor al maximo...
        if (max < num -> numeros){
            //lo cambio
            max = num -> numeros;
        }
    }
    
    // imprimo el mayor
    cout <<max<< " es el mayor"<<endl; 
}


void MaxConArray(int lista[n]){
    // inicio el maximo con el primer numero del array
    int max = lista[0];
    
    // for para buscar el maximo
    for (int i = 1; i < n; i++){
        
        // si el siguiente es mayor al maximo...
        if (max < lista[i]){
            //lo cambio
            max = lista[i];
        }
    }
    
    // imprimo el mayor
    cout <<max<< " es el mayor"<<endl; 
}

void BuesquedaLineal(int x, int lista[n]){
    // asigno el indice 1
    int i = 1;
    
    // while para buscar el indice mayor, si este es igual al numero buscado se rompe
    while((i <= n) and (x != lista[i])){
        // avanzo de indice
        i++;
    }
    
    int indice;
    
    // if en caso de que sea el indice 0
    if (i <= n){
        indice = i;
    }
    else {
        indice = 0;
    }
    
    // imprimo el indice
    cout << x << " esta ubicado en el indice " << indice << endl;
}

int main()
{
// Buscar maximo con listas
    // creo una lista
    lista num1 ,num2 ,num3 ,num4 ,num5 ,num6;
    
    // inicializo las listas
    num1.numeros = 0;
    num2.numeros = 2;
    num3.numeros = 6;
    num4.numeros = 4;
    num5.numeros = 5;
    // le asigno el siguiente
    num1.sig = &num2;
    num2.sig = &num3;
    num3.sig = &num4;
    num4.sig = &num5;
    num5.sig = NULL;
    
    // busco el maximo entregando la cabeza de la lista
    MaxConListas(&num1);

// busqueda lineal
    // inicializa la variable de busqueda
    int x = 4;
    
    // inicializo lista
    int lista1[n] = {0,2,6,4,5};
    int lista2[n] = {2,4,2,7,1};
    // busco el el indice del maximo de la lista
    BuesquedaLineal(x, lista1);
    BuesquedaLineal(x, lista2);
// Buscar maximo con Array
    // busco el maximo de la lista
    MaxConArray(lista1);
    MaxConArray(lista2);
    
    return 0;
}