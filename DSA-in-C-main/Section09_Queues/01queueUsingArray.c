#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};

void create(struct Queue *q)
{
    printf("Enter the size of the queue: ");
    scanf("%d", &q->size);
    q->Q = (int *)malloc(q->size * sizeof(int));
    q->front = q->rear = -1;
    printf("Queue created successfully\n");
}

void enqueue(struct Queue *q, int x)
{
    if (q->rear == q->size - 1)
    {
        printf("Queue is full\n");
    }
    else
    {
        q->rear++;
    }
    q->Q[q->rear] = x;
}

int dequeue(struct Queue *q)
{
    int x = -1;
    if (q->front == q->rear)
    {
        printf("Queue is empty\n");
    }
    else
    {
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}

void Display(struct Queue q)
{
    for (int i = q.front + 1; i <= q.rear; i++)
    {
        printf("%d ", q.Q[i]);
    }
    printf("\n");
}

int main()
{
    struct Queue q;
    create(&q);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 30);
    enqueue(&q, 30);
    printf("Dequeued element: %d\n", dequeue(&q));
    printf("Dequeued element: %d\n", dequeue(&q));
    Display(q);

    return 0;
}