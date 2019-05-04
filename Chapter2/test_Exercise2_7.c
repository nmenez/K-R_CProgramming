#include <stdio.h>
#include "binary_manipulation_utils.h"
#include "Exercise2_7.h"

void test_invert(){
    char x_str[] =    "0000 0000 0000 0000 1100 0101 0000 1111";
    int x = binarystring2int(x_str);


    char expected[] = "0000 0000 0000 0000 0011 1010 1111 1111";
    int p = 15;
    int n = 12;
    int y = invert(x, p, n);

    char actual[40] = {'\0'};
    binarystring(y, actual);

    int pass = testStringEquivalence(expected, actual);
    printf("%i %i\n", getlen(expected), getlen(actual));
    printf("expected: %s\n  actual: %s\npass:%i\n", expected, actual, pass);

}

int main()
{   
    test_invert();
    return 0;
}