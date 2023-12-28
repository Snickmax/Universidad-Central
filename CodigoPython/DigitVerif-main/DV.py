from itertools import cycle

def DV(rut):
    reversed_digits = map(int, reversed(str(rut)))
    factors = cycle(range(2, 8))
    s = sum(d * f for d, f in zip(reversed_digits, factors))
    return (-s) % 11
    
rut = input("RUT: ")
print(f"{rut}-{DV(rut)}")
