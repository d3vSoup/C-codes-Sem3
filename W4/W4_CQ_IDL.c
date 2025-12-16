#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;
void insert(int value) {
    if ((front == 0 && rear == MAX - 1) || (rear + 1) % MAX == front) {
        printf("Queue Overflow! Cannot insert %d\n", value);
        return;
    }

    if (front== -1) { 
        front= rear = 0;
    } else {
        rear= (rear + 1) % MAX;
    }
    queue[rear] = value;
    printf("%d inserted into the queue.\n", value);
}
void delete() {
    if (front == -1) {
        printf("Queue Underflow! Queue is empty.\n");
        return;
    }

    printf("%d deleted from the queue.\n", queue[front]);

    if (front== rear) { 
        front=rear= -1;
    } else {
        front= (front + 1) % MAX;
    }
}
void display() {
    if (front== -1) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    int i= front;
    while (1) {
        printf("%d ", queue[i]);
        if (i== rear) break;
        i = (i+1) % MAX;
    }
    printf("\n");
}

int main() {
    int choice, value;
    while (1) {
        printf("\n------ Circular Queue Menu ------\n");
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
                delete();break;
            case 3:
                display();break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
