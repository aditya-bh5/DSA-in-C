#include <stdio.h>
#include <stdlib.h>

// CREATING A LINKED LIST
struct Node
{
    int data;
    struct Node *next;
} *first = NULL;

// CREATE LL
void create(int A[], int n)
{
    int i;
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

// DISPLAY LL
void display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

void recursiveDisplay(struct Node *p)
{
    if (p != NULL)
    {
        printf("%d ", p->data);
        recursiveDisplay(p->next);
    }
}
void recursiveDisplayReverse(struct Node *p)
{
    if (p != NULL)
    {
        recursiveDisplayReverse(p->next);
        printf("%d ", p->data);
    }
}

// COUNT NODES IN LL
int count(struct Node *p)
{
    int c = 0;
    while (p != NULL)
    {
        c++;
        p = p->next;
    }
    return c;
}
int countRecursive(struct Node *p)
{
    if (p == NULL)
    {
        return 0;
    }
    else
    {
        return countRecursive(p->next) + 1;
    }
}

// SUM OF LL
int sum(struct Node *p)
{
    int sum = 0;
    while (p != NULL)
    {
        sum += p->data;
        p = p->next;
    }
    return sum;
}
int sumRecursive(struct Node *p)
{
    if (p == NULL)
    {
        return 0;
    }
    else
    {
        return sumRecursive(p->next) + p->data;
    }
}

// MAX ELEMENT IN LL
int max(struct Node *p)
{
    int max;
    while (p != NULL)
    {
        if (p->data > max)
        {
            max = p->data;
        }
        p = p->next;
    }
    return max;
}
int maxRecursive(struct Node *p){
    int x = 0;
    int MIN_INT = -32768;
    if(p == 0){
        return MIN_INT;
    }
    x = maxRecursive(p->next);
    return x > p->data ? x : p->data;
}

// MAIN FUNCTION
int main()
{
    printf("Enter number of elements in the linked list: ");
    int n;
    scanf("%d", &n);
    int A[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    create(A, n);

    recursiveDisplay(first);
    printf("\n");
    recursiveDisplayReverse(first);

    int c = count(first);
    printf("\nNumber of nodes in the linked list: %d", c);
    int cR = countRecursive(first);
    printf("\nNumber of nodes in the linked list using recursive function: %d", cR);

    int s = sum(first);
    printf("\nSum of the linked list: %d", s);
    int sR = sumRecursive(first);
    printf("\nSum of the linked list using recursive function: %d", sR);

    int m = max(first);
    printf("\nMax element in the linked list: %d", m);
    int mR = maxRecursive(first);
    printf("\nMax element in the linked list using recursive function: %d", mR);

    return 0;
}