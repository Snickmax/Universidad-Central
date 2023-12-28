/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <cmath> //para usar trunc
#define N 17

using namespace std;

void BusquedaBinaria(int x, int a[], int n){
    int i = 0;
    int j = n;
    
    while (i < j){
        int m = ((i+j)/2);
        
        if (x > a[m]){
            i = m + 1;
        }
        else{
            j = m;
        }
    }
    if (x == a[i]){
        cout << i+1<<endl;
    }
    else{
        cout << 0<<endl;
    }
};

int main()
{
    int x = 20;
    int a[N] = {1,2,3,4,5,6,7,8,10,12,13,15,16,18,19,20,22};
    
    BusquedaBinaria(x, a, N);
    return 0;
}