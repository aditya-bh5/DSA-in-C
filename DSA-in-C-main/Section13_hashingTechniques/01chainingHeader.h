#ifndef CHAINS_H
#define CHAINS_H

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void SortedInsert(struct Node **H, int x)
{
    struct Node *t, *q = NULL, *p = *H;

    // Allocate memory for the new node
    t = (struct Node *)malloc(sizeof(struct Node));
    if (t == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    t->data = x;
    t->next = NULL;

    // If the list is empty
    if (*H == NULL)
    {
        *H = t;
    }
    else
    {
        // Traverse the list to find the correct position
        while (p && p->data < x)
        {
            q = p;
            p = p->next;
        }

        // Inserting at the beginning
        if (q == NULL)
        {
            t->next = *H;
            *H = t;
        }
        else
        {
            // Inserting in between or at the end
            t->next = q->next;
            q->next = t;
        }
    }
}

struct Node *Search(struct Node *p, int key)
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

#endif // CHAINS_H
