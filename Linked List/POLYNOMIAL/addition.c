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

void add(struct node* h1,struct node* h2,struct node* h){
    while(h1!=NULL && h2!=NULL){
        if(h1->pow > h2->pow){
            insert(h,h1->cof,h1->pow);
            h1=h1->next;
        }

        else if(h2->pow > h1->pow){
            insert(h,h2->cof,h2->cof);
            h2=h2->next;
        }
        else{
            insert(h,h1->cof+h2->cof,h1->pow);
            h1=h1->next;
            h2=h2->next;
        }
    }
    return;
}



int main(){
    struct node* head1=NULL;
    head1=insert(head1,2,3);
    head1=insert(head1,1,20);
    head1=insert(head1,0,2);
    head1=insert(head1,1,9);
    head1=insert(head1,3,5);
    head1=insert(head1,2,7);
    display(head1);
    printf("\n");

    struct node* head2=NULL;
    head2=insert(head2,3,3);
    head2=insert(head2,1,15);
    head2=insert(head2,3,8);
    head2=insert(head2,6,9);
    head2=insert(head2,3,5);
    head2=insert(head2,2,10);
    display(head2);
    printf("\n Ans:");

    struct node* h=NULL;
    add(head1,head2,h);
    display(h);

    return 0;
}