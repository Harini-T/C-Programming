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
	temp -> data = 10;
	temp -> next = NULL;
	head = temp;
	return head;
}


int main(){
	
	struct node* head = NULL;
	head = addToEmpty(head,45);
	printf("%d", head->data);
	return 0;

}
