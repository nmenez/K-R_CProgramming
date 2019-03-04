/* Exercise 1-19. Write a function reverse (s) that reverses the character
string s. Use it to write a program that reverses its input a line at a time. 0*/

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


void reverse(char s[]){
    int j = 0;
    char r[MAXLINE];
    int lim = 0;
    while (s[lim] != '\0'){
        lim++;
    }

    for (int i=lim-1; i>=0; i--)
    {   
        r[j] = s[i];
        j++;
    }
    r[j] = '\0';

    for (int i=0; i<=lim; i++){
        s[i] = r[i];
    }
}

int strip(char s[], int lim){
    if (s[lim-1] == '\n')
    {
        lim--;
        s[lim] = '\0';
    }
    return lim;
}

int main()
{   int len;
    char s[MAXLINE];
  
    while ((len=getlinex(s,MAXLINE))>0)
    {   
        len = strip(s, len);
        
        reverse(s);
        printf("%s\n", s);
    }

    return 0;
}
