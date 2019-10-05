#include<stdio.h>
#include<stdlib.h>

struct Node{
	int value;
	struct Node *next;
};

struct Node *start = NULL;

void insert(int val){
	struct Node *ptr;
	ptr = (struct Node*)malloc(sizeof(struct Node));
	ptr->value = val;
	ptr->next = NULL;
	if(start == NULL){
		start = ptr;
	}else{
		struct Node *curr = start;
		while(curr->next!=NULL){
			curr = curr->next;
		}
		curr->next=ptr;
	}
}

void print(){
	if(start == NULL){
		printf("List is Empty");
	}else{
		struct Node *curr = start;
		while(curr != NULL){
			printf("%d ", curr->value);
			curr = curr->next;
		}
		printf("\n");
	}
}

void search(int val){
	if(start == NULL){
		printf("List is Empty");
	}else{
		int count = 0;
		struct Node *curr = start;
		while(curr!=NULL){
			if(curr->value==val){
				printf("Value Found\n");
				count++;
				break;
			}
			curr=curr->next;
		}
		if(count==0){
			printf("Value Not Found\n");
		}		
	}
}

void deleteNode(int val){
	if(start == NULL){
		printf("List is Empty");
	}else{
		struct Node *curr = start;
		if(curr->value==val){
			start = start->next;
			free(curr);
		}else{
			curr = start->next;
			struct Node *prev = start;
			while(curr->value!=val){
				curr=curr->next;
				prev=prev->next;
			}
			prev->next = curr->next;
			free(curr);
		}
	}
}

int main(){
	
	insert(5);
	insert(10);
	insert(15);
	insert(20);
	insert(25);
	print();
	deleteNode(10);
	deleteNode(20);
	print();
}
