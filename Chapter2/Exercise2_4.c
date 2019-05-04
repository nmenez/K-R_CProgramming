#include <stdio.h>

int find_character_in_string(char string[], char character){
    
    for (int index=0; string[index] != '\0'; index++)
    {  // printf("%c %c %i", string[index], character, string[index] ==character);
        if (string[index] == character){
            return 1;
        }
    }

    return 0;

}

void squeeze(char deletefrom [], char checkfrom []){

    int look_index;
    int copy_index;

    int checkfrom_index;

    for (look_index=copy_index=0; deletefrom[look_index] != '\0'; look_index++)
    {   
        if (find_character_in_string(checkfrom, deletefrom[look_index]) == 0)
        {
            deletefrom[copy_index++] =deletefrom[look_index];
        }
    }
    deletefrom[copy_index] = '\0';
}
