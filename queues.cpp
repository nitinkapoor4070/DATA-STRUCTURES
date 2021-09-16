#include<iostream>
#include<bits/stdc++.h>
#include<climits>
//#include<stack>
//#include<queue>
using namespace std;
/*
template <typename T>
class queuesusingarray {
	T *data;
	int nextindex;
	int firstindex;
	int size;
	int capacity;

public:
	queuesusingarray(int totalsize) {
		data = new T[totalsize];
		nextindex = 0;
		firstindex = -1;
		size = 0;
		capacity = totalsize;

	}
	void enqueue(T element) {
		if (size == capacity) {
			cout << "Queue is full";
			return;
		}
		data[nextindex] = element;
		nextindex = (nextindex + 1) % capacity;
		if (firstindex == -1)
			firstindex = 0;
		size++;
	}

	T front() {
		if (isEmpty()) {
			cout << "Queue is Empty";
			return 0;
		}
		return data[firstindex];
	}

	T dequeue() {
		if (isEmpty()) {
			cout << "Queue is Empty";
			return 0;
		}
		T ans = data[firstindex];
		firstindex = (firstindex + 1) % capacity;
		size--;
		if (size == 0) {
			firstindex = -1;
			nextindex = 0;
		}
		return ans;
	}

	int getsize() {
		return size;
	}

	bool isEmpty() {
		return (size == 0);
	}

};







int main() {
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif


	queuesusingarray<int> s(5);
	s.enqueue(100);
	s.enqueue(101);
	s.enqueue(102);
	s.enqueue(103);
	s.enqueue(104);
	s.enqueue(99);
	cout << endl;


	cout << s.front() << endl;
	cout << s.dequeue() << endl;
	cout << s.dequeue() << endl;
	cout << s.getsize() << endl;
	cout << s.isEmpty() << endl;
}
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
class queuesusinglist {
	Node<T> *head;
	Node<T> *tail;
	int size;
public:
	queuesusinglist() {
		head = NULL;
		tail = NULL;
		size = 0;

	}
	int getsize() {
		return size;
	}
	bool isEmpty() {
		return size == 0;
	}
	void enqueue(T element) {
		Node<T> *newnode = new Node<T>(element);
		if (head == NULL) {
			head = newnode;
			tail = newnode;
		}
		else {
			tail-> next = newnode;
			tail = newnode;
		}
		size++;
	}

	T dequeue() {
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

	T front() {
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


	queuesusinglist<int> s;
	s.enqueue(100);
	s.enqueue(101);
	s.enqueue(102);
	s.enqueue(103);
	s.enqueue(104);
	s.enqueue(99);
	cout << endl;


	cout << s.front() << endl;
	cout << s.dequeue() << endl;
	cout << s.dequeue() << endl;
	cout << s.getsize() << endl;
	cout << s.isEmpty() << endl;
}