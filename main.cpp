#include <iostream>
#include <stdlib.h>
using namespace std;

void insert(int val);
void print();
void del(int val);
void search(int val);

int main(int argc, char **argv)
{
	print();
	insert(20);
	insert(30);
	insert(40);
	print();
	del(20);
	print();
	search(40);
	search(50);
	system("pause"); 
}
struct Node
{
	int value;
	struct Node *next;
};

struct Node *start = NULL;
void insert(int val)
{
	struct Node *ptr;
	ptr = (struct Node *)malloc(sizeof(struct Node));
	ptr->value = val;
	ptr->next = NULL;
	if (start == NULL)
	{
		start = ptr;
	}
	else
	{
		struct Node *curr = start;
		while (curr->next != NULL)
		{
			curr = curr->next;
		}
		curr->next = ptr;
	}
}

void print()
{
	if (start == NULL)
	{
		cout << "List is Empty" << endl;
	}
	else
	{
		struct Node *curr = start;
		while (curr->next != NULL)
		{
			cout << curr->value << endl;
			curr = curr->next;
		}
		cout << curr->value << endl;
	}
}
void del(int val)
{
	struct Node *curr = start;
	if (curr->value == val)
	{
		start = start->next;
		free(curr);
	}
	else
	{
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
void search(int val)
{
	if (start == NULL)
	{
		cout << "List is Empty" << endl;
	}
	else
	{
		struct Node *curr = start;
		while (curr->next != NULL)
		{
			if (curr->value == val)
			{
				cout << val << " Found in List" << endl;
				break;
			}
			curr = curr->next;
			if (curr->next == NULL)
			{
				if (curr->value == val)
				{
					cout << val << " Found in List" << endl;
					break;
				}
				else
				{
					cout << val << " is not Found in List " << endl;
				}
			}
		}
	}
}
