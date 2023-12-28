/******************************************************************************

Victor Ibarra
Ejercicio filosofos en lenguaje C++

*******************************************************************************/
#include <iostream>
#include <thread>
#include <mutex>
#include <semaphore.h>
#include <unistd.h>

// defino los Filosofos
#define nFilosofos 5

// defino los posibles estados
#define pensando 0
#define comiendo 1
#define hambriento 2
#define NUM_ITERACIONES 1

using namespace std;

// estructura para los filosofos
struct Filosofos{
    int id;
    sem_t *tenedorIz;
    sem_t *tenedorDer;
    Filosofos *Derecha;
    int estado = pensando;
};

// funcion para imprimir los filosofos
void mostrarEstadoFilosofos(Filosofos* primerFilosofo) {
    Filosofos* filosofoActual = primerFilosofo;
    for (int i = 0; i < nFilosofos; i++) {
        string estado;
        //consultamos el estado del filosofo 
        if (filosofoActual->estado == pensando)
            estado = "PENSANDO";
        else if (filosofoActual->estado == comiendo)
            estado = "COMIENDO";
        else if (filosofoActual->estado == hambriento)
            estado = "HAMBRIENTO";

        cout << "Filosofo " << filosofoActual->id << " esta " << estado << "." << endl;
        filosofoActual = filosofoActual->Derecha;
    }
    cout << endl;
}

int contador = 0;
void filosofoComiendo(Filosofos* Filosofo) {
    Filosofos* Aux = Filosofo;
    
    for (int i = 0; i < NUM_ITERACIONES; i++) {
        
        Filosofo->estado = hambriento;
        mostrarEstadoFilosofos(Aux); // Mostrar el estado actual de los filósofos

        // Intentar obtener los tenedores
        sem_wait(Filosofo->tenedorIz);
        sem_wait(Filosofo->tenedorDer);

        // Simular la acción de comer
        Filosofo->estado = comiendo;
        mostrarEstadoFilosofos(Aux); // Mostrar el estado actual de los filósofos

        sleep(2); // se duerme el hilo durante 2 segundo

        // Liberar los tenedores
        sem_post(Filosofo->tenedorIz);
        sem_post(Filosofo->tenedorDer);

        // Simular la acción de pensar
        Filosofo->estado = pensando;
        mostrarEstadoFilosofos(Aux); // Mostrar el estado actual de los filósofos
        
        sleep(2); // se duerme el hilo durante 2 segundo
        
        // Pasar al siguiente filósofo
        contador++;
        Filosofo = Filosofo->Derecha;
        if (contador == 5){
            contador = 0;
            cout << "\nEstado final"<<endl;
            mostrarEstadoFilosofos(Aux); // Mostrar el estado actual de los filósofos
        }
    }
}

int main()
{
    // creo a los filosofos
    Filosofos filosofo[nFilosofos];
    
    // creo sus semaforos
    sem_t tenedor[nFilosofos];
    
    for (int i = 0; i < nFilosofos; i++) {
        sem_init(&tenedor[i], 0, 1);  // Inicializar el semáforo de cada tenedor
    }
    
    // identificador de Filosofos
    filosofo[0].id = 1;
    filosofo[1].id = 2;
    filosofo[2].id = 3;
    filosofo[3].id = 4;
    filosofo[4].id = 5;
    
    // tenedor al lado derecho de los filosofos
    filosofo[0].tenedorDer = &tenedor[0];
    filosofo[1].tenedorDer = &tenedor[1];
    filosofo[2].tenedorDer = &tenedor[2];
    filosofo[3].tenedorDer = &tenedor[3];
    filosofo[4].tenedorDer = &tenedor[4];
    
    // tenedor al lado izquierdo de los filosofos
    filosofo[0].tenedorIz = &tenedor[4];
    filosofo[1].tenedorIz = &tenedor[0];
    filosofo[2].tenedorIz = &tenedor[1];
    filosofo[3].tenedorIz = &tenedor[2];
    filosofo[4].tenedorIz = &tenedor[3];
    
    for (int i = 0; i < nFilosofos; i++) {
        sem_init(&tenedor[i], 0, 1);  // Inicializar el semáforo de cada tenedor
    }
    
    // conectamos lista circula
    filosofo[0].Derecha = &filosofo[1];
    filosofo[1].Derecha = &filosofo[2];
    filosofo[2].Derecha = &filosofo[3];
    filosofo[3].Derecha = &filosofo[4];
    filosofo[4].Derecha = &filosofo[0];

    // Crear los hilos de los filósofos
    thread filosofosThreads[nFilosofos];

    for (int i = 0; i < nFilosofos; i++) {
        filosofosThreads[i] = thread(filosofoComiendo, &filosofo[i]);
    }
    
    // Esperar a que los hilos terminen
    for (int i = 0; i < nFilosofos; i++) {
        filosofosThreads[i].join();
    }
    
    // Liberar los semáforos de los tenedores
    for (int i = 0; i < nFilosofos; i++) {
        sem_destroy(&tenedor[i]);
    }
    
    return 0;
}




