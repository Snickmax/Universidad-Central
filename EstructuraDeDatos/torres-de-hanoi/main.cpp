/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#define mDiscos 100000
#include <math.h>
using namespace std;

//           creamos la libreria <stack>
// Empezamos creando la clase con sus atributos
class poste{
private:
// Creamos las variables de disco que es la cantidad de discos que pueden almacenar cada poste
    int discos[mDiscos];
// creamos la variable tope que es el ultimo disco del poste
    int tope;
public:
    poste(){
        tope = -1;
    }
    //push ingresar datos
    void ingresar(int disco){
        // agregamos un disco al poste
        discos[++tope] = disco;
    }
    //pop sacar datos
    int sacar(){
        // elimina y devuelve el disco de la parte superior del poste.
        return discos[--tope];
    }
};

int contadorMovimientos = 0;

// Función recursiva para mover los discos de un poste a otro
void desHanoi(int disco, int Agarramos, int Destino, int Aux, poste& posteAgarramos, poste& posteDestino, poste& posteAux)
{
    // consultamos si el disco que se va mover es el menor de todos o no, ya que el patron es el (poste inicial) 
    // disco menor al sig (si el numero de disco es impar) o al subsiguiente (si el numero de discos es par), luego el disco mayor (de los del tope) al otro poste.
    if (disco == 1)
    {
        cout << "Movemos disco 1 del poste " << Agarramos << " al poste " << Destino << endl;

        // Mover el disco de del poste del que agarramos el disco a el poste destino
        posteDestino.ingresar(posteAgarramos.sacar());
        
        // + 1 movimiento
        contadorMovimientos++;
    }
    else
    {
        // Mover (n-1) discos del poste que agarramos el disco al poste auxiliar, usando el poste destino como auxiliar (esto proboca lo del impar o par)
        desHanoi(disco - 1, Agarramos, Aux, Destino, posteAgarramos, posteAux, posteDestino);

        cout << "Movemos disco " << disco << " del poste " << Agarramos << " al poste " << Destino << endl;

        // Mover el disco restante (el más grande) del poste que agarramos el disco a el poste destino (poste restante dif al que se movio el menor ya que antes se cabio el destino)
        posteDestino.ingresar(posteAgarramos.sacar());
        
        // + 1 movimiento
        contadorMovimientos++;

        // Mover los (n-1) discos del poste auxiliar al poste destino, usando el poste que agarramos el disco como auxiliar ( esto ya que cambiamos el origen del disco menor por el del aux) 
        desHanoi(disco - 1, Aux, Destino, Agarramos, posteAux, posteDestino, posteAgarramos);
    }
}

void SolHanoi(int nDiscos){
    //inicializamos los postes 
    poste poste1, poste2, poste3;
    // Rellenamos el poste 1 de discos
    for (int iDisco = nDiscos; iDisco > 0; --iDisco)
    {
        poste1.ingresar(iDisco);
    }
    
    //desarrollamos con recursividad
    desHanoi(nDiscos, 1, 2, 3, poste1, poste2, poste3);
}

int main()
{
    int nDiscos;
    cout<<"Cuantos discos debe poseer la torre: ";
    cin>> nDiscos;

    SolHanoi(nDiscos);

    int Msol =  pow(2, nDiscos)-1;
    cout<<"\nnumero de movimientos "<<contadorMovimientos<< endl;
    cout<<"mejor solucion (2^("<<nDiscos<<")) - 1: "<<Msol<< endl;
    return 0;
}