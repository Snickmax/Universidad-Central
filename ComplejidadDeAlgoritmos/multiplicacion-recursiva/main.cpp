/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;

int iterativo(int a, int b){
    int R;
    for(int ctr = b; ctr >= 1; ctr--){
        R += a;
    }
    return R;
}

int recursivo(int a, int b){
    if (b == 1){
        return a;
    }
    else{
        return a+recursivo(a,b-1);
    }
}

int main()
{
    int a = 7;
    int b = 0;
    
    cout << iterativo(a , b) << endl;
    cout << recursivo(a , b) << endl;
    return 0;
}