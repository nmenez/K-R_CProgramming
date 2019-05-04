#include <stdio.h>
#include "Exercise4_1.h"


void test_strindex(){
    char s[] = "Blah hello blah hello";
              /*0123456789abcedf*/
    char t[] = "blah";
    int expected = 11;
    int actual = strrindex(s, t);
    printf("actual:%i\nexpected:%i\npass:%i\n", actual, expected, actual==expected);

}

int main(){
    test_strindex();
    return 0;
}