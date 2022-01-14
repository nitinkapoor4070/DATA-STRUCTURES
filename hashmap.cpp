#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;

template <typename V>
class mapnode {
public :
	string key;
	V value;
	mapnode* next;
	mapnode(string key, V value) {
		this->key = key;
		this->value = value;
		next = NULL;
	}
	~mapnode() {
		delete next;
	}
};

template <typename V>
class ourmap {
	mapnode<V>** buckets;
	//int size;
	int numbuckets;
	int count;
public:
	ourmap() {
		count = 0;
		numbuckets = 5;
		buckets = new mapnode<V>*[numbuckets];
		for (int i = 0; i < numbuckets; i++) {
			buckets[i] = NULL;
		}
	}
	~ourmap() {
		for (int i = 0; i < numbuckets; i++) {
			delete buckets[i];
		}
		delete [] buckets;
	}

	int size() {
		return count;
	}
	V getvalue(string key) {
		int bucketindex = getbucketindex(key);
		mapnode<V>* head = buckets[bucketindex];
		while (head != NULL) {
			if (head->key == key) {
				return head->value ;
			}
			head = head->next;
		}
		return 0;
	}

private:
	int getbucketindex(string key) {
		int hashcode = 0;
		int coeff = 1;
		for (int i = key.length() - 1; i >= 0; i--) {
			hashcode += key[i] * coeff;
			hashcode = hashcode % numbuckets;
			coeff *= 37;
			coeff = coeff % numbuckets;
		}

		return hashcode % numbuckets;
	}

public:
	double getloadfactor() {
		return (1.0 * count) / numbuckets;
	}
	void insert(string key, V value) {
		int bucketindex = getbucketindex(key);
		mapnode<V>* head = buckets[bucketindex];
		while (head != NULL) {
			if (head->key == key) {
				head->value = value;
				return;
			}
			head = head->next;
		}
		head = buckets[bucketindex];
		mapnode<V>* node = new mapnode<V>(key, value);
		node->next = head;
		buckets[bucketindex] = node;
		count ++;

		double loadfactor = (1.0 * count) / numbuckets;
		if (loadfactor > 0.7) {
			cout << "calling rehash" << endl;
			rehash();
		}

	}
	V remove (string key) {
		int bucketindex = getbucketindex(key);
		mapnode<V>* head = buckets[bucketindex];
		mapnode<V>* prev = NULL;
		while (head != NULL) {
			if (head->key == key) {
				if (prev == NULL) {
					buckets[bucketindex] = head->next;
				}
				else {
					prev->next = head->next;
				}
				V value = head->value;
				head->next = NULL;
				delete head;
				count--;
				return value;

			}
			prev = head;
			head = head->next;
		}
		return 0;
	}


	void rehash() {
		mapnode<V>** temp = buckets;
		buckets = new mapnode<V>*[2 * numbuckets];
		for (int i = 0; i < 2 * numbuckets; i++) {
			buckets[i] = NULL;

		}
		int oldbucketcount = numbuckets;
		numbuckets *= 2;
		count = 0;
		for (int i = 0; i < oldbucketcount; i++) {
			mapnode<V>* head = temp[i];
			while (head != NULL) {
				string key = head->key;
				V value = head->value;
				insert(key, value);
				head = head->next;
			}
		}
		for (int i = 0; i < oldbucketcount; i++) {
			mapnode<V>* head = temp[i];
			delete head;
		}
		delete [] temp;
	}

};



int main() {
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("out.txt", "w", stdout);
#endif
	ourmap<int> map;
	for (int i = 0; i < 10; i++) {
		char c = '0' + i;
		string key = "abc";
		key = key + c;
		//cout << key << endl;
		int value = i + 1;
		map.insert(key, value);
		cout << map.getloadfactor() << endl;
	}
	cout << map.size() << endl << endl;



	for (int i = 0; i < 10; i++) {
		char c = '0' + i;
		string key = "abc";
		key = key + c;
		cout << key << " : " << map.getvalue(key) << endl;
	}
}










