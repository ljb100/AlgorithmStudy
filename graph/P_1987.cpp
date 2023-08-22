#include <iostream>
#include <vector>

// 문제주소 : https://www.acmicpc.net/problem/1987
// 메모리, 응답시간 : 2020kb, 700ms

bool visited[26] = { false, };
int r, c;

int search(char** board, int posY, int posX) {
	char currentAlpha = board[posY][posX];
	bool* currentVisit = &visited[currentAlpha - 'A'];

	if (*currentVisit == true) return 0;
	*currentVisit = true;

	int dx[4] = {1, 0, -1, 0};
	int dy[4] = { 0, -1, 0, 1 };
	
	int maxCount = 0;
	for (int i = 0; i < 4; i++) {
		int count = 1;
		int y = posY + dy[i];
		int x = posX + dx[i];
		if ( (0 <= y && y < r) 
			&& (0 <= x && x < c) ) {
			count += search(board, posY + dy[i], posX + dx[i]);
			if (maxCount < count) maxCount = count;
		}
	}

	*currentVisit = false;
	return maxCount;
}
int main() {
	//세로r, 가로 c
	std::cin >> r >> c;

	//rXC board
	char** board = new char* [r];
	for (int i = 0; i < r; i++) board[i] = new char[c];

	//input
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			std::cin >> board[i][j];
		}
	}

	int count = search(board, 0, 0);
	std::cout << count;


	return 0;
