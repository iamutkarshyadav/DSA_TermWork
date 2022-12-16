#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};
void display(struct node *head)
{
    struct node *trav;
    trav=head;
    while(trav!=0){ 
        printf("%d  ",trav->data);
        trav=trav->next;
    }
}
struct node* create(struct node* head){   
    int ch;
    struct node* newnode,*temp;
    do{
        newnode=(struct node *)malloc(sizeof(struct node));
        printf("Enter data :");
        scanf("%d",&newnode->data);
        newnode->next=0;
        if(head==0)
        {
            temp=head=newnode;
        }
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
     printf("Do you want to continue (0 for exit) :");
     scanf("%d",&ch);
    }while(ch);
    return head;
}
void split(struct node *h){
struct node* positive=NULL,*negative=NULL;
    struct node* t,*t2;
    struct node *temp=h;
    while(temp!=NULL){
        if(temp->data>=0){
            if(positive==NULL){
            positive=t=temp;
            }
            else{
                t->next=temp;
                t=temp;
            }
        }
        else{
            if(negative==NULL){
                negative=t2=temp;
            }
            else{
                t2->next=temp;
                t2=temp;
            }
        }
        temp=temp->next;
    }
   t->next=NULL;
   t2->next=NULL;
    printf("\nThe positive linked list is :\n");
    display(positive);
    printf("\nThe negative linked list is :\n");
    display(negative);
    }
int main(){
    struct node *head=NULL;
    printf("\tENTER THR LINKED LIST :\n");
    struct node* h=create(head);
    printf("\nThe linked list is :\n");
    display(h);
    split(h);
        return 0;
}

