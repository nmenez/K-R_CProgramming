/*    Exercise 3-1. Our binary search makes two tests inside the loop, 
       when one would suffice (at the price of more tests outside). 
       Write a version with only one test inside the loop and measure the difference in run-time. 0

*/

#include <stdio.h>

int binsearch(int x, int v[], int n)
{
    int low, high, mid;
    low =0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid - 1; 
        else if (x > v[mid])
            low = mid + 1;
        else /* foundmatch */
            return mid; 
    } 
    return -1;
}

/*
x= 8
{1,2,4,6,8,9,12,13,20} low: 0 high:9 mid: 4
{1,2,4,6,8}  low:0, high:4 mid:2
    {4,6,8}  low:2, high:4 mid:3
        {8}  low:4, high:4, mid:4

x= 7
{1,2,4,6,8,9,12,13,20} low: 0 high:9 mid: 4
{1,2,4,6,8}  low:0, high:4 mid:2
    {4,6,8}  low:2, high:4 mid:3
        {8}  low:4, high:4, mid:4



*/
    
int binsearch_v2(int x, int v[], int n)
{
    int low, high, mid;
    low =0;
    high = n - 1;
    while ((low < high) &&  (v[high] != x)) {
        //mid = (high + low)/2;
        mid = (high + low) >> 1;
        if (x <= v[mid])
        {
            high = mid;
        } 
        else
        {
            low = mid + 1;
        }
    } 
    return ((v[high] == x) ? high : -1);
}


int binsearch_v3(int x, int v[], int n)
{
  int low, high, mid;

  low = 0;
  high = n-1;
  while ((low <= high) && (v[mid] != x))
    {
      mid = (low + high) / 2;
      if (x < v[mid])
    high = mid - 1;
      else
    low = mid + 1;
    }
  return ((v[mid] == x) ? mid : -1);
}

int binsearch_v4(int x, int v[], int n)
{
  int low, high, mid;

  low = 0;
  high = n-1;
  while ((low <= high) && (v[mid] != x))
    {
      mid = (low + high) >> 1;
      if (x < v[mid])
    high = mid - 1;
      else
    low = mid + 1;
    }
  return ((v[mid] == x) ? mid : -1);
}

