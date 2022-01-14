#include<iostream>
#include<climits>

using namespace std;

int findminvertex(int* weighs, bool* visited, int n) {
	int minvertex = -1;
	for (int i = 0; i < n; i++) {
		if (!visited[i] && (minvertex == -1 || weighs[i] < weighs[minvertex])) {
			minvertex = i;
		}
	}
	return minvertex;
}

void prims(int** edges, int n) {
	int* parent = new int[n];
	int* weighs = new int[n];
	bool* visited = new bool[n];

	for (int i = 0; i < n; i++) {
		visited[i] = false;
		weighs[i] = INT_MAX;
	}
	parent[0] = -1;
	weighs[0] = 0;

	for (int i = 0; i < n - 1; i++) {
		int minvertex = findminvertex(weighs, visited, n);
		visited[minvertex] = true;
		for (int j = 0; j < n; j++) {
			if (edges[minvertex][j] != 0 && !visited[j]) {
				if (edges[minvertex][j] < weighs[j]) {
					weighs[j] = edges[minvertex][j];
					parent[j] = minvertex;
				}
			}
		}
	}
	for (int i = 1; i < n; i++) {
		if (parent[i] < i) {
			cout << parent[i] << " " << i << " " << weighs[i] << endl;
		}
		else {
			cout << parent[i] << " " << parent[i] << " " << weighs[i] << endl;
		}

	}
}

int main() {
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("out.txt", "w", stdout);
#endif

	int n, e;
	cin >> n >> e;
	int** edges = new int*[n];
	for (int i = 0; i < n; i++) {
		edges[i] = new int[n];
		for (int j = 0; j < n; j++) {
			edges[i][j] = 0;
		}
	}

	for (int i = 0; i < e; i++) {
		int f, s, weight;
		cin >> f >> s >> weight;
		edges[f][s] = weight;
		edges[s][f] = weight;

	}
	cout << endl;
	prims(edges, n);

	for (int i = 0; i < n; i++) {
		delete [] edges[i];

	}
	delete [] edges;
}

/*
5 7
0 1 4
0 2 8
1 3 6
1 2 2
2 3 3
2 4 9
3 4 5
*/




