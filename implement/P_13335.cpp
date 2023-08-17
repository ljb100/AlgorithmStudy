#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

// 문제주소 : https://www.acmicpc.net/problem/13335
// 메모리, 응답시간 : 2020kb, 0ms

int main() {
	//n은 다리를 건너는 트럭의 수, w는 다리의 길이, 
	//그리고 L은 다리의 최대하중을 나타낸다.
	int n, w, l;
	std::cin >> n >> w >> l;

	std::vector<int> waitTrucks(n, 0);
	std::vector<int> onTrucks(0, 0);
	std::vector<int> endTrucks(0, 0);
	std::vector<int> timer(0, -1);
	for (int i = 0; i < n; i++) 
		std::cin >> waitTrucks[i];
	
	int time = 1;
	while (true) {
		int onTrucksSum = std::accumulate(onTrucks.begin(), onTrucks.end(), 0);
		//다리의 최대하중까지 트럭 가기
		int nextTruck = 0;
		if (waitTrucks.size() != 0) nextTruck = waitTrucks.front();
		if (onTrucksSum + nextTruck <= l && waitTrucks.size() != 0) {
			//트럭 다리로
			onTrucks.push_back(waitTrucks.front());
			waitTrucks.erase(waitTrucks.begin());
			//이동시간
			timer.push_back(w);
		}
		//이동처리
		for (int i = 0; i < timer.size(); i++) {
			timer[i] -= 1;
			if (timer[i] == 0) {
				//다리 트럭 이동 끝
				endTrucks.push_back(onTrucks.front());
				onTrucks.erase(onTrucks.begin());
				i--;
				timer.erase(timer.begin());
			}
		}

		time++;

		//종료 체크
		if (endTrucks.size() == n) break;

	}

	std::cout << time;
	return 0;
}