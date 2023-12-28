/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h> 

int main()
{
    int a;
    printf("Calculadora de area y perimetro de un cuadrado con lados a.\n\nIngrese el lado:\n");
    scanf("%d", &a);
    int r_a = a*a;
    int r_p = a*4;
    printf("\nResultado perimetro: %d",r_p);
    printf("\nResultado area: %d",r_a);
    return 0;
}



