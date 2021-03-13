
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct __node Node;

typedef enum
{
  Term,
  Prepend,
  Append,
  Delete,
  Print,
  Clear
} Menu;

struct __node
{
  int no;
  char name[10];
  Node *next;
};

void SetNode(Node *n, Node nn, Node *next)
{
  n->no = nn.no;
  n->next = next;
  strcpy(n->name, nn.name);
}

Node *AllocNode(void)
{
  return calloc(1, sizeof(Node));
}

void PrependNode(Node **head, Node new_node)
{
  /*
    child Node doesn't have to know which is parent.
  */
  Node *ptr = *head;   // pass to next arg.
  *head = AllocNode(); // new head Node with previous head reference.
  SetNode(*head, new_node, ptr);
}

/* Add Node at the end of linear list.*/
void AppendNode(Node **head, Node new_node)
{
  if (*head == NULL)
    PrependNode(head, new_node);
  else
  {
    // explore until the last Node.
    Node *ptr = *head;
    while (ptr->next != NULL)
      ptr = ptr->next;
    ptr->next = AllocNode();
    SetNode(ptr->next, new_node, NULL);
  }
}

/* Delete Head Node*/
void DeleteNode(Node **head)
{
  if (*head != NULL)
  {
    Node *ptr = (*head)->next;
    free(*head); // 先頭を指す Node 先に indirectly free, and reassign next Head Node.
    *head = ptr;
  }
}

void ClearList(Node **head)
{
  while (*head != NULL)
    DeleteNode(head);
}

void PrintList(Node **head)
{
  for (Node *ptr = *head; ptr != NULL; ptr = ptr->next)
    printf("%5d %-10.10s\n", ptr->no, ptr->name);
}

void InitList(Node **head)
{
  *head = NULL;
}

void TermList(Node **head)
{
  ClearList(head); // just Delete all Nodes
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
  Node *list;      // head
  InitList(&list); // NULL pointer

  do
  {
    Node n;
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