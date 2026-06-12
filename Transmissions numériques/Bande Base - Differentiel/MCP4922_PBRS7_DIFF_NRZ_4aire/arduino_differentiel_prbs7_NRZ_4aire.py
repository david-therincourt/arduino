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
S0, S1, S2, S3 = 2480-1800, 2048-600, 2048+600, 2048+1800   # -3 / -1 / +1 / +3           

for i in range(0,N,2):
    n = prbs7[i]*2 + prbs7[i+1]
    if n == 0:
        data.append(S0)
    elif n == 1:
        data.append(S1)
    elif n == 3:
        data.append(S2)
    elif n == 2:
        data.append(S3)

        

print(data_to_arduino(data, "uint16_t s"))
