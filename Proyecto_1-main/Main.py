import tkinter
from tkinter import StringVar, messagebox, Text

""" Integrantes:
    
    - Víctor Ibarra
    - Juan Otazo
    - Sergio Meneses
"""

def ventanaPropiedades():
    ventanaProp = messagebox.showinfo("Información","Propiedades:\n    Serie:\n             1. Req = R1 + R2 + ... + Rn\n             2. Ieq = I1 = I2 = ... = In\n             3. V = V(R1) + V(R2) + ... + V(Rn) \n\n    Paralelo:\n             1. Req = ( 1/R1 + 1/R2 + ... + 1/Rn )^(-1)\n             2. Ieq = I1 + I2 + ... + In\n             3.V = V(R1) = V(R2) = ... = V(Rn)\n\n    Ley de Ohm:\n             1. V = Req x Ieq\n             2. Req = V/Ieq\n             3. Ieq = V/Req", parent = ventana1)

def venterror():
    resps.config(state = "normal")
    resps.delete("0.0","end")
    resps.insert("0.0",  "\nDesarrollo:\n\n     Error al ingresar valores")
    resps.config(state = "disabled")
    resps.config(state = "normal")
    resps.delete("0.0","end")
    resps.insert("0.0",  "\nDesarrollo:\n\n     Error al ingresar valores")
    resps.config(state = "disabled")
    resps.config(state = "normal")
    resps.delete("0.0","end")
    resps.insert("0.0",  "\nDesarrollo:\n\n     Error al ingresar valores")
    resps.config(state = "disabled")
    error = messagebox.showerror("ERROR", "Error al ingresar valores", parent = ventana1)

def desbloqueo():
    R1s.config(state = "normal")
    R2s.config(state = "normal")
    R3s.config(state = "normal")
    R4s.config(state = "normal")
    Reqs.config(state = "normal")
    Is.config(state = "normal")
    I1s.config(state = "normal")
    I2s.config(state = "normal")
    vs.config(state = "normal")
    respuesta.config(state = "normal")

    R1s.config(highlightbackground = "white")
    R2s.config(highlightbackground = "white")
    R3s.config(highlightbackground = "white")
    R4s.config(highlightbackground = "white")
    Reqs.config(highlightbackground = "white")
    Is.config(highlightbackground = "white")
    I1s.config(highlightbackground = "white")
    I2s.config(highlightbackground = "white")
    vs.config(highlightbackground = "white")
    respuesta.config(highlightbackground = "white")

def bloqueo():
    R1s.config(state = "disable")
    R2s.config(state = "disable")
    R3s.config(state = "disable")
    R4s.config(state = "disable")
    Reqs.config(state = "disable")
    Is.config(state = "disable")
    I1s.config(state = "disable")
    I2s.config(state = "disable")
    vs.config(state = "disable")
    respuesta.config(state = "disable")

def Leyohm(V,Req,Ieq):
    if ( V != '' and Req != '' and Ieq == ''):
        Req = float(Req)
        V = float(V)
        if(Req == 0 and V >= 0):
            Req = str(Req)
            V = str(V)
            resps.config(state = "normal")
            resps.insert("end", "\n\nIeq = V/Req\nIeq = ("+V+")/("+Req+")\nIeq = ∞"+" A")
            resps.config(state = "disabled")
        elif(Req > 0 and V >= 0):
            Ieq = round(V/Req,3)
            Is.config(highlightbackground = "red")
            entry_ieq.set(Ieq)
            Ieq = str(Ieq)
            Req = str(Req)
            V = str(V)
            resps.config(state = "normal")
            resps.insert("end", "\n\nIeq = V/Req\nIeq = ("+V+")/("+Req+")\nIeq = "+Ieq+" A")
            resps.config(state = "disabled")
            return float(Ieq)
        else:
            venterror()
    elif ( Ieq != '' and Req != '' and V == ''):
            Ieq = float(Ieq)
            Req = float(Req)
            if(Req >= 0 and Ieq >= 0):
                V = round(Ieq*Req,3)
                vs.config(highlightbackground = "red")
                entry_v.set(V)
                V = str(V)
                Req = str(Req)
                Ieq = str(Ieq)
                resps.config(state = "normal")
                resps.insert("end", "\n\nV = Ieq*Req\nV = ("+Ieq+")*("+Req+")\nV = "+V+" V")
                resps.config(state = "disabled")
                return float(V)
            else:
                venterror()
    elif ( V != '' and Ieq != '' and Req == ''):
            Ieq = float(Ieq)
            V = float(V)
            if(Ieq == 0 and V >= 0):
                Ieq = str(Ieq)
                V = str(V)
                resps.config(state = "normal")
                resps.insert("end", "\n\nReq = V/Ieq\nReq = ("+V+")/("+Ieq+")\nReq = ∞"+" Ω")
                resps.config(state = "disabled")
            elif(Ieq > 0 and V >=0 ):
                Req = round(V/Ieq,3)
                Reqs.config(highlightbackground = "red")
                entry_req.set(Req)
                Req = str(Req)
                Ieq = str(Ieq)
                V = str(V)
                resps.config(state = "normal")
                resps.insert("end", "\n\nReq = V/Ieq\nReq = ("+V+")/("+Ieq+")\nReq = "+Req+" Ω")
                resps.config(state = "disabled")
                return float(Ieq)
            else:
                venterror()
    elif ( (V != '' and Ieq != '' and Req != '') or (V != '' and Ieq == '' and Req == '') or (V == '' and Ieq != '' and Req == '')):
        error = messagebox.showerror("ERROR", "No se cumple la ley de ohm", parent = ventana1) 

def Desarrolloh():
    R1 = entry_r1.get()
    R2 = entry_r2.get()
    R3 = entry_r3.get()
    R4 = entry_r4.get()
    I1 = entry_i1.get()
    I2 = entry_i2.get()
    V = entry_v.get()
    Ieq = entry_ieq.get()
    Req = entry_req.get()
    R23 = 0

    if (R1 != '' and R2 != '' and  R3 != '' and R4 != '' and Req == ''):
        # Desarrollo
        Req = 0
        R1 = float(R1)
        R2 = float(R2)
        R3 = float(R3)
        R4 = float(R4)
        resps.config(state = "normal")
        R23 = round(((1/R2)+(1/R3))**(-1),3)
        if ( R1 > 0 and R2 > 0 and R3 > 0 and R4 > 0):
            Req = str(round(R23+R1+R4,3))
        if(float(Req)>0 and (I1 or I2) == ""):
            Reqs.config(highlightbackground = "red")
            entry_req.set(Req)
            # impresion
            resps.delete("0.0","end")
            resps.insert("0.0", "\nDesarrollo:\n\nR23={(1/R2 + 1/R3)^(-1)}\nR23={(1/"+str(R2)+" + 1/"+str(R3)+")^(-1)}\nR23="+str(R23)+" Ω\n\nReq = R1+R23+R4\nReq = "+str(R1)+"+"+str(R23)+"+"+str(R4)+"\nReq = "+str(Req)+" Ω")
            resps.config(state = "disabled")
            Req = float(Req)

            Ieq1 = Leyohm(V,Req,Ieq)
            R2e = R2
            R3e = R3
            intensidades_hibrido(Ieq1,R2e,R3e)
            bloqueo()
        else:
            venterror()
    elif (R1 != '' and R2 == '' and  R3 == '' and R4 != '' and Req != ''):
        R1 = float(R1)
        Req = float(Req)
        R2 = 0
        R3 = 0
        R4 = float(R4)
        R14eq = round(Req-R1-R4,3)
        resps.config(state = "normal")
        R23 = round(R14eq*2,3)
        if (R1 > 0 and R4 > 0 and Req > 0 ):
            R2 = R23
            R3 = R23

        if(float(R2)>0 and (I1 or I2)=="" and V == ""):
            R2s.config(highlightbackground = "red")
            entry_r2.set(R2)
            R3s.config(highlightbackground = "red")
            entry_r3.set(R3)
            # impresion
            resps.delete("0.0","end")
            resps.insert("0.0", "\nDesarrollo:\n\nR23=(Req-R1-R4)\nR23=("+str(Req)+" - "+str(R1)+" - "+str(R4)+")\nR23 = "+str(R14eq)+"\n\nR2 = R3 = (R23)^(2)\nR2 = R3 = ("+str(R14eq)+")^(2) \nR2 = R3 = "+str(R23)+"Ω")
            resps.config(state = "disabled")
            R1 = float(R1)

            bloqueo()
        elif(float(R2)>0 and (I1 or I2)==""):
            R2s.config(highlightbackground = "red")
            entry_r2.set(R2)
            R3s.config(highlightbackground = "red")
            entry_r3.set(R3)
            # impresion
            resps.delete("0.0","end")
            resps.insert("0.0", "\nDesarrollo:\n\nR23=(Req-R1-R4)\nR23=("+str(Req)+" - "+str(R1)+" - "+str(R4)+")\n\nR2 = R3 = 1/(R23)^(2)\nR2 = R3 = 1/"+str(R23)+" Ω")
            resps.config(state = "disabled")
            R1 = float(R1)

            Ieq1 = Leyohm(V,Req,Ieq)
            R2e = R2
            R3e = R3
            intensidades_hibrido(Ieq1,R2e,R3e)
            bloqueo()
        else:
            venterror()       
    elif (R1 == '' and R2 != '' and  R3 != '' and R4 != '' and Req != ''):
        # Desarrollo
        R1 = 0
        Req = float(Req)
        R2 = float(R2)
        R3 = float(R3)
        R4 = float(R4)
        resps.config(state = "normal")
        R23 = round(((1/R2)+(1/R3))**(-1),3)
        if (R2 > 0 and R3 > 0 and R4 > 0 ):
            R1 = str(round(Req-R23-R4,3))

        if(float(R1)>0 and (I1 or I2)=="" and V == ""):
            R1s.config(highlightbackground = "red")
            entry_r1.set(R1)
            # impresion
            resps.delete("0.0","end")
            resps.insert("0.0", "\nDesarrollo:\n\nR23={(1/R2 + 1/R3)^(-1)}\nR23={(1/"+str(R2)+" + 1/"+str(R3)+")^(-1)}\nR23="+str(R23)+" Ω\n\nR1 = Req-R23-R4\nR1 = "+str(Req)+"-"+str(R23)+"-"+str(R4)+"\nR1 = "+str(R1)+" Ω")
            resps.config(state = "disabled")
            R1 = float(R1)

            bloqueo()
        elif(float(R1)>0 and (I1 or I2)==""):
            R1s.config(highlightbackground = "red")
            entry_r1.set(R1)
            # impresion
            resps.delete("0.0","end")
            resps.insert("0.0", "\nDesarrollo:\n\nR23={(1/R2 + 1/R3)^(-1)}\nR23={(1/"+str(R2)+" + 1/"+str(R3)+")^(-1)}\nR23="+str(R23)+" Ω\n\nR1 = Req-R23-R4\nR1 = "+str(Req)+"-"+str(R23)+"-"+str(R4)+"\nR1 = "+str(R1)+" Ω")
            resps.config(state = "disabled")
            R1 = float(R1)

            Ieq1 = Leyohm(V,Req,Ieq)
            R2e = R2
            R3e = R3
            intensidades_hibrido(Ieq1,R2e,R3e)
            bloqueo()
        else:
            venterror()
    elif (R1 != '' and R2 == '' and  R3 != '' and R4 != '' and Req != ''):
        # Desarrollo
        R2 = 0
        Req = float(Req)
        R1 = float(R1)
        R3 = float(R3)
        R4 = float(R4)
        R14eq =  Req-R1-R4
        if (R1 > 0 and R3 > 0 and R4 > 0 and R14eq > 0 and R14eq < R3):
            R2 = str(round((((R14eq)**(-1))-(1/R3))**(-1),3))
        resps.config(state = "normal")
        if(float(R2)>0 and (I1 or I2)=="" and V == ""):
            R2s.config(highlightbackground = "red")
            entry_r2.set(R2)
            resps.delete("0.0","end")
            resps.insert("0.0", "\nDesarrollo:\n\nR2 = {(Req-R1-R4)^(-1)-1/R3}^(-1)\nR2 = {("+entry_req.get()+"-"+entry_r1.get()+"-"+entry_r4.get()+")^(-1)-(1/"+entry_r3.get()+")}^(-1)\nR2 = {("+str(R14eq)+")^(-1)-(1/"+entry_r3.get()+")}^(-1)\nR2 = {(1/"+str(R14eq)+")-(1/"+entry_r3.get()+")}^(-1)\nR2 = "+R2+" Ω")
            resps.config(state = "disabled")
            R2 = float(R2)
            bloqueo()
        elif(float(R2)>0 and (I1 or I2)==""):
            # impresion
            R2s.config(highlightbackground = "red")
            entry_r2.set(R2)
            resps.delete("0.0","end")
            resps.insert("0.0", "\nDesarrollo:\n\nR2 = {(Req-R1-R4)^(-1)-1/R3}^(-1)\nR2 = {("+entry_req.get()+"-"+entry_r1.get()+"-"+entry_r4.get()+")^(-1)-(1/"+entry_r3.get()+")}^(-1)\nR2 = {("+str(R14eq)+")^(-1)-(1/"+entry_r3.get()+")}^(-1)\nR2 = {(1/"+str(R14eq)+")-(1/"+entry_r3.get()+")}^(-1)\nR2 = "+R2+" Ω")
            resps.config(state = "disabled")
            R2 = float(R2)

            Ieq1 = Leyohm(V,Req,Ieq)
            R2e = R2
            R3e = R3
            intensidades_hibrido(Ieq1,R2e,R3e)
            bloqueo()
        else:
            venterror()
            ventanaesp = messagebox.showinfo("Recordatorio","El Req esta limitado por los siguientes parámetros: \n\n1. R1 + R4 < Req\n\n2. Req - R1 - R4 < R3", parent = ventana1)

    elif (R1 != '' and R2 != '' and  R3 == '' and R4 != '' and Req != ''):
        # Desarrollo
        R3 = 0
        Req = float(Req)
        R1 = float(R1)
        R2 = float(R2)
        R4 = float(R4)
        R14eq = Req-R1-R4
        resps.config(state = "normal")
        if (R2 > 0 and R1 > 0 and R4 > 0 and R14eq > 0 and R14eq < R2 ):
            R3 = str(round(((R14eq)**(-1)-1/R2)**(-1),3))
        if(float(R3)>0 and (I1 or I2)=="" and V == ""):
            R3s.config(highlightbackground = "red")
            entry_r3.set(R3)
            resps.delete("0.0","end")
            resps.insert("0.0", "\nDesarrollo:\n\nR3 = {(Req-R1-R4)^(-1)-1/R2}^(-1)\nR3 = {("+entry_req.get()+"-"+entry_r1.get()+"-"+entry_r4.get()+")^(-1)-1/"+entry_r2.get()+"}^(-1)\nR3 = {("+str(R14eq)+")^(-1)-(1/"+entry_r2.get()+")}^(-1)\nR3 = {(1/"+str(R14eq)+")-(1/"+entry_r2.get()+")}^(-1)\nR3 = "+R3+" Ω")
            resps.config(state = "disabled")
            R3 = float(R3)
            bloqueo()
        elif(float(R3)>0 and (I1 or I2)==""):
            R3s.config(highlightbackground = "red")
            entry_r3.set(R3)
            # impresion
            resps.delete("0.0","end")
            resps.insert("0.0", "\nDesarrollo:\n\nR3 = {(Req-R1-R4)^(-1)-1/R2}^(-1)\nR3 = {("+entry_req.get()+"-"+entry_r1.get()+"-"+entry_r4.get()+")^(-1)-1/"+entry_r2.get()+"}^(-1)\nR3 = {("+str(R14eq)+")^(-1)-(1/"+entry_r2.get()+")}^(-1)\nR3 = {(1/"+str(R14eq)+")-(1/"+entry_r2.get()+")}^(-1)\nR3 = "+R3+" Ω")
            R3 = float(R3)

            Ieq1 = Leyohm(V,Req,Ieq)
            R2e = R2
            R3e = R3
            intensidades_hibrido(Ieq1,R2e,R3e)
            bloqueo()
        else:
            venterror()
            ventanaesp = messagebox.showinfo("Recordatorio","El Req esta limitado por los siguientes parámetros: \n\n1. R1 + R4 < Req\n\n2. Req - R1 - R4 < R2", parent = ventana1)
    elif (R1 != '' and R2 != '' and  R3 != '' and R4 == '' and Req != ''):
        # Desarrollo.
        R4 = 0
        Req = float(Req)
        R2 = float(R2)
        R3 = float(R3)
        R1 = float(R1)
        resps.config(state = "normal")
        R23 = round(((1/R2)+(1/R3))**(-1),3)
        if (R2 > 0 and R3 > 0 and R1 > 0 ):
            R4 = str(round(Req-R23-R1,3))
        if(float(R4)>0 and (I1 or I2)=="" and V == ""):
            R4s.config(highlightbackground = "red")
            entry_r4.set(R4)
            resps.delete("0.0","end")
            resps.insert("0.0", "\nDesarrollo:\n\nR23={(1/R2 + 1/R3)^(-1)}\nR23={(1/"+str(R2)+" + 1/"+str(R3)+")^(-1)}\nR23="+str(R23)+" Ω\n\nR4 = Req-R1-R23\nR4 = "+str(Req)+"-"+str(R1)+"-"+str(R23)+"\nR4 = "+str(R4)+" Ω")
            resps.config(state = "disabled")
            R4 = float(R4)
            bloqueo()
        elif(float(R4)>0 and (I1 or I2)==""):
            R4s.config(highlightbackground = "red")
            entry_r4.set(R4)
            # impresion
            resps.delete("0.0","end")
            resps.insert("0.0", "\nDesarrollo:\n\nR23={(1/R2 + 1/R3)^(-1)}\nR23={(1/"+str(R2)+" + 1/"+str(R3)+")^(-1)}\nR23="+str(R23)+" Ω\n\nR4 = Req-R1-R23\nR4 = "+str(Req)+"-"+str(R1)+"-"+str(R23)+"\nR4 = "+str(R4)+" Ω")
            resps.config(state = "disabled")
            R4 = float(R4)

            Ieq1 = Leyohm(V,Req,Ieq)
            R2e = R2
            R3e = R3
            intensidades_hibrido(Ieq1,R2e,R3e)
            bloqueo()
        else:
            venterror()
    elif(I1 =="" and I2 !="" and Ieq !="" and V != ""):
        if(float(Ieq)>float(I2) and float(Ieq)>0 and float(I2)>0):
            R2e = R2
            R3e = R3
            Ieq1 = intensidades_hibrido(Ieq,R2e,R3e)
            Leyohm(V,Req,Ieq1)
            bloqueo()
        else:
            venterror()
    elif(I1 =="" and I2 !=""and Ieq !="" ):
        if(float(Ieq)>float(I2) and float(Ieq)>0 and float(I2)>0):
            Ieq1 = Ieq
            R2e = R2
            R3e = R3
            intensidades_hibrido(Ieq1,R2e,R3e)
            bloqueo()
        else:
            venterror()
    elif(I1 !="" and I2 =="" and Ieq !="" and V != ""):
        if(float(Ieq)>float(I1) and float(Ieq)>0 and float(I1)>0):
            R2e = R2
            R3e = R3
            Ieq1 = intensidades_hibrido(Ieq,R2e,R3e)
            Leyohm(V,Req,Ieq1)
            bloqueo()
        else:
            venterror()
    elif(I1 !="" and I2 =="" and Ieq !=""):
        if(float(Ieq)>float(I1) and float(Ieq)>0 and float(I1)>0):
            Ieq1 = Ieq
            R2e = R2
            R3e = R3
            intensidades_hibrido(Ieq1,R2e,R3e)
            bloqueo()
        else:
            venterror()
    elif(I1 !="" and I2 !="" and Ieq =="" and V != ""):
        if(float(I2)>0 and float(I1)>0):
            R2e = R2
            R3e = R3
            Ieq1 = intensidades_hibrido(Ieq,R2e,R3e)
            Leyohm(V,Req,Ieq1)
            bloqueo()
        else:
            venterror()
    elif(I1 !="" and I2 !="" and Ieq ==""):
        if(float(I2)>0 and float(I1)>0):
            Ieq1 = Leyohm(V,Req,Ieq)
            R2e = R2
            R3e = R3
            intensidades_hibrido(Ieq1,R2e,R3e)
            bloqueo()
        else:
            venterror()
    elif(V !="" and Req !=""and Ieq =="" and R2 != R23 and R3 != R23):
        if((float(V) or float(Req) )>0):
            resps.config(state = "normal")
            resps.delete("0.0","end")
            resps.insert("0.0", "\nDesarrollo:")
            Ieq1 = Leyohm(V,Req,Ieq)
            R2e = R2
            R3e = R3
            intensidades_hibrido(Ieq1,R2e,R3e)
            bloqueo()
        else:
            venterror()
    elif(V !="" and Ieq !=""and Req ==""):
        if((float(V) or float(Ieq) )>0):
            resps.config(state = "normal")
            resps.delete("0.0","end")
            resps.insert("0.0", "\nDesarrollo:")
            Ieq1 = Leyohm(V,Req,Ieq)
            R2e = R2
            R3e = R3
            intensidades_hibrido(Ieq1,R2e,R3e)
            bloqueo()
        else:
            venterror()
    elif(Req !="" and Ieq !=""and V =="" and R2 != R23 and R3 != R23):
        if((float(Ieq) or float(Req) )>0):
            resps.config(state = "normal")
            resps.delete("0.0","end")
            resps.insert("0.0", "\nDesarrollo:")
            Ieq1 = Leyohm(V,Req,Ieq)
            R2e = R2
            R3e = R3
            intensidades_hibrido(Ieq1,R2e,R3e)
            bloqueo()
        else:
            venterror()
    else:
        venterror()

def Desarrollop():
    R1 = entry_r1.get()
    R2 = entry_r2.get()
    I1 = entry_i1.get()
    I2 = entry_i2.get()
    V = entry_v.get()
    Ieq = entry_ieq.get()
    Req = entry_req.get()
    if (R1 != '' and Req != '' and R2 != '' and V != ""):
        venterror()
    elif (R1 != '' and R2 != '' and Req == ''):
        # Desarrollo
        R1 = float(R1)
        R2 = float(R2)
        resps.config(state = "normal")
        Req = -1
        if ( R1 > 0 and R2 > 0):
            Req = (round(((1/R1)+(1/R2))**(-1),3))

        if(float(Req)>0 and (I1 or I2)==""):
            Reqs.config(highlightbackground = "red")
            entry_req.set(Req)
            resps.delete("0.0","end")
            resps.insert("0.0", "\nDesarrollo:\n\nReq = (1/R1 + 1/R2)^(-1)\nReq = (1/"+entry_r1.get()+" + 1/"+entry_r2.get()+")^(-1)\nReq = "+str(Req)+" Ω")
            resps.config(state = "disabled")
            Req = float(Req)

            Ieq1 = Leyohm(V,Req,Ieq)
            intensidades(Ieq1)
            bloqueo()
        else:
            venterror()
    elif (R1 != '' and Req != '' and R2 == '' and R1 != Req):
        # Desarrollo
        R1 = float(R1)
        Req = float(Req)
        resp = -1
        if ( R1 > 0):
            resp = (round(((1/Req)-(1/R1))**(-1),3))
        resps.config(state = "normal")
        if(float(resp)>0 and (I1 or I2)=="" and V == ""):
            R2s.config(highlightbackground = "red")
            entry_r2.set(resp)
            # Impresion
            resps.delete("0.0","end")
            resps.insert("0.0", "\nDesarrollo:\n\nR2 = (1/Req - 1/R1)^(-1)\nR2 = (1/"+entry_req.get()+" + 1/"+entry_r1.get()+")^(-1)\nR2 = "+str(resp)+" Ω")
            resps.config(state = "disabled")
            bloqueo()
        elif(float(resp)>0 and (I1 or I2)=="" ):
            # Impresion
            R2s.config(highlightbackground = "red")
            entry_r2.set(resp)
            resps.delete("0.0","end")
            resps.insert("0.0", "\nDesarrollo:\n\nR2 = (1/Req - 1/R1)^(-1)\nR2 = (1/"+entry_req.get()+" + 1/"+entry_r1.get()+")^(-1)\nR2 = "+str(resp)+" Ω")
            resps.config(state = "disabled")

            Ieq1 = Leyohm(V,Req,Ieq)
            intensidades(Ieq1)
            bloqueo()
        else:
            venterror()
    elif (R2 != '' and Req != '' and R1 == '' and R2 != Req):
        # Desarrollo
        R2 = float(R2)
        Req = float(Req)
        resp = (round(((1/Req)-(1/R2))**(-1),3))
        resps.config(state = "normal")
        if(float(resp)>0 and (I1 or I2)=="" and V== "" and R2 > 0):
            # Impresion
            R1s.config(highlightbackground = "red")
            entry_r1.set(resp)
            resps.delete("0.0","end")
            resps.insert("0.0", "\nDesarrollo:\n\nR1 = (1/Req - 1/R2)^(-1)\nR1 = (1/"+entry_req.get()+" + 1/"+entry_r2.get()+")^(-1)\nR1 = "+str(resp)+" Ω")
            resps.config(state = "disabled")  
            Leyohm(V,Req,Ieq)
            Ieq1 = 0 
            intensidades(Ieq1)
            bloqueo()
        elif(float(resp)>0 and (I1 or I2)=="" and R2 > 0):
            # Impresion
            R1s.config(highlightbackground = "red")
            entry_r1.set(resp)
            resps.delete("0.0","end")
            resps.insert("0.0", "\nDesarrollo:\n\nR1 = (1/Req - 1/R2)^(-1)\nR1 = (1/"+entry_req.get()+" + 1/"+entry_r2.get()+")^(-1)\nR1 = "+str(resp)+" Ω")
            resps.config(state = "disabled")   
            Ieq1 = Leyohm(V,Req,Ieq)
            intensidades(Ieq1)
            bloqueo()
        else:
            venterror()
    elif(I1 =="" and I2 !="" and Ieq !="" and (V != "" or Req != "")):
        if(float(Ieq)>float(I2) and float(Ieq)>0 and float(I2)>0 and Req == ""):
            Ieq1 = intensidades(0)
            Ieq1 = round(float(entry_ieq.get()),3)
            Leyohm(V,Req,Ieq1)
            V = float(entry_v.get())
            I1 = float(entry_i1.get())
            I2 = float(entry_i2.get())
            R1 = round(V/I1,3)
            R2 = round(V/I2,3)
            R1s.config(highlightbackground = "red")
            entry_r1.set(R1)
            R2s.config(highlightbackground = "red")
            entry_r2.set(R2)
            resps.config(state = "normal")
            resps.insert("end", "\n\nR1 = (V / I1)\nR1 = ("+entry_v.get()+" / "+entry_i1.get()+")\nR1 = "+str(R1)+" Ω\n\nR2 = (V / I2)\nR2 = ("+entry_v.get()+" / "+entry_i2.get()+")\nR2 = "+str(R2)+" Ω")
            resps.config(state = "disabled")
            bloqueo()
        else:
            venterror()
    elif(I1 =="" and I2 !="" and Ieq !=""):
        if(float(Ieq)>float(I2) and float(Ieq)>0 and float(I2)>0):
            Ieq1 = 0
            intensidades(Ieq1)
            bloqueo()
        else:
            venterror()
    elif(I1 !="" and I2 =="" and Ieq !="" and (V != "" or Req != "")):
        if(float(Ieq)>float(I1) and float(Ieq)>0 and float(I1)>0 and Req == ""):
            Ieq1 = intensidades(0)
            Ieq1 = round(float(entry_ieq.get()),3)
            Leyohm(V,Req,Ieq1)
            V = float(entry_v.get())
            I1 = float(entry_i1.get())
            I2 = float(entry_i2.get())
            R1 = round(V/I1,3)
            R2 = round(V/I2,3)
            R1s.config(highlightbackground = "red")
            entry_r1.set(R1)
            R2s.config(highlightbackground = "red")
            entry_r2.set(R2)
            resps.config(state = "normal")
            resps.insert("end", "\n\nR1 = (V / I1)\nR1 = ("+entry_v.get()+" / "+entry_i1.get()+")\nR1 = "+str(R1)+" Ω\n\nR2 = (V / I2)\nR2 = ("+entry_v.get()+" / "+entry_i2.get()+")\nR2 = "+str(R2)+" Ω")
            resps.config(state = "disabled")
            bloqueo()
        else:
            venterror()
    elif(I1 !="" and I2 =="" and Ieq !=""):
        if(float(Ieq)>float(I1) and float(Ieq)>0 and float(I1)>0):
            Ieq1 = 0
            intensidades(Ieq1)
            bloqueo()
        else:
            venterror()
    elif(I1 !="" and I2 !="" and Ieq =="" and (V != "" or Req != "")):
        if(float(I2)>0 and float(I1)>0 and Req == ""):
            Ieq1 = intensidades(Ieq)
            Leyohm(V,Req,Ieq1)
            V = float(entry_v.get())
            I1 = float(entry_i1.get())
            I2 = float(entry_i2.get())
            R1 = round(V/I1,3)
            R2 = round(V/I2,3)
            R1s.config(highlightbackground = "red")
            entry_r1.set(R1)
            R2s.config(highlightbackground = "red")
            entry_r2.set(R2)
            resps.config(state = "normal")
            resps.insert("end", "\n\nR1 = (V / I1)\nR1 = ("+entry_v.get()+" / "+entry_i1.get()+")\nR1 = "+str(R1)+" Ω\n\nR2 = (V / I2)\nR2 = ("+entry_v.get()+" / "+entry_i2.get()+")\nR2 = "+str(R2)+" Ω")
            resps.config(state = "disabled")
            bloqueo()
        else:
            venterror()
            
    elif(I1 !="" and I2 !="" and Ieq ==""):
        if(float(I2)>0 and float(I1)>0):
            Ieq1 = Leyohm(V,Req,Ieq)
            intensidades(Ieq1)
            bloqueo()
        else:
            venterror()
    elif(V !="" and Req !=""and Ieq =="" and R2 != Req and R1 != Req):
        if((float(V) or float(Req) )>0):
            resps.config(state = "normal")
            resps.delete("0.0","end")
            resps.insert("0.0", "\nDesarrollo:")
            Ieq1 = Leyohm(V,Req,Ieq)
            intensidades(Ieq1)
            bloqueo()
        else:
            venterror()
    elif(V !="" and Ieq !=""and Req ==""):
        if((float(V) or float(Ieq) )>0):
            resps.config(state = "normal")
            resps.delete("0.0","end")
            resps.insert("0.0", "\nDesarrollo:")
            Ieq1 = Leyohm(V,Req,Ieq)
            bloqueo()
        else:
            venterror()
    elif(Req !="" and Ieq !=""and V =="" and R2 != Req and R1 != Req):
        if((float(Ieq) or float(Req) )>0):
            resps.config(state = "normal")
            resps.delete("0.0","end")
            resps.insert("0.0", "\nDesarrollo:")
            Ieq1 = Leyohm(V,Req,Ieq)
            bloqueo()
        else:
            venterror()
    else:
        venterror()
    
def Desarrollos():
    #Llamo las variables
    R1 = entry_r1.get()
    R2 = entry_r2.get()
    R3 = entry_r3.get()
    V = entry_v.get()
    Req = entry_req.get()
    Ieq = entry_ieq.get()
    # impresion
    # calcula Req
    if (R1 != '' and R2 != '' and R3 != '' and Req == ''):
        # Desarrollo Req
        R1 = float(R1)
        R2 = float(R2)
        R3 = float(R3)
        resps.config(state = "normal")
        Req = float(R1+R2+R3)
         
        # impresion
        if (Req >= 0 and R3 >= 0 and R1 >= 0 and R2 >= 0):
            Reqs.config(highlightbackground = "red")
            entry_req.set(Req)
            Req = str(Req)
            resps.delete("0.0","end")
            resps.insert("0.0",  "\nDesarrollo:\n\nReq = R1 + R2 + R3\nReq = "+entry_r1.get()+" + "+entry_r2.get()+" + "+entry_r3.get()+"\nReq = "+Req+" Ω")
            resps.config(state = "disabled")
            
            Leyohm(V,Req,Ieq)
            bloqueo()
        else:
            venterror()
    # calcula R3
    elif ((R1 != '' and R2 != '' and Req != '' and R3 == '')):
        
        # Desarrollo R3
        R1 = float(R1)
        R2 = float(R2)
        Req = float(Req)
        R3 = (Req-R1-R2)
        if (Req >= 0 and R3 >= 0 and R1 >= 0 and R2 >= 0):
            R3 = str(R3)
            R3s.config(highlightbackground = "red")
            entry_r3.set(R3)
            resps.config(state = "normal")
            
            # impresion
            resps.delete("0.0","end")
            resps.insert("0.0",  "\nDesarrollo:\n\nR3 = Req - R1 - R2\nR3 = "+entry_req.get()+" - "+entry_r1.get()+" - "+entry_r2.get()+"\nR3 = "+R3+" Ω")
            resps.config(state = "disabled")
            Leyohm(V,Req,Ieq)
            bloqueo()
        else:
            venterror()

    # calcula R2
    elif ((R1 != '' and R3 != '' and Req != '' and R2 == '')):
        # Desarrollo R2
        R1 = float(R1)
        R3 = float(R3)
        Req = float(Req)
        R2 = (Req-R1-R3)
        if (Req >= 0 and R3 >= 0 and R1 >= 0 and R2 >= 0):
            R2 = str(R2)
            R2s.config(highlightbackground = "red")
            entry_r2.set(R2)
            resps.config(state = "normal")

            # impresion
            resps.delete("0.0","end")
            resps.insert("0.0",  "\nDesarrollo:\n\nR2 = Req - R1 - R2\nR2 = "+entry_req.get()+" - "+entry_r1.get()+" - "+entry_r3.get()+"\nR2 = "+R2+" Ω")
            resps.config(state = "disabled")
            Leyohm(V,Req,Ieq)
            bloqueo()
        else:
            venterror()
    # calcula R1
    elif ((R2 != '' and R3 != '' and Req != '' and R1 == '')):
        # Desarrollo R1
        R2 = float(R2)
        R3 = float(R3)
        Req = float(Req)
        R1 = (Req-R2-R3)
        if (Req >= 0 and R3 >= 0 and R1 >= 0 and R2 >= 0) :
            R1s.config(highlightbackground = "red")
            entry_r1.set(R1)
            R1 = str(R1)
            resps.config(state = "normal")
            
            # impresion
            resps.delete("0.0","end")
            resps.insert("0.0",  "\nDesarrollo:\n\nR1 = Req - R2 - R3\nR1 = "+entry_req.get()+" - "+entry_r2.get()+" - "+entry_r3.get()+"\nR1 = "+R1+" Ω")
            resps.config(state = "disabled")
            Leyohm(V,Req,Ieq)
            bloqueo()
        else:
            venterror()
    #calcula Req sin r1 r2 r3
    elif (R1 == '' and R2 == '' and R3 == ''):
        resps.config(state = "normal")
        resps.delete("0.0","end")
        resps.insert("0.0",  "\nDesarrollo:")
        resps.config(state = "disabled")
        Leyohm(V,Req,Ieq)
        bloqueo()
    else:
        venterror()

def intensidades(Ieq1):
    R1 = entry_r1.get()
    R2 = entry_r2.get()
    V = entry_v.get()
    Req = entry_req.get()
    Ieq = entry_ieq.get()
    I1e = entry_i1.get()
    I2e = entry_i2.get()
    if (Ieq != ""):
        Ieq1 = float(Ieq1)
    
    if(R1 !="" and R2 !="" and V !="" ):
        I1 = round(float(V)/float(R1),3)
        I2 = round(float(V)/float(R2),3)
        I1s.config(highlightbackground = "red")
        entry_i1.set(I1)
        I2s.config(highlightbackground = "red")
        entry_i2.set(I2)
        resps.config(state = "normal")
        resps.insert("end",  "\n\nI1 = V/R1\nI1 = "+str(V)+" / "+str(R1)+"\nI1 = "+str(I1)+" A\n\nI2 = V/R2\nI2 = "+str(V)+" / "+str(R2)+"\nI2 = "+str(I2)+" A")
        resps.config(state = "disabled")
    elif(R1 !="" and R2 == "" and V!="" and Req !=""):
        I1 = round(float(V)/float(R1),3)
        I2 = round(float(Ieq1)-float(I1),3)
        I1s.config(highlightbackground = "red")
        entry_i1.set(I1)
        I2s.config(highlightbackground = "red")
        entry_i2.set(I2)
        resps.config(state = "normal")
        resps.insert("end",  "\n\nI1 = V/R1\nI1 = "+str(V)+" / "+str(R1)+"\nI1 = "+str(I1)+" A\n\nI2 = Ieq-I1\nI2 = "+str(Ieq1)+" - "+str(I1)+"\nI2 = "+str(I2)+" A")
        resps.config(state = "disabled")
    elif(R1 == "" and R2 !="" and V !=""):
        I2 = round(float(V)/float(R2),3)
        I1 = round(float(Ieq1)-float(I2),3)
        I1s.config(highlightbackground = "red")
        entry_i1.set(I1)
        I2s.config(highlightbackground = "red")
        entry_i2.set(I2)
        resps.config(state = "normal")
        resps.insert("end",  "\n\nI2 = V/R2\nI2 = "+str(V)+" / "+str(R2)+"\nI2 = "+str(I2)+" A\n\nI1 = Ieq-I2\nI1 = "+str(Ieq1)+" - "+str(I2)+"\nI1 = "+str(I1)+" A")
        resps.config(state = "disabled")
    elif(I1e =="" and I2e !=""and Ieq !="" ):
        I1e = round(float(Ieq)-float(I2e),3)
        I1s.config(highlightbackground = "red")
        entry_i1.set(I1e)
        resps.config(state = "normal")
        resps.delete("0.0","end")
        resps.insert("end",  "\nDesarrollo:\n\nI1 = Ieq-I2\nI1 = "+str(Ieq)+" - "+str(I2e)+"\nI1 = "+str(I1e)+" A")
        resps.config(state = "disabled")

    elif(I1e !="" and I2e =="" and Ieq !=""):
        I2e = round(float(Ieq)-float(I1e),3)
        I2s.config(highlightbackground = "red")
        entry_i2.set(I2e)
        resps.config(state = "normal")
        resps.delete("0.0","end")
        resps.insert("end",  "\nDesarrollo:\n\nI2 = Ieq-I1\nI2 = "+str(Ieq)+" - "+str(I1e)+"\nI2 = "+str(I2e)+" A")
        resps.config(state = "disabled")
    elif(I1e !="" and I2e !=""):
        Ieq = round(float(I1e)+float(I2e),3)
        Is.config(highlightbackground = "red")
        entry_ieq.set(Ieq)
        resps.config(state = "normal")
        resps.delete("0.0","end")
        resps.insert("end",  "\nDesarrollo:\n\nIeq = I1+I2\nIeq = "+str(I1e)+" + "+str(I2e)+"\nIeq = "+str(Ieq)+" A")
        resps.config(state = "disabled")
        return Ieq

def intensidades_hibrido(Ieq1,R2e,R3e):
    R1 = entry_r1.get()
    R2 = entry_r2.get()
    R3 = entry_r3.get()
    R4 = entry_r4.get()
    V = entry_v.get()
    Req = entry_req.get()
    Ieq = entry_ieq.get()
    I1e = entry_i1.get()
    I2e = entry_i2.get()
    if(R1 !="" and R2 !="" and R3 !="" and R4 !="" and V !=""):
        VR1 = round(float(Ieq1)*float(R1),3)
        VR4 = round(float(Ieq1)*float(R4),3)
        VR23 = round(float(V)-VR1-VR4,3)
        I1 = round(VR23/float(R2),3)
        I2 = round(VR23/float(R3),3)
        I1s.config(highlightbackground = "red")
        entry_i1.set(I1)
        I2s.config(highlightbackground = "red")
        entry_i2.set(I2)
        resps.config(state = "normal")
        resps.insert("end",  "\n\nV(R1) = Ieq*R1\nV(R1) = "+str(Ieq1)+" * "+str(R1)+"\nV(R1) = "+str(VR1)+" V\n\nV(R4) = Ieq*R4\nV(R4) = "+str(Ieq1)+" * "+str(R4)+"\nV(R4) = "+str(VR4)+" V\n\nV(R23) = V-V(R1)-V(R4)\nV(R23) = "+str(V)+"-"+str(VR1)+"-"+str(VR4)+"\nV(R23) = "+str(VR23)+"V\n\nI1 = V(R23)/R2\nI1 = "+str(VR23)+"/"+str(R2)+"\nI1 ="+str(I1)+"A\n\nI2 = V(R23)/R3\nI2 = "+str(VR23)+"/"+str(R3)+"\nI2 ="+str(I2)+"A")
        resps.config(state = "disabled")
        return Ieq
    elif(R1 !="" and R2 !="" and R3 !="" and R4 =="" and Req !="" and V !=""):
        VR1 = round(float(Ieq1)*float(R1),3)
        R23 = round(((1/float(R2))+(1/float(R3)))**(-1),3)
        VR23 = round(float(Ieq1)*R23,3)
        VR4 = round(float(V)-VR1-VR23,3)
        I1 = round(VR23/float(R2),3)
        I2 = round(VR23/float(R3),3)
        I1s.config(highlightbackground = "red")
        entry_i1.set(I1)
        I2s.config(highlightbackground = "red")
        entry_i2.set(I2)
        resps.config(state = "normal")
        resps.insert("end",  "\n\nV(R1) = Ieq*R1\nV(R1) = "+str(Ieq1)+" * "+str(R1)+"\nV(R1) = "+str(VR1)+" V\n\nV(R23) = Ieq*R23\nV(R23) = "+str(Ieq1)+" * "+str(R23)+"\nV(R23) = "+str(VR23)+" V\n\nV(R4) = V-V(R1)-V(R23)\nV(R4) = "+str(V)+"-"+str(VR1)+"-"+str(VR23)+"\nV(R23) = "+str(VR4)+"V\n\nI1 = V(R23)/R2\nI1 = "+str(VR23)+"/"+str(R2)+"\nI1 ="+str(I1)+"A\n\nI2 = V(R23)/R3\nI2 = "+str(VR23)+"/"+str(R3)+"\nI2 ="+str(I2)+"A")
        resps.config(state = "disabled")
        return Ieq
    elif(R1 !="" and R2 !="" and R4 !="" and R3 =="" and Req !="" and V !=""):
        VR1 = round(float(Ieq1)*float(R1),3)
        VR4 = round(float(Ieq1)*float(R4),3)
        VR23 = round(float(V)-VR1-VR4,3)
        I1 = round(VR23/float(R2),3)
        I2 = round(VR23/float(R3e),3)
        I1s.config(highlightbackground = "red")
        entry_i1.set(I1)
        I2s.config(highlightbackground = "red")
        entry_i2.set(I2)
        resps.config(state = "normal")
        resps.insert("end",  "\n\nV(R1) = Ieq*R1\nV(R1) = "+str(Ieq1)+" * "+str(R1)+"\nV(R1) = "+str(VR1)+" V\n\nV(R4) = Ieq*R4\nV(R4) = "+str(Ieq1)+" * "+str(R4)+"\nV(R4) = "+str(VR4)+" V\n\nV(R23) = V-V(R1)-V(R4)\nV(R23) = "+str(V)+"-"+str(VR1)+"-"+str(VR4)+"\nV(R23) = "+str(VR23)+"V\n\nI1 = V(R23)/R2\nI1 = "+str(VR23)+"/"+str(R2)+"\nI1 ="+str(I1)+"A\n\nI2 = V(R23)/R3\nI2 = "+str(VR23)+"/"+str(R3)+"\nI2 ="+str(I2)+"A")
        resps.config(state = "disabled")
        return Ieq
    elif(R1 !="" and R3 !="" and R4 !="" and R2 =="" and Req !="" and V !=""):
        VR1 = round(float(Ieq1)*float(R1),3)
        VR4 = round(float(Ieq1)*float(R4),3)
        VR23 = round(float(V)-VR1-VR4,3)
        I1 = round(VR23/float(R2e),3)
        I2 = round(VR23/float(R3),3)
        I1s.config(highlightbackground = "red")
        entry_i1.set(I1)
        I2s.config(highlightbackground = "red")
        entry_i2.set(I2)
        resps.config(state = "normal")
        resps.insert("end",  "\n\nV(R1) = Ieq*R1\nV(R1) = "+str(Ieq1)+" * "+str(R1)+"\nV(R1) = "+str(VR1)+" V\n\nV(R4) = Ieq*R4\nV(R4) = "+str(Ieq1)+" * "+str(R4)+"\nV(R4) = "+str(VR4)+" V\n\nV(R23) = V-V(R1)-V(R4)\nV(R23) = "+str(V)+"-"+str(VR1)+"-"+str(VR4)+"\nV(R23) = "+str(VR23)+"V\n\nI1 = V(R23)/R2\nI1 = "+str(VR23)+"/"+str(R2)+"\nI1 ="+str(I1)+"A\n\nI2 = V(R23)/R3\nI2 = "+str(VR23)+"/"+str(R3)+"\nI2 ="+str(I2)+"A")
        resps.config(state = "disabled")
        return Ieq
    elif(I1e =="" and I2e !=""and Ieq !="" ):
        I1e = round(float(Ieq)-float(I2e),3)
        I1s.config(highlightbackground = "red")
        entry_i1.set(I1e)
        resps.config(state = "normal")
        resps.delete("0.0","end")
        resps.insert("end",  "\nDesarrollo:\n\nI1 = Ieq-I2\nI1 = "+str(Ieq)+" - "+str(I2e)+"\nI1 = "+str(I1e)+" A")
        resps.config(state = "disabled")
        return Ieq
    elif(I1e !="" and I2e =="" and Ieq !=""):
        I2e = round(float(Ieq)-float(I1e),3)
        I2s.config(highlightbackground = "red")
        entry_i2.set(I2e)
        resps.config(state = "normal")
        resps.delete("0.0","end")
        resps.insert("end",  "\nDesarrollo:\n\nI2 = Ieq-I1\nI2 = "+str(Ieq)+" - "+str(I1e)+"\nI2 = "+str(I2e)+" A")
        resps.config(state = "disabled")
        return Ieq
    elif(I1e !="" and I2e !=""):
        Ieq = round(float(I1e)+float(I2e),3)
        Is.config(highlightbackground = "red")
        entry_ieq.set(Ieq)
        resps.config(state = "normal")
        resps.delete("0.0","end")
        resps.insert("end",  "\nDesarrollo:\n\nIeq = I1+I2\nIeq = "+str(I1e)+" + "+str(I2e)+"\nIeq = "+str(Ieq)+" A")
        resps.config(state = "disabled")
        return Ieq

def cajasvacias():
    resps.config(state = "normal")
    resps.delete("0.0","end")
    resps.insert("0.0",  "\nDesarrollo:")
    resps.config(state = "disabled")
    entry_r1.set("")
    entry_r2.set("")
    entry_r3.set("")
    entry_v.set("")
    entry_ieq.set("")
    entry_i1.set("")
    entry_i2.set("")
    entry_req.set("")
    entry_r4.set("")
    desbloqueo()

def Instruccvent():
    ventana2.iconify()
    ventana2.deiconify()

def volverespecial():
    ventana1.geometry( "1280x800+350+100" )
    tituloT.place( relx = 0.35 , rely = 0.02 )
    mallasT.place( relx = 0.02, rely = 0.15 )
    propiedades.place( relx = 0.96 , rely = 0.01 )
    malla1.place( relx = 0.14, rely = 0.8 )
    malla2.place( relx = 0.74, rely = 0.8 )
    malla3.place( relx = 0.44, rely = 0.8 )
    imagMalla1.place( relx = 0.01, rely = 0.215 ) 
    imagMalla2.place( relx = 0.47, rely = 0.26 )
    limpiar.place_forget()
    tituloserie.place_forget()
    ohm.place_forget()
    ahm2.place_forget()
    ahm3.place_forget()
    ohmeq.place_forget()
    voltaje.place_forget()
    corriente.place_forget()
    Reqt.place_forget()
    R1t.place_forget()
    R2t.place_forget()
    R3t.place_forget()
    Vt.place_forget()
    Iteq.place_forget()
    volver.place_forget()
    respuesta.place_forget()
    respuestah.place_forget()
    respuestap.place_forget()
    Instrucs.place_forget()
    Reqs.place_forget()
    R1s.place_forget()
    R2s.place_forget()
    R3s.place_forget()
    vs.place_forget()
    Is.place_forget()
    resps.place_forget()
    titulparalelo.place_forget()
    corriente2.place_forget()
    corriente3.place_forget()
    It.place_forget()
    I2t.place_forget()
    I1s.place_forget()
    I2s.place_forget()
    titulohibrido.place_forget()
    R4t.place_forget()
    R4s.place_forget()
    imagMalla3.place_forget()
    ahm4.place_forget()
    ventana2.withdraw()

def ocultar():
    tituloT.place_forget()
    mallasT.place_forget()
    malla1.place_forget()
    malla2.place_forget()
    malla3.place_forget()
    imagMalla1.place_forget()
    imagMalla2.place_forget()

def serie():
    ocultar()
    ventana2.iconify()
    ventana2.deiconify()
    ventana1.geometry( "1280x800+070+100" ) 
    tituloserie.place( relx = 0.4 , rely = 0.02 )
    ohm.place(relx = 0.18, rely = 0.2)
    ahm2.place(relx = 0.38, rely = 0.2)
    ahm3.place(relx = 0.567, rely = 0.2)
    ohmeq.place(relx = 0.38, rely = 0.9)
    voltaje.place(relx = 0.28, rely = 0.78)
    corriente.place(relx = 0.48, rely = 0.78)
    Reqt.place(relx = 0.32, rely = 0.85)
    R1t.place(relx = 0.13, rely = 0.15)
    R2t.place(relx = 0.33, rely = 0.15)
    R3t.place(relx = 0.52, rely = 0.15)
    Vt.place(relx = 0.22, rely = 0.72)
    Iteq.place(relx = 0.421, rely = 0.72)
    volver.place( relx = 0.005 , rely = 0.01 )
    respuesta.place(relx = 0.846, rely=0.926)
    Instrucs.place(relx = 0.6, rely=0.926)
    Reqs.place(relx = 0.31, rely = 0.9)
    R1s.place(relx = 0.11, rely = 0.2)
    R2s.place(relx = 0.31, rely = 0.2)
    R3s.place(relx = 0.5, rely = 0.2)
    vs.place(relx = 0.21, rely = 0.78)
    Is.place(relx = 0.41, rely = 0.78)
    resps.place(relx = 0.6, rely = 0.14)
    imagMalla1.place( relx = 0.07, rely = 0.24 )
    limpiar.place( relx = 0.005 , rely = 0.92 )
    cajasvacias()

def paralelo():
    ocultar()
    ventana2.iconify()
    ventana2.deiconify()
    ventana1.geometry( "1280x800+070+100" )
    titulparalelo.place( relx = 0.4 , rely = 0.02 )
    ohm.place(relx = 0.18, rely = 0.78)
    ahm2.place(relx = 0.38, rely = 0.78)
    ohmeq.place(relx = 0.38, rely = 0.9)
    voltaje.place(relx = 0.567, rely = 0.78)
    corriente.place(relx = 0.18, rely = 0.2)
    corriente2.place(relx = 0.38, rely = 0.2)
    corriente3.place(relx = 0.567, rely = 0.2)
    Reqt.place(relx = 0.32, rely = 0.85)
    R1t.place(relx = 0.13, rely = 0.72)
    R2t.place(relx = 0.33, rely = 0.72)
    Vt.place(relx = 0.51, rely = 0.72)
    Iteq.place(relx = 0.125, rely = 0.15)
    It.place(relx = 0.33, rely = 0.15)
    I2t.place(relx = 0.52, rely = 0.15)
    volver.place( relx = 0.005 , rely = 0.01 )
    respuestap.place(relx = 0.846, rely=0.926)
    Instrucs.place(relx = 0.6, rely=0.926)
    Reqs.place(relx = 0.31, rely = 0.9)
    R1s.place(relx = 0.11, rely = 0.78)
    R2s.place(relx = 0.31, rely = 0.78)
    vs.place(relx = 0.5, rely = 0.78)
    Is.place(relx = 0.11, rely = 0.2)
    I1s.place(relx = 0.31, rely = 0.2)
    I2s.place(relx = 0.5, rely = 0.2)
    resps.place(relx = 0.6, rely = 0.14)
    imagMalla2.place( relx = 0.07, rely = 0.27 )
    limpiar.place( relx = 0.005 , rely = 0.92 )
    cajasvacias()

def hibrida():
    ocultar()
    ventana2.iconify()
    ventana2.deiconify()
    ventana1.geometry( "1280x800+070+100" )
    titulohibrido.place( relx = 0.33 , rely = 0.02 )
    ohm.place(relx = 0.18, rely = 0.78)
    ahm2.place(relx = 0.38, rely = 0.78)
    ahm3.place(relx = 0.567, rely = 0.78)
    ahm4.place(relx = 0.18, rely = 0.9)
    ohmeq.place(relx = 0.38, rely = 0.9)
    voltaje.place(relx = 0.567, rely = 0.9)
    corriente.place(relx = 0.18, rely = 0.2)
    corriente2.place(relx = 0.38, rely = 0.2)
    corriente3.place(relx = 0.567, rely = 0.2)
    Reqt.place(relx = 0.32, rely = 0.85)
    R1t.place(relx = 0.13, rely = 0.72)
    R2t.place(relx = 0.33, rely = 0.72)
    R3t.place(relx = 0.52, rely = 0.72)
    R4t.place(relx = 0.13, rely = 0.85)
    Vt.place(relx = 0.51, rely = 0.85)
    Iteq.place(relx = 0.125, rely = 0.15)
    It.place(relx = 0.33, rely = 0.15)
    I2t.place(relx = 0.52, rely = 0.15)
    volver.place( relx = 0.005 , rely = 0.01 )
    respuestah.place(relx = 0.846, rely=0.926)
    Instrucs.place(relx = 0.6, rely=0.926)
    Reqs.place(relx = 0.31, rely = 0.9)
    R1s.place(relx = 0.11, rely = 0.78)
    R2s.place(relx = 0.31, rely = 0.78)
    R3s.place(relx = 0.5, rely = 0.78)
    R4s.place(relx = 0.11, rely = 0.9)
    vs.place(relx = 0.5, rely = 0.9)
    Is.place(relx = 0.11, rely = 0.2)
    I1s.place(relx = 0.31, rely = 0.2)
    I2s.place(relx = 0.5, rely = 0.2)
    resps.place(relx = 0.6, rely = 0.14)
    imagMalla3.place( relx = 0.07, rely = 0.2 )
    limpiar.place( relx = 0.005 , rely = 0.92 )
    cajasvacias()

# -------Ventana Main------- 

ventana1 = tkinter.Tk()
ventana1.geometry( "1280x800+350+100" )
ventana1.resizable(0,0)
ventana1.title( "Circuitos" )
ventana1.config( bg = "white" , )

# Etiquetas
    # Titulos
tituloT = tkinter.Label( ventana1, text = "Circuitos Eléctricos", font = "Times 35", bg = "white" )
tituloT.place( relx = 0.35 , rely = 0.02 )
mallasT = tkinter.Label( ventana1, text = "Mallas:", font = "Times 20", bg = "white" )
mallasT.place( relx = 0.02, rely = 0.15 )

# Botones
propiedades = tkinter.Button( ventana1, text = "?", font = "Times 20" , command = ventanaPropiedades)
propiedades.place( relx = 0.96 , rely = 0.01 )
malla1 = tkinter.Button( ventana1, text = " Serie ", font = "Times 25", command = serie)
malla1.place( relx = 0.14, rely = 0.8 )
malla2 = tkinter.Button( ventana1, text = "Paralelo", font = "Times 25", command = paralelo)
malla2.place( relx = 0.74, rely = 0.8 )
malla3 = tkinter.Button( ventana1, text = "Mixto", font = "Times 25", command = hibrida)
malla3.place( relx = 0.44, rely = 0.8 )

# imagenes
Malla1 = tkinter.PhotoImage( file = "Circuitoenserie.png" )
imagMalla1 = tkinter.Label(ventana1, image = Malla1, bg = "white")
imagMalla1.place( relx = 0.01, rely = 0.215 ) 
Malla2 = tkinter.PhotoImage( file = "Circuitoparalelo.png" )
imagMalla2 = tkinter.Label(ventana1, image = Malla2, bg = "white")
imagMalla2.place( relx = 0.47, rely = 0.26 ) 
Malla3 = tkinter.PhotoImage( file = "Circuitomixto.png")
imagMalla3 = tkinter.Label(ventana1, image = Malla3, bg = "white")


# -------Limitador de variables-------
entry_r1 = StringVar()
entry_r2 = StringVar()
entry_r3 = StringVar()
entry_v = StringVar()
entry_ieq = StringVar()
entry_i1 = StringVar()
entry_i2 = StringVar()
entry_req = StringVar()
entry_r4 = StringVar()  

def limitador(entry_r1):
    if len(entry_r1.get()) > 0:
        entry_r1.set(entry_r1.get()[:5])
        
entry_r1.trace("w", lambda *args: limitador(entry_r1))
entry_r2.trace("w", lambda *args: limitador(entry_r2))
entry_r3.trace("w", lambda *args: limitador(entry_r3))
entry_v.trace("w", lambda *args: limitador(entry_v))
entry_ieq.trace("w", lambda *args: limitador(entry_ieq))
entry_i1.trace("w", lambda *args: limitador(entry_i1))
entry_i2.trace("w", lambda *args: limitador(entry_i2))
entry_req.trace("w", lambda *args: limitador(entry_req))
entry_r4.trace("w", lambda *args: limitador(entry_r4))

# -------Ventana Serie-------
# Etiquetas
    # Titulos
tituloserie = tkinter.Label( ventana1, text = "Conexión serie", font = "Times 35", bg = "white" )

    # simbolos
ohm = tkinter.Label( ventana1, text = "Ω", font = "Times 20", bg = "white" )
ahm2 = tkinter.Label( ventana1, text = "Ω", font = "Times 20", bg = "white" )
ahm3 = tkinter.Label( ventana1, text = "Ω", font = "Times 20", bg = "white" )
ohmeq = tkinter.Label( ventana1, text = "Ω", font = "Times 20", bg = "white" )
voltaje = tkinter.Label( ventana1, text = "V", font = "Times 20", bg = "white" )
corriente = tkinter.Label( ventana1, text = "A", font = "Times 20", bg = "white" )

    # variables
Reqt = tkinter.Label( ventana1, text = "Req", font = "Times 20", bg = "white" )
R1t = tkinter.Label( ventana1, text = "R1", font = "Times 20", bg = "white" )
R2t = tkinter.Label( ventana1, text = "R2", font = "Times 20", bg = "white" )
R3t = tkinter.Label( ventana1, text = "R3", font = "Times 20", bg = "white" )
Vt = tkinter.Label( ventana1, text = "Vol", font = "Times 20", bg = "white" )
Iteq = tkinter.Label( ventana1, text = "Ieq", font = "Times 20", bg = "white" )

# botones serie
volver = tkinter.Button( ventana1, text = "volver", font = "Times 20" , command = volverespecial)
limpiar = tkinter.Button( ventana1, text = "Limpiar", font = "Times 20" , command = cajasvacias)
respuesta = tkinter.Button( ventana1, text = "Desarrollo", font = "Times 20", command = Desarrollos)
Instrucs = tkinter.Button( ventana1, text = "Instrucciones", font = "Times 20", command = Instruccvent)

# Variables
def validate_entry(text):
    return text.isdecimal()
R1s = tkinter.Entry( ventana1, font = "Times 20", width = 5, bg = "gray88", highlightthickness = 2, textvariable = entry_r1,validate="key",validatecommand=(ventana1.register(validate_entry), "%S"))
R2s = tkinter.Entry( ventana1, font = "Times 20", width = 5, bg = "gray88", highlightthickness = 2, textvariable = entry_r2,validate="key",validatecommand=(ventana1.register(validate_entry), "%S"))
R3s = tkinter.Entry( ventana1, font = "Times 20", width = 5, bg = "gray88", highlightthickness = 2, textvariable = entry_r3,validate="key",validatecommand=(ventana1.register(validate_entry), "%S"))
vs = tkinter.Entry( ventana1, font = "Times 20", width = 5, bg = "gray88", highlightthickness = 2, textvariable = entry_v,validate="key",validatecommand=(ventana1.register(validate_entry), "%S"))
Is = tkinter.Entry( ventana1, font = "Times 20", width = 5, bg = "gray88", highlightthickness = 2, textvariable = entry_ieq,validate="key",validatecommand=(ventana1.register(validate_entry), "%S"))
Reqs = tkinter.Entry( ventana1, font = "Times 20", width = 5, bg = "gray88", highlightthickness = 2, textvariable = entry_req,validate="key",validatecommand=(ventana1.register(validate_entry), "%S"))
resps = Text( ventana1, height = 20, width = 32, font = "Times 20", bg = "#F6F6F6", highlightthickness = 1, highlightbackground = "black")

# -------Ventana Paralelo-------

# Etiquetas
    # Titulos
titulparalelo = tkinter.Label( ventana1, text = "Conexión Paralelo", font = "Times 35", bg = "white" )

    # simbolos
corriente2 = tkinter.Label( ventana1, text = "A", font = "Times 20", bg = "white" )
corriente3 = tkinter.Label( ventana1, text = "A", font = "Times 20", bg = "white" )

    # variables
It = tkinter.Label( ventana1, text = "I1", font = "Times 20", bg = "white" )
I2t = tkinter.Label( ventana1, text = "I2", font = "Times 20", bg = "white" )

# Variables
I1s = tkinter.Entry( ventana1, font = "Times 20", width = 5, bg = "gray88", highlightthickness = 2, textvariable = entry_i1,validate="key",validatecommand=(ventana1.register(validate_entry), "%S"))
I2s = tkinter.Entry( ventana1, font = "Times 20", width = 5, bg = "gray88", highlightthickness = 2, textvariable = entry_i2,validate="key",validatecommand=(ventana1.register(validate_entry), "%S"))

#boton
respuestap = tkinter.Button( ventana1, text = "Desarrollo", font = "Times 20", command = Desarrollop)

# -------Ventana hibrida-------

# Etiquetas
    # Titulos
titulohibrido = tkinter.Label( ventana1, text = "Conexión Serie y Paralelo", font = "Times 35", bg = "white" )
    
    # simbolos
ahm4 = tkinter.Label( ventana1, text = "Ω", font = "Times 20", bg = "white" )

    # variables
R4t = tkinter.Label( ventana1, text = "R4", font = "Times 20", bg = "white" )

# Variables
R4s = tkinter.Entry( ventana1, font = "Times 20", width = 5, bg = "gray88", highlightthickness = 2, textvariable = entry_r4,validate="key",validatecommand=(ventana1.register(validate_entry), "%S"))

#boton
respuestah = tkinter.Button( ventana1, text = "Desarrollo", font = "Times 20", command = Desarrolloh)

# -------Ventana Instrucc serie-------

ventana2 = tkinter.Toplevel()
ventana2.geometry( "530x600+1370+100" ) 
ventana2.resizable(0,0)
ventana2.title( "Instrucciones" )
ventana2.config( bg = "white" )
ventana2.withdraw()

def volverins():
    ventana2.withdraw()

# Botones Instrucciones
volverins = tkinter.Button( ventana2, text = "Cerrar", font = "Times 20" , command = volverins ).place( relx = 0.005 , rely = 0.01 )

# Etiquetas
    # Titulos
ins = tkinter.Label( ventana2, text = "Instrucciones:\n\n 1. Ingrese solo los valores de resistencia (R) a\n     excepción de la que desea calcular\n\n 2. Ingrese un valor de voltaje (V) y los de\n     resistencias (R) (o solo Req) para obtener\n     la corriente eléctrica (I) y la resistencia\n     faltante\n\n 3. Ingrese la corriente eléctrica (I) y todas\n     las resistencias (o solo Req) para obtener el\n     voltaje (V) y la Resistencia faltante\n\n 4. Ingrese el voltaje (V) y la corriente\n     eléctrica para obtener la resistencia\n     equivalente (Req)"
, font = "Times 20", bg = "white" , justify = "left").place( relx = 0.02 , rely = 0.1 )

entry_r1.set(0000000000000)
entry_r2.set(0000000000000)
entry_r3.set(0000000000000)
entry_v.set(0000000000000)
entry_ieq.set(0000000000000)
entry_i1.set(0000000000000)
entry_i2.set(0000000000000)
entry_req.set(0000000000000)
entry_r4.set(0000000000000)


ventana1.mainloop()