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
data_plus = []
data_moins = []
S = 200

for i in range(N):
    if prbs7[i] == 1:
        data_plus.append(S)
        data_moins.append(0)
    else:
        data_plus.append(0)
        data_moins.append(S)
        

print(data_to_arduino(data_plus, "uint8_t s_plus"))
print()
print(data_to_arduino(data_moins, "uint8_t s_moins"))