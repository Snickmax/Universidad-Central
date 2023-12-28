/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    int f0 = 0,f1 = 1, fn, i, n;
    printf("-----Serie de Fibonacci-----\n\n  fn = f(n-1) + f(n-2)\n  f0 = 0\n  f1 = 1\n\nIngrese el valor de n:");
    scanf("%i", &n);
    if (n == 0) printf("0\n\nUltimo valor de la serie: %i",f0);    
    else if (n == 1) printf("0 1\n\nUltimo valor de la serie: %i",f1);      
    else 
    {
        printf("%i %i",f0,f1);
        for (i = 2; i < n; ++i)
        {
            fn = f0 + f1; 
            printf(" %i",fn);    
            f0=f1;    
            f1=fn; 
        }
        printf("\n\nUltimo valor de la serie: %i",fn);   
    }
    return 0;
}
