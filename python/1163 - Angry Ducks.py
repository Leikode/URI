import math

g = -9.80665
pi = 3.14159

while True:
    try:
        i = 0
        velp = []
        angp = []
        alth = float(input())     # Altura do bodoque
        comp = input().split(" ")  # Comprimento da cidade de Nlogonia
        numt = int(input())       # Numero de tentativas

        inin = float(comp[0])	  # Inicio de Nlogonia
        finn = float(comp[1])	  # Final da Nlogonia

        while(i < numt):
            text = input().split(" ")
            angp.append(float(text[0]))
            velp.append(float(text[1]))
            i = i+1

        i = 0

        while(i < numt):
            a = angp[i]
            v = velp[i]
            velh = (math.cos(a*pi/180))*v  # Velocidade horizontal Esta correta
            velv = (math.sin(a*pi/180))*v  # Esta correta
            # Esta incorreta
            temp = (((-velv)-(((velv**2) - (2*g*alth))**0.5))/g)
            dist = velh*temp
            if(dist >= inin and dist <= finn):
                print("%.5f -> DUCK" % dist)
            elif(dist < inin or dist > finn):
                print("%.5f -> NUCK" % dist)
            i = i+1
    except EOFError:
        break
