#include <stdio.h>
#include <stdlib.h>

//Node template
struct node{
	int data;
	struct node *link;
};


int main(){
	struct node *head=NULL;	//create head node
	head = (struct node *)malloc(sizeof(struct node));
	head->data=45;
	head->link=NULL;
	
	struct node *current = malloc(sizeof(struct node));	//create 2nd node
	current -> data = 98;
	current -> link = NULL;
	head -> link = current;	//link head node with current node
	
	//create 3rd node
	current = malloc(sizeof(struct node));
	current -> data = 3;
	current -> link = null;
	head -> link -> link = current;
	
	
	printf("%d",head->data);
	return 0;
}
