#include<stdio.h>
#define size 10 // Macro for size in stack 
typedef struct {
    int item[size];
    int top;
}stack;
// Declaring the pop and push function 
void init(stack *);
void push(stack * , int);
int pop(stack *); // pop will return the data which is deleted 

// Initialize the stack variable before use 
void  init(stack *sp)
{
    sp->top = -1;
}
// Writing the logic for pop and push function
void push(stack *sp , int data)
{
    if (sp->top == size-1)
    {
        printf("Overflow condition can not add more data");
        return;
    }
    sp->top++;
    sp->item[sp->top] = data;
    printf("%d\n" , sp->item[sp->top]);
} 

int pop(stack *sp)
{   int flag; // to store data which need to be deleted
    if(sp->top == -1)
    {
        printf("Under Flow condition can not remove more elements\n");
        return 9999;
    }
    flag = sp->item[sp->top];
    sp->top--;
    printf("%d\n" , flag);
    return flag;
}
int main()
{
    stack s1; // two different stacks,
    init(&s1);
    push(&s1,33);
    push(&s1,44);
    push(&s1,22);
    push(&s1,11);
    pop(&s1);
    pop(&s1);
    pop(&s1);
    pop(&s1);
    pop(&s1);
    return  0;
}