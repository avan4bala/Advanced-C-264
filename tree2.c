Tree * newTree(void)
{
  Tree * t = malloc(sizeof(Tree));
  t -> root = NULL;
  return t;
}

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


// <<<--- UNTIL HERE

// ***
// *** You MUST modify the follow function
// ***
#ifdef TEST_BUILDTREE
TreeNode * newT(int val)
{
  TreeNode * node = (TreeNode*)malloc(sizeof(TreeNode));
  node -> value = val;
  node -> left = NULL;
  node -> right = NULL;
  return node;
}
int search(int * arr, int s, int end, int val)
{
  int i = 0;
  for(i = s; i<=end; i++)
  {
    if(arr[i] == val)
    {
      break;
    }
  }
  return i;
}
TreeNode * help(int * inArray, int * postArray, int s, int end, int * p)
{
  if(s>end)
  {
    return NULL;
  }
  TreeNode * node = newT(postArray[*p]);
  (*p)--;
  if(s==end)
  {
    return node;
  }
  int iii = search(inArray,s,end,node -> value);
  node -> right = help(inArray,postArray,iii+1,end,p);
  node -> left = help(inArray,postArray,s,iii-1,p);
  return node;
}
Tree * buildTree(int * inArray, int * postArray, int size)
{
  int p = size - 1;
  Tree * tree = (Tree*)malloc(sizeof(Tree));
  tree -> root = help(inArray,postArray,0,size-1,&p);
  return tree;
}
#endif

#ifdef TEST_PRINTPATH
bool printHelp(TreeNode * node, int b)
{
  if(node == NULL)
  {
    return false;
  }
  if(b == node -> value)
  {
    printf("%d\n", b);
    return true;
  }
  if(printHelp(node -> left, b) || printHelp(node -> right, b))
  {
    printf("%d\n", node -> value);
    return true;
  }
  else
  {
    return false;
  }
}
void printPath(Tree * tr, int val)
{
  printHelp(tr -> root, val);
}
#endif
