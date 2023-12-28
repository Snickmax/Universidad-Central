from tkinter import *

ventana = Tk()
ventana.title("Calculadora")
ventana.resizable(0,0)

################################################################################################

#  Obtenemos el largo y  ancho de la pantalla
wtotal = ventana.winfo_screenwidth()
htotal = ventana.winfo_screenheight()
#  Guardamos el largo y alto de la ventana
wventana = 300
hventana = 300

#  Aplicamos la siguiente formula para calcular donde debería posicionarse
pwidth = round(wtotal/2-wventana/2)
pheight = round(htotal/2-hventana/2)

#  Se lo aplicamos a la geometría de la ventana
ventana.geometry(str(wventana)+"x"+str(hventana)+"+"+str(pwidth)+"+"+str(pheight))

################################################################################################

eText = Entry(ventana, font = "Calibri 20")
eText.grid(row = 0, column = 0, columnspan = 4, padx = 5, pady = 4)

#creo las funciones
def insertar(valor):
    if eText.get() == 'Syntax Error':
        Borrar()
    eText.insert(END, valor)

def Borrar():
    eText.delete(0,END)

def calcular():

    ecuacion = eText.get()

    if '%' in eText.get():
        ecuacion = ecuacion.replace('%','/100')
        
    try:
        resultado = eval(ecuacion)
    except:
        resultado = 'Syntax Error'
    
    Borrar()
    eText.insert(END,resultado)
    

    
#creo los botones
num_1 = Button(ventana, text = '1', width = 5, height = 2, command = lambda: insertar(1))
num_2 = Button(ventana, text = '2', width = 5, height = 2, command = lambda: insertar(2))
num_3 = Button(ventana, text = '3', width = 5, height = 2, command = lambda: insertar(3))
num_4 = Button(ventana, text = '4', width = 5, height = 2, command = lambda: insertar(4))
num_5 = Button(ventana, text = '5', width = 5, height = 2, command = lambda: insertar(5))
num_6 = Button(ventana, text = '6', width = 5, height = 2, command = lambda: insertar(6))
num_7 = Button(ventana, text = '7', width = 5, height = 2, command = lambda: insertar(7))
num_8 = Button(ventana, text = '8', width = 5, height = 2, command = lambda: insertar(8))
num_9 = Button(ventana, text = '9', width = 5, height = 2, command = lambda: insertar(9))
num_0 = Button(ventana, text = '0', width = 5, height = 2, command = lambda: insertar(0))

AC = Button(ventana, text = 'AC', width = 5, height = 2, command = lambda: Borrar())
parentesis_1 = Button(ventana, text = '(', width = 5, height = 2, command = lambda: insertar('('))
parentesis_2 = Button(ventana, text = ')', width = 5, height = 2, command = lambda: insertar(')'))
punto = Button(ventana, text = '.', width = 5, height = 2, command = lambda: insertar('.'))
porcent = Button(ventana, text = '%', width = 5, height = 2, command = lambda: insertar('%'))

dividir = Button(ventana, text = '/', width = 5, height = 2, command = lambda: insertar('/'))
multiplicar  = Button(ventana, text = 'X', width = 5, height = 2, command = lambda: insertar('*'))
suma = Button(ventana, text = '+', width = 5, height = 2, command = lambda: insertar('+'))
resta = Button(ventana, text = '-', width = 5, height = 2, command = lambda: insertar('-'))
igual = Button(ventana, text = '=', width = 5, height = 2, command = lambda: calcular())

# Agrego los botones
#columna 1
parentesis_1.grid(row = 1, column = 0, padx = 5, pady = 5)
num_7.grid(row = 2, column = 0, padx = 5, pady = 5)
num_4.grid(row = 3, column = 0, padx = 5, pady = 5)
num_1.grid(row = 4, column = 0, padx = 5, pady = 5)
num_0.grid(row = 5, column = 0, padx = 5, pady = 5)

#columna 2
parentesis_2.grid(row = 1, column = 1, padx = 5, pady = 5)
num_8.grid(row = 2, column = 1, padx = 5, pady = 5)
num_5.grid(row = 3, column = 1, padx = 5, pady = 5)
num_2.grid(row = 4, column = 1, padx = 5, pady = 5)
punto.grid(row = 5, column = 1, padx = 5, pady = 5)

#columna 3
porcent.grid(row = 1, column = 2, padx = 5, pady = 5)
num_9.grid(row = 2, column = 2, padx = 5, pady = 5)
num_6.grid(row = 3, column = 2, padx = 5, pady = 5)
num_3.grid(row = 4, column = 2, padx = 5, pady = 5)
igual.grid(row = 5, column = 2, padx = 5, pady = 5)

#columna 4
AC.grid(row = 1, column = 3, padx = 5, pady = 5) 
dividir.grid(row = 2, column = 3, padx = 5, pady = 5)
multiplicar .grid(row = 3, column = 3, padx = 5, pady = 5)
resta.grid(row = 4, column = 3, padx = 5, pady = 5)
suma.grid(row = 5, column = 3, padx = 5, pady = 5)

ventana.mainloop()