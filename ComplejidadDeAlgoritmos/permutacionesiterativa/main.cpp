/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;

void generateI(int n, string A){
    string c;

    for (int i = 0; i < n; i += 1){
        c[i] = 0;
    }

    cout << A << endl;
    
    int i = 0;
    
    while (i < n){
        if  (c[i] < i){
            if (i%2 == 0){
                swap(A[0], A[i]);
            }
            else{
                swap(A[c[i]], A[i]);
            }
            
            cout << A << endl;
            
            c[i] += 1;
            i = 0;
        }
        else{
            c[i] = 0;
            i ++;
        }
    }
}

int main()
{
    string text;
    
    cout << "Ingrese la palabra que desea Permutar: "; cin >> text;
    
    // text.length() devuelve la longitud de la cadena especificada como el número de caracteres.
    
    generateR(text.length(), text);
    return 0;
}