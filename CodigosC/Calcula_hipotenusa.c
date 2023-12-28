/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <math.h>

int main()
{
    float hipotenusa,cateto_a,cateto_b;
    printf("ingrese los valores del cateto a:\n");
    scanf("%f",&cateto_a);
    printf("ingrese los valores del cateto b:\n");
    scanf("%f",&cateto_b);
    hipotenusa = sqrt(pow(cateto_a,2)+pow(cateto_b,2));
    printf("la hipotenusa tiene el valor de: %f",hipotenusa);
    return 0;
}

