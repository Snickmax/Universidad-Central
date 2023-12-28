#include <iostream>

using namespace std;

// funcion que soluciona el problema de torres de hanoi
// esta debe pedir una cantidad n de discos antes (en el main)
void Mover_torre (int n, int orig, int dest, int aux){
    // if para imprimir el paso
    if (n == 1)
    {
        
        // imprime el siguiente paso  
        cout << "paso de " << orig << " a " << dest << endl;
        
    }
    else
    {
        
        // recursividad hasta que n sea 1 e imprimir los pasos
        Mover_torre (n - 1, orig, aux, dest);
        // imprime el siguiente paso
        cout << "paso de " << orig << " a " << dest << endl;
        // recursividad hasta que n sea 1 e imprimir los pasos
        Mover_torre (n - 1, aux, dest, orig);
        
    }
}

int main ()
{
    // variable de cantidad de discos
    int n;
    // ingresa cantidad de discos
    cout << "Ingrese el numero de discos: "; cin >> n;
    // inicia funcion
    Mover_torre (n, 1, 2, 3);

    return 0;

}
