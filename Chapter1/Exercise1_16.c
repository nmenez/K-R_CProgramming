#include <stdio.h>
#define MAXLINE 10

int getlinex(char s[], int li);
void copy(char to[], char from[]);

int main()
{
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];
    int c;
    max = 0;
    while ((len = getlinex(line, MAXLINE)) > 0){
        if (len > max){
            max = len;
            copy(longest, line);
        }

        if (max >= 0)
            printf("%s", longest);

        if (len  == (MAXLINE-1))
        {   
            while (((c=getchar()) != EOF) && (c!='\n'))
            {   len++;
                putchar(c);
            }
            len++;
        }
        printf("\n");
        printf("line length %i\n", len-1);
    }
    return 0;
}


int getlinex(char s[], int lim)
{
    int c, i;
    for (i=0; (i <lim-1 && ((c=getchar()) != EOF) && c != '\n'); ++i)
    {   
        s[i] = c;
    }
    if (c == '\n'){
        s[i] = c;
        i++;
    }
    s[i] = '\0';
    return i;
}


void copy(char to[], char from[]){
    int i;
    i=0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}