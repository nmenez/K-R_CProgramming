#include <stdio.h>
#define BUFSIZE 100

/* not sure what to do here. the EOF is treated as an int which can be pushed into a char array.  maybe this wasn't true when K&R was first written? */
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


int main()
{
    char c;
    while ((c = getch()))
    {
        printf("%i\n", c);
        if (c == EOF){
            printf("ungetching EOF\n");
            printf("%i\n", c);
            ungetch(c);

            char d = getch();
            printf("regetting EOF\n");
            printf("%i\n", d);
            return 0;
        }

    }


}