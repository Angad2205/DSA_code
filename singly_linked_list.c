#include<stdio.h>
#include<stdlib.h>

// defining the structure for the node 
typedef struct {
int data;
struct node *next;
}node;

// defining the structure for the linked list 
typedef struct {
struct node *head;
struct node *tail;
int count;
}linked_list;

//defining the function for the linkedlist 
void init(linked_list *);
void add_at_head(linked_list * , int);
void remove_from_head(linked_list *);
void add_at_tail(linked_list * , int);
void remove_from_tail(linked_list *);
void taversal(linked_list *);
void remove_element_in_between(linked_list * , int);

// defining the functions
void init(linked_list *lp)
{
lp->count = 0;
lp->head = NULL;
lp->tail = NULL;
}

void add_at_head(linked_list *lp , int data)
{
node *new_pointer = (node *)malloc(sizeof(node));
if (new_pointer == NULL)
{
printf("Memory cannot be allocated");
return;
}
new_pointer->data = data;
new_pointer->next = NULL;
if (lp->count == 0)
{// this means that its our first node to be added to the list so both head and tail will be pointing to this node 
lp->head = new_pointer;
lp->tail = new_pointer;
}
else
{
new_pointer->next = lp->head;
lp->head = new_pointer;
}
lp->count++;
}


void remove_from_head(linked_list *lp)
{
node *pointer;
if (lp->count == 0)
{
printf("Linked list is Empty, cannot delete the element");
return;
}
if (lp->count == 1)
{// when only single element is their 
    pointer = lp->head;
    lp->head = NULL;
    lp->tail = NULL;
    free(pointer);
    lp->count--;
    return;
}
pointer = lp->head;
lp->head = pointer->next;
free(pointer);
lp->count--;
}

void add_at_tail(linked_list *lp , int data)
{   node *flag;
    node *pointer1 = (node *)malloc(sizeof(node));
    if (pointer1 == NULL)
    {
        printf("cannot allot the node");
        return;
    } 
    pointer1->next = NULL;
    pointer1->data = data;
    if(lp->count == 0)
    {
    lp->head = pointer1;
    lp->tail = pointer1;
    }
    else
    {
    flag = lp->tail;
    lp->tail = pointer1;
    flag->next = pointer1;
    }
    lp->count++;
}

void remove_from_tail(linked_list *lp)
{
    if (lp->count == 0)
    {
        printf("Linked list is Empty, cannot delete the element\n");
        return;
    }

    // Case 1: Only one element
    if (lp->count == 1)
    {
        free(lp->tail);
        lp->head = NULL;
        lp->tail = NULL;
        lp->count--;
        return;
    }

    // Case 2: More than one element
    node *current = lp->head;
    while (current->next != lp->tail)
    {
        current = current->next;
    }

    // Now current is the second last node
    free(lp->tail);
    lp->tail = current;
    current->next = NULL;
    lp->count--;
}

void taversal(linked_list *lp)
{
node *traverse;
traverse = lp->head;
while(traverse != NULL)
{
    printf("%d \n" , traverse->data);
    traverse = traverse->next;
} 
}

void remove_element_in_between(linked_list *ls, int index)
{
    if (ls->count < 3)
    {
        printf("List must have at least 3 nodes to remove a middle one.\n");
        return;
    }

    if (index <= 0 || index >= ls->count - 1)
    {
        printf("Invalid index. It must be between 1 and %d (exclusive).\n", ls->count - 1);
        return;
    }

    node *prev = ls->head;
    for (int i = 0; i < index - 1; i++)
    {
        prev = prev->next;
    }

    node *to_delete = prev->next;
    prev->next = to_delete->next;
    free(to_delete);
    ls->count--;
}

int main()
{
    return 0;
}