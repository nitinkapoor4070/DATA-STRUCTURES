#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *next;
};

struct Node *addToEmpty(struct Node *last, int data)
{

	if (last != NULL)
		return last;


	struct Node *temp =
	    (struct Node*)malloc(sizeof(struct Node));


	temp -> data = data;
	last = temp;


	last -> next = last;

	return last;
}

struct Node *addBegin(struct Node *last, int data)
{
	if (last == NULL)
		return addToEmpty(last, data);

	struct Node *temp =
	    (struct Node *)malloc(sizeof(struct Node));

	temp -> data = data;
	temp -> next = last -> next;
	last -> next = temp;

	return last;
}

struct Node *addEnd(struct Node *last, int data)
{
	if (last == NULL)
		return addToEmpty(last, data);

	struct Node *temp =
	    (struct Node *)malloc(sizeof(struct Node));

	temp -> data = data;
	temp -> next = last -> next;
	last -> next = temp;
	last = temp;

	return last;
}

struct Node *addAfter(struct Node *last, int data, int item)
{
	if (last == NULL)
		return NULL;

	struct Node *temp, *p;
	p = last -> next;
	do
	{
		if (p ->data == item)
		{
			temp = (struct Node *)malloc(sizeof(struct Node));
			temp -> data = data;
			temp -> next = p -> next;
			p -> next = temp;

			if (p == last)
				last = temp;
			return last;
		}
		p = p -> next;
	} while (p != last -> next);

	cout << item << " not present in the list." << endl;
	return last;

}

void print(struct Node *last)
{
	struct Node *p;


	if (last == NULL)
	{
		cout << "List is empty." << endl;
		return;
	}


	p = last -> next;


	do
	{
		cout << p -> data << " ";
		p = p -> next;

	}
	while (p != last->next);

}
void deleteNode(Node** head, int key)
{

	// If linked list is empty
	if (*head == NULL)
		return;

	// If the list contains only a single node
	if ((*head)->data == key && (*head)->next == *head)
	{
		free(*head);
		*head = NULL;
		return;
	}

	Node *last = *head, *d;

	// If head is to be deleted
	if ((*head)->data == key)
	{

		// Find the last node of the list
		while (last->next != *head)
			last = last->next;

		// Point last node to the next of head i.e.
		// the second node of the list
		last->next = (*head)->next;
		free(*head);
		*head = last->next;
	}

	// Either the node to be deleted is not found
	// or the end of list is not reached
	while (last->next != *head && last->next->data != key)
	{
		last = last->next;
	}

	// If node to be deleted was found
	if (last->next->data == key)
	{
		d = last->next;
		last->next = d->next;
		free(d);
	}
	else
		cout << "no such keyfound";
}
int countNodes(Node* head)
{
	Node* temp = head;
	int result = 0;
	if (head != NULL) {
		do {
			temp = temp->next;
			result++;
		} while (temp != head);
	}

	return result;
}

int main()
{
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("out.txt", "w", stdout);
#endif
	struct Node *last = NULL;

	last = addToEmpty(last, 6);//list= {6}
	last = addBegin(last, 4);//list= {4,6}
	last = addBegin(last, 2);//list= {2,4,6}
	last = addEnd(last, 8);//list= {2,4,6,8}
	last = addEnd(last, 12);//list= {2,4,6,8,12}
	last = addAfter(last, 10, 8);//list= {2,4,6,8,10,12}
	cout << "Circular list : " << endl;
	print(last);
	cout << endl;
	cout << "Length of List : " << countNodes(last);
	cout << endl;
	deleteNode(&last, 10);
	deleteNode(&last, 2);
	cout << "Modified Circular list : " << endl;

	print(last);
	cout << endl;
	cout << "Length of List : " << countNodes(last);

	return 0;
}

