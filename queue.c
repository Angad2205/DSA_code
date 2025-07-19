#include<stdio.h>
#include<stdlib.h>

#define size 4

//structure for defining the queue
typedef struct {
int array[size];
int front;
int rear;
}queue;

// Prototyping the functions 
void Enqueue(queue * , int);
int dequeue(queue *);
void init(queue *);

void init(queue *qp)
{ // initializing the front and rear end of the queue 
qp->front = 0;
qp->rear = 0;
}

void Enqueue(queue *qp, int data)
{
// condition for enqueue condition
if (qp->rear == size)
{
    printf("Overflow condition \n");
    return;
}
qp->array[qp->rear] = data;
printf("%d \n" ,qp->array[qp->rear]);
qp->rear++;

}

int dequeue(queue *qp)
{int flag;
// condition for dequeue condition
if (qp->front == qp->rear)
{
    printf("Underflow Condition \n");
    return 999;
}
flag = qp->array[qp->front];
printf("%d \n" , flag);
qp->front++;
return flag;
}

int main ()
{
    queue q1;
    init(&q1);
    Enqueue(&q1,11);
    Enqueue(&q1,12);
    Enqueue(&q1,13);
    Enqueue(&q1,14);
    Enqueue(&q1,15);
    dequeue(&q1);
    dequeue(&q1);
    dequeue(&q1);
    dequeue(&q1);
    dequeue(&q1);

    return 0;
}