#ifndef CALC_H
#define CALC_H
#define NUMBER '0'
#define VAR 'V'
#define VAR_ASSIGNMENT '='
#define MAXOP 100

void push(double);
double pop(void);
double stack_peak();
void duplicate();
void swap();
void clear();

int getop(char []);
int getch(void);
void ungetch(int);
int peak();


#endif