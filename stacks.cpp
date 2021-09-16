#include<iostream>
#include<bits/stdc++.h>
#include<climits>
//#include<stack>
using namespace std;

/*
template <typename T>
class stackusingarray {
	T *data;
	int nextindex;
	int capacity;
public:
	stackusingarray(int totalsize) {
		data = new T[totalsize];
		nextindex = 0;
		capacity = totalsize;
	}

	int size() {
		return nextindex;
	}

	bool isEmpty() {
		return nextindex == 0;
	}

	void push(T element) {
		if (nextindex == capacity) {
			cout << "stack is full" << endl;
			return;
		}
		data[nextindex] = element;
		nextindex++;
	}

	T pop() {
		if (isEmpty()) {
			cout << "stack is empty" << endl;
			return 0;
		}
		nextindex--;
		return data[nextindex];
	}

	T top() {
		if (isEmpty()) {
			cout << "stack is empty" << endl;
			return 0;
		}
		return data[nextindex - 1];
	}

};
*/



template <typename T>
class Node {
public:
	T data;
	Node<T> *next;
	Node(T data) {
		this -> data = data;
		next = NULL;
	}
};
template <typename T>
class stac {
	Node<T> *head;
	int size;
public:
	stac() {
		head = NULL;
		size = 0;

	}
	int getsize() {
		return size;
	}
	bool isEmpty() {
		return size == 0;
	}
	void push(T element) {
		Node<T> *newnode = new Node<T>(element);
		newnode -> next = head;
		head = newnode;
		size++;
	}

	T pop() {
		if (isEmpty()) {
			return 0;
		}
		T ans = head->data;
		Node<T> *temp = head;
		head = head->next;
		delete temp;
		size--;
		return ans;
	}

	T top() {
		if (isEmpty()) {
			return 0;
		}
		return head->data;
	}


};


int main() {

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif


	stac<int> s;
	s.push(100);
	s.push(101);
	s.push(102);
	s.push(103);
	s.push(104);


	cout << s.top() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.getsize() << endl;
	cout << s.isEmpty() << endl;

}















