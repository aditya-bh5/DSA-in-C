#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
} *first = NULL;

// Create a doubly linked list
void Create(int A[], int n)
{
    struct Node *t, *last;
    int i;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->prev = first->next = NULL;
    last = first;
    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = last->next;
        t->prev = last;
        last->next = t;
        last = t;
    }
}

// Displaying DLL
void Display(struct Node *p)
{
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// Counting Nodes in a DLL
int Count(struct Node *p)
{
    int count = 0;
    while (p)
    {
        count++;
        p = p->next;
    }
    return count;
}

// Inserting in a DLL
void Insert(struct Node *p, int index, int x)
{
    struct Node *t;
    int i;
    if (index < 0 || index > Count(p))
    {
        printf("Invalid Index\n");
        return;
    }
    if (index == 0)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        t->prev = NULL;
        t->next = first;
        first->prev = t;
        first = t;
    }
    else
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        for (i = 1; i < index - 1; i++)
        {
            p = p->next;
        }
        t->prev = p;
        t->next = p->next;
        if (p->next)
            p->next->prev = t;
        p->next = t;
    }
}

// Deleting a Node from DLL
int Delete(struct Node *p, int pos)
{
    int x;
    if (pos < 1 || pos > Count(p))
    {
        printf("Invalid Position\n");
        return;
    }
    if (pos == 1)
    {

        first = first->next;
        if (first)
            first->prev = NULL;
        x = p->data;
        free(p);
    }
    else
    {
        for (int i = 0; i < pos - 1; i++)
        {
            p = p->next;
        }
        p->prev->next = p->next;
        if (p->next)
            p->next->prev = p->prev;
        x = p->data;
        free(p);
    }
    return x;
}

// Reverse
void Reverse(struct Node *p)
{
    struct Node *temp;
    while (p != NULL)
    {
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = p->prev;
        if (p!=NULL && p->next == NULL)
        {
            first = p;
        }
    }
}

int main()
{
    int A[] = {10, 20, 30, 40, 50};

    Create(A, 5);
    Display(first);

    printf("Length is %d\n", Count(first));

    // Insert(first, 1, 5);
    // Display(first);

    // printf("DELETED : %d\n", Delete(first, 1));
    // Display(first);

    Reverse(first);
    Display(first);

    return 0;
}