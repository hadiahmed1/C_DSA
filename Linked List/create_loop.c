#include <stdio.h>
#include <stdlib.h>
struct node{//structure
    int data;
    struct node* next;
};
void insert_tail(struct node* head, int d){//inserting at tail
    struct node* new=(struct node*)malloc(sizeof(struct node));
    new->data=d;
    new->next=NULL;
    while(head->next!=NULL){
        head=head->next;
    }
    head->next=new;
}
void display(struct node* ptr){// function to Display
    int count=0;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
        count++;
    }  
    printf("\n"); 
    printf("Count=%d\n",count);
}
struct node* insert_head(struct node* head,int d){//inserting at head
    struct node* new=(struct node*)malloc(sizeof(struct node));
    new->data=d;
    new->next=head;
    return new;
}
void insert_atPos(struct node* ptr, int d, int pos){
    struct node* new=(struct node*)malloc(sizeof(struct node));
    new->data=d;
    for(int i=1;i<pos;i++)
        ptr=ptr->next;
    new->next=ptr->next;
    ptr->next=new;
}
int main(){
    struct node* head;
    head=(struct node*)malloc(sizeof(struct node));
    head->data=0;
    head->next=NULL;
    for(int i=1; i<=10;i++)
        insert_tail(head,i*i);
    //head=insert_head(head,11);
    display(head);
    insert_atPos(head,123,3);
    printf("\n");
    display(head);
    return 0;
}