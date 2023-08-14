#include <iostream>
#include <vector>
#include <string>

// 문제주소 : https://www.acmicpc.net/problem/17264
// 메모리, 응답시간 : 2024kb, 0ms

int main() {
	//총 게임 횟수 n, 해킹을 통해 얻은 플레이어 정보 수 p
	int n, p;
	std::cin >> n >> p;

	//이긴 경우 획득 점수 W와 졌을 때 떨어지는 점수 L, 
	//그리고 IRON 티어에서 벗어나기 위한 점수 G
	int w, l, g;
	std::cin >> w >> l >> g;

	std::vector<std::string>player(p, "");
	std::vector<std::string>match(p, "");

	//다음 P개의 줄에는 플레이어의 이름과 무조건 이길 수 있는 경우 W, 
	//무조건 지는 경우 L이라는 단어가 플레이어 이름과 쌍으로 나온다.
	for (int i = 0; i < p; i++) {
		std::cin >> player[i] >> match[i];
	}

	//그리고 그 다음 N개의 줄에는 같이 게임을 하는 플레이어의 이름이 나온다.
	int score = 0;
	for (int i = 0; i < n; i++) {
		std::string input = "";
		std::cin >> input;

		//해킹해서 안 얘냐 아니냐 isKnow
		bool isKnow = false;
		//해킹한 플레이어 대조
		for (int j = 0; j < p; j++) {
			if (player[j] == input) {
				isKnow = true;
				if (match[j] == "W") {
					score += w;
				}
				else if (match[j] == "L") {
					score -= l;
				}
				else {
					score -= l;
				}
				
				//-면 0으로
				if (score < 0) score = 0;
				break;
			}
		}

		//해킹한 얘들 중에 없으면
		if (isKnow == false) {
			score -= l;
			if (score < 0) score = 0;
		}

		//승급하면 끝
		if (score >= g) {
			std::cout << "I AM NOT IRONMAN!!";
			return 0;
		}
	}
	//경기 중 승급못하면 아이언
	std::cout << "I AM IRONMAN!!";

	return 0;
}