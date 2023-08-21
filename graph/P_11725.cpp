#include <iostream>
#include <vector>
#include <queue>

// 문제주소 : https://www.acmicpc.net/problem/11725
// 메모리, 응답시간 : 12488kb, 108ms

bool* visited;
std::vector<int>* graph;
std::queue<int*> q;
int* parentArray;
void dfs(int x, int parent) {
	visited[x] = true;
	parentArray[x] = parent;
	for (int i = 0; i < graph[x].size(); i++) {
		int y = graph[x][i];
		if (!visited[y])
			dfs(y, x);
	}
}

int main() {
	int n;
	std::cin >> n;

	visited = new bool[n + 1] {false, };
	graph = new std::vector<int>[n+1];
	parentArray = new int[n + 1];
	for (int i = 0; i < n-1; i++) {
		int input1, input2;
		std::cin >> input1 >> input2;

		graph[input1].push_back(input2);
		graph[input2].push_back(input1);
	}
	dfs(1, 1);
	for (int i = 2; i <= n; i++) {
		std::cout << parentArray[i] << "\n";
	}
	return 0;
}