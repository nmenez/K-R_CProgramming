
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "calc.h"


double vars[26]; 
int main()
{   
    int type;
    double op2, op1;
    char s[MAXOP];
    int var_letter;

    while ((type = getop(s)) != EOF){
        printf("type %c\n", type);
        switch (type){
            case NUMBER:
                push(atof(s));
                break;

            case 'S':
                op1 = pop();
                push(sin(op1));
                break;

            case 'C':
                op1 =pop();
                printf("cos(%f)\n", op1);
                push(cos(op1));
                break;

            case 'E':
                op1 = pop();
                push(exp(op1));
                break;

            case 'P':
                op2 = pop();
                op1 = pop();
                push(pow(op1, op2));
                break;

            case VAR:
                printf("var reference %c\n", s[0]);
                push(vars[s[0]-'A']);
                var_letter = s[0];
                printf("setting var_letter to %c\n", var_letter);
                break;

            case VAR_ASSIGNMENT:
                op1 = pop();
                op2 = pop();
                printf("assignment %c = %f\n\n", var_letter, op2);
                vars[var_letter- 'A'] = op2;
                break;

            case '+':
                op2 = pop();
                op1 = pop();
                push(op1 + op2);
                break;

            case '*':
                op1 = pop();
                op2 = pop();
                push(op1 * op2);
                break;

            case '-':
                op2 = pop();
                op1 = pop();
                push(op1 - op2);
                break;

            case '%':
                op2 = pop();
                push((int)pop() % (int)op2);
                break;

            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor \n");

                break;

            case 'p':
                op1 = stack_peak();
                printf("peaking %f\n", op1);
                break;

            case 'd':
                duplicate();
                printf("duplcateing top\n");
                break;

            case 's':
                swap();
                printf("swapping top two\n");
                break;

            case 'c':
                clear();
                printf("clearing stack\n");

            case '\n':
                printf("answer\t%.8g\n", pop());
                return 0;
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }

    } 
    return 0;
}

