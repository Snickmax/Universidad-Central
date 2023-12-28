#include <stdio.h>
#include <iostream>

using namespace std;

int fibonacci(int fib, int prim, int seg){
    int n = prim+seg;
    if((fib - 3 == 0)){
        return n;
    }
    cout << n << endl;
    return  fibonacci(fib-1,seg,n);
}

int main()
{
    cout <<"-----Serie de Fibonacci-----\n\n  fn = f(n-1) + f(n-2)\n  f0 = 0\n  f1 = 1\n\nIngrese el valor de n: ";
    int n;
    cin >> n;
    
    cout<< 0 << endl << 1<< endl;
    int resp = fibonacci(n+1,0,1);
    cout<<"Ultimo valor de la serie: "<<resp<<endl;
    return 0;
}
