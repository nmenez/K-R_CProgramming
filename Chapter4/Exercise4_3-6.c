
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAXOP 100
#define NUMBER '0'
#define VAR 'V'
#define VAR_ASSIGNMENT '='

int getop(char []);
void push(double);
double pop(void);
double stack_peak(void);
void duplicate();
int getch(void);
void swap(void);
void clear(void);
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


#define MAXVAL 100
int sp = 0;
double val[MAXVAL];

void push(double f)
{   printf("pushing %f\n", f);
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full can't push %g\n", f);


}

double pop(void){
    if (sp > 0){
        return val[--sp];
    }
    else{
        printf("error: stack empty\n"); 
        return 0.0;
    }
}

double stack_peak(){
    if (sp > 0){
    return val[sp-1];
}
    else{
        printf("nothing to peak. stack empty\n");
        return 0;
    }
}

void duplicate()
{
    if (sp >= 0)
    {
        double value = stack_peak();
        printf("value to dup %f at %i\n ", value, sp);
        push(value);
        printf("%f %f\n", val[sp], val[sp+1]);
    }
}

void swap()
{
    double op1 = pop();
    double op2 = pop();
    push(op1);
    push(op2);
}

void clear()
{
    sp = 0;
}


#include <ctype.h>
int getch(void);
void ungetch(int);
int peak(void);
int checktrig(char s[]);

int getop(char s[]){
    int i, c, next_c, next_next_c;
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;

    if ((c=='s') || (c=='c') || (c=='e') || (c=='p'))
    {
        next_c  = getch();
        next_next_c =getch();
        char trig_check[] = {c, next_c, next_next_c, '\0'};
        printf("%s\n", trig_check);
        if (strcmp(trig_check, "sin") == 0){
            printf("returning S\n");

            return 'S';
        }

        if (strcmp(trig_check, "cos") == 0){
            printf("returning C\n");
            return 'C';
        }

        if (strcmp(trig_check, "exp") == 0){
            printf("returning E\n");
            return 'E';
        }

        if (strcmp(trig_check, "pow") == 0){
            printf("returning P\n");
            return 'P';
        }

        ungetch(next_next_c);
        ungetch(next_c);
    }

    s[1] = '\0';

    if ((c >= 'A') && (c <='Z')){
        s[0] = c;
        return VAR;
    }

    if (c == '='){
        return VAR_ASSIGNMENT;
    }

    next_c = peak(); 
    i = 0;
    if ((isdigit(next_c)) & (c == '-' ))
    {   s[0] = '-';
        i = 1;
        c = getch();
        s[i] = c;

    } 
    else if (!isdigit(c) && (c != '.'))
    {  
        return c;
    }

    if (isdigit(c))
        while (isdigit(s[++i] = c = getch()))
            ;

    if (c == '.') 
        while (isdigit(s[++i] = c = getch()))
            ;

    s[i] = '\0';
    if (c != EOF)
        ungetch(c);

    return NUMBER;
}


#define BUFSIZE 100

char buff[BUFSIZE];
int bufp = 0;

int getch(void)
{   
    if (bufp > 0)
        return buff[--bufp];
    else{
        char c = getchar();
        return c;
    }
}

void ungetch(int c){
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buff[bufp++] = c;

}

int peak()
{
    int next = getch();
    ungetch(next);
    return next;
}


