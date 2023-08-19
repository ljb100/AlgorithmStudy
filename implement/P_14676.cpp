#include <iostream>
#include <vector>
#include <algorithm>

// 문제주소 : https://www.acmicpc.net/problem/14676
// 메모리, 응답시간 : 11888kb, 940ms

typedef struct node {
	//건물 보유 수
	int count = 0;
	//선행건물들
	std::vector<struct node*> before;
	std::vector<struct node*> after;
}Node;

int main() {
	int n, m, k;
	std::cin >> n >> m >> k;

	//buildInfo초기화
	Node* buildInfo = new Node[n + 2];
	
	//buildInfo선행건물 연결
	for (int i = 0; i < m; i++) {
		int inputX;
		int inputY;
		std::cin >> inputX >> inputY;

		buildInfo[inputY].before.push_back(&buildInfo[inputX]);
		buildInfo[inputX].after.push_back(&buildInfo[inputY]);
	}

	//영우데이터 검사
	std::vector<int> canBuild;
	for (int i = 0; i < k; i++) {
		int command;
		int object;
		std::cin >> command >> object;

		//생성
		if (command == 1) {
			//핵판별
			if (std::find(canBuild.begin(), canBuild.end(), object) == canBuild.end()) {
				int beforeSize = buildInfo[object].before.size();
				for (int j = 0; j < beforeSize; j++) {
					if (buildInfo[object].before[j]->count == 0) {
						std::cout << "Lier!";
						return 0;
					}
				}
				canBuild.push_back(object);
			}

			buildInfo[object].count++;
		}
		//파괴
		else if (command == 2) {
			//핵판별
			if (buildInfo[object].count > 0) {
				buildInfo[object].count--;
			}
			else {
				std::cout << "Lier!";
				return 0;
			}

			int deleteIndex;
			if (buildInfo[object].count == 0) {
				for (int j = 0; j < buildInfo[object].after.size(); j++) {
					deleteIndex = (buildInfo[object].after[j] - &buildInfo[0]);
					auto deletePos = std::find(canBuild.begin(), canBuild.end(), deleteIndex);
					if(deletePos != canBuild.end())
						canBuild.erase(deletePos);
				}
			}
		}
	}

	std::cout << "King-God-Emperor";
	return 0;
}
