#include <iostream>
#include <vector>
#include <algorithm>

// 문제주소 : https://www.acmicpc.net/problem/23349
// 메모리, 응답시간 : 13208kb, 24ms

class student {
public:
	std::string name;
	std::string place;
	int timeStart;
	int timeEnd;

	student() {}
	student(std::string name, std::string place, int timeStart, int timeEnd) {
		this->name = name;
		this->place = place;
		this->timeStart = timeStart;
		this->timeEnd = timeEnd;
	}

	bool operator > (student& a) {
		return place > a.place;
	}

	bool operator < (student& a) {
		return place < a.place;
	}
};
int main() {
	//첫째 줄에 제출 수 N
	int n;
	std::cin >> n;

	//다음 N개의 줄에 제출의 정보 name, place, time 가 
	//한 줄에 하나씩 주어진다.
	std::vector<student> studentArray;
	//입력받기
	for (int i = 0; i < n; i++) {
		std::string nameTmp, placeTmp;
		int timeStartTmp, timeEndTmp;

		std::cin >> nameTmp >> placeTmp >> timeStartTmp >> timeEndTmp;

		//중복 제출 확인
		bool isDup = false;
		for (int j = 0; j < studentArray.size(); j++) 
			if (studentArray[j].name == nameTmp) isDup = true;
		if (isDup) continue;
	
		//name, time, place에 데이터 삽입
		studentArray.push_back(student(nameTmp, placeTmp, timeStartTmp, timeEndTmp));
	}

	//혼잡시간 구하기
	//
	//사전 순 정렬
	sort(studentArray.begin(), studentArray.end());
	//처리할 장소 정하기
	//장소 갯수 셀 placeCnt, placeCnt의 최댓값을 갱신할 maxCnt, 가장 많이 나온 장소 selectedPlace
	int placeCnt = 0;
	std::string currentPlace = "";
	std::string selectedPlace = "";
	int collisionCnt = -1;
	for (int i = 0; i < studentArray.size(); i++) {
		//현재 입력 장소에 대한 임시 시간 표 tmp
		//int* tmp = new int[studentArray[i].timeEnd+2] {};
		int* tmp = new int[50002] {};
		for (int j = 0; j < studentArray.size(); j++) {
			if (studentArray[j].place == studentArray[i].place) {
				for (int k = studentArray[j].timeStart; k < studentArray[j].timeEnd; k++) {
					tmp[k]++;
				}
			}
		}
		//겹치면 카운트
		int currentCollisionCnt = *std::max_element(&tmp[1], &tmp[1] + 50000);
		if (currentCollisionCnt > collisionCnt) {
			collisionCnt = currentCollisionCnt;

			//최대 빈도 장소 갱신
			selectedPlace = studentArray[i].place;
		}
	}

	//std::cout << selectedPlace << "!!\n";

	//선택된 장소의 가장빠른 혼잡시간 계산
	//시간 표 만들기
	int* time = new int[50002] {};
	for (int i = 0; i < studentArray.size(); i++) {
		if (studentArray[i].place == selectedPlace) {
			for (int k = studentArray[i].timeStart; k < studentArray[i].timeEnd; k++) {
				time[k]++;
			}
		}
	}

	int* maxPlaceStart = std::max_element(&time[1], &time[1] + 50000);
	int* maxPlaceEnd = maxPlaceStart;
	for (int* currentTime = maxPlaceStart; ; currentTime++) {
		if (*currentTime < *maxPlaceStart) break;
		maxPlaceEnd++;
	}

	std::cout << selectedPlace << " " << (maxPlaceStart - &time[0]) << " " << (maxPlaceEnd - &time[0]);

	return 0;
}