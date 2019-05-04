#include <stdio.h>
#include "Exercise3_3.h"


void test_expand(){
    char orig[] = "-0-4a-gA-G-";
    char dest[100] = {'\0'};


    expand(orig, dest);
    char expected[] = "-01234abcdefgABCDEFG-";
    printf("orig:%s\nexpected:%s\nactual:%s\n", orig, expected, dest);

}

void test_strlen()
{
    char test[] = "hello";
    int expected = 5;
    int actual = strlen_(test);

    printf("expected :%i\nactual:%i\npass:%i", expected, actual, expected==actual);

}


void test_innerexpand(){
    char first_char = 'a';
    char last_char = 'd';
    int dest_index = 2;

    char dest[100] = {'\0'};
    dest[0] = ' ';
    dest[1] = 'a';

    int updated_index =  innerexpand(first_char, last_char, dest_index, dest);
    printf("%s\n", dest); 
    printf("%i\n", updated_index);

}

int main()
{
    test_expand();
    //test_strlen();
    //test_innerexpand();
}