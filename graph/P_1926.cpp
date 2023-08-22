#include <iostream>
#include <vector>

// 문제주소 : https://www.acmicpc.net/problem/2161
// 메모리, 응답시간 : 18708kb, 64ms

int n, m;
int search(int y, int x, int* paint[], bool* visited[]) {
	if (paint[y][x] == 0) return 0;
	//방문한 지점이면 중단
	if (visited[y][x] == true) return 0;
	visited[y][x] = true;

	//그림 넓이 count
	int count = 0;
	//x, y기준 위
	if (y - 1 >= 0) {
		count += search(y - 1, x, paint, visited);
	}
	//왼쪽
	if (x - 1 >= 0) {
		count += search(y, x - 1, paint, visited);
	}
	//아래
	if (y + 1 < n) {
		count += search(y + 1, x, paint, visited);
	}
	//오른쪽
	if(x + 1 < m){
		count += search(y, x + 1, paint, visited);
	}

	if (paint[y][x] == 1) count++;
	
	return count;
}

int main() {
	//도화지의 세로크기 n, 
	//가로크기 m
	std::cin >> n >> m;
	//mXn 그림
	int** paint = new int* [n];
	for (int i = 0; i < n; i++) paint[i] = new int[m];

	int paintCount = 0;
	int maxPaintSize = 0;
	//입력
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			std::cin >> paint[y][x];
		}
	}

	//mXn 배열
	bool** visited = new bool*[n];
	for (int i = 0; i < n; i++) visited[i] = new bool[m];

	//탐색
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			int paintSize = search(y, x, paint, visited);
			if (paintSize > 0) {
				paintCount++;
				if (paintSize > maxPaintSize) maxPaintSize = paintSize;
			}
		}
	}

	std::cout << paintCount << "\n" << maxPaintSize;

	return 0;
}