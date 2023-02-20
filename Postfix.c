#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define MAX 100
//evaulation : https://www.youtube.com/watch?v=imfuqa9E6O8
int stack[MAX];
char infix[MAX], postfix[MAX];
int top=-1;

int isEmpty(){
    if(top==-1)
        return 1;
    else
        return 0;
}

int pop(){
    char c;
    if(top == -1){
        printf("Stack underflow\n");
        exit(1);
    }
    c=stack[top];
    top=top-1;
    return c;
}

void push(char c){
    if(top==MAX-1){
        printf("Stack overflow\n");
    }
    top++;
    stack[top]=c;
}

void print(){
    int i=0;
    printf("The equivalent postfix expression is: \n");
    while(postfix[i]){
        printf("%c", postfix[i++]);
    }
    printf("\n");
}

int precedence(char symbol){
    switch (symbol)
    {
    case '^':
        return 3;
    case '/':
    case '*':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return 0;;
    }
}

void inToPost(){
    int i,j=0;
    char symbol, next;
    for(i=0;i<strlen(infix);i++){
        symbol=infix[i];
        switch (symbol){
        case '(':
            push(symbol);
            break;
        
        case ')':
            while((next=pop())!='(')
                postfix[j++]=next;
            break;
        
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
            while(!isEmpty() && precedence(stack[top])>= precedence(symbol))
                postfix[j++]=pop();
            push(symbol);
            break;

        default:
            postfix[j++]=symbol;
        }
    }
    while(!isEmpty())
        postfix[j++]=pop();
    postfix[j]='\0';
}
/* 
int pow(int a,int b){
    int i,multi;
    for ( i = 0; i < b; i++)
        multi*=a;
    return multi;
}
 */
int post_eval(){
    int i,a,b;
    for(i=0;i<strlen(postfix);i++){
        if(postfix[i]>='0' && postfix[i]<='9'){
            push(postfix[i]-'0');
        }
        else{
            a=pop();
            b=pop();
            switch(postfix[i]){
                case '+':
                    push(b+a);
                    break;
                case '-':
                    push(b-a);
                    break;
                case '*':
                    push(b*a);
                    break;
                case '/':
                    push(b/a);
                    break;
                case '^':
                    push(pow(b,a));
                    break;
            }
        }
    }
    return pop();
}

int main(){
    int result;
    printf("Enter the infix expression: \n");
    gets(infix);

    inToPost();
    result=post_eval();
    print();
    printf("The result obtained after postfix evaluation is: ");
    printf("%d\n",result);
    return 0;
}
