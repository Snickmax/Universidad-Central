/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <string.h>
#define bit 30
int opc = 0,num, n, i;
const char* cero = "0";
const char* uno = "1";

int main()
{
    while (opc == 0)
    {
        n = 0; 
        char binario[bit] = "";
        printf("\n----- Decimal a binario-----\n\n Ingrese un numero decimal entero:");
        scanf("%i", &num);
        for(i = 0; i < num; i = 0)
        {
            (num%2 == 0) ? strcat(binario, cero) : strcat(binario, uno);
            num = num/2;
            n++;
        }
        do
        {
            printf("%c",binario[n]);
            n--;
        } while (n >= 0);
        printf("\n\nIngrese 0 para continuar:");
        scanf("%i", &opc);
    }
    return 0;
}


