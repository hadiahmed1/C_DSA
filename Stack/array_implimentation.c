#include <stdio.h>
#include <stdlib.h>

struct stack{//Advantage of making struct: pass the whole stack by refrence. instead of an attribute
    int size;
    int top;
    int* arr;
};
int peek(struct stack* pk,int i){
    if((pk->top+1)-i<0){
        printf("INVALID");
        return -1;
    }
    else
        return pk->arr[(pk->top+1)-i];
}
void push(struct stack* ptr, int data){
    if(ptr->top==ptr->size){
        printf("Cannot push, Stack is full\n");
        return;
    }
    ptr->top+=1;
    ptr->arr[ptr->top]=data;
    return;
}
void pop(struct stack* ptr){
    if(ptr->top<0){
        printf("Cannot pop, Stack is empty\n");
        return;
    }
    ptr->top-=1;
    return;
}
int isEmpty(struct stack* ptr){
    if(ptr->top==-1)
        return 1;
    else 
        return 0;
}
int isFull(struct stack* ptr){
    if((ptr->top)<(ptr->size))
        return 0;
    else 
        return 1;
}
void printStack(struct stack* ptr){
    for(int i=0;i<=ptr->top;i++)
        printf("%d, ",ptr->arr[i]);
    
    return;
}
void menue(){
    printf("MAIN MENUE\n1.Push\n2.Pop\n3.Print\n4.Peek\n5.Exit\n");
}
void choice(struct stack* s){
    int choice;
    int d;
    while(choice!=5){
        
        printf("Enter your Choice:");
        scanf("%d",&choice);
        switch (choice){
            case 1:{
                //int d;
                printf("Data=");
                scanf("%d",&d);
                push(s,d);
                break;
            }
            case 2:{
                pop(s);
                break;
            }
            case 3:
                printStack(s);
                break;
            case 4:{
                printf("Enter peek position:");
                int i;
                scanf("%d",&i);
                i=peek(s,i);
                printf("peek=%d\n",i);
                break;
            }
            default:
                printf("Wrong choice\n");
        }     
    }
    return;
}
int main(){
    struct stack *s=(struct stack*)malloc(sizeof(struct stack));
    s->size=15;
    s->top=-1;//stack is empty
    s->arr=(int*)malloc((s->size)*sizeof(int));
    menue();
    choice(s);
    return 0;
}