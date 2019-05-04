#include <stdio.h>
#include "Exercise2_3.h"

void test_hoi(){
    printf("test_hoi\n");
    char test_input[] = "0x1";
    int actual = htoi(test_input);
    int expected = 1;
    printf("actual: %i expected:%i  pass:%i\n", actual, expected, actual == expected);

    char test_input2[] = "12";
    actual = htoi(test_input2);
    expected = 18;
    printf("actual: %i expected:%i  pass:%i\n", actual, expected, actual == expected);


    char test_input3[] = "0x12";
    actual = htoi(test_input3);
    expected = 18;
    printf("actual: %i expected:%i  pass:%i\n", actual, expected, actual == expected);

    char test_input4[] = "0xaa";
    actual = htoi(test_input4);
    expected = 16*10+10;
    printf("actual: %i expected:%i  pass:%i\n", actual, expected, actual == expected);


    char test_input5[] = "aa";
    actual = htoi(test_input5);
    expected = 16*10+10;
    printf("actual: %i expected:%i  pass:%i\n", actual, expected, actual == expected);

    char test_input6[] = "0xff";
    actual = htoi(test_input6);
    expected = 16*15+15;
    printf("actual: %i expected:%i  pass:%i\n", actual, expected, actual == expected);

    char test_input7[] = "0xabcd";
    actual = htoi(test_input7);
    expected = 16*16*16*10 + 16*16*11 + 16*12 + 13;
    printf("actual: %i expected:%i  pass:%i\n", actual, expected, actual == expected);




    printf("______________________\n");


}

void test_first_digit_location()
{   printf("test test_first_digit_location\n");
    int expected, actual;

    expected = 0;
    actual = find_first_digit_location("1234");
    printf("%i\n", expected == actual);


    expected = 2;
    actual = find_first_digit_location("0x123");
    printf("%i\n", expected == actual);


    printf("______________________\n");
}


void test_digit_converter()
{
    int actual;
    printf("test_digit_converter\n");
    actual = digit_converter('0');
    printf("%i\n", actual == 0);

    actual = digit_converter('1');
    printf("%i\n", actual == 1);

    actual = digit_converter('2');
    printf("%i\n", actual == 2);

    actual = digit_converter('3');
    printf("%i\n", actual == 3);

    actual = digit_converter('4');
    printf("%i\n", actual == 4);

    actual = digit_converter('5');
    printf("%i\n", actual == 5);

    actual = digit_converter('6');
    printf("%i\n", actual == 6);

    actual = digit_converter('7');
    printf("%i\n", actual == 7);

    actual = digit_converter('8');
    printf("%i\n", actual == 8);

    actual = digit_converter('9');
    printf("%i\n", actual == 9);

    actual = digit_converter('a');
    printf("%i\n", actual == 10);

    actual = digit_converter('b');
    printf("%i\n", actual == 11);

    actual = digit_converter('c');
    printf("%i\n", actual == 12);

    actual = digit_converter('d');
    printf("%i\n", actual == 13);

    actual = digit_converter('e');
    printf("%i\n", actual == 14);

    actual = digit_converter('f');
    printf("%i\n", actual == 15);

    actual = digit_converter('A');
    printf("%i\n", actual == 10);

    actual = digit_converter('B');
    printf("%i\n", actual == 11);

    actual = digit_converter('C');
    printf("%i\n", actual == 12);

    actual = digit_converter('D');
    printf("%i\n", actual == 13);

    actual = digit_converter('E');
    printf("%i\n", actual == 14);

    actual = digit_converter('F');
    printf("%i\n", actual == 15);

    printf("______________________\n");


}


int main(){
    test_digit_converter();
    test_first_digit_location();
    test_hoi();

}