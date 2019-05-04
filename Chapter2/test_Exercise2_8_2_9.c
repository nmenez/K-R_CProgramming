#include <stdio.h>
#include "binary_manipulation_utils.h"
#include "Exercise2_8.h"
#include <time.h>

void test_rotaterightone()
{
    char x_str[] =    "0000 0000 0000 0000 1100 0101 0000 1111";
    int x = binarystring2int(x_str);


    char expected[] = "1000 0000 0000 0000 0110 0010 1000 0111";
    int y = rotaterightone(x);

    char actual[40] = {'\0'};
    binarystring(y, actual);
    printf("%s\n%s\npass:%i", expected,actual, testStringEquivalence(actual, expected));

}


void test_rightrot()
{
    char x_str[] =    "0000 0000 0000 0000 1100 0101 0000 1111";
    int x = binarystring2int(x_str);


    char expected[] = "1111 0000 0000 0000 0000 1100 0101 0000";
    int n = 4;
    int y = rightrot(x, n);

    char actual[40] = {'\0'};
    binarystring(y, actual);
    int pass =  testStringEquivalence(actual, expected);
    printf("%s\n%s\n%s\npass:%i\n", x_str,expected,actual,pass);



}


void test_rightrot_better()
{
    char x_str[] =    "0000 0000 0000 0000 1100 0101 0000 1010";
    int x = binarystring2int(x_str);


    char expected[] = "1010 0000 0000 0000 0000 1100 0101 0000";
    int n = 4;
    int y = rightrot_better(x, n);

    char actual[40] = {'\0'};
    binarystring(y, actual);
    int pass =  testStringEquivalence(actual, expected);
    printf("%s\n%s\n%s\npass:%i\n", x_str,expected,actual,pass);



}

void comp_right_rots(){
    time_t start, end;
    int N =10000000;
    char x_str[] =    "0000 0000 0000 0000 1100 0101 0000 1010";
    int x = binarystring2int(x_str);
   
    start = clock();
    int n = 4;
    for (int i=0; i<N; i++){
        int y = rightrot(x, n);
    
    }
    end = clock() - start;
    float elapsed_old = (float)end/CLOCKS_PER_SEC;


    start = clock();
    for (int i=0; i<N; i++){
        int y = rightrot_better(x, n);

    }
    end = clock() - start;
    float elapsed_better = (float)end/CLOCKS_PER_SEC;

    printf("old: %f\nnew: %f\npass: %i\n", elapsed_old, elapsed_better, elapsed_better<elapsed_old);
}

int bitcount_better(int x)
{
    int count=0;
    while (x!=0){
        x &=(x-1);
        count++;
    }
    return count;
}


int bitcount(int  x)
{
    int b;
    for(b=0;x !=0;x>>= 1)
    { 
        if (x & 01){
            b++;
        }
    }
    return b;
}



void test_Exercise_2_9()
{
    //test_rotaterightone();
    char x_str[] =    "0000 1000 0000 0000 1100 0101 1111 1110";
    int x = binarystring2int(x_str);
    time_t start, end;


    start = clock();
    int N = 100000000;
    for (int i=0; i<N; i++)
    {
        int y = x;
        int result = bitcount(y);

    }
    end = clock() - start;
    float span_old = (float)end/CLOCKS_PER_SEC;


    start = clock();
    for (int i=0; i<N; i++)
    {
        int y = x;
        int result = bitcount_better(y);

    }
    end = clock() - start;
    float span_better = (float)end/CLOCKS_PER_SEC;
    printf("%f %f pass:%i\n", span_old, span_better, span_better < span_old);

}

int main()
{   //test_rotaterightone();

    //test_rightrot();
    test_Exercise_2_9();
    test_rightrot_better();
    comp_right_rots();
}