/* Exercise 1-17. Write a program to print all input lines that are longer than 80
characters. 0 */

#include <stdio.h>
#define MAXLINE 1000
#define PRINTLONGER 80



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


int main()
{   int len;
    char line[MAXLINE];
    while ((len=getlinex(line, MAXLINE)) > 0)
    {   printf("\n");
        if (len > PRINTLONGER)
        {   
            printf("%s", line);
        }
    }
    return 0;
}