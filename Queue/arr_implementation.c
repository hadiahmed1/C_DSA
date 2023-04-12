#include <stdio.h>
#include <stdlib.h>

struct queue{
    int* arr;
    int size;
    int f;
    int r;
};
void print_queue(struct queue* q){
    for(int i=q->f+1;i<=q->r;i++){
        printf("%d,",q->arr[i]);
    }
    printf("\n");
    return;
}
void enqueue(struct queue* q,int item){
    if(q->r==q->size-1){
        printf("Queue Overflow\n");
        return;
    }
    q->r+=1;
    q->arr[q->r]=item;
    return;
}
void dequeue(struct queue* q){
    if(q->f==q->r){
        printf("Queue is empty\n");
        return;
    }
    printf("%d is dequeued\n",q->arr[q->f+1]);//de queueing
    q->f+=1;
    return;
}

int main(){
    struct queue* q=(struct queue*)malloc(sizeof(struct queue));
    q->f=q->r=-1;
    q->size=10;
    q->arr=(int *)malloc(q->size*sizeof(int));
    enqueue(q,5);
    enqueue(q,8);
    enqueue(q,3);
    enqueue(q,6);
    enqueue(q,19);
    enqueue(q,6);
    dequeue(q);
    enqueue(q,5);
    enqueue(q,8);
    enqueue(q,3);
    enqueue(q,6);
    enqueue(q,19);
    enqueue(q,6);
    print_queue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    print_queue(q);
    return 0;
}
