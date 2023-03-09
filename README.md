# LFSR-internal_feedback
Random number generation with linear feedback shift register (LFSR)

LFSR inner feedback is a type of feedback where the signal from the output of the last flip-flop is fed to its inputs.

![internal_feedback](https://user-images.githubusercontent.com/126601389/224120046-ff86207b-159b-4e7c-940d-c9201b1c1865.png)


Project LFSR-internal_feedback:

INPUT:
  n - variable specifying the lenght of the register (consists of a set of integers)
  r - initial state with a length of n digits (consists of the digits {0,1})
  
OUTPUT:
  tab[0]...tab[n-1] - vector containing successive elements of the register
