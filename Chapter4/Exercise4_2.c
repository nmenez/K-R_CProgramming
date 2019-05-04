#include <ctype.h>
#include <stdio.h>



int atoi(char s[], int starting_index)
{
    int i, n;
    n = 0;
    for (i = starting_index; s[i] >= '0' && s[i] <= '9'; ++i)
        n =10 * n + (s[i] - '0'); 
    return n;
}

double power_(double base, int exponent){
    double output = 1;
    for (int i = 0; i<exponent; i++)
    {
        output *= base;
    }
    return output;
}

double calculate_exponent(char s[], double pre_exp, int i)
{   char exponent_sign;
    double output;
    i++;
    if (s[i] == '-'){
        exponent_sign = '-';
        i++;
    }
    else{
        exponent_sign = '+'; 
    }
    
    int exponent = atoi(s,  i);
    double base = 10.0;
    double sci = power_(base, exponent);

    if (exponent_sign == '+')
    {
        output = pre_exp * sci;
    }
    else{
        output = pre_exp / sci;
    }
    return output;
}

/* atof: convertstringstodouble*/ 
double atof(char s[])
{
    double val, power; 
    int i, sign;
    double output;
    for(i=0; isspace(s[i]); i++) /* skipwhitespace */
    ;
    sign =(s[i] == '-')? -1 : 1; 
    if (s[i] == '+' || s[i] == '-')
        i++;
    
    for (val = 0.0; isdigit(s[i]); i++)
        val =10.0 * val + (s[i] - '0'); 
    if (s[i] == '.')
        i++;

    for (power =1.0; isdigit(s[i]); i++) {
        val =10.0 * val + (s[i] - '0');
        power *= 10.0;
    }

    double pre_exp = sign * val / power; 
    
    if (s[i] == 'e')
    {
        output = calculate_exponent(s, pre_exp, i);

    }

    else{
        output = pre_exp;
    }

    return output;
}