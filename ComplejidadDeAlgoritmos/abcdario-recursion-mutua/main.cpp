/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;

void funcionA(char c);
void funcionB(char c);

void funcionA(char c){
    if ( c > 'A'){
        funcionB(c);
    }
    cout<<c;
}

void funcionB(char c){
    funcionA(--c);
}
int main()
{
    cout<<endl;
    funcionA('Z');
    cout<<endl;

    return 0;
}