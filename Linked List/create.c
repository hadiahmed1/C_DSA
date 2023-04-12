#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node* next;
};

void traverse(struct Node* ptr){
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }   
}

int main(){
    struct Node* head;
    struct Node* second;
    struct Node* third;
    head=(struct Node*)malloc(sizeof(struct Node));
    second=(struct Node*)malloc(sizeof(struct Node));
    third=(struct Node*)malloc(sizeof(struct Node));
    head->data=7;
    head->next=second;//linking head to second
    second->data=5;
    second->next=third;//linking second to third
    third->data=9;
    third->next=NULL;//list terminated at null

    traverse(head);
    return 0;
}