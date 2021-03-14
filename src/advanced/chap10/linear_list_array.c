
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Null -1 // empty index
#define Head (list->head)
#define Second (list->n[Head].next)
#define Next(x) (list->n[(x)].next)
#define D_HEAD (list->d_head)
#define D_Next(x) (list->n[(x)].d_next)

typedef int Index;
typedef enum
{
  Term,
  Prepend,
  Append,
  Delete,
  Print,
  Clear
} Menu;
typedef struct
{
  int no;
  char name[10];
  Index next; // next is just int
  Index d_next;
} Node;
typedef struct
{
  Node *n;      // list
  Index head;   // the head of list
  Index max;    // current index of list
  Index d_head; // the head of deleted list
} List;

void SetNode(Node *n, Node nn, Index next_idx)
{
  n->no = nn.no;
  n->next = next_idx;
  strcpy(n->name, nn.name);
}

int GetIndex(List *list)
{
  if (D_HEAD == Null)
    return ++(list->max);
  else
  {
    // delete リストの先頭を取り出して、先頭にその次の record を入れる
    Index idx = D_HEAD;
    D_HEAD = list->n[idx].next;
    return idx;
  }
}

void DeleteIndex(List *list, int idx)
{
  // 削除リストが空の場合でも idx を削除された record  として扱う
  if (D_HEAD == Null)
  {
    D_HEAD = idx;
    D_Next(idx) = Null;
  }
  else
  {
    D_Next(idx) = D_HEAD;
    D_HEAD = idx;
  }
}

void PrependNode(List *list, Node new_node)
{
  Index idx = Head;
  Head = GetIndex(list); // just index
  SetNode(&list->n[Head], new_node, idx);
}

void AppendNode(List *list, Node new_node)
{
  if (Head == Null)
    PrependNode(list, new_node);
  else
  {
    Index idx = Head;
    while (Next(idx) != Null)
      idx = Next(idx);
    // after while procedure, the idx is the last index of linear list.
    // and set parent Node's next child Node index instead of Null because it's no longer last record of list
    Next(idx) = GetIndex(list);
    SetNode(&list->n[Next(idx)], new_node, Null);
  }
}

// delete head of list
void DeleteNode(List *list)
{
  if (list->head != Null)
  {
    DeleteIndex(list, Head);
    Head = Second;
  }
}

void ClearList(List *list)
{
  while (Head != Null)
    DeleteNode(list);
}

void PrintList(List *list)
{
  for (Index idx = Head; idx != Null; idx = Next(idx))
    printf("%5d %-10.10s\n", list->n[idx].no, list->n[idx].name);
}

void InitList(List *list, int size)
{
  list->n = calloc(size, sizeof(Node));
  Head = list->max = D_HEAD = Null; // 初期化
}

void TermList(List *list)
{
  ClearList(list);
  free(list->n);
}

Node Read(void)
{
  Node temp;
  printf("input new Node information\n");
  printf("no:");
  scanf("%d", &temp.no);
  printf("name:");
  scanf("%s", temp.name);

  return temp;
}

Menu SelectMenu(void)
{
  int ch;
  do
  {
    printf("\n 1. prepend Node, 2. append Node,");
    printf("\n 3. delete head Node, 4. print all Nodes,");
    printf("\n 5. delete all Nodes, 0. end application\n: ");
    scanf("%d", &ch);
  } while (ch < Term || ch > Clear);

  return (Menu)ch;
}

int main(void)
{
  Menu menu;
  List list;
  InitList(&list, 5);

  do
  {
    switch (menu = SelectMenu())
    {
    case Prepend:
      PrependNode(&list, Read());
      break;
    case Append:
      AppendNode(&list, Read());
      break;
    case Delete:
      DeleteNode(&list);
      break;
    case Print:
      PrintList(&list);
      break;
    case Clear:
      ClearList(&list);
      break;
    case Term:
      break;
    }
  } while (menu != Term);

  TermList(&list);

  return 0;
}