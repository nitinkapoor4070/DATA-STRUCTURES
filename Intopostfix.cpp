#include<iostream>
#include<string>
#include<vector>
using namespace std;

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

bool isoperator(char x) {
	switch (x) {
	case '+':
	case '-':
	case '/':
	case '*':
	case '(':
	case ')':
	case '^':
		return true;
	}
	return false;
}




int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	vector<char> arr;
	stac<char> s;
	string str;
	int len;
	char b;
	cin >> str;
	len = str.length();
	for (int i = 0; i < len; i++) {
		b = s.top();
		if ((str[i] >= 48 && str[i] <= 57) || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')) {
			arr.push_back(str[i]);
			continue;
		}



		if (str[i] == '(') {
			s.push(str[i]);
			continue;
		}

		if (str[i] == ')') {

			while (s.top() != '(') {
				char a = s.pop();
				arr.push_back(a);
			}
			s.pop();
			continue;
		}


		if (isoperator(str[i])) {
			if (b == 0) {
				s.push(str[i]);
				b = s.top();
				continue;
			}
		}
		if (str[i] == '^' && b == '^') {
			arr.push_back(b);
			s.pop();
			s.push(str[i]);
			continue;
		}
		if (str[i] == '^') {
			s.push(str[i]);
			continue;

		}


		if ((str[i] == '+' || str[i] == '-') && (b == '*' || b == '/' || b == '^')) {
			while (b == '*' || b == '/' || b == '^') {
				arr.push_back(b);
				s.pop();
				b = s.top();
			}

		}

		if ((str[i] == '+' || str[i] == '-') && (b == '+' || b == '-')) {

			arr.push_back(b);
			s.pop();
			s.push(str[i]);
			continue;
		}
		if ((str[i] == '+' || str[i] == '-') &&  b == '(') {

			s.push(str[i]);
			continue;
		}
		if ((str[i] == '*' || str[i] == '/') && (b == '^')) {
			while (b == '^' ) {
				arr.push_back(b);
				s.pop();
				b = s.top();
			}

		}

		if ((str[i] == '*' || str[i] == '/') && (b == '+' || b == '-' || b == '(')) {
			s.push(str[i]);
			continue;
		}
		if ((str[i] == '*' || str[i] == '/') && (b == '*' || b == '/')) {

			arr.push_back(b);
			s.pop();
			s.push(str[i]);
			continue;
		}




	}
	while (s.isEmpty() != 1) {
		char a = s.pop();
		arr.push_back(a);
	}


	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] ;
	}



}












