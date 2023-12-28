/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#define N 8
#define n (N+1)
void saltoCaballo(int i, int x, int y, int* exito);
void escribeTablero();
int tablero [n][n];
int d[8][2] = {{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};

int main()
{
    int x, y;
    int solucion;
    int i, j;
    do {
        printf("\nCoordenadas iniciales del caballo ");
        scanf("%d %d", &x , &y);
    } while ((x < 1) || (x > N) || 
             (y < 1) || (y > N));
                            /* valores iniciales del tablero*/
    for (i = 1 ; i <= N ; i++)
    {
        for (j = 1 ; j <= N; j++)
        {
            tablero[i][j] = 0 ;
        }
    }
    tablero[x][y] = 1 ;
        /* Llamada con coordenadas iniciales y primer salto */
    solucion = 0;
    saltoCaballo(2, x, y, &solucion);
    if (solucion)
    {
        puts("\n\tEl problema tiene solucion:\n");
        escribeTablero();
    }
    else
    {
        puts("¡¡ No se ha encontrado solucion al problema !!");
    }
    return 0;
}

void saltoCaballo(int i, int x, int y, int* exito)
{
    int nx, ny;
    int k;
    *exito = 0;
    k = 0;      /* inicializa el conjunto posible de movimientos*/
    do {
        k++;
        nx = x+d[k-1][0];
        ny = y+d[k-1][1];
                /* determina si nuevas coordenadas son aceptavles */
        if ((nx >= 1) && (nx <= N)&&
            (ny >= 1) && (ny <= N)&&
            (tablero[nx][ny] == 0))
        {
            tablero[nx][ny] = i;            /*anota movimientos*/
            if (i < N*N)
            {
                saltoCaballo(i+1, nx, ny, exito);
                        /* se analiza si se ha completado la solucion */
                if (!(*exito))
                {                   /* no se alcanzo la solucion */
                    tablero[nx][ny] = 0;        /*se borra anotacion*/
                }
            }
            else
            {
                *exito = 1;         /* cabballo ha cubiero el tablero*/
            }
        }
    } while ((k < 8) && !(*exito));
}

void escribeTablero()
{
    int i, j;
    for (i = 1; i <= N; i++)
    {
        for (j = 1; j <= N; j++)
        {
            printf("%d %c",tablero[i][j], (j < N ? ' ': '\n'));
        }
    }
}


