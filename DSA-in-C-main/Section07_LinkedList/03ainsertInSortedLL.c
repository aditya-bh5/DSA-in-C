#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *first = NULL;

void create(int A[], int n)
{
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;
    for (int i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}
void insertInSortedLL(struct Node *p, int x)
{
    struct Node *t, *q = NULL;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;
    while (p && p->data < x)
    {
        q = p;
        p = p->next;
    }
    q->next = t;
    t->next = p;
}

int main()
{
    int n;
    printf("Enter the number of elements in the LL:\n");
    scanf("%d", &n);
    int A[n];
    printf("Enter the sorted elements for LL:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    create(A, n);
    display(first);
    printf("\n");
    printf("After insertion of 10 in sorted LL:\n");
    insertInSortedLL(first, 10);
    display(first);
    return 0;
}
