/* Exercise2·3.Write the function htoi(s),which converts a string of hexadecimal digits (including an optional Ox or ox) into its equivalent integer value. The allowable digits are 0 through 9,a through f,and A through F.0

*/

int digit_converter(char digit){
    int value ;
    if ((digit >= '0') && (digit <= '9'))
    {
        value = digit - '0';
    }
    else if ((digit >= 'a') && (digit <='f'))
    {
        value = 10 + (digit - 'a');
    }

    else if ((digit >= 'A') && (digit <= 'F'))
    {
        value = 10 + (digit - 'A');
    }
    else{
        value = 0;
    }
    return value;
}

int find_first_digit_location(char hex[])
{
    if ((hex[0] == '0') && (hex[1]=='x')){
        return 2;
    }

    else if ((hex[0] == '0') && (hex[1] == 'X'))
    {
        return 2;
    }

    else
    {
        return 0;
    }
}

int htoi(char hex[]){
    int first_digit = find_first_digit_location(hex);
    int value = 0;
    for (int current_index=first_digit; hex[current_index] != '\0'; current_index++)
    {   
        value = 16 * value + digit_converter(hex[current_index]);
    }

    return value;
}

