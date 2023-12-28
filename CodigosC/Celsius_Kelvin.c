/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <math.h>
#define CaK 273.15 //defino 1 celsius en kelvin

int main()
{
    float Celsius, Kelvin;
    printf("Ingrese un grado Celsius:\n");
    scanf("%f", &Celsius);
    Kelvin = Celsius+CaK ;
    printf("%f grados Celsius son %f grados Kelvin ",Celsius,Kelvin);
    return 0;
}

