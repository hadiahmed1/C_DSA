//Day6: Circular Linked List

#include <stdio.h>
#include <stdlib.h>

struct node//structure of node
{
    int data;
    struct node* next;//self refrencing pointer to next node
};

void print_circular(struct node* head){
    struct node* ptr=head;
    do{
        printf("%d ,",ptr->data);
        ptr=ptr->next;
    }while(ptr!=head);//printing till we reach head
}

struct node* insert_head(struct node* head, int d){
    //creating the new node
    struct node* new= (struct node*)malloc(sizeof(struct node*));
    new->data=d;
    new->next=head;//new node is before head, therefore points to head
    struct node* ptr=head;
    do{//finding tail
        ptr=ptr->next;
    }while(ptr->next!=head);
    ptr->next=new;//tail points to new head
    return new;
}
void insert_tail(struct node* head, int data){
    struct node* ptr=head;
    //creating new node
    struct node* new=(struct node*)malloc(sizeof(struct node*));
    new->data=data;
    new->next=head;//new tail points to head
    do{
        ptr=ptr->next;
    }
    while(ptr->next!=head);
    ptr->next=new;
    return;
}
int main(){-
    struct node* head=(struct node*)malloc(sizeof(struct node));
    struct node* n2=(struct node*)malloc(sizeof(struct node));
    struct node* n3=(struct node*)malloc(sizeof(struct node));
    struct node* n4=(struct node*)malloc(sizeof(struct node));
    head->data=0;
    head->next=n2;
    n2->data=2;
    n2->next=n3;
    n3->data=3;
    n3->next=n4;
    n4->data=4;
    n4->next=head;
    head=insert_head(head,8008);
    insert_tail(head,123);
    print_circular(head);
    return 0;
}