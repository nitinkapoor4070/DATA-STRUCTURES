#include<iostream>
//#include<stack>
#include<string>
#include <sstream>
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

		return true;
	}
	return false;
}




int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	stac<int> s;
	string str;
	getline(cin, str);
	// cout << str << endl;
	for (int i = 0; i < str.length(); i++) {




		/*
				if (str[i] >= 48 && str[i] <= 57) {

					s.push(int(str[i]) - int('0'));
					//cout << (int(str[i]) - int('0')) << endl;
				}

		*/

		if (str[i] == ' ')
			continue;
		else if (isdigit(str[i])) {
			int num = 0;
			while (isdigit(str[i]))
			{
				num = num * 10 + int(str[i] - '0');
				i++;
			}
			//i--;
			s.push(num);

		}







		else  {
			int a = s.pop();
			int b = s.pop();

			switch (str[i]) {
			case '+':
				s.push(a + b);
				break;
			case '-':
				s.push(b - a);
				break;
			case '/':
				s.push(b / a);
				break;
			case '*':
				s.push(a * b);
				break;

			}


		}

	}

	cout << s.top();
}
/*
else
{
	int val1 = s.pop();
	int val2 = s.pop();

	switch (str[i])
	{
	case '+': s.push( val2 + val1); break;
	case '-': s.push(val2 - val1); break;
	case '*': s.push( val2 * val1); break;
	case '/': s.push( val2 / val1); break;

	}
}
}
cout << s.top();
}

















*/



