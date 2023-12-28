'''

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

'''

def ord_burbuja(arreglo):
    n = len(arreglo)
    for i in range(n-1):
        print(f"{i+1} Recorrido (i = {i})")
        for j in range(n-1-i):
            print("j =",j)
            if arreglo[j] > arreglo[j+1]:
                arreglo[j], arreglo[j+1] = arreglo[j+1],arreglo[j]

def burbuja_optimus(arreglo):
    n = len(arreglo)
    
    for i in range(n-1):
        intercambio = False
        
        print(f"{i+1} Recorrido (i = {i})")
        for j in range(n-1-i):
            print("j =",j)
            if arreglo[j] > arreglo[j+1]:
                arreglo[j], arreglo[j+1] = arreglo[j+1],arreglo[j]
                intercambio = True
        
        if intercambio == False:
            break
        
elementos = [8, 3, 1, 19, 14]
burbuja_optimus(elementos)
print (elementos)
