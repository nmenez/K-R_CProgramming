#include <stdio.h>
#include <ctype.h>
#include "calc.h"
#include <stdlib.h>
#include <string.h>

static char static_c = 0;


int getop(char s[]){
    int i, c, next_c;

    if (static_c != 0){
        c = static_c;
    }
    else{
        c = getch();
    }
    static_c = 0;


    while ((s[0] = c)  == ' ' || c == '\t')
    {
        c = getch();
    }
 
    if ((c=='s') || (c=='c') || (c=='e') || (c=='p'))
    {   getch();
        getch();
        switch (c){
            case 's':
                return 'S';
            case 'c':
                return 'C';
            case 'e':
                return 'E';
            case 'p':
                return 'P';

        }

    }

    s[1] = '\0';

    if ((c >= 'A') && (c <='Z')){
        s[0] = c;
        return VAR;
    }

    if (c == '='){
        return VAR_ASSIGNMENT;
    }

    next_c = peak(); 
    i = 0;
    if ((isdigit(next_c)) & (c == '-' ))
    {   s[0] = '-';
        i = 1;
        c = getch();
        s[i] = c;

    } 
    else if (!isdigit(c) && (c != '.'))
    {  
        return c;
    }

    if (isdigit(c))
        while (isdigit(s[++i] = c = getch()))
            ;

    if (c == '.') 
        while (isdigit(s[++i] = c = getch()))
            ;

    s[i] = '\0';
    if (c != EOF)
        static_c = c;

    return NUMBER;
}
