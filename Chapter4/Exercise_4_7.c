#include <string.h>
#include <stdio.h>
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

void ungets(char s[]){
    int string_len = strlen(s);
    printf("bufp %i\nstringlen:%i\n", bufp, string_len);

    if (bufp + string_len >= BUFSIZE){
        printf("ungets: string too big for buffer");
    }
    else{
        for (int n = (string_len -1); n >= 0; n--)
        {   
            ungetch(s[n]);
        }
    }
}
