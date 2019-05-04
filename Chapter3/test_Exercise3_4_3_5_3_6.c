#include <stdio.h>
#include "Exercise3_4.h"


void test_itoa()
{
    char test[100] = {'\0'};
    int x = -(1<<31) ;    
    itoa(x, test);
    printf("%s\n", test);
    
}

void test_itob()
{   for (int x =0; x<256; x++){
        char test[100] = {'\0'};
        itob(x, test, 2);
        printf("%i %s ", x, test);
        itob(x, test, 16);
        printf("%s\n", test);
    }
}

void test_itoa_min()
{
    char test[100] = {'\0'};
    int x = -200;    
    int min_width = 10;
    itoa_min(x, test, min_width);
    printf("%s\n", test);

    x = -2000;    
    min_width = 10;
    itoa_min(x, test, min_width);
    printf("%s\n", test);

}

int main()
{   test_itoa();
    test_itob();
    test_itoa_min();
    return 0;
}