/*Exercise 1-18. Write a program to remove trailing blanks and tabs from each
line of input, and to delete entirely blank lines. */

#include <stdio.h>
#define MAXLINE 1000

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

int trim(char s[], int len){
    int i=len-2;
    int newlen;
    while (((s[i] == ' ') || (s[i] == '\t')))
    {   
        i--;
    }
    newlen = i+1;
    s[newlen] = '\n';
    s[newlen+1] = '\0';
    newlen++;
    return newlen;
}

int main()
{   
    char s[MAXLINE];
    int len;
    while ((len = getlinex(s, MAXLINE))> 0)
    {
        int newlen = trim(s, len);
        if (newlen > 1)
            printf("%s", s);
    }
    return 0;
}