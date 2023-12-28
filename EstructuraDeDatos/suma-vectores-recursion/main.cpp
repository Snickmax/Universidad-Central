/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;
int v3[10];

int contador = 0;

void sumaVector(int* v1, int* v2, int n){

    v3[n-1] = *v1 + *v2;

    if (n!=0)
        sumaVector(v1-1, v2-1 , n-1);

}

int main()
{
    int n = 10;
    int v1[10] = {1,2,3,4,5,6,7,8,9,10};
    int v2[10] = {1,2,3,4,5,6,7,8,9,10};
    
    sumaVector(&v1[n-1] ,&v2[n-1] ,10);
    
    for (int i; i < n; i++){
        cout<< v3[i]<<" ";
    }

    return 0;
}