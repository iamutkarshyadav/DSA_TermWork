#include<stdio.h>
#include<stdlib.h>
struct node {
    int cons;
    int deg;
    struct node *next;
};
void display(struct node *head)
{
    struct node *trav;
    trav=head;
    while(trav!=0)
    { 
        if(trav->deg==0){
             printf("%d",trav->cons);
        }
        else{
        printf("%dx%d+ ",trav->cons,trav->deg);
        }
        trav=trav->next;
    }
}
struct node* create(struct node* head){   
    
    struct node* newnode,*temp;
    int n;
        printf("Enter the highest degree :");
        scanf("%d",&n);
        int i=n;
        while(i>=0){
        newnode=(struct node *)malloc(sizeof(struct node));
        printf("Enter constant value:");
        scanf("%d",&newnode->cons);
        newnode->deg=i;
        newnode->next=0;
        if(head==0){
            temp=head=newnode;
        }
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
        i-=1;
        }
    return head;
}
struct node * add(struct node* f,struct node *s){
    int n1=f->deg;
    int n2=s->deg;
    struct node* newnode,*temp,*t,*t2;
    t=f;
    t2=s;
    struct node* final=NULL;
    if(n1>n2){
        while(n1!=n2){
            newnode=(struct node *)malloc(sizeof(struct node));
            newnode->cons=t->cons;
            newnode->deg=t->deg;
            newnode->next=0;
             if(final==NULL)
        {
            temp=final=newnode;
        }
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
        t=t->next;
            n1--;
        }
    }
    if(n1<n2){
        while(n2!=n1){
            newnode=(struct node *)malloc(sizeof(struct node));
            newnode->cons=t2->cons;
            newnode->deg=t2->deg;
            newnode->next=0;
             if(final==NULL)
        {
            temp=final=newnode;
        }
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
        t2=t2->next;
            n2--;
        }
    }
    while(t!=NULL && t2!=NULL){
       newnode=(struct node *)malloc(sizeof(struct node));
       newnode->cons=t->cons+t2->cons;
       newnode->deg=t->deg;
       newnode->next=0;
        if(final==NULL)
        {
            temp=final=newnode;
        }
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
        t=t->next;
        t2=t2->next;
        }
return final;
    }

int main(){
    struct node *first=NULL,*second=NULL;
    printf("ENTER FIRST POLYNOMIAL :\n");
    struct node *f=create(first);
    printf("\nENTER SECOND POLYNOMIAL :\n");
    struct node *s=create(second);
    printf("\nFirst polynomial is:\n");
    display(f);
    printf("\nSecond polynomial is:\n");
    display(s);
    printf("\nFinal polynomial is:\n");
    struct node * final=add(f,s);
    display(final);
    return 0;
}
