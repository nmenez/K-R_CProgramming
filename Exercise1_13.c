/*Exercise 1-13. Write a program to print a histogram of the lengths of words in
its input. It is easy to draw the histogram with the bars horizontal; a vertical
orientation is more challenging. */

#include <stdio.h>

#define MAXWORDLENGTH 20

int main(){
    int nword[MAXWORDLENGTH+1];
    int c;
    for (int i=0; i<=MAXWORDLENGTH; i++){
        nword[i] = 0;
    }

    int wordlength = 0;
    while ((c=getchar()) != EOF){
        if ((c == ' ') || (c == '\t') || (c=='\n')){
            nword[wordlength]++;
            wordlength = 0;
        }
        else{
            wordlength++;
        }
    }
    // Horizontal
    printf("#########HORIZONTAL############\n");
    for (int i =1; i<=MAXWORDLENGTH; i++)
    {
        if (i < 10){
            printf("0%d:", i);
        }
        else
        {
            printf("%d:",i);
        }
        for (int j=0; j<nword[i]; j++)
        {
            printf("#");
        }
        printf("\n");
    }
    printf("###############################\n");

    // Vertical
    printf("#########VERTICAL############\n");

    int maxvalue = 0;
    for (int i=1; i<=MAXWORDLENGTH; i++){
        if (nword[i] > maxvalue)
            maxvalue = nword[i];
    } 
    for (int row=maxvalue; row>0; row--){
        for (int i=1; i<=MAXWORDLENGTH; i++){
            if (nword[i] >= row){
                printf("  #");
            }
            else{
                printf("   ");
            }

        }
        printf("\n");
    }
    for (int i=1; i<=MAXWORDLENGTH;i++){
        if (i <10)
            printf("|0%d", i);
        else
            printf("|%d", i);
    }
    printf("\n");
    return 0;

}