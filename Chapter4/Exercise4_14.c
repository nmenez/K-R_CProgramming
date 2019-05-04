#include <stdio.h>
#define swap(t, x, y)  t temp = y; y=x;x=temp;

int main(){
    double a = 1.0;
    double b = 2.2;
    swap(double, a, b);
    printf("a=%f\n", a);
    printf("b=%f\n", b);
}