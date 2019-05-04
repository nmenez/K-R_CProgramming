//Exercise 2-7. Write a function invert(x,p,n) that returns x with the n bits that begin at position p inverted (i.e., I changed into 0 and vice 
//versa), leaving the others unchanged. 0

#include <stdio.h>

int makeOnesMasktAtPosPandLenN(int p, int n){
  return ~(~0 << n) << (p-n+1);
}



int invert(int x, int p, int n)
{
    int mask = makeOnesMasktAtPosPandLenN(p, n);

    return x^mask;
};
