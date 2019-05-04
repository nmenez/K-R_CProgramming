#include <stdio.h>
#include "Exercise3_2.h"

void test_escape(){
    char orig[] = "h \nc \tabc \a qwer";
    char dest[32] = {'\0'};
    escape(orig, dest);

    char expected[] = "h \\nc \\tabc \\a qwer";
    printf("orig:%s\n expected:%s\n  actual:%s\n", orig, expected, dest);
}



void test_unescape(){
    char orig[] = "abcd\\nb\\tefg\\ahijk\\blmnop";
    char dest[32] = {'\0'};
    unescape(orig, dest);

    char expected[] = "abcd\nb\tefg\ahijk\blmnop";
    printf("orig:%s\n expected:%s\n   actual:%s\n", orig, expected, dest);
}



int main(){
    //test_escape();
    test_unescape();

    return 0;
}