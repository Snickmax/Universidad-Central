/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <iostream>

using namespace std;

int exponencial(int ex){
    int n = 2;
    int m = 1;
    if(ex >1){
        m = exponencial(ex-1);
    }
    n = m*n;
    return n;
};

int main()
{
    cout << "Ingrese exponencial para 2"<<endl;
    int m;
    cin >> m;
    int n = exponencial(m);
    cout<<"2 elevado a "<<m<<" es:"<<n<<endl;
    return 0;
}