#include <stdio.h>
#define SIZE 100

// Stack structure
struct TwoStacks {
    int arr[SIZE];
    int top1;
    int top2;
};

// Initialize the stacks
void initStacks(struct TwoStacks *s) {
    s->top1 = -1;
    s->top2 = SIZE;
}

// Push to Stack 1
void push1(struct TwoStacks *s, int value) {
    if (s->top1 < s->top2 - 1) {
        s->arr[++(s->top1)] = value;
    } else {
        printf("Stack Overflow in Stack 1\n");
    }
}

// Push to Stack 2
void push2(struct TwoStacks *s, int value) {
    if (s->top1 < s->top2 - 1) {
        s->arr[--(s->top2)] = value;
    } else {
        printf("Stack Overflow in Stack 2\n");
    }
}

// Pop from Stack 1
int pop1(struct TwoStacks *s) {
    if (s->top1 >= 0) {
        return s->arr[(s->top1)--];
    } else {
        printf("Stack Underflow in Stack 1\n");
        return -1;
    }
}

// Pop from Stack 2
int pop2(struct TwoStacks *s) {
    if (s->top2 < SIZE) {
        return s->arr[(s->top2)++];
    } else {
        printf("Stack Underflow in Stack 2\n");
        return -1;
    }
}

// Main function
int main() {
    struct TwoStacks s;
    initStacks(&s);

    push1(&s, 10);
    push1(&s, 20);
    push2(&s, 100);
    push2(&s, 200);

    printf("Popped from Stack 1: %d\n", pop1(&s));
    printf("Popped from Stack 2: %d\n", pop2(&s));

    return 0;
}
