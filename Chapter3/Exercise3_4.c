/* itoa: convert n to characters in s */
#include <string.h>
#include <stdio.h>

void reverse(char s[]){

    int c, i, j;
    for (i  = 0, j = strlen(s)-1; i < j; i++, j--){ 
        c =s[i];
        s[i]=s[j];
        s[j] =c;
    }
}


int abs(int x){
    return (x < 0) ? -x : x;
}

void itoa(int n, char s[]){
    int i, sign;
    int digit;
    if (n < 0)
    {sign = -1;}
    else{
        sign = 1;
    }

        
    i = 0;
    do {
        digit = abs(n % 10);
        s[i++] = digit  + '0';
    } while (abs(n/=10) > 0);

    if (sign < 0){
        s[i++] = '-';
    }
    s[i]  = '\0';
    reverse(s);
}


void itob(int n, char s[], int b){
    int i, sign;
    int digit;
    char digit_char;
    if (n < 0)
    {sign = -1;}
    else{
        sign = 1;
    }
        
    i = 0;
    do {
        digit = abs(n % b);
        if (digit >= 10){
            digit_char = 'A' + (digit-10);
        }
        else
            digit_char = digit + '0';
        s[i++] = digit_char;

    } while (abs(n/=b) > 0);

    if (sign < 0){
        s[i++] = '-';
    }
    s[i]  = '\0';
    reverse(s);
}


void itoa_min(int n, char s[], int min_width){
    int i, sign;
    int digit;
    if (n < 0)
    {sign = -1;}
    else{
        sign = 1;
    }

        
    i = 0;
    do {
        digit = abs(n % 10);
        s[i++] = digit  + '0';
    } while (abs(n/=10) > 0);

    if (sign < 0){
        s[i++] = '-';
    }


    while (i < min_width)
    {
        s[i] = ' ';
        i++;
    }
    reverse(s);
    s[i] = '\0';
}
