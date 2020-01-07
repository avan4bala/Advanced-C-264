#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "calculate.h"

// DO NOT MODIFY FROM HERE --->>>
const int Operations[] = {'+', '-', '*'};

// return -1 if the word is not an operator
// return 0 if the word contains '+'
// return 1 if the word contains '-'
// ...
int isOperator(char * word)
{
  int ind;
  int numop = sizeof(Operations) / sizeof(int);
  for (ind = 0; ind < numop; ind ++)
    {
    char *loc = strchr(word, Operations[ind]);
    if (loc != NULL && !isdigit(loc[1]))
	{
	  return ind;
	}
    }
  return -1;
}
// <<<--- UNTIL HERE

// ***
// *** You MUST modify the calculate function
// ***
#ifdef TEST_CALCULATE
// if arithlist is NULL, return true
// if arithlist -> head is NULL, return true
// if the input list is invalid, return false
bool calculate(List * arithlist)
{
  if (arithlist == NULL)
    {
      return true;
    }
  if ((arithlist -> head) == NULL)
    {
      return true;
    }

    ListNode * curr = arithlist -> head;
    int i = 0;
    int a,b,c;
    char s[WORDLENGTH];
    bool test = false;

    while (curr != NULL)
    {
      i = isOperator((curr -> word));
      if (i == -1)
      {
        curr = curr -> next;
      }
      else if (i == 0)
      {
        if (curr -> prev == NULL)
        {
          return false;
        }
        if (curr -> prev -> prev == NULL)
        {
          return false;
        }

        a = atoi((curr -> prev) -> word);
        b = atoi((curr -> prev -> prev) -> word);
        c = a + b;
        sprintf(s, "%d\n", c);
        strcpy(curr -> word, s);
        test = deleteNode(arithlist, curr -> prev);

        if(test == false)
        {
          return false;
        }
        test = deleteNode(arithlist, curr -> prev);
        if(test == false)
        {
          return false;
        }
        curr = curr -> next;
      }
      else if (i == 1)
      {
        if (curr -> prev == NULL)
        {
          return false;
        }
        if (curr -> prev -> prev == NULL)
        {
          return false;
        }

        a = atoi((curr -> prev) -> word);
        b = atoi((curr -> prev -> prev) -> word);
        c = b - a;
        sprintf(s, "%d\n", c);
        strcpy(curr -> word, s);
        test = deleteNode(arithlist, curr -> prev);

        if(test == false)
        {
          return false;
        }
        test = deleteNode(arithlist, curr -> prev);
        if(test == false)
        {
          return false;
        }
        curr = curr -> next;
      }
      else if (i == 2)
      {
        if (curr -> prev == NULL)
        {
          return false;
        }
        if (curr -> prev -> prev == NULL)
        {
          return false;
        }

        a = atoi((curr -> prev) -> word);
        b = atoi((curr -> prev -> prev) -> word);
        c = a * b;
        sprintf(s, "%d\n", c);
        strcpy(curr -> word, s);
        test = deleteNode(arithlist, curr -> prev);

        if(test == false)
        {
          return false;
        }
        test = deleteNode(arithlist, curr -> prev);
        if(test == false)
        {
          return false;
        }
        curr = curr -> next;
      }
    }
    if(arithlist -> head != arithlist -> tail)
    {
      return false;
    }
    if (isOperator(arithlist -> head -> word) > -1)
    {
      return false;
    }

  return true;
}
#endif
