// Archivo: conjun1.cpp
#include <iostream>
#include <stdlib.h>
#include "conjunto.h"

using namespace std;

int main() {
    conjunto A, B, C, D, E, F;
    int i, x, n;
    cout << "Cuantos elementos desea ingresar para el Conjunto A? ";
    cin >> n;
    for (i = 1; i <= n; i++) {
        cout << "Ingrese elemento " << i << ": ";
        cin >> x;
        A + x;
    }
    A.imprimir();

    cout << "\nCuantos elementos desea ingresar para el Conjunto B? ";
    cin >> n;
    for (i = 1; i <= n; i++) {
        cout << "Ingrese elemento " << i << ": ";
        cin >> x;
        B + x;
    }
    B.imprimir();

    C = A + B;
    cout << endl << "\nC = A UNION B" << endl;
    C.imprimir();
    cout << "La cardinalidad de C es " << C.cardinalidad() << endl;

    D = A * B;
    cout << endl << "\nD = A INTERSECCION B" << endl;
    D.imprimir();
    cout << "La cardinalidad de D es " << D.cardinalidad() << endl;

    E = A - B;
    cout << endl << "\nE = DIFERENCIA de A y B" << endl;
    E.imprimir();
    cout << "La cardinalidad de E es " << E.cardinalidad() << endl;
    
    F = A ^ B;
    cout << endl << "\nF = DIFERENCIA SIMETRICA de A y B" << endl;
    F.imprimir();
    cout << "La cardinalidad de F es " << F.cardinalidad() << endl;

    if (A <= B) {
        cout << "\nA es subconjunto de B" << endl;
        if (A < B)
            cout << "\nA es subconjunto propio de B" << endl;
    } else
        cout << "\nA no es subconjunto de B" << endl;

    if (A == B)
        cout << "\nA y B son iguales" << endl;
    else
        cout << "\nA y B son diferentes" << endl;

    cout << endl;
    system("PAUSE");
    return 0;
}