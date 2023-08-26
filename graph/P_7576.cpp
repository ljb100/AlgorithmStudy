#include <iostream>
#include <queue>

// 문제주소 : https://www.acmicpc.net/problem/7576
// 메모리, 응답시간 : 13368kb, 264ms

int m, n;
int** tomatoes;
bool** visited;
std::queue<std::pair<std::pair<int, int>, int>> q;
int RipeTomatoCount = 0;
int emptyCount = 0;
int searchTime;

bool search() {
	while (!q.empty()) {
		int currentPosY = q.front().first.first;
		int currentPosX = q.front().first.second;
		int currentSearchTime = q.front().second;
		searchTime = currentSearchTime;
		q.pop();

		visited[currentPosY][currentPosX] = true;

		tomatoes[currentPosY][currentPosX]++;

		int dx[4] = { 1, 0, -1, 0 };
		int dy[4] = { 0, -1, 0, 1 };
		for (int i = 0; i < 4; i++) {
			int nextY = currentPosY + dy[i];
			int nextX = currentPosX + dx[i];
			if ((0 > nextY || nextY >= n) ||
				(0 > nextX || nextX >= m)) {
				continue;
			}

			if (visited[nextY][nextX] == false &&
				tomatoes[nextY][nextX] == 0) {
				RipeTomatoCount++;

				visited[nextY][nextX] = true;
				q.push({{ nextY, nextX }, currentSearchTime +1});
			}
		}
	}

	if (RipeTomatoCount == (m * n) - emptyCount) return true;
	else return false;

}
int main() {
	//상자의 가로m, 세로 n
	std::cin >> m >> n;

	tomatoes = new int* [n];
	for (int i = 0; i < n; i++) tomatoes[i] = new int[m];

	visited = new bool* [n];
	for (int i = 0; i < n; i++) visited[i] = new bool[m] {false, };

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int input;
			std::cin >> input;
			
			tomatoes[i][j] = input;

			if (input == 1) {
				q.push({ { i, j }, 0 });
				//익은 토마토 갯수
				RipeTomatoCount++;
			}
			else if (input == -1) {
				//빈 자리
				emptyCount++;
			}
		}
	}

	int boardSize = m * n;
	if (RipeTomatoCount + emptyCount == boardSize) {
		std::cout << 0;
	}
	else if (search()) {
		std::cout << searchTime;
	}
	else {
		std::cout << -1;
	}

	return 0;
}