#include <stdio.h>


int makeOnesMasktAtPosPandLenN(int p, int n){
  return ~(~0 << n) << (p-n+1);
}

int zeroBitsAtPosPandLenN(int input, int p, int n){
  int mask = makeOnesMasktAtPosPandLenN(p, n);

  return input & ~mask;
}

int zeroAllbutNRightBits(int input, int n){
  int mask = makeOnesMasktAtPosPandLenN(n-1, n);
  return input & mask;

}

int setbits(int x, int p, int n, int y){
  x = zeroBitsAtPosPandLenN(x, p, n);
  y = zeroAllbutNRightBits(y, n);
  y = y << (p - n + 1);
  return x | y;
}

