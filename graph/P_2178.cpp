#include <iostream>
#include <queue>
#include <stdlib.h>
#include <stdio.h>
#pragma warning(disable:4996)

// 문제주소 : https://www.acmicpc.net/problem/2178
// 메모리, 응답시간 : 2024kb, 0ms

std::queue<std::pair<std::pair<int, int>, int>> q;
bool** visited;
int n, m;
//이동한 타일 수 반환
int search(bool** maze, int posY, int posX) {
	int searchCount = 0;
	std::pair<int, int> startPos = { posY, posX };
	q.push({ startPos , searchCount});

	
	while (!q.empty()) {
		int currentPosX = q.front().first.second;
		int currentPosY = q.front().first.first;
		int searchCount = q.front().second;
		visited[currentPosY][currentPosX] = true;
		q.pop();

		if (currentPosX == m-1 && currentPosY == n-1) return searchCount + 1;

		int dx[4] = { 1, 0, -1, 0 };
		int dy[4] = { 0, -1, 0, 1 };

		for (int i = 0; i < 4; i++) {
			int nextX = currentPosX + dx[i];
			int nextY = currentPosY + dy[i];

			if ((0 <= nextX && nextX < m) &&
				(0 <= nextY && nextY < n)) {
				if (maze[nextY][nextX] == true &&
					visited[nextY][nextX] == false) {
					visited[nextY][nextX] = true;
					q.push({ {nextY, nextX}, searchCount + 1 });
				}
			}
		}
	}

	return -1;
}

int main() {
	std::cin >> n >> m;

	//nXm maze
	bool** maze = new bool* [n];
	for (int i = 0; i < n; i++) maze[i] = new bool[m];

	visited = new bool* [n];
	for (int i = 0; i < n; i++) visited[i] = new bool[m] {false, };
	

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &maze[i][j]);
		}
	}

	std::cout << search(maze, 0, 0);

	return 0;
}