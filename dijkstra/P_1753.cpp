#include <iostream>
#include <queue>
#include <vector>
#include <cstdio>

int* shortest;

struct cmp {
	bool operator()(int n1, int n2) {
		if (shortest[n1] > shortest[n2]) return true;
		else return false;
	}
};

int main() {
	int v, e;
	std::cin >> v >> e;

	int k;
	std::cin >> k;

	std::vector<std::pair<int, int>>* graph = new std::vector<std::pair<int, int>>[v + 1];

	for (int i = 0; i < e; i++) {
		int u, v, w;
		std::cin >> u >> v >> w;

		graph[u].push_back({ v, w });
	}

	shortest = new int[v + 1];
	std::fill(&shortest[0], &shortest[v + 1], 1000000);
	shortest[k] = 0;

	//<노드, 가중치>
	std::priority_queue<int, std::vector<int>, cmp> q;
	q.push(k);

	while (!q.empty()) {
		int currentNode = q.top();
		q.pop();

		for (int i = 0; i < graph[currentNode].size(); i++) {
			int currentNextNode = graph[currentNode][i].first;
			int currentNextWeight = graph[currentNode][i].second;

			if (shortest[currentNextNode] > shortest[currentNode] + currentNextWeight) {
				shortest[currentNextNode] = shortest[currentNode] + currentNextWeight;
				q.push(currentNextNode);
			}
		}
	}

	for (int i = 1; i <= v; i++) {
		if (shortest[i] == 1000000)
			std::cout << "INF";
		else 
			std::cout << shortest[i];

		std::cout << "\n";
	}

	return 0;
}