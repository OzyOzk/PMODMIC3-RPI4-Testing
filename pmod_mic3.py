import numpy as np
import numpy.ctypeslib as npct
from ctypes import c_int
from ctypes import c_longdouble

# input type for the cos_doubles function
# must be a double array, with single dimension that is contiguous
array_1d_double = npct.ndpointer(dtype=np.double, ndim=1, flags='CONTIGUOUS')

# load the library, using numpy mechanisms
libcd = npct.load_library("libpmod_mic3", ".")

# setup the return types and argument types
libcd.pmod_mic3.restype = c_longdouble
libcd.pmod_mic3.argtypes = [array_1d_double, c_int]


def pmod_mic3_func(in_array):
    return libcd.pmod_mic3(in_array, len(in_array))
