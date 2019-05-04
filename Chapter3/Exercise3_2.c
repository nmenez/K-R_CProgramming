#include <stdio.h>

void escape(char orig[], char dest[])
{
    int orig_index = 0;
    int dest_index = 0;
    while (orig[orig_index] != '\0')
    {   
        switch (orig[orig_index])
        {

            case '\a':
                dest[dest_index] = '\\';
                dest[dest_index+1] = 'a';
                dest_index += 2;
                break;

            case '\n':
                dest[dest_index] = '\\';
                dest[dest_index+1] = 'n';
                dest_index += 2;
                break;

            case '\t':
                dest[dest_index] = '\\';
                dest[dest_index+1] = 't';
                dest_index += 2;
                break;

            default:
                dest[dest_index] = orig[orig_index];
                dest_index++;
                break;
        }
        orig_index++;
    }
}


void unescape(char orig[], char dest[])
{
    int orig_index = 0;
    int dest_index = 0;
    char next_char ;
    while (orig[orig_index] != '\0')
    {
        if (orig[orig_index] == '\\'){
            orig_index++;
            next_char = orig[orig_index];
            switch (next_char){
                case 'n':
                    dest[dest_index] = '\n';
                    break;
                case 'b':
                    dest[dest_index] = '\b';
                    break;
                case 't':
                    dest[dest_index] = '\t';
                    break;
                case 'a':
                    dest[dest_index] = '\a';
                    break;
            }
        }

        else{
            dest[dest_index] = orig[orig_index];
        }
        dest_index++;
        orig_index++;
    }
}   