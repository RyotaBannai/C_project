#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 50
#define STK_SIZE 100

typedef enum
{
  Term,
  Insert,
  Search,
  Print,
  Prev,
  Next,
} Menu;

typedef struct __bnode
{
  char name[MAX_LEN];
  struct __bnode *right;
  struct __bnode *left;
} BinNode;

BinNode *stk[STK_SIZE];
int ptr;

void Error(void)
{
  puts("ERROR");
}

BinNode *AllocNode(void)
{
  return calloc(1, sizeof(BinNode));
}

BinNode *InsertNode(BinNode *p, BinNode nn)
{
  int cond;
  if (p == NULL)
  {
    p = AllocNode();
    strcpy(p->name, nn.name);
    p->right = p->left = NULL;
  }
  else if ((cond = strcmp(nn.name, p->name)) == 0)
    printf("name '%s' already exists.", nn.name);
  else if (cond < 0)
    p->left = InsertNode(p->left, nn);
  else
    p->right = InsertNode(p->right, nn);
  return p;
}

void SearchNode(BinNode *root, BinNode nn)
{
  if (root != NULL)
  {
    BinNode *p = root;
    ptr = 0;
    while (1)
    {
      if (p != NULL)
      {
        int cond;
        stk[ptr++] = p;
        if ((cond = strcmp(nn.name, p->name)) == 0)
        {
          printf("%s exist.", nn.name);
          ptr--;
          break;
        }
        // else
        p = (cond < 0) ? p->left : p->right;
      }
      else
      {
        printf("%s doesn't exist.", nn.name);
        ptr = -1;
        break;
      }
    }
  }
}

BinNode *SearchMinOrMax(BinNode *root, int is_max)
{
  if (root == NULL)
    return NULL;
  else
  {
    BinNode *p = root;
    while (p != NULL)
    {
      stk[++ptr] = p;                         // ptr is considered -a at first time.
      p = (is_max == 0) ? p->left : p->right; // going left recursively will reach the smallest.
    }
    return stk[ptr];
  }
}

void SearchNext(void)
{
  printf("SearchNext ptr %d\n", ptr);
  if (ptr == -1)
    Error();
  else
  {
    BinNode *p;
    if (stk[ptr]->right != NULL)
    {
      printf("in \n");
      // 右が存在するなら、右の Node 配下の最小が parent の次に大きい値
      p = SearchMinOrMax(stk[ptr]->right, 0);
    }
    else
    {
      // 左は自分よりも小さい値しかないので、上に上がっていく.
      // そのため stk からひとつずつ取り出していく.
      // parent の右側に Node が存在していたとしてもそれは parent よりも大きいため考慮しない
      char *name = stk[ptr]->name;
      while (1)
      {
        if (--ptr < 0)
        {
          p = NULL;
          break;
        }
        if (strcmp(stk[ptr]->name, name) > 0)
        {
          p = stk[ptr];
          break;
        }
      }
    }
    if (p == NULL)
      Error();
    else
      printf("data is %s\n", p->name);
  }
}

void SearchPrev(void)
{
  printf("SearchPrev ptr %d\n", ptr);
  if (ptr == -1)
    Error();
  else
  {
    BinNode *p;
    if (stk[ptr]->left != NULL)
      // 左が存在するなら、左の Node 配下の最大が parent のひとつ前の値
      p = SearchMinOrMax(stk[ptr]->left, 1);
    else
    {
      // 右は自分よりも大きい値しかないので、上に上がっていく.
      // parent の左側に Node が存在していたとしてもそれは parent よりもより小さい値のため考慮しない
      char *name = stk[ptr]->name;
      while (1)
      {
        if (--ptr < 0)
        {
          p = NULL;
          break;
        }
        if (strcmp(stk[ptr]->name, name) < 0)
        {
          p = stk[ptr];
          break;
        }
      }
    }
    if (p == NULL)
      Error();
    else
      printf("data is %s\n", p->name);
  }
}

void PrintTree(BinNode *p)
{
  if (p != NULL)
  {
    BinNode *root = p;
    BinNode *stk[STK_SIZE];
    int ptr = 0;
    while (1)
    {
      if (p != NULL)
      {
        stk[ptr++] = p;
        p = p->left;
      }
      else if (ptr > 0)
      {
        p = stk[--ptr];
        printf("%s\n", p->name);
        p = p->right;
      }
      else
        break;
    }
  }
}

void FreeTree(BinNode *p)
{
  if (p != NULL)
  {
    FreeTree(p->left);
    FreeTree(p->right);
    free(p);
  }
}

BinNode Read(char *message)
{
  BinNode temp;
  printf("input Node name to %s\n", message);
  scanf("%s", temp.name);
  return temp;
}

Menu SelectMenu(void)
{
  int ch;
  do
  {
    printf("\n 1. insert Node, 2. search Node, 3. print whole tree");
    printf("\n 4. previous Node, 5. next Node, 0. end application\n: ");
    scanf("%d", &ch);
  } while (ch < Term);

  return (Menu)ch;
}

#define NUMBER_OF_STRINGS 12
BinNode *seed(BinNode *p)
{
  BinNode *root = NULL;
  char *name_lists[NUMBER_OF_STRINGS] = {

      "cc",
      "cd",
      "ccb",
      "ccc",
      "ccd",
      "cce",
      "a",
      "aa",
      "aaa",
      "aab",
      "abb",
      "bbb",
  };
  for (int n = 0; n < NUMBER_OF_STRINGS; n++)
  {
    BinNode temp;
    strcpy(temp.name, name_lists[n]);
    root = InsertNode(root, temp);
  }
  return root;
}

int main(void)
{
  Menu menu;
  BinNode *root = NULL;
  root = seed(root);
  ptr = -1; // searchNode 時に 0 にリセット
  do
  {
    switch (menu = SelectMenu())
    {
    case Insert:
      root = InsertNode(root, Read("Insert"));
      break;
    case Search:
      SearchNode(root, Read("Search"));
      break;
    case Next:
      SearchNext();
      break;
    case Prev:
      SearchPrev();
      break;
    case Print:
      PrintTree(root);
      break;
    case Term:
      break;
    }
  } while (menu != Term);
  FreeTree(root);
  return 0;
}