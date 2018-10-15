#include<iostream>
#include<stdlib.h>
using namespace std;
struct Node{
	struct Node *next;
	int value;
};
void insertAtFront(int val);
void insertAtEnd(int val);
void insertAt(struct Node* prevNode,int val);
void deleteNode(int val);
void printNode();
struct Node *start = NULL;
int main(){
	insertAtEnd(5);
	insertAtEnd(10);
	insertAtEnd(15);
	insertAtEnd(20);
	insertAt(start->next,8);
	printNode();
}

void insertAtFront(int val){
	struct Node *ptr;
	ptr = (struct Node*) malloc (sizeof(struct Node));
	ptr->value = val;
	ptr->next = start;
	start = ptr;
}

void insertAtEnd(int val){
	struct Node *ptr;
	ptr = (struct Node*) malloc (sizeof(struct Node));
	ptr->next = NULL;
	ptr->value = val;
	if(start == NULL){
		start = ptr;
	}else{
		struct Node *curr = start;
		while(curr->next!=NULL){
			curr = curr->next;
		}
		curr->next = ptr;
	}
}
void insertAt(struct Node* prevNode,int val){
	if(prevNode == NULL){
		cout << "The Given Previous Node Can not be NULL" << endl;
	}
	struct Node *ptr;
	ptr = (struct Node*) malloc (sizeof(struct Node));
	ptr->value = val;
	ptr->next = prevNode->next;
	prevNode->next = ptr;	
}

void deleteNode(int val){
	struct Node *curr = start;
	if(curr->value == val){
		start = start->next;
		free(curr);
	}else{
		struct Node *prev = start;
		curr = curr->next;
		while (curr->value != val)
		{
			curr = curr->next;
			prev = prev->next;
		}
		prev->next = curr->next;
		free(curr);
	}
}

void printNode(){
	struct Node *curr = start;
	while(curr->next!=NULL){
		cout << curr->value << endl;
		curr = curr->next;
	}
	cout << curr->value << endl;
}
