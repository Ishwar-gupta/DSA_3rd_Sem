#include <stdio.h>
#define MAX_SIZE 5

struct stack2 {
    int tos;
    int item[MAX_SIZE];
};

typedef struct stack2 st;

/* Initialize stack */
void createEmpty(st *s) {
    s->tos = -1;
}

/* Check if stack is full */
int isFull(st *s) {
    return s->tos == MAX_SIZE - 1;
}

/* Check if stack is empty */
int isEmpty(st *s) {
    return s->tos == -1;
}

/* Push operation */
void push(st *s, int x) {
    if (isFull(s)) {
        printf("Stack Overflow! Cannot push %d\n", x);
    } else {
        s->tos++;
        s->item[s->tos] = x;
        printf("Pushed element: %d\n", x);
    }
}

/* Pop operation */
void pop(st *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow! Stack is empty.\n");
    } else {
        int x = s->item[s->tos];
        s->tos--;
        printf("Popped element: %d\n", x);
    }
}

/* Display stack */
void display(st *s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements: ");
        for (int i = 0; i <= s->tos; i++) {
            printf("%d ", s->item[i]);
        }
        printf("\n");
    }
}

int main() {
    st s1;
    int ch, el;

    createEmpty(&s1);

    while (1) {
        printf("\n---- STACK MENU ----\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter element to push: ");
                scanf("%d", &el);
                push(&s1, el);
                break;

            case 2:
                pop(&s1);
                break;

            case 3:
                display(&s1);
                break;

            case 4:
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice! Please enter 1-4.\n");
        }
    }
}
