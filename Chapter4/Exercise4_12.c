#include <stdio.h>
#include <string.h>
void reverse(char s[]);
void itoa_r(int num, char s[], int index);

void itoa(int num, char s[]){
    itoa_r(num, s, 0);
    reverse(s);
}

void itoa_r(int num, char s[], int index){
    if (num < 0){
        num = -1 * num;
    }

    if (num / 10){
        itoa_r(num/10, s, index+1);
    }
    else{
        s[index+1]= '\0';
    }

    char c = num % 10 +'0';
    s[index] = c;

}


void reverse(char s[]){

    int c, i, j;
    for (i  = 0, j = strlen(s)-1; i < j; i++, j--){ 
        c =s[i];
        s[i]=s[j];
        s[j] =c;
    }
}


int main()
{
    char s[100];
    itoa(123, s);
    printf("%s\n", s);

}