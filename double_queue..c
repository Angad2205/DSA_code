#include <stdio.h>
#include <stdlib.h>

#define size 4

typedef struct {
    int array[size];
    int front;
    int rare;
    int count;
} queue;

// Function prototypes
void init(queue *);
void enqueue(queue *, int);
void dequeue(queue *);
int isEmpty(queue *);
int isFull(queue *);

void init(queue *qp) {
    qp->front = 0;
    qp->rare = 0;
    qp->count = 0;
}

int isFull(queue *qp) {
    return qp->count == size;
}

int isEmpty(queue *qp) {
    return qp->count == 0;
}

void enqueue(queue *qp, int data) {
    if (isFull(qp)) {
        printf("Queue is Full! Cannot enqueue %d\n", data);
        return;
    }
    qp->array[qp->rare] = data;
    qp->rare = (qp->rare + 1) % size;
    qp->count++;
    printf("Enqueued: %d\n", data);
}

void dequeue(queue *qp) {
    if (isEmpty(qp)) {
        printf("Queue is Empty! Cannot dequeue\n");
        return;
    }
    int data = qp->array[qp->front];
    qp->front = (qp->front + 1) % size;
    qp->count--;
    printf("Dequeued: %d\n", data);
}

int main() {
    queue q1;
    init(&q1);

    enqueue(&q1, 10);
    enqueue(&q1, 20);
    enqueue(&q1, 30);
    enqueue(&q1, 40);
    dequeue(&q1);
    enqueue(&q1, 50); // should say full

    dequeue(&q1);
    dequeue(&q1);
    dequeue(&q1);
    dequeue(&q1);
    dequeue(&q1); // should say empty

    return 0;
}
