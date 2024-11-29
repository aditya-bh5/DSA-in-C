#include <stdio.h>
#include <stdlib.h>

// Creating a NODE
struct Node
{
    int data;
    struct Node *next;
} *first = NULL, *second = NULL, *third = NULL;

// Displaying the linked list
void Display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

// Creating the linked list
void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
void create2(int A[], int n)
{
    int i;
    struct Node *t, *last;
    second = (struct Node *)malloc(sizeof(struct Node));
    second->data = A[0];
    second->next = NULL;
    last = second;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

// Concatenating LL's
void concat(struct Node *p1, struct Node *p2)
{
    third = p1;
    while (p1->next != NULL)
    {
        p1 = p1->next;
    }
    p1->next = p2;
}

// Merging Sorted Lists
void merge(struct Node *p1, struct Node *p2)
{
    struct Node *last;
    if (p1->data < p2->data)
    {
        third = last = p1;
        p1 = p1->next;
        third->next = NULL;
    }
    else
    {
        third = last = p2;
        p2 = p2->next;
        third->next = NULL;
    }
    while (p1 && p2)
    {
        if (p1->data < p2->data)
        {
            last->next = p1;
            last = p1;
            p1 = p1->next;
            last->next = NULL;
        }
        else
        {
            last->next = p2;
            last = p2;
            p2 = p2->next;
            last->next = NULL;
        }
    }
    if (p1)
        last->next = p1;
    if (p2)
        last->next = p2;
}

// Check:LOOP
int isLoop(struct Node *f)
{
    struct Node *p, *q;
    p = q = f;
    do
    {
        p = p->next;
        q = q->next;
        if (q != NULL)
        {
            q = q->next;
        }
        else
        {
            q = NULL;
        }
    } while (p && q && p != q);
    if (p == q)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int A[] = {10, 20, 40, 50, 60};
    int B[] = {15, 18, 25, 30, 55};
    create(A, 5);
    create2(B, 5);
    printf("LL1 : ");
    Display(first);
    printf("\n");
    printf("LL2 : ");
    Display(second);

    // Concatenating LL1 and LL2
    //  concat(second,first);
    //  printf("\n");
    //  printf("LL1 + LL2 : ");
    //  Display(third);

    // Merging Sorted Lists LL1 and LL2
    // merge(first, second);
    // printf("\n");
    // printf("Merged LL : ");
    // Display(third);

    // Creating a loop in the linked list
    // struct Node *t1, *t2;
    // t1 = first->next->next;
    // t2 = first->next->next->next->next;
    // t2->next = t1;
    printf("\n");
    printf("Is there a loop in the linked list? %d", isLoop(first));

    return 0;
}