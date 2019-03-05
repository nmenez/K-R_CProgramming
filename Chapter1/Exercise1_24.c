/* Exercise 1-24. Write a program to check a C program for rudimentary syntax errors 
like unbalanced parentheses, brackets and braces.
 Don't forget about quotes, both single and double, escape sequences, and comments.
  (This program is hard if you do it in full generality.)
*/

#include <stdio.h>
#define INQUOTE 0
#define OUTQUOTE 1
#define INDOUBLEQUOTE 2
#define ESCAPE 3
#define INBLOCKQUOTE 4
#define INLINEQUOTE 5
#define SYNTAXERROR 6
#define NOSYNTAXERROR  7

int check_syntax()
{   
    /* there are many ways this function can be improved.  I am limiting myself only to the techniques
    introduced in Chapter 1 of K&C.  therefore i can not use pass by reference, pointer, switch, etc
    */
    int status = OUTQUOTE;
    int syntax_stack[1000];
    int buffer[2] = {'\0', '\0'};
    /* indicates where the syntax_stack is initialize to 0 because when the first element is placed on a stack 
       the syntax_stack position should point at the first element (i.e. position 0)
    */
    int syntax_stack_position = -1; 
    int c;
    while ((c=getchar()) != EOF)
    {  
        buffer[0] = buffer[1]; //move character in buffer pos 1 to pos 0
        buffer[1] = c; // add current */ character  to buffer

        if (status == OUTQUOTE)
        {    
  
            if ((buffer[0] == '/') & (buffer[1] == '*'))
            {
                status =  INBLOCKQUOTE;
                syntax_stack_position++;
                syntax_stack[syntax_stack_position] = '/';
                syntax_stack_position++;
                syntax_stack[syntax_stack_position] = '*';
            }   

            if ((buffer[0] == '/') & (buffer[1] == '/'))
            {
                status =  INLINEQUOTE;
                syntax_stack_position++;
                syntax_stack[syntax_stack_position] = '/';
                syntax_stack_position++;
                syntax_stack[syntax_stack_position] = '/';
            }  


            if ((c == '{') | (c=='[') | (c=='('))
            {
                syntax_stack_position++;
                syntax_stack[syntax_stack_position] = c;
            }

            else if (c == '}') 
            {   
                if (syntax_stack[syntax_stack_position] == '{')
                    {
                        syntax_stack[syntax_stack_position] = '\0';
                        syntax_stack_position--;
                    }
                else{
                        syntax_stack_position++;
                        syntax_stack[syntax_stack_position] = c;
                    }
            }

            else if (c == ']') 
            {   
                if (syntax_stack[syntax_stack_position] == '[')
                    {
                        syntax_stack[syntax_stack_position] = '\0';
                        syntax_stack_position--;
                    }
                else{
                        syntax_stack_position++;
                        syntax_stack[syntax_stack_position] = c;
                    }
            }
     
            else if (c == ')') 
            {   
                if (syntax_stack[syntax_stack_position] == '(')
                    {
                        syntax_stack[syntax_stack_position] = '\0';
                        syntax_stack_position--;
                    }
                else{
                        syntax_stack_position++;
                        syntax_stack[syntax_stack_position] = c;
                    }
            }

            else if (c == '\'')
            {
                syntax_stack_position++;
                syntax_stack[syntax_stack_position] = c;
                status = INQUOTE;
                printf("INQUOTE");
            }

            else if (c == '\"')
            {
                syntax_stack_position++;
                syntax_stack[syntax_stack_position] = c;
                status = INDOUBLEQUOTE;
                printf("INDOUBLEQUOTE");
            }

        }

        else if (status == INQUOTE)
        {
            if (c == '\'')
            {   printf("OUTQUOTE");
                syntax_stack[syntax_stack_position] = '\0';
                syntax_stack_position--;
                status = OUTQUOTE;
            }
            else if (c =='\\')
            {
                syntax_stack_position++;
                syntax_stack[syntax_stack_position] = c;
                status = ESCAPE;
                printf("ESCAPE");
            }

        }

        else if (status == INDOUBLEQUOTE)
        {
            if (c=='\"')
            {
                printf("OUTQUOTE");
                syntax_stack[syntax_stack_position] = '\0';
                syntax_stack_position--;
                status = OUTQUOTE;                

            }
        }

        else if (status == ESCAPE)
        {
            if ((c=='a') | (c=='b') | (c=='e') | (c=='f') | (c=='n') | (c=='r') | (c=='t') | (c=='v') | (c=='\\') | (c=='\'') | (c=='\"') | (c=='0'))
            {
                printf("INQUOTE");
                syntax_stack[syntax_stack_position] = '\0';
                syntax_stack_position--;
                status = INQUOTE;
            }
        }

        else if (status == INBLOCKQUOTE)
        {
           if ((buffer[0] == '*') & (buffer[1] == '/'))
           {
                syntax_stack[syntax_stack_position] = '\0';
                syntax_stack_position--;
                syntax_stack[syntax_stack_position] = '\0';
                syntax_stack_position--;
                status = OUTQUOTE;
           }
        }

        else if (status == INLINEQUOTE)
        {
            if (c=='\n')
            {
                syntax_stack[syntax_stack_position] = '\0';
                syntax_stack_position--;
                syntax_stack[syntax_stack_position] = '\0';
                syntax_stack_position--;
                status = OUTQUOTE;
            }
        }


        if (c=='\n')
        {
            printf("\n");
        }

        printf("%i", syntax_stack_position);
    }
    
    if (syntax_stack_position == -1)
    {
        return NOSYNTAXERROR;
    }
    else
    {
        return SYNTAXERROR;
    }
}


int main()
{
    int res = check_syntax();
    if (res == NOSYNTAXERROR)
    {
        printf("all good\n");
    }
    else
    {   
        printf("no good\n");
    }
}