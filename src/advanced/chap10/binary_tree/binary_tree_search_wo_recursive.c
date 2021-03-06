#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum
{
  Term,
  Insert,
  Search,
  Print
} Menu;

#define MAX_LEN 50

typedef struct __bnode
{
  char name[MAX_LEN];
  struct __bnode *right; // 自己参照
  struct __bnode *left;
} BinNode;

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

void SearchNode(BinNode *p, BinNode nn)
{
  int cond;
  if (p == NULL)
    printf("%s doesn't exist.", nn.name);
  else if ((cond = strcmp(nn.name, p->name)) == 0)
    printf("name '%s' exists.", nn.name);
  else if (cond < 0)
    SearchNode(p->left, nn);
  else
    SearchNode(p->right, nn);
}

void PrintTree(BinNode *p)
{
  if (p != NULL)
  {
    BinNode *root = p;
    BinNode *stk[100];
    int ptr = 0;
    while (1)
    {
      if (p != NULL)
      {
        stk[ptr++] = p; // まずは stack に parent Node を積む
        p = p->left;
      }
      else if (ptr > 0)
      {
        /* p->left == NULL */
        p = stk[--ptr];
        printf("%s\n", p->name); // left == NULL なら親の Node を取り出して print 右側の Node は親より大きいので再び親を表示する必要性がないため取り出してしまって問題ない
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
    printf("\n 1. insert Node, 2. search Node, 3. print whole tree, 0. end application\n: ");
    scanf("%d", &ch);
  } while (ch < Term);

  return (Menu)ch;
}

int main(void)
{
  Menu menu;
  BinNode *root = NULL;
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