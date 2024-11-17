#include "AVL.h"

int main() {
    queue<int> numerosIngresados;
    stack<int> numerosDivisibles;
    Nodo* raizAVL = nullptr;
    int contador = 0;

    while (contador < 100) {
        int turno;
        string nombre;
        cout << "Ingrese el número de turno: ";
        cin >> turno;
        cout << "Ingrese el nombre del paciente: ";
        cin >> nombre;

        if (turno < 1 || turno > 100) {
            cout << "El número de turno debe estar entre 1 y 100\n";
            continue;
        }
        
        if ((contador+1) % 10 == 0) {
            
            // meto lso 10
            while (!numerosIngresados.empty()) {
                int numero = numerosIngresados.front();
                numerosIngresados.pop();
                int divisor = 5;
                RecorridoIRD(raizAVL, numerosDivisibles, divisor);
                if (!numerosDivisibles.empty()) {
                    int numeroDivisible = numerosDivisibles.top();
                    numerosDivisibles.pop();
                    string nombreEliminado;
                    EliminarNodo(raizAVL, numeroDivisible, nombreEliminado);
                    cout << "Turno eliminado: " << numeroDivisible << " (" << nombreEliminado << ")\n";
                }
            }
            // mostrar repetidos
            MostrarRepetidos(numerosIngresados);
        }
        
        InsertarNodo(raizAVL, turno, nombre);
        numerosIngresados.push(turno);
        contador++;
    }
    
    while (!numerosIngresados.empty()) {
        int numero = numerosIngresados.front();
        numerosIngresados.pop();
        int divisor = rand() % 10 + 1;
        RecorridoIRD(raizAVL, numerosDivisibles, divisor);
        
        if (!numerosDivisibles.empty()) {
            
            int numeroDivisible = numerosDivisibles.top();
            numerosDivisibles.pop();
            string nombreEliminado;
            EliminarNodo(raizAVL, numeroDivisible, nombreEliminado);
            cout << "Turno eliminado: " << numeroDivisible << " (" << nombreEliminado << ")\n";
        }
    }

    MostrarRepetidos(numerosIngresados);

    delete raizAVL;

    return 0;
}

