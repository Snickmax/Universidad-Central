/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <cstring>

using namespace std;

int par (int n);
int impar (int n);

int
par (int n)
{
  if (n == 0)
    {
      return 1;
    }
  else
    {
      return impar (n - 1);
    }
}

int
impar (int n)
{
  if (n == 0)
    {
      return 0;
    }
  else
    {
      return par (n - 1);
    }
}


int
main ()
{
  int n;
  char rslt[12];
  do
    {
      cout << "introduzca un numero: ";
      cin >> n;
    }
  while (n < 0);

  if (par (n))
    {
      strcpy (rslt, " es par");
    }
  else
    {
      strcpy (rslt, " es impar");
    }
  cout << "\t" << n << rslt;
  return 0;
}
