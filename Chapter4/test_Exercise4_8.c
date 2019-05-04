#include <stdio.h>
#include "Exercise4_8.h"

void test_ungetch(){
    
    ungetch('H');
    char c = getch();
    printf("%c\n", c);
    c = getch();
    printf("%c\n", c);
    

}

int main(){
    test_ungetch();

    return 0;
}