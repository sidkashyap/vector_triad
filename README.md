# vector_triad


Compiler instructions for Intel:

icc mem_saxpy.c -fast -vec-report=7 -o mem_saxpy -std=c99

This is a generic program for us to measure the performance (FLOPS) of the system under various floating point vector lengths. README has the further instructions. 
