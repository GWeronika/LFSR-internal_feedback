# LFSR-internal_feedback
Random number generation with linear feedback shift register (LFSR)

LFSR inner feedback is a type of feedback where the signal from the output of the last flip-flop is fed to its inputs.

Project LFSR-internal_feedback:

INPUT:
  n - variable specifying the lenght of the register (consists of a set of integers)
  r - initial state with a length of n digits (consists of the digits {0,1})
  
OUTPUT:
  tab[0]...tab[n-1] - vector containing successive elements of the register
