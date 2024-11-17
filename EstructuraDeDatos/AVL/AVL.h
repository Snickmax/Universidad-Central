#include "Nodo.h"

Nodo* InsertarNodo(Nodo*& raiz, int turno, string nombre);
Nodo* EliminarNodo(Nodo*& raiz, int turno, string& nombre);
Nodo* RotacionDerecha(Nodo* nodo);
Nodo* RotacionIzquierda(Nodo* nodo);
int ObtenerAltura(Nodo* nodo);
void RecorridoIRD(Nodo* raiz, stack<int>& pila, int divisor);
void MostrarRepetidos(stack<int>& numeros);