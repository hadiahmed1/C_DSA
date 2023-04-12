//push opperators in stack
//higher precidence always above(in stack)
// +,- > *,/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stack{
    int size;
    int top;
    char* arr;
};
void push(struct stack* s,char ch){
    s->top=s->top+1;
    s->arr[s->top]=ch;
    return;
}
char pop(struct stack* s){
    char ret=s->arr[s->top];
    s->top -=1;
    return ret;
}
int isOperator(char ch){
    if(ch=='+'||ch=='-'||ch=='*'||ch=='/')
        return 1;
    else
        return 0;
}
int precedence(char ch){
    if(ch=='*'||ch=='/'){
        return 3;
    }
    else if(ch=='+'||ch=='-'){
        return 2;
    }
    else{
        return 0;
    }
}
char* infixToPostfix(char* infix){
    //creating stack
    struct stack* sp=(struct stack*)malloc(sizeof(struct stack));
    sp->size=10;
    sp->top=-1;
    sp->arr=(char*)malloc(sizeof(char)*sp->size);
    char* postfix=(char*)malloc(sizeof(char)*(strlen(infix)+1));
    int i=0;//iterating infix
    int j=0;//iterating postfix
    while(infix[i]!='\0'){
        if(!isOperator(infix[i])){//if scanned character isn't an operator
            postfix[j]=infix[i];//add it to postfix expression
            i++;
            j++;
        }
        else{//if scanned character is an Operator
            //checking precedence
            if(precedence(infix[i])>precedence(sp->arr[sp->top])){//higher precedence
                push(sp,infix[i]);
                i++;
            }
            else{//lower precedence
                postfix[j]=pop(sp);
                j++;
            }
        }
    }
    while(sp->top!=-1){//emptying stack
        postfix[j]=pop(sp);
        j++;
    }
    postfix[j]='\0';//terminating string
    return postfix;
}
int main(){
    printf("Enter Infix Expression:");
    char infix[100];
    scanf("%s",infix);
    char* postfix=infixToPostfix(infix);
    int i=0;
    printf("Postfix Expression:");
    while(postfix[i]!='\0'){
        printf("%c",postfix[i]);
        i++;
    }
    printf("\n");
    return 0;
}