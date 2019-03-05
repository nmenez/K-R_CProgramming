/* Exercise 1-21. Write a program entab that replaces strings of blanks by the
minimum number of tabs and blanks to achieve the same spacing. Use the
same tab stops as for detab. When either a tab or a single blank would suffice
to reach a tab stop, which should be given preference?  */

#include <stdio.h>
#define MAXLINE 1000
#define NTAB  4
#define BLANK ' '
#define TAB '\t'


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

void entab(char s[]){
    int i = 0;
    int j = 0;
    char tmp[MAXLINE] = {'\0'};
    int spaces = 0;
    while (s[i] != '\0')
    {
        if (s[i] == BLANK)
        {    
            spaces++;
        }
        else    
        {   
            int ntabs = spaces / NTAB;
            int remspaces = spaces % NTAB;

            for (int n=0; n<ntabs; n++)
            {
                tmp[j] = TAB;
                j++;
            }
         
            for (int m=0; m<remspaces; m++)
            {
                tmp[j] = BLANK;
                j++;
            }
            tmp[j] = s[i];
            j++;
            spaces=0;
        }
        i++;
    }
    copy(s, tmp);
}


int main(){
    int len;
    char line[MAXLINE] = {'\0'};;
    printf("hello");
    while ((len=getlinex(line, MAXLINE)) > 0)
    {   //printf("old:  %s", line);
        entab(line);
        printf("%s", line);
    }
    return 0;
}
