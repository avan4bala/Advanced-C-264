#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

// DO NOT MODIFY FROM HERE --->>>
void deleteTreeNode(TreeNode * tr)
{
  if (tr == NULL)
    {
      return;
    }
  deleteTreeNode (tr -> left);
  deleteTreeNode (tr -> right);
  free (tr);
}

void freeTree(Tree * tr)
{
  if (tr == NULL)
    {
      // nothing to delete
      return;
    }
  deleteTreeNode (tr -> root);
  free (tr);
}

static void preOrderNode(TreeNode * tn, FILE * fptr)
{
  if (tn == NULL)
    {
      return;
    }
  fprintf(fptr, "%d\n", tn -> value);
  preOrderNode(tn -> left, fptr);
  preOrderNode(tn -> right, fptr);
}

void preOrder(Tree * tr, char * filename)
{
  if (tr == NULL)
    {
      return;
    }
  FILE * fptr = fopen(filename, "w");
  preOrderNode(tr -> root, fptr);
  fclose (fptr);
}
// <<<--- UNTIL HERE

// ***
// *** You MUST modify the follow function
// ***

#ifdef TEST_BUILDTREE
// Consider the algorithm posted on
// https://www.geeksforgeeks.org/construct-a-binary-tree-from-postorder-and-inorder/

int g (int * arr, int beg, int end, int value);
TreeNode * help (int * num, int * p, int beg, int end, int * last);
TreeNode * buildNode (int value);

int g(int * arr, int beg, int end, int value)
{
  int i;
  for (i = beg; i <= end; i++)
  {
    if(arr[i] == value)
    {
      return i;
    }
  }
  return -1;
}

TreeNode * help (int * num, int * p, int beg, int end, int * last)
{
  if (beg > end)
  {
    return NULL;
  }
  TreeNode * newNode = buildNode(p[*last]);
  (*last)--;

  if (beg == end)
  {
    return newNode;
  }

  int newInd = g(num, beg, end, newNode -> value);

  newNode -> right = help(num, p, newInd + 1, end, last);
  newNode -> left = help(num, p, newInd - 1, end, last);

  return newNode;
}

Tree * buildTree(int * inArray, int * postArray, int size)
{
  Tree * tr = malloc(sizeof(Tree));
  tr -> root = NULL;

  int last = size - 1;

  tr -> root = help(inArray, postArray, 0, last, &last);
  return tr;
}

TreeNode * buildNode (int value)
{
  TreeNode * newNode = malloc(sizeof(TreeNode));
  newNode -> left = NULL;
  newNode -> right = NULL;
  newNode -> value = value;
  return newNode;
}
#endif
