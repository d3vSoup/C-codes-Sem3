#include <stdio.h>
#include <ctype.h>

#define MAX 100
char stack[MAX];
int top=-1;

void push(char x){
    if(top==MAX-1) printf("Overflow");
    else stack[++top]= x;
}

char pop(){
    if(top==-1) printf("Underflow");
    return stack[top--];
}

int prec(char x){
    if(x=='+' || x=='-') return 1;
    else if (x=='*' || x=='/') return 2;
    return 0;
}

int main()
{
    char infix[MAX],postfix[MAX];
    int i=0,j=0;
    printf("Enter infix expression");
    scanf("%s",&infix);
    while(infix[i] != '\0'){
        char c= infix[i];
        if(isalnum(c)) postfix[j++]=c;
        else if (c=='(') push(c);
        else if (c==')') { while(stack[top] != '(') postfix[j++]=pop();
        pop();}

        else {
            while(top!= -1 && prec(stack[top])>= prec(c)) postfix[j++]=pop();
            push(c);
        }
        i++;
    }

    while(top != -1) postfix[j++]= pop();
    postfix[j] = '\0';
    printf("Postfix expression is : %s \n", postfix);
    return 0;

}