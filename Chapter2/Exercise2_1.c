/* Exercise 2-1. Write a program to determine the ranges of char, short, int,
and long variables, both signed and unsigned, by printing appropriate values from standard headers
 and by direct computation. Harder if you compute them: determine the ranges of the various floating-point types.
*/

/* 
direct computation can be easily done by bit manipulation.  but at this point in the book bit manipulation has not 
been introduced yet
*/

#include <stdio.h>
#include <limits.h>

long int pow_(long int base, long int n)
{
    long int i, p;
    p=1;
    for (i=1; i<=n; i++)
    {
        p = p * base;
    }
    return p;
}

int main()
{   
    printf("-------------------\n");

    printf("\n");
    printf("CHAR MAX %d\n", CHAR_MAX);
    printf("CHAR MIN %d\n", CHAR_MIN);

    printf("\n");  
    printf("SHORT INT MAX %d\n", SHRT_MAX);
    printf("SHORT INT MIN %d\n", SHRT_MIN);

    printf("\n");
    printf("INT MAX %d\n", INT_MAX);
    printf("INT MIN %d\n", INT_MIN);

    printf("\n");
    printf("LONG INT MAX %ld\n", LONG_MAX);
    printf("LONG INT MIN %ld\n", LONG_MIN);

    printf("-------------------\n");
    printf("\n");  
    printf("USHORT INT MAX %d\n", USHRT_MAX);

    printf("\n");
    printf("UINT MAX %u\n", UINT_MAX);

    printf("\n");
    printf("ULONG INT MAX %lu\n", ULONG_MAX);

    printf("-------------------\n");
    printf("calc CHAR MAX %ld\n", pow_(2, 8)/2-1);
    printf("calc CHAR MIN %ld\n", -1*pow_(2,8)/2);

    printf("\n");
    printf("calc SHORT MAX %ld\n", pow_(2, 16)/2-1);
    printf("calc SHORT MIN %ld\n", -1*pow_(2,16)/2);

    printf("\n");
    printf("calc INT MAX %ld\n", pow_(2, 32)/2-1);
    printf("calc INT MIN %ld\n", -1*pow_(2,32)/2);

    printf("\n");
    printf("calc LONG INT MAX %ld\n", pow_(2, 63)-1);
    printf("calc LONG INT MIN %ld\n", -1*pow_(2,63));


    printf("-------------------\n");
    printf("calc UCHAR MAX %lu\n", pow_(2, 8)-1);

    printf("\n");
    printf("calc USHORT MAX %lu\n", pow_(2, 16)-1);

    printf("\n");
    printf("calc UINT MAX %lu\n", pow_(2, 32)-1);

    printf("\n");
    printf("calc UINT MAX %lu\n", pow_(2, 64)-1);
    printf("-------------------\n");


    printf("\n");
    printf("%f", pow_(2,64)-1);

}