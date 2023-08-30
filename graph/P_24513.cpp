#include <iostream>
#include <queue>

// 문제주소 : https://www.acmicpc.net/problem/24513
// 메모리, 응답시간 : 11300kb, 240ms

int n, m;
std::pair<int, int>** village;
bool** visited;
int virus1, virus2, virus3;

std::queue<std::pair<int, int>> q;

void start() {
	while (!q.empty()) {
		//현재 X,Y좌표
		int currentPosX = q.front().second;
		int currentPosY = q.front().first;
		q.pop();
		//현재 마을의 pair = {currentStatus1, currentStatus2} <- 마을 상태
		int currentStatus1 = village[currentPosY][currentPosX].first;
		int currentStatus2 = village[currentPosY][currentPosX].second;

		//완전감염
		bool isInfected = false;
		if (currentStatus1 + currentStatus2 == 3) {
			village[currentPosY][currentPosX].first = village[currentPosY][currentPosX].second = 3;
			virus3++;
			isInfected = true;
			visited[currentPosY][currentPosX] = true;
			continue;
		}
		else if (currentStatus1 + currentStatus2 == 4) {
			virus2++;
			isInfected = true;
		}
		else if (currentStatus1 == 1 && currentStatus2 == 1) {
			virus1++;
			isInfected = true;
		}

		//완전감염되면 전염시작
		if (isInfected) {
			visited[currentPosY][currentPosX] = true;
			int dx[4] = { 1, 0, -1, 0 };
			int dy[4] = { 0, -1, 0, 1 };
			for (int i = 0; i < 4; i++) {
				int nextX = currentPosX + dx[i];
				int nextY = currentPosY + dy[i];
				if ((nextX < 0 || nextX >= m) ||
					(nextY < 0 || nextY >= n)) {
					continue;
				}

				//백신없고 완전감염 전이면
				if (visited[nextY][nextX] == false &&
					village[nextY][nextX].first != -1) {

					//{0, 0}이면
					if (village[nextY][nextX].first == 0) {
						village[nextY][nextX].first = currentStatus1;
						q.push({ nextY, nextX });
					}
					//다른 바이러스가 감염되어있을때만 혼합
					else if (village[nextY][nextX].first != currentStatus1 && 
						village[nextY][nextX].second == 0) {
						village[nextY][nextX].second = currentStatus1;
						q.push({ nextY, nextX });
					}
				}
			}
		}
		//완전감염 전이면 다음 회차에 다시 처리
		else if(visited[currentPosY][currentPosX] == false){
			village[currentPosY][currentPosX].second = currentStatus1;
			q.push({ currentPosY, currentPosX });
		}
	}
}

int main() {
	//바이러스 카운트
	virus1 = virus2 = virus3 = 0;
	//n개의 줄에 걸쳐 마을 상태 m개
	std::cin >> n >> m;

	//nXm 마을
	village = new std::pair<int, int>*[n];
	for (int i = 0; i < n; i++) {
		village[i] = new std::pair<int, int>[m];
		for (int j = 0; j < m; j++) village[i][j] = { 0, 0 };
	}

	//완전감염 visited
	visited = new bool* [n];
	for (int i = 0; i < n; i++) {
		visited[i] = new bool[m];
		std::fill(&visited[i][0], &visited[i][m], false);
	}

	//입력
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int input;
			std::cin >> input;
			
			village[i][j].second = village[i][j].first = input;

			//감염된 마을이면 큐에 푸시
			if (input == 1 || input == 2) {
				visited[i][j] = true;
				q.push({i, j});
			}
		}
	}

	//감염 진행
	start();

	std::cout << virus1 << " " << virus2 << " " << virus3;
	return 0;
}