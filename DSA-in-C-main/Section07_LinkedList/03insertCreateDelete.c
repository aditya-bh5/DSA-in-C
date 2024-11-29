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

// INSERTING IN A LINKED LIST
//  i. Inserting before the first node
void insertFirst(struct Node *p, int x)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = first;
    first = t;
}
// ii. Inserting after a given node
void insertAfter(struct Node *p, int index, int x)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
    }
    t->data = x;
    t->next = p->next;
    p->next = t;
}
// iii. Inserting at the end of the linked list
void insertLast(struct Node *p, int x)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = t;
}
// void insertLL(struct Node *p1,int x){}

// DELETING FROM A LINKED LIST
int delete(struct Node *n, int pos)
{
    struct Node *p, *q;
    int x = -1;
    if (pos == 1)
    {
        x = first->data;
        p = first;
        first = first->next;
        free(p);
    }
    else
    {
        p = first;
        q = NULL;
        for (int i = 0; i < pos - 1 && p; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        free(p);
    }
    return x;
}

// EXTRA FUNCTIONS ON LL
void sortCheck(struct Node *n)
{
    struct Node *p, *q;
    p = first->next;
    q = first;
    while (p != NULL)
    {
        if (p->data < q->data)
        {
            printf("The linked list is not sorted.\n");
            return;
        }
        q = p;
        p = p->next;
    }
    printf("The linked list is sorted.\n");
}

void removeDuplicates(struct Node *n)
{
    struct Node *p = first;
    struct Node *q = first->next;
    while (q != NULL)
    {
        if (p->data != q->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            free(q);
            q = p->next;
        }
    }
}

// REVERSE A LINKED LIST
// i. Reverse the linked list using an array
void reverseUsingArray(int B[], struct Node *p)
{
    int i;
    while (p != NULL)
    {
        for (i = 0; p != NULL; i++)
        {
            B[i] = p->data;
            p = p->next;
        }
    }
    p = first;
    i--;
    for (i; i >= 0; i--)
    {
        p->data = B[i];
        p = p->next;
    }
}
// ii. Reverse the linked list using sliding pointers(linking changes)
void reverseUsingSlidingPointers(struct Node *p)
{
    struct Node *q, *r;
    q = NULL;
    r = NULL;
    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}
// iii. Reverse using Recursion
void reverseUsingRecursion(struct Node *q, struct Node *p)
{

    if (p != NULL)
    {
        reverseUsingRecursion(p, p->next);
        p->next = q;
    }
    else
    {
        first = q;
    }
}

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

    // INSERTING:
    // i.INSERTING TO THE FIRST NODE
    // int x;
    // printf("\nWhat do you want to push to the array:\n ");
    // scanf("%d", &x);
    // insertFirst(first, x);
    // display(first);
    // printf("\n");

    // ii.INSERT AFTER A SPECIFIC INDEX
    //  int ele, pos;
    //  printf("Add after specific index (element,pos) :");
    //  scanf("%d%d", &ele, &pos);
    //  insertAfter(first, pos, ele);
    //  display(first);

    // iii. INSERT AT THE END OF THE LINKED LIST
    //  int ele;
    //  printf("\nAdd at the end of the linked list: ");
    //  scanf("%d", &ele);
    //  insertLast(first, ele);
    //  display(first);

    // DELETING FROM A LINKED LIST:
    //  i. DELETING THE FIRST NODE
    //  ii. DELETING A NODE AT A SPECIFIC INDEX
    // Combined Equation-
    // int pos;
    // printf("\n");
    // printf("Enter the position to be deleted:\n");
    // scanf("%d", &pos);
    // printf("The deleted element is: %d\n", delete (first, pos));
    // display(first);

    // SORT CHECK
    // printf("\n");
    // sortCheck(first);

    // REMOVE DUPLICATES
    // printf("\n");
    // printf("After removing duplicates: ");
    // removeDuplicates(first);
    // display(first);

    // REVERSE A LINKED LIST
    // i. Reverse the linked list using an array
    // printf("\n");
    // printf("Reversing the linked list using an array: ");
    // int B[n];
    // reverseUsingArray(B, first);
    // display(first);

    // ii. Reverse the linked list using sliding pointers(linking changes)
    // printf("\n");
    // printf("Reversing the linked list using sliding pointers: ");
    // reverseUsingSlidingPointers(first);
    // display(first);

    // iii. Reverse using Recursion
    printf("\n");
    printf("Reversing the linked list using recursion: ");
    struct Node *q = NULL;
    reverseUsingRecursion(q, first);
    display(first);

    return 0;
}