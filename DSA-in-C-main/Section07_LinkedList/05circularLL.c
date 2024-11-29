#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *Head;

void create(int A[], int n)
{
    struct Node *t, *last;
    Head = (struct Node *)malloc(sizeof(struct Node));
    Head->data = A[0];
    Head->next = Head;
    last = Head;

    for (int i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}
// Displaying in a circular linked list
void Display(struct Node *p)
{
    do
    {
        printf("%d ", p->data);
        p = p->next;
    } while (p != Head);
    printf("\n");
}
void recursiveDisplay(struct Node *p)
{
    static int flag = 0;
    if (p != Head || flag == 0)
    {
        flag = 1;
        printf("%d ", p->data);
        recursiveDisplay(p->next);
    }
    flag = 0;
}

// Counting Nodes in a Circular Linked List
int Count(struct Node *p)
{
    int count = 1;
    while (p->next != Head)
    {
        count++;
        p = p->next;
    }
    return count;
}

// Inserting in a Circular Linked List
void Insert(struct Node *p, int pos, int x)
{
    struct Node *t;
    if (pos > Count(p) || pos < 0)
    {
        printf("Invalid Position\n");
        return;
    }
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    if (pos == 0)
    {
        if (Head == NULL)
        {
            Head = t;
            Head->next = Head;
        }
        else
        {
            t->next = p;
            while (p->next != Head)
            {
                p = p->next;
            }
            p->next = t;
            Head = t;
        }
    }
    else
    {

        for (int i = 0; i < pos - 1; i++)
        {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}

// Deleting in a Circular Linked List
int Delete(struct Node *p, int pos)
{
    struct Node *q;
    int x;
    if (pos > Count(p) || pos < 0)
    {
        printf("Invalid Position\n");
        return 0;
    }
    if (pos == 1)
    {
        while (p->next != Head)
        {
            p = p->next;
        }
        x=Head->data;
        p->next = Head->next;
        free(Head);
        Head = p->next;
    }
    else
    {
        for (int i = 1; i < pos - 1; i++)
        {
            p = p->next;
        }
        q = p->next;
        x=q->data;
        p->next = q->next;
        free(q);
    }
    return x;
}

int main()
{
    int A[] = {1, 2, 3, 4, 5};
    create(A, 5);
    Display(Head);

    // recursiveDisplay(Head);
    // printf("\n");

    // Insert(Head, 0, 10);
    // Display(Head);

    printf("DELETED : %d",Delete(Head,3));
    printf("\n");
    Display(Head);

    return 0;
}