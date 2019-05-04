#include <stdio.h>
#include "Exercise2_4.h"

void test_find_character_in_string()
{
    char test_in[] = "hello";
    char test_char = 'h';

    int expected = 1;
    int actual = find_character_in_string(test_in, test_char);

    // find_character_in_string(test_in, test_char);

    printf("expected: %i, actual: %i\n", expected, actual);

    expected = 0;
    actual = find_character_in_string(test_in ,'z');
    printf("expected: %i, actual: %i\n", expected, actual);


    expected = 1;
    actual = find_character_in_string(test_in ,'l');
    printf("expected: %i, actual: %i\n", expected, actual);
}


void test_squeeze()
{
    char test_delete_from[] = "hello there";
    char test_check_from[] = "there";

    squeeze(test_delete_from, test_check_from);
    char expected[] = "llo";
    printf("expected: %s, actual: %s\n", expected, test_delete_from);


}


int main()
{   
    test_squeeze();
    test_find_character_in_string();
}
