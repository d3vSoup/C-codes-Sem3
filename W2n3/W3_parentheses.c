#include <stdio.h>
#define MAX 100
int top=-1;
char stack[MAX];

void push(char x){
    if(top==MAX -1) printf("Overflow");
    else stack[++top]=x;
}

char pop(){
    if(top == -1){
        printf("Underflow"); return '\0';
    }
    else return stack[top--];
}

int main(){
    char exp[MAX];
    int i, flag=1;
    printf("Enter expression \n");
    scanf("%s", & exp);
    for(int i=0; exp[i]!='\0';i++){
        char c= exp[i];
        if(c=='(' || c=='{' || c=='[') push(c);
        else if (c==')' || c=='}' || c==']'){
            char t= pop();
            if(t=='\0') { flag = 0; break;}
            if((c==')' && t!='(') || (c=='}' && t!='{') || (c==']' && t!='[') ){ flag =0; break;}
        }
    }

    if(top != -1 ) flag = 0;
    if(flag) printf("Parenthesis are balanced \n");
    else printf("Parenthesis are NOT balanced \n");
    return 0;
}
