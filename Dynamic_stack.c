#include<stdio.h>
#include <stdlib.h>

// structure for the stack
// here size is put inside the struct because different stack can have different size
typedef struct {
int *pointer_to_hold_dynamic_stack ;
int size;
int top;
}stack;


// initializing of the stack 
void init(stack * , int);
int pop(stack *);
void push(stack * , int);
void deallocate(stack *);

void init(stack *sp , int size)
{
    printf("The stack size alloted is %d \n" , size);
    sp->pointer_to_hold_dynamic_stack = (int *)malloc(sizeof(int) * size);
    // this above statement is used to store the pointer of alloted dynamic stack
    if (sp->pointer_to_hold_dynamic_stack == NULL)
    {
        printf("Memory can not be allocated \n");
        return;
    }
    sp->top = -1;
    sp->size = size; 
}

void push(stack *sp , int data)
{
    if(sp->top == sp->size-1)
    {
    printf("Overflow Condition \n");
    return;
    }
    sp->top++;
    sp->pointer_to_hold_dynamic_stack[sp->top] = data;
    printf("%d \n" , sp->pointer_to_hold_dynamic_stack[sp->top]);
    
}

int pop (stack *sp)
{   int flag; //  to store and return pop variable 
    if(sp->top == -1)
    {
    printf("Under Flow \n");
    return 999;
    }
    flag = sp->pointer_to_hold_dynamic_stack[sp->top];
    sp->top--;
    printf("%d\n" , flag);
    return flag;
}

void deallocate(stack *sp)
{
    if(sp->pointer_to_hold_dynamic_stack != NULL){
        free(sp->pointer_to_hold_dynamic_stack);
        printf("Memory Deallocated");
}
}
int main ()
{   stack s1;
    printf("Enter the size of the stack \n");
    init(&s1,4);
    push(&s1,11);
    push(&s1,22);
    push(&s1,33);
    push(&s1,44);
    push(&s1,55);
    pop(&s1);
    pop(&s1);
    pop(&s1);
    pop(&s1);
    pop(&s1);


    return 0;
}