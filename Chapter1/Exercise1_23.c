/* Exercise 1-23. Write a program to remove all comments from a C program.  
Don't forget to handle // quoted strings and character constants properly. C comments do not nest.  */

#include <stdio.h> 
#define INBLOCKCOMMENT 0
#define OUTCOMMENT 1
#define INLINECOMMENT 2

void remove_comments(){

    int buffer[2] = {'\0', '\0'}; 
    int c;
    int status = OUTCOMMENT;
    while ((c = getchar()) != EOF)
    {
        buffer[0] = buffer[1]; //move character in buffer pos 1 to pos 0
        buffer[1] = c; // add current */ character  to buffer

        // block comment
        if ((status == OUTCOMMENT) & (buffer[0] == '/') & (buffer[1] == '*'))
        {
            status = INBLOCKCOMMENT;
        }

        if ((status == INBLOCKCOMMENT) & (buffer[0] == '*') & (buffer[1] == '/'))
        {
            status = OUTCOMMENT;
            buffer[0] = '\0';
            buffer[1] = '\0';
        }

        //in line comment
        if ((status == OUTCOMMENT) & (buffer[0] == '/') & (buffer[1] == '/'))
        {
            status = INLINECOMMENT;
        }

        if ((status == INLINECOMMENT) & (c == '\n'))
        {
            status = OUTCOMMENT;
            printf("\n");
            buffer[0] = '\0';
            buffer[1] = '\0';
        }


        if ((status == OUTCOMMENT) & (buffer[1] != '\0') & (buffer[0] != '\0'))
        {
           printf("%c", buffer[0]);
        }

    }
    if ((status == OUTCOMMENT) & (buffer[1] != '\0'))  // print last character if OUTCOMMENt
    {
        printf("%c", buffer[1]);
    }
}


int main()
{
    remove_comments();
    return 0;
}
