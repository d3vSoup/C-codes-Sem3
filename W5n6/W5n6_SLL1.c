#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

Node* create(int x) {
    Node *p = malloc(sizeof(Node));
    p->data = x;
    p->next = NULL;
    return p;
}

Node* create_list(int n) {
    if (n <= 0) return NULL;
    int x;
    printf("Enter data: ");
    scanf("%d", &x);
    Node *head = create(x), *tail = head;
    for (int i = 1; i < n; i++) {
        printf("Enter data: ");
        scanf("%d", &x);
        tail->next = create(x);
        tail = tail->next;
    }
    return head;
}

Node* insert_first(Node *head, int x) {
    Node *p = create(x);
    p->next = head;
    return p;
}

Node* insert_end(Node *head, int x) {
    Node *p = create(x);
    if (!head) return p;
    Node *t = head;
    while (t->next) t = t->next;
    t->next = p;
    return head;
}

Node* insert_pos(Node *head, int x, int pos) {
    if (pos == 1) return insert_first(head, x);
    Node *p = create(x);
    Node *t = head;
    for (int i = 1; i < pos - 1 && t; i++)
        t = t->next;
    if (!t) return head;
    p->next = t->next;
    t->next = p;
    return head;
}

void display(Node *head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node *head = NULL;
    int ch, n, x, pos;

    while (1) {
        printf("\n1.Create list\n2.Insert first\n3.Insert at position\n4.Insert end\n5.Display\n6.Exit\nChoice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("How many nodes: ");
                scanf("%d", &n);
                head = create_list(n);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &x);
                head = insert_first(head, x);
                break;

            case 3:
                printf("Enter value and position: ");
                scanf("%d %d", &x, &pos);
                head = insert_pos(head, x, pos);
                break;

            case 4:
                printf("Enter value: ");
                scanf("%d", &x);
                head = insert_end(head, x);
                break;

            case 5:
                display(head);
                break;

            case 6:
                exit(0);
        }
    }
}
