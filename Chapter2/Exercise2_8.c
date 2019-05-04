
//Exercise 2-8. Write a function rightrot(x,n) that returns the value of the integer x rotated to the right by n bit positions. 0
#include <stdio.h>
#include "binary_manipulation_utils.h"

int rotaterightone(int x){
    int y = (x & 1) << 31;
    x = x >> 1;


    return x | y;

}

int rightrot(int x, int n){
    for (int i=0; i<n;i++){
        x = rotaterightone(x);

    }
    return x;
}

int rightrot_better(int x, int n){

    int right_most_mask = ~(~0 << n); 
    int right_most_bits = x & right_most_mask;
    right_most_bits <<= (31-n+1);

    int x_shift_right = x >> n;
    return x_shift_right | right_most_bits;
}