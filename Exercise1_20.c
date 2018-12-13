/*Exercise 1-20. Write a program detab that replaces tabs in the input with the
proper number of blanks to space to the next tab stop. Assume a fixed set of
tab stops, say every n columns. Should n be a variable or a symbolic parameter?

0123012301230123
0123456789abcdef
t   t   t
hellotworld
hello   world
thello world
    hello world
*/


#include <stdio.h>
#define MAXLINE 1000
#define NTAB  5

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

void entab(char s[])
{ 
    char tmp[MAXLINE];
    int i, j;
    i = j = 0;

    while (s[i] != '\0')
    {   
        if (s[i] == '\t')
        {   tmp[j] = '#';
            j++;
            while ((j%NTAB) != 0)
            {   
                tmp[j] = '#';
                j++;
            }
        }
        else
        {
            tmp[j] = s[i];
            j++;
            
        }
        i++;
       
    }
    copy(s, tmp);
}

char line[MAXLINE];
int len;
int main()
{    
    printf("t1234t1234t1234t1234t1234t1234t1234t1234\n");
    while ((len=getlinex(line, MAXLINE)) > 0)
    {   
        
        entab(line);
        printf("%s", line);
    }
    
}