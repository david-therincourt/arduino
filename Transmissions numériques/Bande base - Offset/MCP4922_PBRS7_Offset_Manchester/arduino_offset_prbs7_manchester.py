# Mise en forme d'un signal PRS7 en symbole
# NRZ (+3V ,-3V) sur 12 bits pour Arduino

import numpy as np


def data_to_arduino(tab, name):
    txt = name + " [] = {\n"
    n = 0
    for val in tab:
        if n<16:
            txt += str(val) + ',\t'
            n += 1
        else:
            txt += str(val) + ',\n'
            n =0
    txt = txt[:-2] + '};'
    return txt

###################
prbs7 = np.load("prbs7.npy")
prbs7 = prbs7[:-11]

N = len(prbs7)
data = []

A_plus = 2048+1800
A_moins = 2048-1800

for i in range(N):
    if prbs7[i] == 1:
        data.append(A_plus)
        data.append(A_moins)
    else:
        data.append(A_moins)
        data.append(A_plus)

        

print(data_to_arduino(data, "uint16_t s"))
