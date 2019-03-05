

#include <stdio.h> 
#define INBLOCKCOMMENT 0
#define OUTCOMMENT 1
#define INLINECOMMENT 2
/* indicates where the syntax_stack is initialize to 0 because when the first element is placed on a stack 
       the syntax_stack position should point at the first element (i.e. position 0)
*/

void remove_comments(){
   {
    int buffer[2] = {'\0', '\0'}; 
    int c;
    int status = OUTCOMMENT;
    while ((c = getchar()) != EOF)
    {
        buffer[0] = buffer[1]; 
        buffer[1] = c; 
        
        if ((status== OUTCOMMENT) & (buffer[0] == '/') & (buffer[1] == '*'))
        {
            status = INBLOCKCOMMENT;
        }

        if ((status == INBLOCKCOMMENT) & (buffer[0] == '*') & (buffer[1] == '/'))
        {
            status = OUTCOMMENT;
            buffer[0] = '\0';
            buffer[1] = '\0';
        }

        
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
    if ((status == OUTCOMMENT) & (buffer[1] != '\0'))  
    {
        printf("%c", buffer[1]);
    }
}
}

int main()
{
    remove_comments();
    int c = '\a'; 

}
