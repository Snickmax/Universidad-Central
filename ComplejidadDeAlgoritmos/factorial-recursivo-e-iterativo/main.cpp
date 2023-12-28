/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;

long factousI(int n){
    long f = 1;
    for(int ctr = n; ctr >= 1; ctr--){
        f *= ctr;
    }
    return f;
}

long factousR(int n){
    if(n == 0){
        return 1;
    }
    else{
        return n*factousR(n-1);
    }
}

int main()
{
    int n = 3;
    cout << factousR(n) << endl;
    cout << factousI(n) << endl;
}
