#include <stdio.h>
#include "Exercise2_6.h"
#include "binary_manipulation_utils.h"


void test_teststring()
{   
    char stringA[] = "Hello";
    char stringB[] = "hello";
    int res = testStringEquivalence(stringA, stringB, 6);
    printf("%s, %s, %i\n", stringA, stringB, res);

    char stringC[] = "Hello";
    res = testStringEquivalence(stringC, stringA, 6);
    printf("%s, %s, %i\n", stringC, stringA, res);


}

void test_binarystring(){
    char str[50] = {'\0'};
    unsigned int test = 15;
    test = test << 10; 
    binarystring(test, str);
    
    char expected[] = "0000 0000 0000 0000 0000 0000 0000 1111";
    int res = testStringEquivalence(expected, str, 40);
    printf("expected: %s\nactual:   %s\nres:%i\n", expected, str, res);
    
}

void test_makeOnesMasktAtPosPandLenN()
{
    char expected[] = "0000 0000 0000 0000 1111 1000 0000 0000\0";
    int position = 15;
    int lenght = 5;

    int mask =  makeOnesMasktAtPosPandLenN(position,lenght);

    char str[39] = {'\0'};
    binarystring(~mask, str);
    int res = testStringEquivalence(expected, str, 39);


    printf("expected: %s\nactual:   %s\nres:%i\n", expected, str, res);


}

void test_zeroBitsAtPosPandLenN()
{
    char expected[] = "1010 1010 1010 1010 0000 0010 1010 1010\0";


    int position = 15;
    int length = 5;
    unsigned int input_value = 2863311530;

    unsigned int test_int = zeroBitsAtPosPandLenN(input_value, position, length);

    char str[39] = {'\0'};
    binarystring(test_int, str);
    int res = testStringEquivalence(expected, str, 39);


    printf("expected: %s\nactual:   %s\nres:%i\n", expected, str, res);
 
}


void test_zeroBitsAtPosPandLenN2()
{
    char expected[] = "0000 0000 0000 0000 0000 0000 0001 1111\0";


    int position = 31;
    int length = 31-(5-1);                                                                        
    unsigned int input_value = ~0;

    int test_int = zeroBitsAtPosPandLenN(input_value, position, length);

    char str[39] = {'\0'};
    binarystring(test_int, str);
    int res = testStringEquivalence(expected, str, 39);


    printf("expected: %s\nactual:   %s\nres:%i\n\n", expected, str, res);
 
}

void test_zeroAllbutNRightBits()
{
    char expected[] = "0000 0000 0000 0000 0000 0000 0111 1111\0";
    int input_value = ~0;
    int n = 7;
    int test_int = zeroAllbutNRightBits(input_value,  n);
    char str[39] = {'\0'};
    binarystring(test_int, str);
    int res = testStringEquivalence(expected, str, 39);

    printf("expected: %s\nactual:   %s\nres:%i\n", expected, str, res);


}



void test_setbits(){

    char x_char[] = "0000 0000 0000 1111 1111 1111 1111 1111";
    char y_char[] = "0000 0000 0000 1010 1010 1010 1011 1010";

    int p = 19;
    int n = 6;
    int x = binarystring2int(x_char);
    int y = binarystring2int(y_char);
    int z = setbits(x, p, n, y);

    char z_char[50] = {'\0'};
    binarystring(z, z_char);
    printf(" x:%s\n y:%s\n z:%s\n", x_char, y_char, z_char);
}

int main(){    
    test_setbits();

    return 0;

}

