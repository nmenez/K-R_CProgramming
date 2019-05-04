#include <stdio.h>
#include "Exercise4_2.h"


void test_atof()
{
    char test[] = "1.3e4";
    double res = atof(test);
    printf("%f\n", res);
    printf("success: %i\n", res == 13000);
}


int main(){
    test_atof();
    return 0;
}
