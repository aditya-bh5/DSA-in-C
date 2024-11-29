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

// SEARCHING IN LL
// i. Linear Search(Iterative)
struct Node *search(struct Node *p, int key)
{
    while (p != NULL)
    {
        if (key == p->data)
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
}
// ii. Linear Search(Recursive)
struct Node *recursiveSearch(struct Node *p, int key)
{
    if (p == NULL)
    {
        return NULL;
    }
    if (key == p->data)
    {
        return p;
    }
    return recursiveSearch(p->next, key);
}
// IMPROVED LINEAR SEARCH
// iii. Transposition Linear Search
struct Node *tLSearch(struct Node *p, int key)
{
    struct Node *q = NULL;
    while (p != NULL)
    {
        if (key == p->data)
        {
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        q = p;
        p = p->next;
    }
}

// iv. Move to Head Linear Search
struct Node *hLSearch(struct Node *p, int key) {}

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
    display(first);

    struct Node *searchResult = search(first, 3);
    struct Node *recursiveSearchResult = recursiveSearch(first, 5);
    struct Node *tranposnLSearchResult = tLSearch(first, 4);
    printf("\nKey found:%d", searchResult->data);
    printf("\nRecursive Search Key Found:%d", recursiveSearchResult->data);
    printf("\nTransposition Linear Search Key Found:%d", tranposnLSearchResult->data);
    printf("\n");
    display(first);

    return 0;
}