#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node
{
  char name[20];
  long long int phone;
  struct node *llink;
  struct node *rlink;
} node;

node *create(char *name, long long int phone)
{
  node *newnode = (struct node *)malloc(sizeof(struct node));
  strcpy(newnode->name, name);
  newnode->phone = phone;
  newnode->llink = NULL;
  newnode->rlink = NULL;
  return newnode;
}
node *insert(node *root, char *name, long long int phone)
{
  if (root == NULL)
    return create(name, phone);
  if (strcmp(name, root->name) < 0)
    root->llink = insert(root->llink, name, phone);
  else
    root->rlink = insert(root->rlink, name, phone);
  return root;
}

node *search(node *root, char *name)
{
  if (root == NULL)
    return NULL;
  if (strcmp(name, root->name) == 0)
    return root;
  if (strcmp(name, root->name) < 0)
    return search(root->llink, name);
  else
    return search(root->rlink, name);
}
node *findmin(node *root)
{
  while (root->llink != NULL)
    root = root->llink;
  return root;
}

node *delete(node *root, char *name)
{
  node *temp;
  if (root == NULL)
    return root;
  if (strcmp(name, root->name) < 0)
    root->llink = delete (root->llink, name);
  else if (strcmp(name, root->name) > 0)
    root->rlink == delete (root->rlink, name);
  else
  {
    if (root->llink == NULL)
    {
      temp = root->rlink;
      free(root);
      return temp;
    }
    else if (root->rlink == NULL)
    {
      temp = root->llink;
      free(root);
      return temp;
    }
    temp = findmin(root->rlink);
    strcpy(root->name, temp->name);
    root->phone = temp->phone;
    root->rlink = delete (root->rlink, temp->name);
  }
  return root;
}
void inorder(node *root)
{
  if (root != NULL)
  {
    inorder(root->llink);
    printf("Name: %s,phone :%lld\n", root->name, root->phone);
    inorder(root->rlink);
  }
}
void postorder(node *root)
{
  if (root != NULL)
  {
    postorder(root->llink);
    postorder(root->rlink);
    printf("Name: %s ,Phone %lld\n", root->name, root->phone);
  }
}
void preorder(node *root)
{
  if (root != NULL)
  {
    printf("Name: %s ,Phone %lld\n", root->name, root->phone);
    preorder(root->llink);
    preorder(root->rlink);
  }
}

int main()
{
  int choice, flag = 1;
  long long int phone;
  char name[20];
  node *root = NULL;
  while (flag)
  {
    printf("\n1. insert \n2. Traversal\n3. search \n4. delete \n5. exit\n");
    printf("Enter your choice\n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
      printf("Enter the name \n");
      scanf("%s", name);
      printf("Enter the telephone number \n");
      scanf("%lld", &phone);
      root = insert(root, name, phone);
      break;
    case 2:
      printf("Preorder Traversal\n\n");
      preorder(root);
      printf("Inorder Traversal\n\n");
      inorder(root);
      printf("Postorder Traversal\n\n");
      postorder(root);
      break;
    case 3:
      printf("enter the element to search \n");
      scanf("%s", name);
      node *temp = search(root, name);
      if (temp == NULL)
        printf("name is not found \n");
      else
        printf("name: %s; phone %lld\n", temp->name, temp->phone);
      break;
    case 4:
      printf("Enter the name to delete \n");
      scanf("%s", name);
      root = delete (root, name);
      break;
    case 5:
      flag = 0;
      break;
    default:
      printf("invalid !!");
    }
  }
  return 0;
}
