#include<iostream>
#include<bits/stdc++.h>
//#include "student.cpp"
using namespace std;

/*
class student
{
public:
	int rollnumber;
	int age;
	student(int r) {
		cout << "constructor called" << endl;
		rollnumber = r;
	}
	student() {

	}
	~student() {
		cout << "destructor called";
	}
};


int main() {

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
// 2d array using heap memory
	/*int n,m;
		cin>>m>>n;
		int** p= new int*[m];
		for (int i=0;i<m;i++){
			p[i]=new int[m];
			for (int j=0;j<n;j++){
				cin>>p[i][j];
			}
		}
		cout<< p[1][1];
	for (int i=0;i<m;i++){
		delete [] p[i];

	}
	delete [] p;
	*/

/*student s1;
s1.age = 24;
s1.rollnumber = 17;
cout << s1.rollnumber << endl;

student *s2 = new student;
(*s2).age = 45;
cout << (*s2).age;

student s4(10);
cout << s4.rollnumber << endl;

}
*/
class Node {
public:
	int data;
	Node *next;
	Node(int data) {
		this ->data = data;
		next = NULL;
	}
};



Node* takeInput() {
	int data;
	cin >> data;
	Node* head = NULL;
	Node *tail = NULL;
	while (data != -1) {
		Node *newnode = new Node(data);
		if (head == NULL) {
			head = newnode;
			tail = newnode;
		}
		else {
			/*Node *temp = head;

			while (temp -> next != NULL) {
				temp = temp ->next;*/

			tail->next = newnode;
			tail = tail->next;
			//or
			//tail=newnode

			/*}
			temp -> next = newnode;*/
		}
		cin >> data;
	}
	return head;
}


Node* insertnode(Node *head, int i, int data) {
	Node *newNode = new Node(data);
	int count = 0;
	Node *temp = head;

	if (i == 0) {
		newNode->next = head;
		head = newNode;
		return head;
	}

	while (temp != NULL && count < i - 1) {
		temp = temp->next;
		count++;
	}
	if (temp != NULL) {
		newNode -> next = temp-> next;
		temp->next = newNode;
	}
	return head;
}


void print(Node *head) {
	while (head != NULL) {
		cout << head -> data << " ";
		head = head -> next;
	}

}
//reverse a list
void fun1(struct Node* head)
{
	if (head == NULL)
		return;
	//cout << head->data << endl;
	fun1(head->next);
	//cout << head << endl;
	cout << head->data << endl;
}


int main() {
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	Node *head = takeInput();
	print(head);
	int i, data;
	cin >> i >> data;
	cout << endl << endl;
	head = insertnode(head, i, data);
	print(head);
	cout << endl << endl;
	fun1(head);
}

