#include <stdio.h>
#include <string.h>

void r_reverse(char s[], int last_space){
    char tmp = s[0];
    int i;
    for (i = 1; i <= last_space; i++){
        s[i-1] = s[i];
    }
    s[last_space] = tmp;
    if (last_space > 0){
        r_reverse(s, last_space-1);
    }

}

void reverse(char s[]){
    int last_space = (int) strlen(s) - 1;
    r_reverse(s, last_space);
}

int main(){
    char s[] = "interesting";
    reverse(s);
    printf("%s\n", s);

}