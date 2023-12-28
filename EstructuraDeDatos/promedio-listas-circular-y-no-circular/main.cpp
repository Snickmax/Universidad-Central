/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;
struct Nota{
    double nota;
    Nota* sig;
};

// Lista circular
double CalcularPromedioC(Nota* head, Nota* auxHead, int ctr = 0, double sumaNotas = 0.0) {
    Nota* aux = head;
    ctr++;
    sumaNotas += aux->nota;
    
    if (aux -> sig == auxHead) {
        return sumaNotas / ctr;
    }

    double promedio = CalcularPromedioC(aux->sig,auxHead, ctr, sumaNotas);
    return promedio;
}

// lista final NULL
double CalcularPromedio(Nota* head, int ctr = 0, double sumaNotas = 0.0) {
    Nota* aux = head;
    if (aux == NULL) {
        return sumaNotas / ctr;
    }

    ctr++;
    sumaNotas += aux->nota;
    double promedio = CalcularPromedio(aux->sig, ctr, sumaNotas);
    return promedio;
}

int main()
{
    double prom;
    
    Nota n1 ,n2 ,n3 ,n4 ,n5 ,n6;
    n1.nota = 2;
    n2.nota = 7;
    n3.nota = 6;
    n4.nota = 1;
    n5.nota = 2;
    n6.nota = 3;
    
    n1.sig = &n2;
    n2.sig = &n3;
    n3.sig = &n4;
    n4.sig = &n5;
    n5.sig = &n6;
    n6.sig = &n1; // cambiar a NULL para la de lisata a NULL
    
    prom = CalcularPromedioC(&n1, &n1); //quitar la C para usar el de lista circular a la del NULL
    
    cout<<prom;

    return 0;
}
