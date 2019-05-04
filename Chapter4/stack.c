#include <stdio.h>
#include <ctype.h>
#include "calc.h"
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
