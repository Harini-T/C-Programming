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



//Add element at the end of the list with O(n)
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

//Add element at the end of the list with O(1)
struct node* add_at_end_O_1(struct node *ptr, int data){
	struct node *temp = malloc(sizeof(struct node));
	temp->data = data;
	temp->link = NULL;
	
	ptr->link = temp;
	return temp;
}


//Add element at the beginning of the list
struct node* add_at_beginning(struct node* head, int d){
	struct node *ptr =malloc(sizeof(struct node));
	ptr->data = d;
	ptr->link = NULL;
	
	ptr->link=head;
	head=ptr;
	return head;
}

//Add element at the beginning of the list 2.0
void add_beg(struct node **head, int d){
	struct node *ptr = malloc(sizeof(struct node));
	ptr->data=d;
	ptr->link=NULL;
	
	ptr->link=*head;
	*head=ptr;
}


//Add element at a position
void add_at_pos(struct node* head, int data, int pos){
	struct node *ptr = head;
	struct node *ptr2 = malloc(sizeof(struct node));
	ptr2->data = data;
	ptr2->link = NULL;
	
	pos--;
	while(pos!=1){
		ptr = ptr->link;
		pos--;
	}
	ptr2->link = ptr->link;
	ptr->link = ptr2;
}


//Deleting 1st node
struct node* del_first(struct node *head){
	if(head==NULL)
		printf("List is already empty");
	else{
		struct node *temp = head;
		head = head->link;
		free(temp);
	}
	return head;
}


//Deleting last node using 2 temp pointers
struct node* del_last(struct node *head){
	if(head==NULL)
		printf("List is already empty");
	else if(head->link == NULL){
		free(head);
		head = NULL;
	}
	else{
		struct node *temp = head;
		struct node *temp2 = head;
		while(temp->link != NULL){
			temp2=temp;
			temp=temp->link;
		}
		temp2 -> link = NULL;
		free(temp);
		temp = NULL;
	}
	return head;
	
}

//Deleting last node using 1 temp pointer
struct node* del_last_1(struct node *head){
	if(head==NULL)
		printf("List is already empty");
	else if(head->link == NULL){
		free(head);
		head = NULL;
	}
	else{
		struct node *temp = head;
		while(temp->link->link != NULL){
			temp=temp->link;
		}
		free(temp->link);
		temp->link = NULL;
	}
	return head;
	
}


//Delete node at position
void del_position(struct node **head, int position){
	struct node *current = *head;
	struct node *previous = *head;
	if(*head == NULL){
		printf("List is already empty");
	}
	else if(position == 1){
		*head = current -> link;
		free(current);
		current = NULL;
	}
	else{
		while(position != 1){
			previous = current;
			current = current -> link;
			position--;
		}
		previous->link = current->link;
		free(current);
		current=NULL;
	}
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
	
	head = add_at_beginning(head,3);
	add_beg(&head,2);	
	ptr = head;
	
	int d=63, pos=3;
	add_at_pos(head,d,pos);
	
	head = del_first(head);
	
	head = del_last(head);
	
	head = del_last_1(head);
	
	del_position(&head, 2);
	print_data(head);
	return 0;
}
