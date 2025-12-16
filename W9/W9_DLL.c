#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *prev, *next;
};

struct node *head = NULL;

struct node* create_node(int x) {
    struct node *p = (struct node*)malloc(sizeof(struct node));
    p->data = x;
    p->prev = p->next = NULL;
    return p;
}

void create_list() {
    int n, x;
    struct node *tail = NULL;
    printf("How many nodes? ");
    scanf("%d", &n);
    head = NULL;
    for (int i= 0; i<n;i++) {
        printf("Enter data: ");
        scanf("%d", &x);
        struct node *p = create_node(x);
        if (head == NULL) {
            head=tail= p;
        } else {
            tail->next = p;
            p->prev = tail;
            tail = p;
        }
    }
}

void insert_left_of_node() {
    if (head == NULL) {
        printf("List empty.\n");
        return;
    }
    int key, x;
    printf("Insert new node with data: ");
    scanf("%d", &x);
    printf("To the left of node with value: ");
    scanf("%d", &key);

    struct node *curr = head;
    while (curr && curr->data != key)
        curr = curr->next;

    if (!curr) {
        printf("Node with value %d not found.\n", key);
        return;
    }

    struct node *p = create_node(x);
    p->next = curr;
    p->prev = curr->prev;
    if (curr->prev) curr->prev->next = p;
    else head = p;

    curr->prev = p;
}

void delete_by_value() {
    if (head == NULL) {
        printf("List empty.\n");
        return;
    }
    int key;
    printf("Enter value to delete: ");
    scanf("%d", &key);

    struct node *curr = head;
    while (curr && curr->data != key)
        curr = curr->next;

    if (!curr) {
        printf("Node with value %d not found.\n", key);
        return;
    }

    if (curr->prev)  curr->prev->next = curr->next;
    else head = curr->next;
    if (curr->next)  curr->next->prev = curr->prev;
    free(curr);
    printf("Deleted.\n");
}
void display() {
    struct node *p = head;
    if (!p) {
        printf("List empty.\n");
        return;
    }
    printf("List: ");
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
int main() {
    int ch;
    while(1) {
        printf("\n1. Create list\n2. Insert left of node\n3. Delete by value\n4. Display\n5. Exit\n");
        printf("Choice: ");
        if (scanf("%d", &ch) != 1) break;
        switch (ch) {
            case 1: create_list(); break;
            case 2: insert_left_of_node(); break;
            case 3: delete_by_value(); break;
            case 4: display(); break;
            case 5: exit(0);
            default: printf("Invalid choice.\n");
        }
    }
    return 0;
}
