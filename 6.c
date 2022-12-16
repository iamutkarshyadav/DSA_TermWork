#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
	struct Node *prev, *next;
};
void nodeInsetail(struct Node **head, struct Node **tail,int key)
{
	struct Node *p =(struct Node*)malloc(sizeof(struct Node));
	p->data = key;
	p->next = NULL;
	if ((*head) == NULL)
	{
		(*head) = p;
		(*tail) = p;
		(*head)->prev = NULL;
		return;
    }
	if ((p->data) < ((*head)->data))
	{
		p->prev = NULL;
		(*head)->prev = p;
		p->next = (*head);
		(*head) = p;
		return;
	}
	if ((p->data) > ((*tail)->data))
	{
		p->prev = (*tail);
		(*tail)->next = p;
		(*tail) = p;
		return;
	}

	struct Node *temp;
	temp = (*head)->next;
	while ((temp->data) < (p->data))
		temp = temp->next;

	(temp->prev)->next = p;
	p->prev = temp->prev;
	temp->prev = p;
	p->next = temp;
}
void printList(struct Node *temp)
{
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}
int main()
{
	struct Node *left = NULL, *right = NULL;
	int ch;
	do{
		int val;
		printf("Enter data :");
		scanf("%d",&val);
		nodeInsetail(&left, &right, val);
		printf("Enter the choice (0 for Exit) : ");
		scanf("%d",&ch);
	}while(ch);

	printf("\nDoubly linked list in ascending order :\n");
	printList(left);

	return 0;
}
