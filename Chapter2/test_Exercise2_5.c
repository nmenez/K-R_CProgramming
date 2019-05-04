#include <stdio.h>
#include "Exercise2_5.h"

void test_find_position_of_char()
{   printf("test_find_position_of_char\n");
    char look_string[] = "hello";
    char char_look = 'e';

    int expected = 1;
    int actual = find_position_of_char(look_string, char_look);
    printf("expected: %i, actual: %i, pass:%i\n", expected, actual, expected==actual);

    printf("_________________\n");
}


void test_find_position_of_char2()
{   char look_string[] = "hello";
    char char_look = 'z';

    int expected = -1;
    int actual = find_position_of_char(look_string, char_look);
    printf("expected: %i, actual: %i, pass:%i\n", expected, actual, expected==actual);

    printf("_________________\n");
}

void test_find_position_of_char3()
{   char look_string[] = "hello";
    char char_look = 'l';

    int expected = 2;
    int actual = find_position_of_char(look_string, char_look);
    printf("expected: %i, actual: %i, pass:%i\n", expected, actual, expected==actual);

    printf("_________________\n");
}


void test_any(){
    printf("test_any\n");
    char test_in[] = "hello";
    char test_look[] = "bae";

    int expected = 1;
    int actual = any(test_in, test_look);

    printf("expected: %i, actual: %i, pass:%i\n", expected, actual, expected==actual);
    printf("___________________");

}



void test_any2(){
    printf("test_any\n");
    char test_in[] = "qwertyuiop";
    char test_look[] = "bae";

    int expected = 2;
    int actual = any(test_in, test_look);

    printf("expected: %i, actual: %i, pass:%i\n", expected, actual, expected==actual);
    printf("___________________");

}

void test_any3(){
    printf("test_any\n");
    char test_in[] = "qwrtyuiop";
    char test_look[] = "bae";

    int expected = -1;
    int actual = any(test_in, test_look);

    printf("expected: %i, actual: %i, pass:%i\n", expected, actual, expected==actual);
    printf("___________________");

}


void test_any4(){
    printf("test_any\n");
    char test_in[] = "qwrtyuiop";
    char test_look[] = "baep";

    int expected = 8;
    int actual = any(test_in, test_look);

    printf("expected: %i, actual: %i, pass:%i\n", expected, actual, expected==actual);
    printf("___________________");

}

int main(){
    test_find_position_of_char();
    test_find_position_of_char2();
    test_find_position_of_char3();
    test_any();
    test_any2();
    test_any3();
    test_any4();
}