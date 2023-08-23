#include <iostream>

// 문제주소 : https://www.acmicpc.net/problem/1405
// 메모리, 응답시간 : 2020kb, 36ms

int inputN, e, w, s, n;
int centerX, centerY;

double search(bool** board, int posY, int posX, int count) {
	board[posY][posX] = true;

	int dx[4] = { 1, 0, -1, 0 };
	int dy[4] = { 0, -1, 0, 1 };
	double percent[4] = { e/ 100.0, n/ 100.0, w/ 100.0, s/100.0 };

	double result = 0;
	for (int i = 0; i < 4; i++) {
		if (percent[i] == 0) continue;

		int nextY = posY + dy[i];
		int nextX = posX + dx[i];

		//탐색 끝부분
		if ((count == inputN - 1) && 
			(board[nextY][nextX] == false)) {
			result += percent[i];
		}
		//탐색 도중
		else {
			if(board[nextY][nextX] == false)
				result += (search(board, nextY, nextX, count + 1) * percent[i]);
		}
	}

	board[posY][posX] = false;
	return result;
}

int main() {
	//첫째 줄에 N, 
	//동쪽으로 이동할 확률, 서쪽으로 이동할 확률, 
	//남쪽으로 이동할 확률, 북쪽으로 이동할 확률이 주어진다
	std::cin >> inputN >> e >> w >> s >> n;

	//(n*2 + 1)X(n*2 + 1) board
	int boardSize = inputN * 2 + 1;
	bool** board = new bool* [boardSize + 1];
	for (int i = 0; i < boardSize + 1; i++) board[i] = new bool[boardSize + 1] {false, };

	centerX = boardSize / 2 + 1;
	centerY = boardSize / 2 + 1;
	double result = search(board, centerY, centerX, 0);

	std::cout.precision(10);
	std::cout << result;

	return 0;
}