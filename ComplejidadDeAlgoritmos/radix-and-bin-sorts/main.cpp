#include <iostream>

using namespace std;

// ingreso datos en forma de punteros para poder actualizar los datos cuando se desee
void datos(int* lista,int* lista2, int* N){
    // ingreso N dentro de los limites
    do
    {
        cout << "Ingrese el numero de elementos de la lista (max 60): ";
        cin >> *N;
    } while (!(0 < *N and *N<= 60));
    
    // ingreso los datos en la lista
    for(int i = 0; i < *N ; i++){
        do
        {
            cout << "ingrese el dato "<<i+1<< " ( != 0): ";
            // ingreso el dato
            cin >> *(lista+i);
            // lo guardo en el auxiliar que se manipulara
            *(lista2+i) = *(lista+i);
        } while ((*(lista+i) == 0));
        
    }
}

// muestro los datos de la lista
void mostrar(int* lista, int N){
    for(int i = 0; i < N ; i++){
        if (*(lista+i) != 0){
            cout << *(lista+i) << " ";
        }
    }
    cout << endl;
}

// copio la lista que se ordeno para volverla a usar
void actualizar(int* lista,int* lista2, int N){
    for(int i = 0; i < N ; i++){
        *(lista2+i) = *(lista+i);
    }
}

// Implementación del algoritmo de radixsort
void radixsort(int* lista, int N) {
    int max = *lista; // Encontrar el valor máximo en la lista
    for (int i = 1; i < N; i++) {
        if (*(lista+i) > max) {
            max = *(lista+i);
        }
    }

    // Ordenar los números en base a los dígitos de menor a mayor
    for (int exp = 1; max / exp > 0; exp *= 10) {
        int salida[N];
        int conteo[10] = {0};

        // Contar la frecuencia de cada dígito
        for (int i = 0; i < N; i++) {
            conteo[( (*(lista+i)) / exp) % 10]++;
        }

        // Calcular las posiciones finales de los dígitos en la salida
        for (int i = 1; i < 10; i++) {
            conteo[i] += conteo[i - 1];
        }

        // Construir la lista de salida
        for (int i = N - 1; i >= 0; i--) {
            salida[conteo[((*(lista+i)) / exp) % 10] - 1] = *(lista+i);
            conteo[((*(lista+i)) / exp) % 10]--;
        }

        // Copiar la salida a la lista original
        int count = 0;

        for (int i = 0; i < N; i++) {
            *(lista+i) = salida[i];
            if(!(i%N)){
                mostrar(&salida[0], N);
            }
        }
    }
}

void binsort(int* lista, int N) 
{
    int max = *lista; // guardo el primer dato de la lista
    // busco el dato mayor de la lista
    for (int i = 1; i < N; i++) {
        // cambio el dato de max si es mayor al que ya tenia guardado
        if (*(lista+i) > max) {
            max = *(lista+i);
        }
    }

    //rango de limites
    int selecion = (max/4) + 1;

    //creo limites
    int limI[4];
    int limS[4];

    // limites de bins
    for(int i = 0; i < 4; i++){
        limI[i] = selecion * i;
        limS[i] = selecion* (i+1) - 1;
    }

    // creo bins
    int bins1[N];
    int bins2[N];
    int bins3[N];
    int bins4[N];

    // ingreso 0 en todos los bins
    for (int i = 0; i < N; i++) { 
        bins1[i] = 0;
        bins2[i] = 0;
        bins3[i] = 0;
        bins4[i] = 0;
    }

    // ingreso los datos en los bins
    int c1,c2,c3,c4 = 0;
    c1 = c2 = c3 = c4;
    for (int i = 0; i < N; i++) { 
        if ((*(lista+i) >= limI[0]) and (*(lista+i) <= limS[0]) ){
            bins1[c1] = *(lista+i);
            c1++;
        }
        if ((*(lista+i) >= limI[1]) and (*(lista+i) <= limS[1]) ){
            bins2[c2] = *(lista+i);
            c2++;
        }
        if ((*(lista+i) >= limI[2]) and (*(lista+i) <= limS[2]) ){
            bins3[c3] = *(lista+i);
            c3++;
        }
        if ((*(lista+i) >= limI[3]) and (*(lista+i) <= limS[3]) ){
            bins4[c4] = *(lista+i);
            c4++;
        }
    }

    // mostrar bins
    cout<< "Bins sin ordenar:"<< endl << endl;
    cout<< "Bin 1:"<< endl;
    mostrar(&bins1[0], N);
    cout<< endl <<"Bin 2:"<< endl;
    mostrar(&bins2[0], N);
    cout<< endl <<"Bin 3:"<< endl;
    mostrar(&bins3[0], N);
    cout<< endl <<"Bin 4:"<< endl;
    mostrar(&bins4[0], N);

    // ordenamos listas con cualquier ordenamiento

    cout<<"Bins ordenando con radixs:"<< endl << endl;
    cout<< endl <<"Bin 1 ["<<limI[0]<< " - " << limS[0]<< "] :"<< endl;
    radixsort(&bins1[0], N);
    cout<< endl <<"Bin 2 ["<<limI[1]<< " - " << limS[1]<< "] :"<< endl;
    radixsort(&bins2[0], N);
    cout<< endl <<"Bin 3 ["<<limI[2]<< " - " << limS[2]<< "] :"<< endl;
    radixsort(&bins3[0], N);
    cout<< endl <<"Bin 4 ["<<limI[3]<< " - " << limS[3]<< "] :"<< endl;
    radixsort(&bins4[0], N);

    //union de bins
    int cf = 0; 
    for (int i = 0 ; i < N; i++){
        if (bins1[i] != 0){
            *(lista+cf) = bins1[i];
            cf++;
        }
    }
    for (int i = 0 ; i < N; i++){
        if (bins2[i] != 0){
            *(lista+cf) = bins2[i];
            cf++;
        }
    }
    for (int i = 0 ; i < N; i++){
        if (bins3[i] != 0){
            *(lista+cf) = bins3[i];
            cf++;
        }
    }
    for (int i = 0 ; i < N; i++){
        if (bins4[i] != 0){
            *(lista+cf) = bins4[i];
            cf++;
        }
    }
    cout<< endl <<" Ordenado: "<< endl;
    mostrar(lista, N);

}

int main(int argc, char const *argv[])
{
    // N para cantidad de datos
    int N;
    // lista para cantidad de datos pero la limito a max 60 datos
    int lista[60];
    // lista aux para cantidad de datos pero la limito a max 60 datos
    int lista2[60];
    // funcion para ingresar los N datos
    datos(&lista[0],&lista2[0], &N);
    // opcion para salir
    bool opcion = true;
    
    // ciclo del menu
    do
    {
        //opcion para el menu
        int opcion2;
        // menu
        cout << endl << "---- Menu ---" << endl;
        cout << "1. Cambiar datos" << endl;
        cout << "2. Binsort" << endl;
        cout << "3. Radixsort" << endl;
        cout << "0. Salir" << endl;
        cout << "Ingrese su opcion: ";
        // ingreso opcion
        cin >> opcion2;
        cout << endl;

        switch (opcion2)
        {
            case 0://salir
                // cambio opcion a false para salir
                opcion = false;
                break;
            case 1://cambiar datos
                datos(&lista[0],&lista2[0], &N);
                break;
            case 2://Binsort
                binsort(&lista2[0], N);
                //actualizo los datos para trabajar con ellos de nuevo
                actualizar(&lista[0],&lista2[0], N);
                break;
            case 3://Radixsort
                cout << "ordenamiento binsort: " << endl;
                radixsort(&lista2[0], N);
                //actualizo los datos para trabajar con ellos de nuevo
                actualizar(&lista[0],&lista2[0], N);
                break;
            default:
            // en caso de que se salgan del rango de opciones
                cout << endl << "Ingrese una opcion disponible...." << endl;
                break;
        }
    } while (opcion);
    
    return 0;
}
