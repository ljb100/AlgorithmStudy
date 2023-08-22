#include <iostream>

int n;
int** gameBoard;
bool** visited;
bool search(int posY, int posX) {
	if (visited[posY][posX]) return false;
	visited[posY][posX] = true;

	if (gameBoard[posY][posX] == -1) return true;
	int length = gameBoard[posY][posX];

	//아래
	if (posY + length < n) {
		if(search(posY + length, posX)) return true;
	}

	//오른쪽
	if (posX + length < n) {
		if(search(posY, posX + length)) return true;
	}

	return false;
}

int main(){
	//게임 구역 크기 n
	std::cin >> n;

	//게임 구역 
	gameBoard = new int* [n];
	for (int i = 0; i < n; i++) gameBoard[i] = new int[n];

	//방문여부
	visited = new bool* [n];
	for (int i = 0; i < n; i++) visited[i] = new bool[n];

	//입력
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cin >> gameBoard[i][j];
		}
	}

	//탐색
	if (search(0, 0)) {
		std::cout << "HaruHaru";
	}
	else {
		std::cout << "Hing";
	}

	return 0;
}