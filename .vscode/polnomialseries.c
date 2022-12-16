#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct node
{ // it is declear of coeff and exp of one type of node
  int coeff;
  int exp;
  struct node *next;
} *poly = NULL;
void create()
{
  struct node *t, *last = NULL;
  int num, i;
  printf("enter number of nodes:");
  scanf("%d", &num);
  printf("enter the coeff and exp:\n");
  for (i = 0; i < num; i++)
  {
    t = (struct node *)malloc(sizeof(struct node));
    scanf("%d%d", &t->coeff, &t->exp);
    t->next = NULL;
    if (poly == NULL)
      poly = last = t;
    else
    {
      last->next = t;
      last = t;
    }
  }
}
void display(struct node *p)
{
  int x;
  while (p)
  {
    printf("%dx%d + ", p->coeff, p->exp);
    p = p->next;
  }
  printf("\n");
}
long eval(struct node *p, int x)
{
  long val = 0;
  while (p)
  {
    val += p->coeff * pow(x, p->exp);
    p = p->next;
  }
  return val;
}
int main()
{
  create();
  display(poly);
  printf("%ld\n", eval(poly, 3)); // long ma ld in scanf
  return 0;
}