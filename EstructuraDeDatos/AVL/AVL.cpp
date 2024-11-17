#include "AVL.h"

int ObtenerAltura(Nodo* nodo) {
    if (nodo == nullptr) {
        return 0;
    }
    int alturaIzq = ObtenerAltura(nodo->hIzq);
    int alturaDer = ObtenerAltura(nodo->hDer);
    return 1 + max(alturaIzq, alturaDer);
}

Nodo* RotacionIzquierda(Nodo* nodo) {
    Nodo* hijoDerecha = nodo->hDer;
    nodo->hDer = hijoDerecha->hIzq;
    hijoDerecha->hIzq = nodo;
    return hijoDerecha;
}

Nodo* RotacionDerecha(Nodo* nodo) {
    Nodo* hijoIzquierda = nodo->hIzq;
    nodo->hIzq = hijoIzquierda->hDer;
    hijoIzquierda->hDer = nodo;
    return hijoIzquierda;
}

Nodo* InsertarNodo(Nodo*& raiz, int turno, string nombre) {
    if (raiz == nullptr) {
        return CrearNodo(turno, nombre);
    }

    if (turno < raiz->turno) {
        raiz->hIzq = InsertarNodo(raiz->hIzq, turno, nombre);
    } else {
        raiz->hDer = InsertarNodo(raiz->hDer, turno, nombre);
    }

    int factorEquilibrio = ObtenerAltura(raiz->hIzq) - ObtenerAltura(raiz->hDer);

    if (factorEquilibrio > 1) {
        if (turno < raiz->hIzq->turno) {
            raiz = RotacionDerecha(raiz);
        } else {
            raiz->hIzq = RotacionIzquierda(raiz->hIzq);
            raiz = RotacionDerecha(raiz);
        }
    } else if (factorEquilibrio < -1) {
        if (turno > raiz->hDer->turno) {
            raiz = RotacionIzquierda(raiz);
        } else {
            raiz->hDer = RotacionDerecha(raiz->hDer);
            raiz = RotacionIzquierda(raiz);
        }
    }

    return raiz;
}

Nodo* EliminarNodo(Nodo*& raiz, int turno, string& nombre) {
    if (raiz == nullptr) {
        return raiz;
    }

    if (turno < raiz->turno) {
        raiz->hIzq = EliminarNodo(raiz->hIzq, turno, nombre);
    } else if (turno > raiz->turno) {
        raiz->hDer = EliminarNodo(raiz->hDer, turno, nombre);
    } else {
        nombre = raiz->nombre;

        if (raiz->hIzq == nullptr && raiz->hDer == nullptr) {
            delete raiz;
            raiz = nullptr;
        } else if (raiz->hIzq == nullptr) {
            Nodo* temp = raiz;
            raiz = raiz->hDer;
            delete temp;
        } else if (raiz->hDer == nullptr) {
            Nodo* temp = raiz;
            raiz = raiz->hIzq;
            delete temp;
        } else {
            Nodo* sucesor = raiz->hDer;
            while (sucesor->hIzq != nullptr) {
                sucesor = sucesor->hIzq;
            }
            raiz->turno = sucesor->turno;
            raiz->nombre = sucesor->nombre;
            raiz->hDer = EliminarNodo(raiz->hDer, sucesor->turno, sucesor->nombre);
        }
    }

    if (raiz == nullptr) {
        return raiz;
    }

    int factorEquilibrio = ObtenerAltura(raiz->hIzq) - ObtenerAltura(raiz->hDer);

    if (factorEquilibrio > 1) {
        if (ObtenerAltura(raiz->hIzq->hIzq) >= ObtenerAltura(raiz->hIzq->hDer)) {
            raiz = RotacionDerecha(raiz);
        } else {
            raiz->hIzq = RotacionIzquierda(raiz->hIzq);
            raiz = RotacionDerecha(raiz);
        }
    } else if (factorEquilibrio < -1) {
        if (ObtenerAltura(raiz->hDer->hDer) >= ObtenerAltura(raiz->hDer->hIzq)) {
            raiz = RotacionIzquierda(raiz);
        } else {
            raiz->hDer = RotacionDerecha(raiz->hDer);
            raiz = RotacionIzquierda(raiz);
        }
    }

    return raiz;
}

void RecorridoIRD(Nodo* raiz, stack<int>& pila, int divisor) {
    if (raiz == nullptr) {
        return;
    }

    RecorridoIRD(raiz->hIzq, pila, divisor);
    if (raiz->turno % divisor == 0) {
        pila.push(raiz->turno);
    }
    RecorridoIRD(raiz->hDer, pila, divisor);
}

void MostrarRepetidos(stack<int>& numeros) {
    int conteo[101] = {0};
    while (!numeros.empty()) {
        int numero = numeros.top();
        numeros.pop();
        conteo[numero]++;
    }

    bool huboRepetidos = false;
    cout << "Números repetidos:\n";
    for (int i = 1; i <= 100; i++) {
        if (conteo[i] > 1) {
            cout << i << " se repitió " << conteo[i] << " veces\n";
            huboRepetidos = true;
        }
    }

    if (!huboRepetidos) {
        cout << "No hubo números repetidos\n";
    }
}