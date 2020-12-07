import numpy as np
#import matplotlib.pyplot as plt
import pmod_mic3
from ctypes import c_longdouble

samples = 50

x = np.zeros(samples)
delta = c_longdouble(0)

delta = pmod_mic3.pmod_mic3_func(x)
print(x)
print("duration: ", delta)
print("Hz: ", (1/delta)*samples)
#plt.plot(x)
#plt.show()

