#include<iostream>
using namespace std;

template <typename T>
class queuesusingarray {
	T *data;
	int lastindex;
	int firstindex;
	int size;
	int capacity;

public:
	queuesusingarray(int totalsize) {
		data = new T[totalsize];

		firstindex = -1;
		lastindex = -1;
		size = 0;
		capacity = totalsize;

	}
	void enqueue_b(T element) {
		if (size == capacity) {
			cout << "Queue is full" << endl;
			return;
		}

		if (firstindex == -1) {
			firstindex = 0;
			lastindex = 0;
		}
		else if (lastindex == capacity - 1) {
			lastindex = 0;

		}
		else {
			lastindex++;
		}
		data[lastindex] = element;
		cout << element << " inserted at the back" << endl;

		size++;
	}

	void enqueue_f(T element) {
		if (size == capacity) {
			cout << "Queue is full" << endl;
			return;
		}

		if (firstindex == -1) {
			firstindex = 0;
			lastindex = 0;
		}
		else if (firstindex == 0) {
			firstindex = capacity - 1;

		}
		else {
			firstindex--;
		}
		data[firstindex] = element;
		cout << element << " inserted at the front" << endl;

		size++;
	}

	T front() {
		if (isEmpty()) {
			cout << "Queue is Empty" << endl;
			return 0;
		}
		return data[firstindex];
	}

	T back() {
		if (isEmpty()) {
			cout << "Queue is Empty" << endl;
			return 0;
		}
		return data[lastindex];
	}

	T dequeue_f() {
		if (isEmpty()) {
			cout << "Queue is Empty" << endl;
			return 0;
		}
		if (firstindex == lastindex) {
			firstindex = -1;
			lastindex = -1;

		}
		else if (firstindex = capacity - 1) {
			firstindex = 0;
		}
		else {
			firstindex++;
		}
	}
	T dequeue_b() {
		if (isEmpty()) {
			cout << "Queue is Empty";
			return 0;
		}
		if (firstindex == lastindex) {
			firstindex = -1;
			lastindex = -1;

		}
		else if (lastindex = 0) {
			lastindex = capacity - 1;
		}
		else {
			lastindex--;
		}
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
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	queuesusingarray<int> s(5);
	s.enqueue_f(10);
	s.enqueue_f(20);
	s.enqueue_f(30);
	s.enqueue_b(40);
	s.enqueue_b(50);
	s.enqueue_b(60);//queue is full


	cout << s.isEmpty() << endl;
	cout << s.front() << endl;
	cout << s.back() << endl;
}








