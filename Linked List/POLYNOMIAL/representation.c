#include <stdio.h>
#include <stdlib.h>
struct node
{
    int cof;//coefficient
    int pow;//power
    struct node* next;
};
struct node* findLoc(struct node* head,int p){//finds Location
    if(head==NULL)//list is empty
        return NULL;
    if(p>head->pow)//insert at begining
        return NULL;
    struct node* ptr=head->next;
    while (ptr!= NULL){//finding the node with higher power
        if(p>ptr->pow)
            return head;//inserting before highest power
        head=ptr;
        ptr=ptr->next;
    }
    return head;
}
struct node* insert(struct node* head,int c,int p){//power of next node must be larger
    struct node* new=(struct node*)malloc(sizeof(struct node));//creating new node
    new->cof=c;
    new->pow=p;
    struct node* loc=findLoc(head,p);//finding location to be inserted
    if (loc==NULL){
        new->next=head;
        head=new;
    }
    else{
        new->next=loc->next;
        loc->next=new;
    }
    return head;
}
void display(struct node* head){
    if(head==NULL)
        return;
    printf("%dx^%d + ",head->cof,head->pow);
    display(head->next);//recusive call
}
int main(){
    struct node* head=NULL;
    head=insert(head,2,3);
    head=insert(head,1,20);
    head=insert(head,0,2);
    head=insert(head,1,9);
    head=insert(head,3,5);
    head=insert(head,2,7);
    display(head);

    return 0;
}