#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data;
    struct node *next;
} Node;

Node *top = NULL;   
Node *front = NULL;  
Node *rear = NULL;
Node* create_node(int x) {
    Node *p = (Node*)malloc(sizeof(Node));
    p->data = x; p->next = NULL;
    return p;}

void push(int x) {
    Node *p = create_node(x);
    p->next = top;
    top = p;
    printf("Pushed %d onto stack.\n", x);}

void pop() {
    if (!top) {
        printf("Stack Underflow.\n"); return;}
    Node *temp = top;
    printf("%d  ", temp->data);
    top = top->next;
    free(temp);
}
void display_stack() {
    Node *p = top;
    if (!p) {
        printf("Stack is empty.\n");  return;}
    printf("Stack: ");
    while (p) {
        printf("%d ", p->data); p = p->next;
    }
    printf("\n");}

void enqueue(int x) {
    Node *p = create_node(x);
    if (rear == NULL) front = rear = p;
    else {
        rear->next = p;
        rear = p;}
    printf("Put %d into queue.\n", x);
}
void dequeue() {
    if (front == NULL) {
        printf("Queue Underflow.\n");  return;}
    Node *temp = front;
    printf("Dequeued %d\n", temp->data);
    front = front->next;
    if (front == NULL) rear = NULL;
    free(temp);
}

void display_queue() {
    Node *p = front;
    if (!p) {
        printf("Queue is empty.\n");  return;}
    printf("Queue: ");
    while (p) {
        printf("%d ", p->data); p = p->next;  }
    printf("\n");}

int main() {
    int ch, x;
    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Push (Stack)\n");
        printf("2. Pop (Stack)\n");
        printf("3. Display Stack\n");
        printf("4. Enqueue (Queue)\n");
        printf("5. Dequeue (Queue)\n");
        printf("6. Display Queue\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &x);
                push(x);
                break;

            case 2:
                pop();break;
            case 3:
                display_stack();break;
            case 4:
                printf("Enter value: ");
                scanf("%d", &x);
                enqueue(x); break;
            case 5:
                dequeue(); break;
            case 6:
                display_queue(); break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
