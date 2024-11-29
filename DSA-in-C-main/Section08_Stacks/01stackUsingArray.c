#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int top;
    int size;
    int *s;
};

void Create(struct Node *st)
{
    printf("Enter size of stack: ");
    scanf("%d", &st->size);
    st->s = (int *)malloc(st->size * sizeof(int));
    st->top = -1;
}

void Display(struct Node *st)
{
    printf("Elements of stack are:\n");
    printf("------\n");
    for (int i = st->top; i >= 0; i--)
    {
        printf("| %d |\n", st->s[i]);
        printf("------\n");
    }
    // printf("\n");
}

void push(struct Node *st, int x)
{
    if (st->top == st->size - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        st->top++;
        st->s[st->top] = x;
    }
}

int pop(struct Node *st)
{
    int x = -1;
    if (st->top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        printf("Popped element is %d\n", st->s[st->top]);
        x = st->s[st->top];
        st->top--;
    }
    return x;
}

int Peek(struct Node *st, int index)
{
    int x = -1;
    if (st->top - index + 1 < 0)
    {
        printf("Invalid Index\n");
    }
    x = st->s[st->top - index + 1];
    return x;
}

int stackTop(struct Node *st)
{
    if (st->top == -1)
    {
        return -1;
    }
    else
    {
        return st->s[st->top];
    }
}

int isFull(struct Node *st)
{
    return (st->top == st->size - 1);
}

int isEmpty(struct Node *st)
{
    return (st->top == -1);
}

int main()
{
    struct Node st;
    Create(&st);
    push(&st, 10);
    push(&st, 20);
    Display(&st);
    // pop(&st);
    // Display(&st);
    printf("Element at index 1 is %d\n", Peek(&st, 1));
    printf("Element at top of stack is %d\n", stackTop(&st));
    printf("Is stack full? %d\n", isFull(&st));
    printf("Is stack empty? %d\n", isEmpty(&st));
    return 0;
}