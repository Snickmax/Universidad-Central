/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#define PI 3.14159

int main()
{
    int r;
    printf("Calculadora de area y perimetro de un cudrado con lados a.\n\nIngrese el radio:\n");
    scanf("%d", &r);
    int r_a = 2*PI*r;
    int r_p = PI*r*r;
    printf("\nResultado perimetro: %d",r_p);
    printf("\nResultado area: %d",r_a);
    return 0;
}


