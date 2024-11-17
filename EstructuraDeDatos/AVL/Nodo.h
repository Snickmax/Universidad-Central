#include <iostream>
#include <queue>
#include <stack>
#include <cstdlib>

using namespace std;

struct Nodo {
    int turno;
    string nombre;
    Nodo* hIzq;
    Nodo* hDer;
};

Nodo* CrearNodo(int turno, string nombre);