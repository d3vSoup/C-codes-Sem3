#include <stdio.h>
#include <stdlib.h>

#define MAX 5 

int queue[MAX];
int front = -1, rear = -1;
void insert(int x) {
    if (rear == MAX - 1) {
        printf("Queue Overflow! Cannot insert %d\n", x);
        return;
    }
    if (front == -1) front = 0;
    queue[++rear] = x;
    printf("%d inserted into the queue.\n", x);
}
void delete() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow! Queue is empty.\n");
        return;
    }
    printf("%d deleted from the queue.\n", queue[front]);
    front++;
}
void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n------ Queue Menu ------\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
