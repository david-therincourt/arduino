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
S0, S1 = 2480-1800, 2048+1800   #           

for i in range(0,N):
    if prbs7[i] == 0:
        data.append(S0)
    else:
        data.append(S1)

        

print(data_to_arduino(data, "uint16_t s"))
