/*Exercise 1-14. Write a program to print a histogram of the frequencies of different
characters in its input */
#include <unistd.h>
#include <stdio.h>

int main(){
    int c;
    int chararray[255];

    for (int i=0; i<256; i++){
        chararray[i] = 0;
    }

    while ((c=getchar()) != EOF ){
        chararray[c]++ ;
    }

    for (int i=0; i<256; i++){
        if (chararray[i] > 0){
            printf("%c:", i);
           for (int j = 0; j<chararray[i]; j++)
           {
                printf("#");
           }
           printf("\n");
        }
    }

    return 0;

}