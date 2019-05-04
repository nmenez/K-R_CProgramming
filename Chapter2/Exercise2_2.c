/* Exercise 2-2. Write a loop equivalent to the for loop above without using &.&. or II. 0

i am restricting myself to using only language features that have been introduced
up to this point in the book.  (can't use break)
    
for (i=O; i<lim-1 && (c=getchar(» 1= '\n' && c 1= EOF; ++i) s[i] =c;
*/  

#include <stdio.h>


int getline_(char s[], int lim)
{
    int c, i;
    for (i=0; i<lim-1 && (c=getchar()) !=EOF && c!='\n'; ++i)
        s[i] = c;

    if (c == '\n')
    {
        s[i] = c;
        ++i ;
    }
    s[i] = '\0';
    return i;
}


int getline_no_ands_ors(char s[], int lim)
{
    int c;
    int  i=0;
    while ((c=getchar()) !=EOF)
    {   
        if (i == lim -1)
        {  
            s[i] = '\0';
            return i;
        }
        else if (c == EOF)
        {
            
            s[i] = '\0';
            return i;
        }
        else if (c == '\n')
        {   i++;
            s[i] = c;
            s[i] = '\0';
            return i;
        }
        else
        {
            s[i] = c;
            i++;
        }
    }

    s[i] = '\0';
    return i;
}


int main()
{   char s[10000];
    int len = getline_no_ands_ors(s, 10000);
    printf("%s\n", s);
    printf("%d\n", len);
}