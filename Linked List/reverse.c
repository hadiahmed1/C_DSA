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
void reverse_list(struct node** head){//Function to reverse
    struct node* prev=NULL;
    struct node* current=*head;
    struct node * nxt=NULL;
    while (current!=NULL){
        nxt=current->next;
        current->next=prev;//current node will point to previous node
        prev=current;//moving to the next node
        current=nxt;//moving to the next node
    }
    *head=prev;
}
int main(){
    struct node* head;
    head=(struct node*)malloc(sizeof(struct node));
    head->data=0;
    head->next=NULL;
    for(int i=1; i<=10;i++)
        insert_tail(head,i);

    reverse_list(&head);
    display(head);
    return 0;
    
}