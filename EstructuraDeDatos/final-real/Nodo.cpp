#include "Nodo.h"

Nodo* CrearNodo(int turno, string nombre) {
    Nodo* nuevoNodo = new Nodo;
    nuevoNodo->turno = turno;
    nuevoNodo->nombre = nombre;
    nuevoNodo->hIzq = nullptr;
    nuevoNodo->hDer = nullptr;
    return nuevoNodo;
}