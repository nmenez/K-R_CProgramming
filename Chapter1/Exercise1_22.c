/*Write a program to "fold" long input lines into two or more shorter lines 
after the last non-blank character that occurs before the n-th column of input.
 Make sure your program does something intelligent with very long lines,
  and if there are no blanks or tabs before the specified column */


#include <stdio.h>
#define MAXLINE 30

int add_word_to_line(char line[], int line_counter, char word[], int word_counter)
{   
    line[line_counter] = ' '; // add space before adding word
    line_counter++;
    int copy_counter = 0;
    while (copy_counter < word_counter)
    {   
        line[line_counter] = word[copy_counter];
        line_counter++;
        copy_counter++;
    }

    line[line_counter] = '\0';  
    return line_counter;
}

void fold(){ 

    int c;
    int word_counter = 0;
    int line_counter = 0;
    char line[MAXLINE+1];
    char word[MAXLINE+1];
    line[line_counter] = '\0';
    word[word_counter] = '\0';

   while ((c=getchar())!= EOF){
        if ((c != ' ') & (c!= '\n') & (word_counter<MAXLINE)) /* accumulate chars into word buffer */
        {
            word[word_counter] = c;
            word_counter++;
        }
        else // space encountered, end of previous word.
        {   
            if (word_counter + line_counter + 1 >= MAXLINE) //if adding word to line is greater than MAXLINE, print line,  and then reset
            {  
                printf("%s: %i\n", line, line_counter);
                line[0] = '\0';
                line_counter = 0;
            }

            if (word_counter > 0)
            {
                line_counter = add_word_to_line(line, line_counter, word, word_counter);
            }
            word[word_counter] = '\0';          
            word_counter=0;    
        }
    }
}

int main(){
    fold();
}
