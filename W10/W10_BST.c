#include <stdio.h> 
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* left, *right;
}Node;

Node* root = NULL;

Node* newNode(int x) {
    Node *p = (Node*)malloc(sizeof(Node));
    p->data = x;
    p->left = p->right = NULL;
    return p;
}

Node* insert ( Node* r, int x){
    if(!r) return newNode(x);
        if (x < r->data)  r->left  = insert(r->left, x);
    else if (x > r->data) r->right = insert(r->right, x);
    return r;
}

void inorder(Node* r){
    if(!r) return;
    inorder(r-> left);
    printf("%d  ", r->data);
    inorder(r-> right);
}

void preorder(struct node *r) {
    if (!r) return;
    printf("%d   ", r->data);
    preorder(r->left);
    preorder(r->right);
}

void postorder(struct node *r) {
    if (!r) return;
    postorder(r->left);
    postorder(r->right);
    printf("%d  ", r->data);
}

int main() {
    int ch, x;
    while (1) {
        printf("\n1.Insert\n2.Inorder\n3.Preorder\n4.Postorder\n5.Exit\nChoice: ");
        scanf("%d", &ch);

        if (ch == 1) {
            printf("Enter value: ");
            scanf("%d", &x);
            root = insert(root, x);
        }
        else if (ch == 2) {
            printf("Inorder : ");
            inorder(root);
            printf("\n");
        }
        else if (ch == 3) {
            printf("Preorder: ");
            preorder(root);
            printf(" \n");
        }
        else if (ch == 4) {
            printf("Postorder: ");
            postorder(root);
            printf("\n");
        }
        else if (ch == 5) {
            break;
        }
        else {
            printf("Invalid choice\n");
        }
    }
    return 0;
}



