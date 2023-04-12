//Push & Pop at Head as O(1)
#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* next;//self refrencing pointer
};
struct stack{
    struct node* top;
};
void push(struct stack* s, int d){
    struct node* n=(struct node*)malloc(sizeof(struct node));
    if(n==NULL){
        n->data=d;
        n->next=s->top;
        s->top=n;
    }
    else
        printf("Stack OverFlow"); 
}
void pop(struct stack* s){
    struct node* n=s->top;
    if(s->top==NULL){
        printf("Cannot Pop Stack is Empty\n");
        return;
    }
    s->top=(s->top)->next;
    free(n);
}
void printStack(struct stack* s){
    struct node* ptr=s->top;
    while(ptr!=NULL){
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}
int main(){
    struct stack* s=(struct stack*)malloc(sizeof(struct stack));
    s->top=NULL;
    push(s,1);
    push(s,2);
    push(s,3);
    pop(s);
    push(s,1);
    pop(s);
    push(s,2);
    push(s,3);
    push(s,1);
    push(s,2);
    push(s,3);
    printStack(s);
    return 0;
}