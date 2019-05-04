#include <stdio.h>

void binarystring(int n,char binaryrep[]){  
    int  c, k; 
    int binaryrep_index = 0;
    int group_counter = 0;

    for (c = 31; c >= 0; c--)
    { 
      k = n >> c;
      group_counter++;

      if (k & 1)
        binaryrep[binaryrep_index] = '1';
      else
        binaryrep[binaryrep_index] = '0';
      binaryrep_index++;

      if (group_counter == 4)
      {
        binaryrep[binaryrep_index] = ' ';
        binaryrep_index++;
        group_counter = 0;
      }
    }
    binaryrep[binaryrep_index-1] = '\0';
}

int binarystring2int(char string[]){
    int value = 0;
    int i = 0;
    while (string[i] != '\0'){
        if ((string[i] >= '0') && (string[i] <= '1')){
            value = value * 2 + (string[i] - '0');
        }
        i++;

    }

    return value;
} 

int getlen(char stringA[]){
  int len = 0;
  int i = 0;
  while (stringA[i] != '\0'){
    len++;
    i++;
  }
  return len;
}


int testStringEquivalence(char stringA[], char stringB[])
{
  int lenA = getlen(stringA);
  int lenB = getlen(stringB);

  if (lenA != lenB){
    return 0;
  }

  for (int index = 0; index < lenA; index++)
  {
    if (stringA[index] != stringB[index]){
      return 0;
    }
  }

  return 1;

}
