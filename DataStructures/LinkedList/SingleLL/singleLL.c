#include <stdio.h>
#include <stdlib.h>

//Node template
struct node{
	int data;
	struct node *link;
};

//Count number of nodes by traversing
void count_of_nodes(struct node *head){
	int count=0;
	if(head == NULL){
		printf("Linked List is empty");
	}	
	struct node *ptr = NULL;
	ptr = head;
	while(ptr!=NULL){
		count++;
		ptr=ptr->link;
	}
	printf("Count : %d\n",count);
}


//print all the elements of the linked list
void print_data(struct node* head){
	if(head == NULL){
		printf("Linked List is empty");
	}
	struct node *ptr = head;
	while(ptr!=NULL){
		printf("%d --> ",ptr->data);
		ptr=ptr->link;
	}
	printf(" NULL\n");
}



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
	current -> link = NULL;
	head -> link -> link = current;
	
	
	//printf("%d",head->data);
	count_of_nodes(head);
	print_data(head);
	return 0;
}
