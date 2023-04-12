#include <stdio.h>
#include <stdlib.h>
struct node{//Structire
    int data;
    struct node* prev;
    struct node* next;
};
void printDLL(struct node* ptr){//function to print
    printf("%d,",ptr->data);
    if(ptr->next==NULL){
        printf("\n");
        return;
    }else{
        printDLL(ptr->next);
    }
}
//INSERTIONS
void insertTail(struct node* head,int data){
    //creating new node
    struct node* new=(struct node*)malloc(sizeof(struct node));
    new->data=data;
    new->next=NULL;
    struct node* ptr=head;
    while(ptr->next!=NULL){//finding old tail
        ptr=ptr->next;
    }
    //linking old tail & new tail
    ptr->next=new;
    new->prev=ptr;
}
struct node* insertHead(struct node* head,int data){
    //creating new node
    struct node* new=(struct node*)malloc(sizeof(struct node));
    new->data=data;
    new->prev=NULL;
    //conecting to next node,i.e, head
    new->next=head;
    head->prev=new;
    return new;
}
void insertAfter(struct node* ptr, int after,int data){
    while(ptr->data!=after && ptr->next!=NULL){//finding node with reqired data
        ptr=ptr->next;
    }
    //creating new node
    struct node* new=(struct node*)malloc(sizeof(struct node));
    new->data=data;
    //conecting to node that'll come after
    new->next=ptr->next;
    ptr->next->prev=new;
    //conecting to node that'll come before
    new->prev=ptr;
    ptr->next=new;
    return;
}
void insertBefore(struct node* ptr, int before,int data){
    while(ptr->data!=before && ptr->next!=NULL){//finding node with reqired data
        ptr=ptr->next;
    }
    //creating new node
    struct node* new=(struct node*)malloc(sizeof(struct node));
    new->data=data;
    //conecting to node before new node
    new->prev=ptr->prev;
    ptr->prev->next=new;
    //conecting to node after
    new->next=ptr;
    ptr->prev=new;
    return;
}
//DELETIONS
void deleteNode(struct node* del){
    del->prev->next=del->next;
    del->next->prev=del->prev;
    free(del);
    return;
}
void deleteNodeWith(struct node* ptr,int d){
    while(ptr->data!=d && ptr->next!=NULL){
        ptr=ptr->next;
    }
    deleteNode(ptr);
}
void deleteNodeAfter(struct node* ptr, int d){
    while(ptr->data!=d && ptr->next!=NULL){
        ptr=ptr->next;
    }
    if(ptr->next==NULL)
        printf("\nnothing is after %d",d);
    else
        deleteNode(ptr->next);
    return;
}
void deleteNodeBefore(struct node* ptr, int d){
    while(ptr->data!=d && ptr->next!=NULL){
        ptr=ptr->next;
    }
    if(ptr->prev==NULL)
        printf("\nnothing is before %d",d);
    else
        deleteNode(ptr->prev);
    return;
}
int main(){
    struct node* head=(struct node*)malloc(sizeof(struct node));
    head->data=0;
    head->next=NULL;
    head->prev=NULL;
    insertTail(head,1);
    insertTail(head,2);
    insertTail(head,3);
    insertTail(head,4);
    insertTail(head,5);
    head=insertHead(head,-1);
    insertAfter(head,3,6);
    insertBefore(head,2,7);
    deleteNodeWith(head,2);
    deleteNodeAfter(head,1);
    deleteNodeBefore(head,4);
    printDLL(head);
    return 0;
}