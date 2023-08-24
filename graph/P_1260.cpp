#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

// 문제주소 : https://www.acmicpc.net/problem/1260
// 메모리, 응답시간 : 2156kb, 8ms

std::queue<int> q;
bool* visited;

void dfs(std::vector<int>* graph, int v) {
	if (visited[v] == true) return;
	visited[v] = true;

	std::cout << v << " ";

	for (int i = 0; i < graph[v].size(); i++) {
		int nextNode = graph[v][i];
		if (visited[nextNode] == false) {
			dfs(graph, nextNode);
		}
	}
}

void bfs(std::vector<int>* graph, int v) {
	if (visited[v] == true) return;
	visited[v] = true;

	std::cout << v << " ";

	for (int i = 0; i < graph[v].size(); i++) {
		int nextNode = graph[v][i];
		if (visited[nextNode] == false) {
			q.push(nextNode);
		}
	}
	while(!q.empty()){
		int node = q.front();
		if (visited[node] == true) {
			q.pop();
			continue;
		}
		visited[node] = true;

		std::cout << node << " ";
		for (int j = 0; j < graph[node].size(); j++) {
			if (visited[graph[node][j]] == false)
				q.push(graph[node][j]);
		}
		q.pop();
	}
}
int main() {
	//정점의 개수N, 간선의 개수M, 시작할 정점의 번호V
	int n, m, v;
	std::cin >> n >> m >> v;

	std::vector<int>* graph = new std::vector<int>[n+1];
	for (int i = 0; i < m; i++) {
		int tmp1, tmp2;
		std::cin >> tmp1 >> tmp2;

		graph[tmp1].push_back(tmp2);
		graph[tmp2].push_back(tmp1);
	}

	for (int i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	visited = new bool[n+1] {false, };
	dfs(graph, v);
	std::cout << "\n";

	for (int i = 0; i < n+1; i++) visited[i] = false;
	bfs(graph, v);

	return 0;
}