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


//Insertion between the nodes

struct node* addAfterPos(struct node* head, int data, int position){
	struct node* newP = NULL;
	struct node* temp = head;
	struct node* temp2 = NULL;
	newP = addToEmpty(newP,data);
	
	while(position!=1){
		temp=temp->next;
		position--;
	}
	if(temp->next == NULL){
		temp->next = newP;
		newP->prev=temp;
	}
	temp2 = temp->next;
	temp->next = newP;
	temp2 -> prev = newP;
	newP->next = temp2;
	newP->prev = temp;
	return head;


}

struct node* addBeforePos(struct node* head, int data, int position){
	struct node* newP = NULL;
	struct node* temp = head;
	struct node* temp2 = NULL;
	newP = addToEmpty(newP,data);
	
	int pos = position;
	while(pos>2){
		temp=temp->next;
		pos--;
	}
	if(position ==1){
		head = addAtBeg(head,data);
	}
	else{
		temp2 = temp->next;
		temp->next = newP;
		temp2 -> prev = newP;
		newP->next = temp2;
		newP->prev = temp;
	}
	return head;


}

//Create an entire doubly linked list
struct node* createList(struct node* head){
	int n,data,i;
	printf("Enter the number of nodes: ");
	scanf("%d",&n);
	
	if(n==0)
		return head;
		
	printf("Enter the element for the node 1: ");
	scanf("%d",&data);
	head = addToEmpty(head,data);
	
	for(i=1;i<n;i++){
		printf("Enter the element for the node %d: ",i+1);
		scanf("%d", &data);
		head = addAtEnd(head, data);
	}
	return head;
}


//Delete the 1st node
struct node* delFirst(struct node* head){
	head = head->next;
	free(head->prev);
	head ->prev =NULL;
	return head;
}

//Delete last node
struct node* delLast(struct node* head){
	struct node* temp=head;
	struct node* temp2;
	while(temp->next != NULL)
		temp= temp->next;
	temp2 = temp->prev;
	temp2->next = NULL;
	free(temp);
	return head;
}

//Delete at a position
struct node* delInter(struct node* head, int position){
	struct node* temp=head;
	struct node* temp2 = NULL;
	if(position == 1){
		head = delFirst(head);
		return head;
	}
	while(position>1){
		temp=temp->next;
		position--;
	}
	if(temp->next == NULL)
		head = delLast(head);
	else{
		temp2 = temp->prev;
		temp2->next = temp->next;
		temp->next->prev = temp2;
		free(temp);
		temp=NULL;
	}
	return head;
}

int main(){
	
	struct node* head = NULL;
	//head = addToEmpty(head,45);
	
	//head = addAtBeg(head,34);
	
	//head = addAtEnd(head,9);
	
	//head = addAfterPos(head,20,2);
	
	//head = addBeforePos(head,345,3);
	
	head = createList(head);
	print_data(head);
	head = delFirst(head);
	print_data(head);
	
	head = delLast(head);
	print_data(head);
	
	head = delInter(head,3);
	print_data(head);
	return 0;

}
