#include <stdio.h>
#include <stdlib.h>

#define size 100 // Increased size for longer expressions

typedef struct {
    char item[size];
    int top;
} stack;

void init(stack *sp) {
    sp->top = -1;
}

void push(stack *sp, char data) {
    if (sp->top == size - 1) {
        printf("Stack Overflow: Cannot push '%c'\n", data);
        return;
    }
    sp->item[++(sp->top)] = data;
}

char pop(stack *sp) {
    if (sp->top == -1) {
        printf("Stack Underflow: Nothing to pop\n");
        return '\0';
    }
    return sp->item[(sp->top)--];
}

int isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

int main() {
    stack s1;
    char data[size];
    int i = 0;

    init(&s1);

    printf("Enter the expression:\n");
    scanf("%s", data);

    while (data[i] != '\0') {
        switch (data[i]) {
            case '(': 
            case '{': 
            case '[':
                push(&s1, data[i]);
                break;

            case ')': 
            case '}': 
            case ']':
                if (s1.top == -1) {
                    printf("The expression is wrong: Unmatched closing '%c'\n", data[i]);
                    return 0;
                } else {
                    char temp = pop(&s1);
                    if (!isMatchingPair(temp, data[i])) {
                        printf("The expression is wrong: Mismatch '%c' with '%c'\n", temp, data[i]);
                        return 0;
                    }
                }
                break;

            default:
                // If you want to ignore other characters, do nothing
                break;
        }
        i++;
    }

    if (s1.top == -1) {
        printf("The expression is correct\n");
    } else {
        printf("The expression is wrong: Unmatched opening brackets remain\n");
    }

    return 0;
}
