#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;
Node* create_node(int x) {
    Node *p = malloc(sizeof(Node));
    p->data = x;
    p->next = NULL;
    return p;
}
Node* create_list(int n) {
    if (n <= 0) return NULL;
    int x;
    scanf("%d", &x);
    Node *head = create_node(x), *tail = head;
    for (int i = 1; i < n; i++) {
        scanf("%d", &x);
        tail->next = create_node(x);
        tail = tail->next;
    }
    return head;
}
Node* delete_first(Node *head) {
    if (!head) return NULL;
    Node *t = head;
    head = head->next;
    free(t);
    return head;
}
Node* delete_last(Node *head) {
    if (!head) return NULL;
    if (!head->next) {
        free(head);
        return NULL;
    }
    Node *p = head;
    while (p->next->next) p = p->next;
    free(p->next);
    p->next = NULL;
    return head;
}
Node* delete_value(Node *head, int key) {
    if (!head) return NULL;
    if (head->data == key) {
        Node *t = head;
        head = head->next;
        free(t);
        return head;
    }
    Node *p = head;
    while (p->next && p->next->data != key)
        p = p->next;
    if (p->next) {
        Node *t = p->next;
        p->next = t->next;
        free(t);
    }
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
    int ch, n, x;
    while (1) {
        printf("\n1.Create list\n2.Delete first\n3.Delete by value\n4.Delete last\n5.Display\n6.Exit\nChoice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                printf("Enter number of nodes: ");
                scanf("%d", &n);
                printf("Enter elements:\n");
                head = create_list(n);
                break;

            case 2:
                head = delete_first(head);
                break;

            case 3:
                printf("Enter value: ");
                scanf("%d", &x);
                head = delete_value(head, x);
                break;

            case 4:
                head = delete_last(head);
                break;

            case 5:
                display(head);
                break;

            case 6:
                exit(0);
        }
    }
}
