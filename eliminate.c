// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#ifdef TEST_ELIMINATE
// 100% of the score
void eliminate(int n, int k)
{
  // allocate an arry of n elements
  int * arr = malloc(sizeof(* arr) * n);
  // check whether memory allocation succeeds.
  // if allocation fails, stop
  if (arr == NULL)
    {
      fprintf(stderr, "malloc fail\n");
      return;
    }
  // initialize all elements
int value = 0; //element value
int index = 0; //index value
int place = 0; //placeholder
int zero;
int last;

for(zero = 0; zero < n; zero++) //initialize array to 0 for all values
{
  arr[zero] = 0;
}
  // counting to k,
  // mark the eliminated element
  // print the index of the marked element
  // repeat until only one element is unmarked

    while(value != (n-1)) //Iterates the placeholder when elements is n-1
      {
        if(place == n)
        {
          place = 0;  //Sets to zero
        }
        if(arr[place] == 'X') //If the index is equal to 'X', then iterate to next element
        {
          place++;
        }
        else //If not, iterates both value and element of array
        {
          place++;
          index++;
        }
        if(index == k)
        {
          arr[place-1] = 'X';
          printf("%d\n", place - 1); //Prints out the eliminated element value
          value++;
          index = 0;
        }
      }

    for(last = 0; last < n; last++)
    {
      if(arr[last] != 'X')
      {
        printf("%d\n", last);
      }
    }
  // print the last one
  //printf("%d\n", last index variable);
  // release the memory of the array
  free (arr);
}
#endif
