#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
}Node;

/* ---------------- INSERT ---------------- */
 struct node* insert(struct node *head, int x) {
    struct node *t = malloc(sizeof(struct node));
    t->data = x;
    t->next = NULL;

    if (!head) return t;

    struct node *p = head;
    while (p->next) p = p->next;
    p->next = t;
    return head;
}

/* ---------------- DISPLAY ---------------- */
void display(Node *head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

/* ---------------- REVERSE ---------------- */

struct node* reverse(struct node *head) {
    struct node *prev = NULL, *cur = head, *next = NULL;

    while (cur) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

/* ---------------- CONCATENATION ---------------- */
struct node* concat(struct node *h1, struct node *h2) {
    if (!h1) return h2;
    struct node *p = h1;
    while (p->next) p = p->next;
    p->next = h2;
    return h1;
}

/* =============== MERGE SORT =============== */

/* Merge two sorted LL */
struct node* merge(struct node *a, struct node *b) {
    if (!a) return b;
    if (!b) return a;

    if (a->data < b->data) {
        a->next = merge(a->next, b);
        return a;
    } else {
        b->next = merge(a, b->next);
        return b;
    }
}

/* Split into left and right halves */
void split(struct node *head, struct node **left, struct node **right) {
    struct node *slow = head, *fast = head->next;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    *left = head;
    *right = slow->next;
    slow->next = NULL;
}

/* Main mergesort function */
struct node* mergesort(struct node *head) {
    if (!head || !head->next)
        return head;

    struct node *left, *right;
    split(head, &left, &right);

    left = mergesort(left);
    right = mergesort(right);

    return merge(left, right);
}

/* ---------------- MENU ---------------- */
int main() {
    struct node *h1 = NULL, *h2 = NULL;
    int choice, val;

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Insert into List 1\n");
        printf("2. Insert into List 2\n");
        printf("3. Display List 1\n");
        printf("4. Display List 2\n");
        printf("5. Sort List 1 (Merge Sort)\n");
        printf("6. Reverse List 1\n");
        printf("7. Concatenate List1 + List2\n");
        printf("8. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                h1 = insert(h1, val);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &val);
                h2 = insert(h2, val);
                break;

            case 3:
                printf("List 1: ");
                display(h1);
                break;

            case 4:
                printf("List 2: ");
                display(h2);
                break;

            case 5:
                h1 = mergesort(h1);
                printf("List 1 Sorted.\n");
                break;

            case 6:
                h1 = reverse(h1);
                printf("List 1 Reversed.\n");
                break;

            case 7:
                h1 = concat(h1, h2);
                printf("Concatenated List (L1 + L2): ");
                display(h1);
                break;

            case 8:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
}