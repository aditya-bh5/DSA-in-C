
#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
#include "Stack.h"

struct Node *root = NULL;
void Treecreate()
{
    struct Node *p, *t;
    int x;
    struct Queue q;
    create(&q, 100);

    printf("Enter root value:");
    scanf("%d", &x);
    root = (struct Node *)malloc(sizeof(struct Node));
    root->data = x;
    root->lchild = root->rchild = NULL;
    enqueue(&q, root);

    while (!isEmpty(q))
    {
        p = dequeue(&q);
        printf("Enter left child of %d:", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct
                                             Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q, t);
        }
        printf("Enter right child of %d:", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct
                                             Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q, t);
        }
    }
}
void Preorder(struct Node *p)
{
    if (p)
    {
        printf("%d ", p->data);
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}
void Inorder(struct Node *p)
{
    if (p)
    {
        Inorder(p->lchild);
        printf("%d ", p->data);
        Inorder(p->rchild);
    }
}
void Postorder(struct Node *p)
{
    if (p)
    {
        Postorder(p->lchild);
        Postorder(p->rchild);
        printf("%d ", p->data);
    }
}

void IPreorder(struct Node *p)
{
    struct Stack stk;
    StackCreate(&stk, 100);

    while (p || !isEmptyStack(stk))
    {
        if (p)
        {
            printf("%d ", p->data);
            push(&stk, p);
            p = p->lchild;
        }
        else
        {
            p = pop(&stk);
            p = p->rchild;
        }
    }
}
void IInorder(struct Node *p)
{
    struct Stack stk;
    StackCreate(&stk, 100);

    while (p || !isEmptyStack(stk))
    {
        if (p)
        {
            push(&stk, p);
            p = p->lchild;
        }
        else
        {
            p = pop(&stk);
            printf("%d ", p->data);
            p = p->rchild;
        }
    }
}

void LevelOrder(struct Node *root)
{
    struct Queue q;
    create(&q, 100);

    printf("%d ", root->data);
    enqueue(&q, root);

    while (!isEmpty(q))
    {
        root = dequeue(&q);
        if (root->lchild)
        {
            printf("%d ", root->lchild->data);
            enqueue(&q, root->lchild);
        }
        if (root->rchild)
        {
            printf("%d ", root->rchild->data);
            enqueue(&q, root->rchild);
        }
    }
}

int count(struct Node *root)
{
    if (root)
    {
        return count(root->lchild) + count(root->rchild) + 1;
    }
    return 0;
}

int ht(struct Node *root)
{
    int x = 0, y = 0;
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        x = ht(root->lchild);
        y = ht(root->rchild);
        if (x > y)
        {
            return x + 1;
        }
        else
        {
            return y + 1;
        }
    }
    return 0;
}

int leaf(struct Node *root)
{
    int x = 0, y = 0;
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        x = leaf(root->lchild);
        y = leaf(root->rchild);
        if (root->lchild == NULL && root->rchild == NULL)
        {
            return x + y + 1;
        }
        else
        {
            return x + y;
        }
    }
    return 0;
}

int nonleaf(struct Node *root)
{
    int x = 0, y = 0;
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        x = nonleaf(root->lchild);
        y = nonleaf(root->rchild);
        if (root->lchild != NULL || root->rchild != NULL)
        {
            return x + y + 1;
        }
        else
        {
            return x + y;
        }
    }
    return 0;
}

int main()
{
    Treecreate();

    // // Recursive Traversal
    // printf("\nPreorder : ");
    // Preorder(root);
    // printf("\nInOrder  : ");
    // Inorder(root);
    // printf("\nPost Order : ");
    // Postorder(root);

    // // Iterative Traversal
    // printf("\nPreorder : ");
    // IPreorder(root);
    // printf("\nInOrder  : ");
    // IInorder(root);
    // printf("\nPost Order : ");
    // Postorder(root);
    // printf("\nLevel Order : ");
    // LevelOrder(root);

    // // Count Nodes
    // printf("\nCount : %d", count(root));
    // // Height of Tree
    // printf("\nHeight : %d", ht(root));

    // // Count Leaf Nodes
    printf("\nLeaf Nodes or External Nodes : %d", leaf(root));
    // // Count Non-Leaf Nodes
    printf("\nNon-Leaf Nodes or Internal Nodes : %d", nonleaf(root));

    return 0;
}
