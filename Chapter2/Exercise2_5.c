#include <stdio.h>


int find_position_of_char(char string_look_up[], char look)
{
    int position = -1;
    for (int index = 0; string_look_up[index] != '\0'; index++)
    {
         if (string_look_up[index] == look)
         {
            return index;
         }
    }
    return position;
}

int any(char location_in[], char character_in[]){
    for (int index=0; character_in[index] != '\0'; index++)
    {
        int location = find_position_of_char(location_in, character_in[index]);
        if (location != -1){
            return location;
        }
    }

    return -1;

}