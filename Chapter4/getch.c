#include <stdio.h>
#include <ctype.h>
#include "calc.h"

#define BUFSIZE 100

char buff[BUFSIZE];
int bufp = 0;

int getch(void)
{   
    if (bufp > 0)
        return buff[--bufp];
    else{
        char c = getchar();
        return c;
    }
}

void ungetch(int c){
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buff[bufp++] = c;

}

int peak()
{
    int next = getch();
    ungetch(next);
    return next;
}
