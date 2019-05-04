/* Exercise 4-1. Write the function strrindex (s, t), which returns the position
of the rightmost occurrence of t in s, or - 1 if there is none. 0
*/

int strindex(char s[], char t[])
{
    int i, j, k;
    for (i = 0; s[i] != '\0'; i++) {
        for (j=i, k=0; t[k] != '\0' && s[j]==t[k]; j++, k++)
        ;
        if (k > 0 &&t[k] == '\0') 
            return i;
    }
    return -1;
}

int strlen_(char s[]){
    int N = 0;
    for (int i=0; s[i] != '\0'; i++){
        N++;
    }
    return N;
}

int strrindex(char s[], char t[])
{
    int i, j, k;
    int N = strlen_(s);
    for (i = N-1; i > 0; i--) {
        for (j=i, k=0; t[k] != '\0' && s[j]==t[k]; j++, k++)
        ;
        if (k > 0 &&t[k] == '\0') 
            return i;
    }
    return -1;
}
