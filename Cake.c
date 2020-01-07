
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "hw12.h"

// DO NOT MODIFY this function --->>>
void printListNode(ListNode * head)
{
  ListNode * p = head;
  printf("printListNode: ");
  while (p != NULL)
    {
      printf("%7d ", p -> value);
      p = p -> next;
    }
  printf("\n");
}
// <<<--- until here

// You MUST modify the following functions

#ifdef TEST_CREATELIST

ListNode * createList(int valn)
{
  ListNode * head = malloc(sizeof(ListNode));
  head = malloc(sizeof(ListNode));
  head -> value = 0;
  head -> next = NULL;
  ListNode * newN = head;

  for(int j = 1; j <= valn - 1; j++)
  {
    newN -> next = malloc(sizeof(ListNode));
    newN = newN -> next;
    newN -> value = j;
    newN -> next = NULL;
  }
  return head;
}
#endif

#ifdef TEST_ELIMINATE
// eliminate the nodes in the linked list
// starting from the head, move one node at a time and count to valk.
// eliminate that node, keep counting
//
// when reaching the end of the list, continue from the beginning of
// the list
//
// print the values of the nodes to be deleted
void eliminate(ListNode * head, int valk)
{
  ListNode * p = head;

  while(head -> next != NULL)
  {
    for (int i = 1; i < valk; i++)
    {
      if(p -> next == NULL)
      {
        p = head;
      }
      else
      {
        p = p -> next;
      }
    }

  ListNode * todelete = p;
  printListNode (todelete);

  printf("%d\n", todelete -> value);
  if(p -> next == NULL)
    {
      p = head;
    }
  else
    {
      p = p -> next;
    }
  head = deleteNode(head, todelete);
}
printf("%d\n", head -> value);
free(head);
}
#endif

#ifdef TEST_DELETENODE
// head points to the first node in the linked list
// todelete points  to the node to be deleted
//
// delete the node and return the head of the linked list
// release the memory of the deleted node
//
// should check several conditions:
// 1. If head is NULL, the list is empty and this function returns
//    NULL
// 2. If todelete is NULL, nothing can be deleted, return head
// 3. If todelete is not in the list, keep the list unchanged and
//    return head
// It is possible that todelete is the first node in the list (i.e.,
// the head). If this occurs, return the second node of the list.
ListNode * deleteNode(ListNode * head, ListNode * todelete)
{
  ListNode * point = head;
  if (point == NULL)
  {
    return NULL;
  }
  if (todelete == NULL)
  {
    return point;
  }

  ListNode * nodal = point -> next;

  if(todelete -> value == point -> value)
  {
    free(point);
    return nodal;
  }
  while((nodal != NULL) && (nodal -> value) != (todelete -> value))
  {
    point = point -> next;
    nodal = nodal -> next;
  }
  if (nodal != NULL)
  {
    if (nodal -> next == NULL)
    {
      point -> next = NULL;
    }
    else
    {
      point -> next = nodal -> next;
    }
    free(nodal);
  }
  return head;
}
#endif
