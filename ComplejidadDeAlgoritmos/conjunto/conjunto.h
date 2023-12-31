#include <iostream>
using namespace std;
//implementacion de la libreria conjunto
#ifndef CONJUNTO_H
#define CONJUNTO_H

//Autores: Edgar Ruiz L. y Hilmar Hinojosa L.
const int N = 100;

//declarando la clase conjunto
class conjunto {
public:
    conjunto();     //constructor
    ~conjunto();    //destuctor
    void imprimir();
    void ordenar();
    bool pertenece(int x);
    int cardinalidad();
    void operator+(int x);

    //funciones amigas
    friend conjunto operator+(conjunto c1, conjunto c2);
    friend conjunto operator*(conjunto c1, conjunto c2);
    friend conjunto operator-(conjunto c1, conjunto c2);
    friend conjunto operator^(conjunto c1, conjunto c2);

    //comparaciones
    friend bool operator<=(conjunto c1, conjunto c2);
    friend bool operator==(conjunto c1, conjunto c2);
    friend bool operator!=(conjunto c1, conjunto c2);
    friend bool operator<(conjunto c1, conjunto c2);

private:
    int elem[N];
    int ne;
};

//constructor
conjunto::conjunto() {
    int i;
    for (i = 0; i < N; i++)
        elem[i] = 0;
    ne = 0;
}

//destuctor
conjunto::~conjunto() {}

//sobrecarga para el operador + para insertar un nuevo elemento
void conjunto::operator+(int x) {
    if (pertenece(x) == false) {
        elem[ne] = x;
        ne++;
    } else
        cout << "Elemento ya existe" << endl;
}

//imprimir los elementos del conjunto
void conjunto::imprimir() {
    int i;
    if (ne > 0) {
        ordenar();
        for (i = 0; i < ne; i++)
            cout << elem[i] << "\t";
        cout << endl;
    } else
        cout << "El conjunto esta vacio" << endl;
}

//ordenar los elementos del conjunto
void conjunto::ordenar() {
    int i, j, x;
    if (ne > 1) {
        for (i = 0; i < ne - 1; i++)
            for (j = i + 1; j < ne; j++)
                if (elem[i] > elem[j]) {
                    x = elem[i];
                    elem[i] = elem[j];
                    elem[j] = x;
                }
    }
}

// el elemento pertenece al conjunto?
bool conjunto::pertenece(int x) {
    int i;
    bool b;
    b = false;
    i = 0;
    while (b == false && i < ne)
        if (elem[i] == x)
            b = true;
        else
            i++;
    return b;
}

//cardinalidad: numero de elementos del conjunto
int conjunto::cardinalidad() {
    return ne;
}

//definiendo la union de conjuntos
conjunto operator+(conjunto c1, conjunto c2) {
    conjunto c3;
    int x, i;
    for (i = 0; i < c1.ne; i++)
        c3.elem[i] = c1.elem[i];
    c3.ne = c1.ne;
    for (i = 0; i < c2.ne; i++) {
        x = c2.elem[i];
        if (c3.pertenece(x) == false) {
            c3.elem[c3.ne] = x;
            c3.ne++;
        }
    }
    return c3;
}

//definiendo la interseccion de conjuntos
conjunto operator*(conjunto c1, conjunto c2) {
    conjunto c3;
    int x, i;
    for (i = 0; i < c1.ne; i++) {
        x = c1.elem[i];
        if (c2.pertenece(x) == true) {
            c3.elem[c3.ne] = x;
            c3.ne++;
        }
    }
    return c3;
}

//definiendo la diferencia de conjuntos
conjunto operator-(conjunto c1, conjunto c2) {
    conjunto c3;
    int x, i;
    for (i = 0; i < c1.ne; i++) {
        x = c1.elem[i];
        if (c2.pertenece(x) == false) {
            c3.elem[c3.ne] = x;
            c3.ne++;
        }
    }
    return c3;
}

conjunto operator^(conjunto c1, conjunto c2) {
    conjunto c3;
    
    int x, i;
    for (i = 0; i < c1.ne; i++) {
        x = c1.elem[i];
        if (c2.pertenece(x) == false) {
            c3.elem[c3.ne] = x;
            c3.ne++;
        }
    }

    for (i = 0; i < c2.ne; i++) {
        x = c2.elem[i];
        if (c1.pertenece(x) == false) {
            c3.elem[c3.ne] = x;
            c3.ne++;
        }
    }

    return c3;
}

//definiendo el subconjunto propio
bool operator<=(conjunto c1, conjunto c2) {
    int x, i;
    for (i = 0; i < c1.ne; i++) {
        x = c1.elem[i];
        if (c2.pertenece(x) == false)
            return false;
    }
    return true;
}

//definiendo la igualdad de conjuntos
bool operator==(conjunto c1, conjunto c2) {
    if ((c1 <= c2) && (c2 <= c1))
        return true;
    else
        return false;
}

//definiendo la desigualdad de conjuntos
bool operator!=(conjunto c1, conjunto c2) {
    return !(c1 == c2);
}

//definiendo el subconjunto
bool operator<(conjunto c1, conjunto c2) {
    if ((c1 <= c2) && (c1 != c2))
        return true;
    else
        return false;
}

#endif //fin de la libreria conjunto.h
