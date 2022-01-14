#include<iostream>
#include<vector>
using namespace std;


class Priorityqueue {
	vector<int> pq ;
public:

	Priorityqueue() {
	}



	void insert(int value) {
		pq.push_back(value);

		int childindex = pq.size() - 1;

		while (childindex > 0) {
			int parentindex = (childindex - 1) / 2;

			if (pq[childindex] < pq[parentindex]) {
				int temp = pq[childindex];
				pq[childindex] = pq[parentindex];
				pq[parentindex] = temp;
			}
			else {
				break;
			}
			childindex = parentindex;
			//parentindex = (childindex - 1) / 2;

		}
	}


	int getmin() {
		if (pq.size() == 0)
			return 0;
		return pq[0];
	}


	int removeMin() {
		if (pq.size () == 0)
			return 0;

		int ans = pq[0];
		pq[0] = pq[pq.size() - 1];
		pq.pop_back();

		int parentindex = 0;
		int LCI = 2 * parentindex + 1;
		int RCI = 2 * parentindex + 2;


		while (LCI < pq.size() ) {
			int minindex = parentindex;


			if (pq[minindex] > pq[LCI]) {
				minindex = LCI;
			}

			if (RCI < pq.size() &&  pq[minindex] > pq[RCI]) {
				minindex = RCI;
			}
			if (minindex == parentindex) {
				break;
			}

			int temp = pq[minindex];
			pq[minindex] = pq[parentindex];
			pq[parentindex] = temp;
			int parentindex = minindex;
			int LCI = 2 * parentindex + 1;
			int RCI = 2 * parentindex + 2;

		}
		return ans;
	}

	int getsize() {
		return pq.size();
	}


};

int main() {
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	Priorityqueue p;
	p.insert(100);
	p.insert(10);
	p.insert(15);
	p.insert(4);
	p.insert(17);
	p.insert(21);
	p.insert(67);


	cout << p.getsize() << endl;
	cout << p.getmin() << endl;

	while (p.getsize() != 0) {
		cout << p.removeMin() << " ";
	}
	cout << endl;


}


// output
// 7
// 4
// 4 10 15 17 21 67 100




