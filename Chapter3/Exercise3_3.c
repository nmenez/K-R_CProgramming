#include <stdio.h>


int strlen_(char str[]){
    int N = 0;
    int i = 0;
    while (str[i] != '\0'){
        N++;
        i++;
    }
    return N;
}

int innerexpand(char first_char, char last_char, int dest_index, char dest[]){
    char current_char;
    for (current_char = first_char+1; current_char <last_char; current_char++){
        dest[dest_index] = current_char;
        dest_index++; 
    }
    return dest_index;
}

void expand(char orig[], char dest[]){
    int N = strlen_(orig);
    int orig_index;
    int dest_index = 0;
    int starting_orig_index;
    if (orig[0] == '-')
    {
        dest[dest_index] = '-';
        dest_index++;
        starting_orig_index = 1;
    }
    else
    {
        starting_orig_index = 0;
    }

    for (orig_index=starting_orig_index; orig_index<N; orig_index++){
        if ((orig[orig_index] == '-') && (orig[orig_index+1] != '\0')){
            dest_index = innerexpand(orig[orig_index-1], orig[orig_index+1], dest_index, dest);
        }
        else{
            dest[dest_index] = orig[orig_index];
            dest_index++;
        }
    }
}
