#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void printDFS(int** edges, int n, int sv, bool* visited) {
	cout << sv << endl;
	visited[sv] = true;
	for (int i = 0; i < n; i++) {
		if (i == sv) {
			continue;
		}
		if (edges[sv][i] == 1) {
			if (visited[i]) {
				continue;
			}
			printDFS(edges, n, i, visited);
		}
	}
}

void printBFS(int** edges, int n, int sv, bool* visited) {
	queue<int> pendingvertices;

	pendingvertices.push(sv);
	visited[sv] = true;
	while (!pendingvertices.empty()) {
		int currentvertex = pendingvertices.front();
		pendingvertices.pop();
		cout << currentvertex << endl;
		for (int i = 0; i < n; i++) {
			if (i == currentvertex) {
				continue;

			}
			if (edges[currentvertex][i] == 1 && !visited[i]) {
				pendingvertices.push(i);
				visited[i] = true;
			}
		}

	}
}

void BFS(int **edges, int n) {

	bool * visited = new bool[n];
	for (int i = 0; i < n; i++) {
		visited[i] = false;
	}
	for (int i = 0; i < n; i++) {
		if (!visited[i])
			printBFS(edges, n, i, visited);
	}
	delete [] visited;
}

void DFS(int **edges, int n) {
	bool * visited = new bool[n];
	for (int i = 0; i < n; i++) {
		visited[i] = false;
	}
	for (int i = 0; i < n; i++) {
		if (!visited[i])
			printDFS(edges, n, i, visited);
	}
	delete [] visited;
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
		int f, s;
		cin >> f >> s;
		edges[f][s] = 1;
		edges[s][f] = 1;
	}

	//print(edges, n, 0);
	cout << "DFS" << endl;
	DFS(edges, n);
	cout << "B FS" << endl;
	BFS(edges, n);


	for (int i = 0; i < n; i++) {
		delete [] edges[i];
	}
	delete [] edges;
}

/*
7
5
0 2
0 3
2 3
1 4
5 6
*/

