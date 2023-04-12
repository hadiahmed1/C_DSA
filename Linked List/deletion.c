#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* next;
};
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
void insert_tail(struct node* head, int d){//inserting at tail
    struct node* new=(struct node*)malloc(sizeof(struct node));
    new->data=d;
    new->next=NULL;
    while(head->next!=NULL){
        head=head->next;
    }
    head->next=new;
}
struct node* del_head(struct node* head){
    struct node* ptr= head;
    head=head->next;
    free(ptr);
    return (head);
}
void del_index(struct node* ptr){
    printf("Enter the index you want to Delete:");
    int index;
    scanf("%d",&index);
    for(int i=0;i<index-1;i++){
        ptr=ptr->next;
    }
    ptr->next=(ptr->next)->next;
    return;
}
void delete_data(struct node* ptr, int d){
    while(ptr->next!=NULL){
        //printf("%d \n",(ptr->next)->data);
        if((ptr->next)->data==d){
            ptr->next=(ptr->next)->next;
        }    
        ptr=ptr->next; 
    }
    return;
}

int main(){
    struct node* head=(struct node*)malloc(sizeof(struct node));
    head->data=0;
    head->next=NULL;
    for(int i=1;i<10;i++)
        insert_tail(head,i);
    display(head);

    /*printf("Linked list after deleting Head: ");
    head=del_head(head);
    display(head);*/
    //del_index(head);


    delete_data(head,5);
    display(head);

    return 0;
}