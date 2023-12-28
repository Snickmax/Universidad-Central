/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#define N 8

using namespace std;


int MAX(int a[N], int n){
    int max = a[0];
    for (int i = 1; i < n; i ++){
        if (max < a[i]){
            max = a[i];
        }
    }
    return max;
}

int main()
{   
    int a[N] = {1,2,5,3,6,4,8,7};
    
    cout<<MAX(a ,N )<< endl;
    
    return 0;
}