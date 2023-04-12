#include <stdio.h>
#include <stdlib.h>
struct stack{
    int size;
    int top;
    int* arr;
};
int isEmpty(struct stack* ptr){
    if(ptr->top==-1)
        return 1;
    else 
        return 0;
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
int pop(struct stack* ptr){
    int ret=ptr->arr[ptr->top];
    ptr->top-=1;
    return ret;
}
struct queue{
    int size;
    struct stack* input;
    struct stack* output;
};

void enqueue(struct queue* q,int item){
    push(q->input,item);
    return;
}
void dequeue(struct queue* q){
    if(isEmpty(q->output)){
        do{
            push(q->output,pop(q->input));
        }while(q->input->top >=0);
    }
    printf("\n%d is DeQueued",pop(q->output));
}
int main(){
    struct queue* q=(struct queue*)malloc(sizeof(struct queue));
    q->size=10;
    q->input=(struct stack*)malloc(sizeof(struct stack));
    q->input->size=q->size;
    q->input->arr=(int *)malloc(sizeof(int)*q->size);
    q->input->top=-1;

    q->output=(struct stack*)malloc(sizeof(struct stack));
    q->output->size=q->size;
    q->output->arr=(int *)malloc(sizeof(int)*q->size);
    q->output->top=-1;
    enqueue(q,1);
    enqueue(q,2);
    enqueue(q,3);
    enqueue(q,4);
    enqueue(q,5);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    enqueue(q,6);
    enqueue(q,7);
    enqueue(q,8);
    dequeue(q);
    enqueue(q,9);
    enqueue(q,10);
    enqueue(q,11);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);

    return 0;
}
