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



//add element at the end of the list
void add_at_end_O_n(struct node *head, int data){
	struct node *ptr, *temp;
	ptr=head;
	temp = (struct node*) malloc(sizeof(struct node));
	
	temp->data = data;
	temp->link = NULL;
	
	while(ptr->link != NULL){
		ptr=ptr->link;
	}
	ptr->link = temp;
}


struct node* add_at_end_O_1(struct node *ptr, int data){
	struct node *temp = malloc(sizeof(struct node));
	temp->data = data;
	temp->link = NULL;
	
	ptr->link = temp;
	return temp;
}

int main(){
	
	struct node *head=NULL;	//create head node
	head = (struct node *)malloc(sizeof(struct node));
	head->data=45;
	head->link=NULL;
	
	struct node *ptr = head;
	ptr = add_at_end_O_1(ptr,98);
	ptr = add_at_end_O_1(ptr,3);
	ptr = add_at_end_O_1(ptr,67);
	ptr = head;
	
	print_data(head);
	return 0;
}
