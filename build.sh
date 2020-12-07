#!/bin/bash

gcc -pthread -c -fPIC pmod_mic3.c -o pmod_mic3.o -lpigpio
gcc -shared -Wl,-soname,libpmod_mic3.so -o libpmod_mic3.so pmod_mic3.o -lpigpio
