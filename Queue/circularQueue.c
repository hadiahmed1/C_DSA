#include <stdio.h>
#include <stdlib.h>
struct queue{
    int* arr;
    int size;
    int f;
    int r;
};
int isEmpty(struct queue* q){
    if(q->f==q->r){
        return 1;
    }else
        return 0;
}
int isFull(struct queue* q){
    if((q->r +1)%q->size ==q->f){
        return 1;
    }else
        return 0;
}
void enqueue(struct queue* q,int item){
    if(isFull(q)){
        printf("Queue Overflow\n");
        return;
    }else{
        q->r=(q->r +1)%(q->size);//circular incriment
        q->arr[q->r]=item;
    }
    return;
}
void dequeue(struct queue* q){
    if(isEmpty(q)){
        printf("Queue is empty\n");
        return;
    }else{
        q->f=(q->f +1)%q->size;
        printf("%d is deQueued\n",q->arr[q->f]);
    }
    return;
}
int main(){
    struct queue* q=(struct queue*)malloc(sizeof(struct queue));
    q->f=q->r=0;
    q->size=5;
    q->arr=(int *)malloc(q->size*sizeof(int));
    enqueue(q,1);
    enqueue(q,2);
    enqueue(q,3);
    enqueue(q,4);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    enqueue(q,5);
    enqueue(q,6);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    return 0;
}
