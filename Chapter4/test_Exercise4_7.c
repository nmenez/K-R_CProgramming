#include <stdio.h>
#include "Exercise4_7.h"

void test_ungets1(){
    char s[] = "hello";
    ungets(s);
    char lorem[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Quisque et massa congue, interdum ame";
    ungets(lorem);    
    char c;
    while ((c = getch()) != EOF){
        printf("%c", c);
}
}

int main(){
    test_ungets1();
    return 0;
}