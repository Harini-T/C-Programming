#include <stdio.h>
#include <stdlib.h>

struct node{
	struct node* prev;
	int data;
	struct node* next;
};


//Add to empty list
struct node* addToEmpty(struct node* head, int data){
	struct node *temp = malloc(sizeof(struct node));
	temp -> prev = NULL;
	temp -> data = data;
	temp -> next = NULL;
	head = temp;
	return head;
}


//Insertion at beginning
struct node* addAtBeg(struct node* head, int data){
	struct node* temp = malloc(sizeof(struct node));
	temp -> prev = NULL;
	temp -> data = data;
	temp -> next = NULL;
	
	temp -> next = head;
	head -> prev = temp;
	head = temp;
	
	return head;
}

//print all the elements of the linked list
void print_data(struct node* head){
	if(head == NULL){
		printf("Linked List is empty");
	}
	struct node *ptr = head;
	while(ptr!=NULL){
		printf("%d --> ",ptr->data);
		ptr=ptr->next;
	}
	printf(" NULL\n");
}


//Insertion at end
struct node* addAtEnd(struct node* head, int data){
	struct node* temp = malloc(sizeof(struct node));
	temp -> prev = NULL;
	temp -> data = data;
	temp -> next = NULL;
	
	struct node* tp = head;
	while(tp->next != NULL)
		tp = tp->next;
	tp->next = temp;
	temp -> prev = tp;
	
	return head;
}


int main(){
	
	struct node* head = NULL;
	head = addToEmpty(head,45);
	
	head = addAtBeg(head,34);
	
	head = addAtEnd(head,9);
	print_data(head);
	return 0;

}
