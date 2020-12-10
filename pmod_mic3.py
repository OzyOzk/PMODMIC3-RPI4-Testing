import numpy as np
import numpy.ctypeslib as npct
from ctypes import c_int
from ctypes import c_longdouble

# Input for the pmod_mic3 c function
array_1d_double = npct.ndpointer(dtype=np.double, ndim=1, flags='CONTIGUOUS')

# numpy c library loading function
libcd = npct.load_library("libpmod_mic3", ".")

# arg and return types
libcd.pmod_mic3.restype = c_longdouble
libcd.pmod_mic3.argtypes = [array_1d_double, c_int]

def pmod_mic3_func(in_array):
    return libcd.pmod_mic3(in_array, len(in_array))
