#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

bool compareDiffer(int first[], int second[]) {
	if (abs(first[1] - first[2]) > abs(second[1] - second[2]))
		return true;
	else
		return false;
}

// 문제주소 : https://www.acmicpc.net/problem/4716
// 메모리, 응답시간 : 2816kb, 92ms

int main() {
	while (true) {
		//팀의 수 n, 풍선의 수 a, b
		int teamNum, aRoom, bRoom;
		cin >> teamNum >> aRoom >> bRoom;

		if (teamNum == 0 && aRoom == 0 && bRoom == 0) {
			break;
		}

		
		//2차원 배열
		int** teamInfo = new int* [teamNum];
		for (int i = 0; i < teamNum; i++) teamInfo[i] = new int[3];

		//입력받기
		//[i][0] -> 요구 풍선 갯수, [i][1] -> A방 거리, [i][1] -> B방 거리
		for(int i = 0; i < teamNum; i++){
			cin >> teamInfo[i][0] >> teamInfo[i][1] >> teamInfo[i][2];
		}
		
		//정렬
		sort(&teamInfo[0], &teamInfo[teamNum], compareDiffer);

		int moveLen = 0;
		//분배
		for (int i = 0; i < teamNum; i++) {
			int* room;
			int roomIndex;

			//가까운 방 선택
			if (aRoom == 0) {
				roomIndex = 2;
				room = &bRoom;
			}
			else if (bRoom == 0) {
				roomIndex = 1;
				room = &aRoom;
			}
			else if (teamInfo[i][1] > teamInfo[i][2]) {
				roomIndex = 2;
				room = &bRoom;
			}
			else {
				roomIndex = 1;
				room = &aRoom;
			}


		
			//풍선 부족하면
			if (*room < teamInfo[i][0]) {
				moveLen += (teamInfo[i][roomIndex] * (*room));
				teamInfo[i][0] -= *room;
				*room = 0;
				i--;
			}
			else {
				*room -= teamInfo[i][0];
				moveLen += (teamInfo[i][roomIndex] * teamInfo[i][0]);
				teamInfo[i][0] = 0;
			}
		}
		cout << moveLen << "\n";
	}
	return 0;
}